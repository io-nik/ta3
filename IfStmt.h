//
// Created by ionik on 17.06.2025.
//

#ifndef TA3_IFSTMT_H
#define TA3_IFSTMT_H

#include "Statement.h"
#include "FunctionCallStmt.h"
#include "Expression.h"

struct IfStmt : Statement {  // меняли стмт на экспр
    Expression* condition;
    //FunctionCallStmt* call;
    Expression* call;

    IfStmt(Expression* condition, Expression* call)
        : condition(condition), call(call) {}

    Value* execute(Environment* env) override {
        Value* cond = condition->evaluate(env)->castTo(ValueType::BOOL);

        bool shouldExecute = false;
        for (int val : cond->data) {
            if (val != 0) {
                shouldExecute = true;
                break;
            }
        }

        delete cond;

        if (shouldExecute)
            return call->evaluate(env);
        return nullptr;
    }

    ~IfStmt() override {
        delete condition;
        delete call;
    }
};

#endif //TA3_IFSTMT_H

