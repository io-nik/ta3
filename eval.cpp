//
// Created by ionik on 17.06.2025.
//

#include <algorithm>
#include <string>
#include "eval.h"
#include "Value.h"

Value* eval_mod(const Value* a, const Value* b) {
    /*if (a->type != ValueType::INT || b->type != ValueType::INT)
        throw std::runtime_error("Mismatched types in '%' operation");*/

    a = a->castTo(ValueType::INT);
    b = b->castTo(ValueType::INT);

    auto result = new Value(ValueType::INT);
    size_t maxLen = std::max(a->size(), b->size());
    result->data.resize(maxLen);

    for (size_t i = 0; i < maxLen; ++i) {
        int av = (i < a->size()) ? a->data[i] : 0;
        int bv = (i < b->size()) ? b->data[i] : 1; // избегаем деления на 0
        if (bv == 0)
            throw std::runtime_error("Division by zero in '%' operation");
        result->data[i] = av % bv;
    }

    return result;
}


Value* eval_add(const Value* a, const Value* b) {
    a = a->castTo(ValueType::INT);
    b = b->castTo(ValueType::INT);
    auto result = new Value(ValueType::INT);

    size_t maxLen = std::max(a->size(), b->size());
    size_t minLen = std::min(a->size(), b->size());

    result->data.resize(maxLen);

    for(size_t i = 0; i < minLen; ++i)
        result->data[i] = a->data[i] + b->data[i];
    for(size_t i = minLen; i < maxLen; ++i)
        result->data[i] = (a->size() > b->size()) ? a->data[i] : b->data[i];

    return result;
}


Value* eval_sub(const Value* a, const Value* b) {
    a = a->castTo(ValueType::INT);
    b = b->castTo(ValueType::INT);
    auto result = new Value(ValueType::INT);

    size_t maxLen = std::max(a->size(), b->size());
    size_t minLen = std::min(a->size(), b->size());

    result->data.resize(maxLen);

    for(size_t i = 0; i < minLen; ++i)
        result->data[i] = a->data[i] - b->data[i];
    for(size_t i = minLen; i < maxLen; ++i)
        result->data[i] = (a->size() > b->size()) ? a->data[i] : - b->data[i];

    return result;
}


Value* eval_minus(const Value* a) {
    a = a->castTo(ValueType::INT);
    auto result = new Value(ValueType::INT);
    result->data.resize(a->size());

    std::transform(a->data.begin(), a->data.end(), result->data.begin(),
                   [=](int number) {return -number; });

    return result;
}


Value* eval_length(const Value* val) {
    auto result = new Value(ValueType::INT);
    result->data.push_back(val->size());
    return result;
}


Value* eval_unequal(const Value* a, const Value* b) { // приведения типов?
    if (a->type != b->type)
        throw std::runtime_error("Type mismatch in '!=' operator: " + prType(a->type) + " vs " + prType(b->type));
    auto result = new Value(ValueType::BOOL);

    if(a->size() != b->size()) {
        result->data.push_back(1);
        return result;
    }

    bool equal = std::equal(a->data.begin(), a->data.end(), b->data.begin());
    result->data.push_back(equal ? 0 : 1);

    return result;
}


Value* eval_equal(const Value* a, const Value* b) { // приведения типов?
    if (a->type != b->type)
        throw std::runtime_error("Type mismatch in '==' operator: " + prType(a->type) + " vs " + prType(b->type));//cast((int)a->type) + " vs " + cast((int)b->type));
    auto result = new Value(ValueType::BOOL);

    if(a->size() != b->size()) {
        result->data.push_back(0);
        return result;
    }

    bool equal = std::equal(a->data.begin(), a->data.end(), b->data.begin());
    result->data.push_back(equal ? 1 : 0);

    return result;
}


Value* eval_and(const Value* a, const Value* b) {
    a = a->castTo(ValueType::BOOL);
    b = b->castTo(ValueType::BOOL);
    auto result = new Value(ValueType::BOOL);

    size_t maxLen = std::max(a->size(), b->size());
    size_t minLen = std::min(a->size(), b->size());

    result->data.resize(maxLen);

    for(size_t i = 0; i < minLen; ++i)
        result->data[i] = a->data[i] and b->data[i]; // остальные и так уже заполнены нулями

    return result;
}


Value* eval_or(const Value* a, const Value* b) {
    a = a->castTo(ValueType::BOOL);
    b = b->castTo(ValueType::BOOL);
    auto result = new Value(ValueType::BOOL);

    size_t maxLen = std::max(a->size(), b->size());
    size_t minLen = std::min(a->size(), b->size());

    result->data.resize(maxLen);

    for(size_t i = 0; i < minLen; ++i)
        result->data[i] = a->data[i] or b->data[i];
    for(size_t i = minLen; i < maxLen; ++i) // число ИЛИ 0 = число
        result->data[i] = (a->size() > b->size()) ? a->data[i] : b->data[i];

    return result;
}

Value* eval_neg(const Value* a) {
    a = a->castTo(ValueType::BOOL);
    auto result = new Value(ValueType::BOOL);
    result->data.resize(a->size());

    std::transform(a->data.begin(), a->data.end(), result->data.begin(),
                   [=](int number) {return !number; });

    return result;
}


Value* eval_in(const Value *x, const Value *arr) {
    if(x->type != arr->type)
        throw std::runtime_error("Type mismatch in 'in' operator: " + prType(x->type) + " vs " + prType(arr->type));


    auto result = new Value(ValueType::BOOL);

    int target = x->data[0];
    bool found = false;

    for(int i: arr->data) {
        if(i == target) {
            found = true;
            break;
        }
    }

    result->data.push_back(found ? 1 : 0);
    return result;
}


Value* eval_all_in(const Value* a, const Value* b) {
    if (a->type != b->type)
        throw std::runtime_error("Type mismatch in 'all in' operator: " + prType(a->type) + " vs " + prType(b->type));

    auto result = new Value(ValueType::BOOL);
    bool allFound = true;

    for (int ai : a->data) {
        bool found = false;
        for (int bi : b->data) {
            if (ai == bi) {
                found = true;
                break;
            }
        }
        if (!found) {
            allFound = false;
            break;
        }
    }

    result->data.push_back(allFound ? 1 : 0);
    return result;
}


Value* eval_some_in(const Value* a, const Value* b) {
    if (a->type != b->type)
        throw std::runtime_error("Type mismatch in 'some in' operator: " + prType(a->type) + " vs " + prType(b->type));

    auto result = new Value(ValueType::BOOL);
    bool found = false;

    for (int ai : a->data) {
        for (int bi : b->data) {
            if (ai == bi) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    result->data.push_back(found ? 1 : 0);
    return result;
}


Value* eval_less(const Value* x, const Value* arr) {
    if (x->type != arr->type)
        throw std::runtime_error("Type mismatch in 'less' operator: " + prType(x->type) + " vs " + prType(arr->type));

    auto result = new Value(ValueType::BOOL);

    int val = x->data[0]; // Одно значение
    bool is_less = false;

    for (int i : arr->data) {
        if (val < i) {
            is_less = true;
            break;
        }
    }

    result->data.push_back(is_less ? 1 : 0);
    return result;
}


Value* eval_all_less(const Value* a, const Value* b) {
    if (a->type != b->type)
        throw std::runtime_error("Type mismatch in 'all less' operator: " + prType(a->type) + " vs " + prType(b->type));

    auto result = new Value(ValueType::BOOL);
    bool all_less = true;

    for (int x : a->data) {
        for (int y : b->data) {
            if (x >= y) {
                all_less = false;
                goto done;
            }
        }
    }

    done:
    result->data.push_back(all_less ? 1 : 0);
    return result;
}


Value* eval_some_less(const Value* a, const Value* b) {
    if (a->type != b->type)
        throw std::runtime_error("Type mismatch in 'some less' operator: " + prType(a->type) + " vs " + prType(b->type));

    auto result = new Value(ValueType::BOOL);
    bool some_less = false;

    for (int x : a->data) {
        for (int y : b->data) {
            if (x < y) {
                some_less = true;
                goto done;
            }
        }
    }

    done:
    result->data.push_back(some_less ? 1 : 0);
    return result;
}
