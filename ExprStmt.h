//
// Created by ionik on 17.06.2025.
//

#ifndef TA3_EXPRSTMT_H
#define TA3_EXPRSTMT_H

#include "Statement.h"
#include "Expression.h"

struct ExprStmt : public Statement {
    Expression* expr;
    explicit ExprStmt(Expression* expr) : expr(expr) {}

    Value* execute(Environment* env) override {
        return expr->evaluate(env);
    }

    ~ExprStmt() override { delete expr; }
};

#endif //TA3_EXPRSTMT_H

