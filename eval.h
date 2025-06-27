//
// Created by ionik on 17.06.2025.
//

#ifndef TA3_EVAL_H
#define TA3_EVAL_H

#include "Value.h"
    Value* eval_mod(const Value* a, const Value* b);

    Value* eval_add(const Value* a, const Value* b);

    Value* eval_sub(const Value* a, const Value* b);

    Value* eval_minus(const Value* a);

    Value* eval_length(const Value* val);

    Value* eval_unequal(const Value* a, const Value* b);

    Value* eval_equal(const Value* a, const Value* b);

    Value* eval_and(const Value* a, const Value* b);

    Value* eval_or(const Value* a, const Value* b);

    Value* eval_neg(const Value* a);

    Value* eval_in(const Value* x, const Value* arr);

    Value* eval_all_in(const Value* a, const Value* b);

    Value* eval_some_in(const Value* a, const Value* b);

    Value* eval_less(const Value* x, const Value* arr);

    Value* eval_all_less(const Value* a, const Value* b);

    Value* eval_some_less(const Value* a, const Value* b);

#endif //TA3_EVAL_H
