//
// Created by ionik on 23.06.2025.
//
#ifndef TA3_EXPRESSION_H
#define TA3_EXPRESSION_H

#include <string>
#include "Value.h"
#include "Environment.h"
#include "eval.h"
#include "CellTypes.h"
#include "Robot.h"
#include "FunctionDef.h"
#include "interpreter.h"
#include <map>
extern std::map<std::string, FunctionDef*> functionTable;

struct Expression {
    virtual Value* evaluate(Environment* env) = 0;
    virtual ~Expression() = default;
};

// ConstantExpr: обертка над конкретным значением
struct ConstantExpr : public Expression {
    Value* val;

    explicit ConstantExpr(Value* val) : val(val) {}

    Value* evaluate(Environment* env) override {
        return val;
    }
};

// VariableExpr: обращение к переменной по имени и индексу
struct VariableExpr : public Expression {
    std::string name;

    explicit VariableExpr(std::string name) : name(std::move(name)) {}

    Value* evaluate(Environment* env) override {
        return env->get(name);
    }
};

// BinaryExpr: бинарные выражения типа +, -, in, less и др.
struct BinaryExpr : public Expression {
    Expression* left;
    Expression* right;
    std::string op;

    BinaryExpr(std::string op, Expression* left, Expression* right)
            : left(left), right(right), op(std::move(op)) {}

    Value* evaluate(Environment* env) override {
        Value* lval = left->evaluate(env);
        Value* rval = right->evaluate(env);

        if (op == "%") return eval_mod(lval, rval);
        if (op == "+") return eval_add(lval, rval);
        if (op == "-") return eval_sub(lval, rval);
        if (op == "!=") return eval_unequal(lval, rval);
        if (op == "==") return eval_equal(lval, rval);
        if (op == "in") return eval_in(lval, rval);
        if (op == "less") return eval_less(lval, rval);
        if (op == "and") return eval_and(lval, rval);
        if (op == "or") return eval_or(lval, rval);
        if (op == "some in") return eval_some_in(lval, rval);
        if (op == "all in") return eval_all_in(lval, rval);
        if (op == "some less") return eval_some_less(lval, rval);
        if (op == "all less") return eval_all_less(lval, rval);

        throw std::runtime_error("Unsupported binary operator: " + op);
    }
};

// UnaryExpr: унарные выражения (например, -x, not x)
struct UnaryExpr : public Expression {
    std::string op;
    Expression* subexpr;

    UnaryExpr(std::string op, Expression* subexpr)
            : op(std::move(op)), subexpr(subexpr) {}

    Value* evaluate(Environment* env) override {
        Value* val = subexpr->evaluate(env);

        if (op == "-") return eval_minus(val);
        if (op == "not") return eval_neg(val);
        if (op == "length") return eval_length(val);

        throw std::runtime_error("Unsupported unary operator: " + op);
    }
};

struct ArrayAccessExpr : public Expression {
    std::string name;
    Expression* index;

    ArrayAccessExpr(const std::string& name, Expression* index): name(name), index(index) {}

    Value * evaluate(Environment *env) override {
        Value* v = index->evaluate(env)->castTo(ValueType::INT);
        return env->get(name, v->data[0]);
    }
};


enum class RobotCommandType {
    GO,
    PICK,
    DROP,
    LOOK,
    SET_VISIBILITY,
    GET_VISIBILITY
};


struct RobotCommandExpr : public Expression {
    RobotCommandType command;
    Direction direction;
    Expression* argument;
    Robot* robot;

    RobotCommandExpr(RobotCommandType cmd, Expression* expr, Robot* r)
            : command(cmd), argument(expr), robot(r) {}

    RobotCommandExpr(RobotCommandType cmd, Direction dir, Robot* r)
            : command(cmd), direction(dir), argument(nullptr), robot(r) {}

    Value* evaluate(Environment* env) override {
        Value* result = nullptr;
        switch (command) {
            case RobotCommandType::GO:
                result = robot->go(direction);
                break;
            case RobotCommandType::PICK:
                result = robot->pick(direction);
                break;
            case RobotCommandType::DROP:
                result = robot->drop(direction);
                break;
            case RobotCommandType::LOOK:
                result = robot->look(direction);
                break;
            case RobotCommandType::SET_VISIBILITY: {
                int radius = argument->evaluate(env)->castTo(ValueType::INT)->data[0];
                robot->set_visibility(radius);
                return new Value(ValueType::INT, radius);
            }
            case RobotCommandType::GET_VISIBILITY: {
                int radius = robot->get_visibility();
                return new Value(ValueType::INT, radius);
            }
        }
        robot->print_field();
        return result;
    }
};


struct FunctionCallExpr : public Expression {
    std::string name;

    FunctionCallExpr(const std::string &name) : name(name) {}

    Value* evaluate(Environment *env) override {
        auto it = functionTable.find(name);
        if(it == functionTable.end())
            throw std::runtime_error("Function not found (in expression) " + name);

        //Environment* localEnv = new Environment(env); // я уже создаю область видимости в eval_function()
        Value* result = eval_function(it->second, env); // localEnv
        //delete localEnv;
        return result ? result : new Value(ValueType::INT, 0);

    }
};


// VariableExpr: обращение к переменной по имени
struct FullVariableExpr : public Expression {
    std::string name;

    explicit FullVariableExpr(std::string name) : name(std::move(name)) {}

    Value* evaluate(Environment* env) override {
        return env->get_full(name);
    }
};
#endif // TA3_EXPRESSION_H
