//
// Created by ionik on 21.06.2025.
//

#ifndef TA3_ASSIGNARRAYSTMT_H
#define TA3_ASSIGNARRAYSTMT_H

#include "Statement.h"
#include "Value.h"
#include "Expression.h"

struct AssignArrayStmt : public Statement {
    std::string name;
    Expression* index;
    Expression* expr;

    AssignArrayStmt(const std::string& name, Expression* index, Expression* expr): name(name), index(index), expr(expr) {}

    Value* execute(Environment* env) override {
        if(!env->has(name))
            throw std::runtime_error("Variable not defined: " + name);

        Value* val = expr->evaluate(env)->castTo(env->getType(name));
        int idx = index->evaluate(env)->castTo(ValueType::INT)->data[0];
        env->set(name, idx, val);
        return val;
    }

    ~AssignArrayStmt() override { delete expr; delete index; }
};

#endif //TA3_ASSIGNARRAYSTMT_H
