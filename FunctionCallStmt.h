//
// Created by ionik on 17.06.2025.
//

#ifndef TA3_FUNCTIONCALLSTMT_H
#define TA3_FUNCTIONCALLSTMT_H

#include "Statement.h"
#include "interpreter.h"
#include <stdexcept>
#include <map>

extern std::map<std::string, FunctionDef*> functionTable;

struct FunctionCallStmt : public Statement {
    std::string name;

    explicit FunctionCallStmt(const std::string& name): name(name) {}

    Value* execute(Environment* env) override {
        auto it = functionTable.find(name);
        if(it == functionTable.end())
            throw std::runtime_error("Function not found " + name);

        Environment* localEnv = new Environment(env);
        Value* result = eval_function(it->second, localEnv);
        delete localEnv;
        return result ? result : new Value(ValueType::INT, 0);
    }
};

#endif //TA3_FUNCTIONCALLSTMT_H
