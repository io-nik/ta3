//
// Created by ionik on 17.06.2025.
//

#ifndef TA3_INTERPRETER_H
#define TA3_INTERPRETER_H

#include "FunctionDef.h"

Value* eval_function(FunctionDef* fn, Environment* parent);

#endif //TA3_INTERPRETER_H
