//
// Created by ionik on 20.06.2025.
//

#ifndef TA3_PRINTSTMT_H
#define TA3_PRINTSTMT_H

#include "Statement.h"
#include "Value.h"
#include "Expression.h"

struct PrintStmt : public Statement {
    Expression* expr;

    explicit PrintStmt(Expression* expr): expr(expr) {}

    Value* execute(Environment *env) override {
        Value* val = expr->evaluate(env);
        print_value(val);
        return val;
    }
};

#endif //TA3_PRINTSTMT_H
