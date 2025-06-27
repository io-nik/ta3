//
// Created by ionik on 17.06.2025.
//

#ifndef TA3_LOOPSTMT_H
#define TA3_LOOPSTMT_H

#include "Statement.h"
#include "FunctionCallStmt.h"
#include "Expression.h"

struct LoopStmt : public Statement {
    Expression* from;
    Expression* to;
    Expression* step;
    //FunctionCallStmt* body;
    Expression* body;

    LoopStmt(Expression* from, Expression* to, Expression* step, Expression* body)
            : from(from), to(to), step(step), body(body) {}

    Value* execute(Environment* env) override {
        Value *v1 = from->evaluate(env)->castTo(ValueType::INT);
        Value *v2 = to->evaluate(env)->castTo(ValueType::INT);
        Value* v3 = step ? step->evaluate(env)->castTo(ValueType::INT)
                : new Value(ValueType::INT, 1);

        int begin = v1->data[0];
        int end = v2->data[0];
        int s = v3->data[0];

        delete v1; delete v2; delete v3;

        if(s == 0)
            throw std::runtime_error("Loop step cannot be zero");

        Value* result = nullptr;
        if(s > 0)
            for(int i = begin; i < end; i += s)
                result = body->evaluate(env);
        else
            for(int i = begin; i > end; i -= s)
                result = body->evaluate(env);

        return result;
    }

    ~LoopStmt() override { delete from, delete to, delete step, delete body; }
};

#endif //TA3_LOOPSTMT_H
