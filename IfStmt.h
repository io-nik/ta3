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
	Expression* elsecall;

    IfStmt(Expression* condition, Expression* call, Expression* elsecall = nullptr)
        : condition(condition), call(call), elsecall(elsecall) {}

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
		else if(elsecall)
			return elsecall->evaluate(env);
        return new Value(ValueType::BOOL, 0);
    }

    ~IfStmt() override {
        delete condition;
        delete call;
    }
};

#endif //TA3_IFSTMT_H

