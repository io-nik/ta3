//
// Created by ionik on 21.06.2025.
//

#ifndef TA3_ASSIGNDEFSTMT_H
#define TA3_ASSIGNDEFSTMT_H

#include "Statement.h"
#include "Value.h"
#include "Expression.h"

struct AssignDefStmt : public Statement {
    std::string name;
    ValueType type;
    Expression* expr;

    AssignDefStmt(const std::string& name, ValueType type, Expression* expr)
            : name(name), type(type), expr(expr) {}

    Value* execute(Environment* env) override {
        Value* val = expr->evaluate(env)->castTo(type);
        env->define(name, val);  // именно define!
        return val;
    }
};

#endif //TA3_ASSIGNDEFSTMT_H
