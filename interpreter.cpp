//
// Created by ionik on 21.06.2025.
//

#include "interpreter.h"
#include "globals.h"


Value* eval_function(FunctionDef* fn, Environment* parent) {
    Environment* local = new Environment(parent);
    current_env = local;

    Value* result = nullptr;
    for (Statement* stmt : *fn->body) {
        result = stmt->execute(local);
    }

    delete local;
    current_env = nullptr;
    return result;
}