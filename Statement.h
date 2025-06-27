//
// Created by ionik on 17.06.2025.
//

#ifndef TA3_STATEMENT_H
#define TA3_STATEMENT_H

#include "Environment.h"
#include "Value.h"

struct Statement {
    virtual ~Statement() = default;

    virtual Value* execute(Environment *env) = 0;
};


#endif //TA3_STATEMENT_H
