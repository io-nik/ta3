//
// Created by ionik on 17.06.2025.
//

#ifndef TA3_ASSIGNSTMT_H
#define TA3_ASSIGNSTMT_H

#include "Statement.h"
#include "Expression.h"

struct AssignStmt : public Statement {
    std::string name;
    Expression* expr;

    AssignStmt(const std::string& name, Expression* expr) : name(name), expr(expr) {}

    Value* execute(Environment* env) override {
        if (!env->has(name))
            throw std::runtime_error("Variable not defined: " + name);

        Value* val = expr->evaluate(env)->castTo(env->getType(name));
        env->assign(name, val);
        return val;
    }

    ~AssignStmt() override { delete expr; }
};

#endif //TA3_ASSIGNSTMT_H
