//
// Created by ionik on 17.06.2025.
//

#include <algorithm>
#include <iostream>
#include "Value.h"
#include "CellTypes.h"


std::string prType(ValueType t) {
    switch (t) {
        case ValueType::INT:
            return "INT";
        case ValueType::BOOL:
            return "BOOL";
        case ValueType::CELL:
            return "CELL";
        default:
            return "UNKNOWN";
    }
}


std::string cast(int i) {
    switch (i) {
        case 0: return "UNDEF";
        case 1: return "EMPTY";
        case 2: return "WALL";
        case 3: return "BOX";
        case 4: return "EXIT";
        default: return "ERROR_OCURRED";
    }
}


Value *Value::castTo(ValueType target) const {
    if(type == target)
        return new Value(*this);

    std::vector<int> result;

    switch (target) {
        case ValueType::INT:
            if(type == ValueType::BOOL) {
                result = data;
                return new Value(ValueType::INT, result);
            }
            if (type == ValueType::CELL) {
                for (int x : data)
                    result.push_back(x != CELL_UNDEF ? 1 : 0);
                return new Value(ValueType::INT, result);
            }
            break;
        case ValueType::BOOL:
            if(type == ValueType::INT) {
                for (int x: data)
                    result.push_back(x != 0 ? 1 : 0);
                return new Value(ValueType::BOOL, result);
            }
            if(type == ValueType::CELL) {
                for (int x: data)
                    result.push_back(x != CELL_UNDEF ? 1 : 0);
                return new Value(ValueType::BOOL, result);
            }
            break;
        case ValueType::CELL:
            if (type == ValueType::INT || type == ValueType::BOOL) {
                bool all_zero = std::all_of(data.begin(), data.end(), [](int x) { return x == 0; });
                if (!all_zero)
                    throw std::runtime_error("Only 0/false can be cast to CELL");

                result.resize(data.size(), CELL_UNDEF);
                return new Value(ValueType::CELL, result);
            }
            break;
    }
    throw std::runtime_error("Invalid cast from " + cast(static_cast<int>(type)) + " to " +
            cast(static_cast<int>(target)));
}


void print_value(Value* v) {
    std::cout << prType(v->type) << " -- ";
    switch (v->type) {
        case ValueType::INT:
            for (int i : v->data)
                std::cout << i << ' ';
            break;
        case ValueType::BOOL:
            for (int i: v->data) {
                auto s = i == 0 ? "false" : "true";
                std::cout << s << " ";
            }
            break;
        case ValueType::CELL:
            for (int i: v->data) {
                auto s = cast(i);
                std::cout << s << " ";
            }
            break;
    }
    std::cout << std::endl;
}
