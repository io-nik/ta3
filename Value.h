//
// Created by ionik on 17.06.2025.
//

#ifndef TA3_VALUE_H
#define TA3_VALUE_H

#include <vector>
#include <string>
#include <stdexcept>

enum class ValueType { INT, BOOL, CELL };

struct Value {
    ValueType type;
    std::vector<int> data;

    explicit Value(ValueType t = ValueType::INT) : type(t) {}

    explicit Value(ValueType t, std::vector<int> v) : type(t), data(v) {}

    Value(ValueType t, int single): type(t) {
        data.push_back(single); // оборачивает одно значение в массив
    }

    Value* castTo(ValueType target) const;

    int size() const { return data.size(); }

    int at(size_t i) const {
        if (i >= data.size())
            throw std::runtime_error("Index out of bounds");
        return data[i];
    }
};

std::string cast(int i);

void print_value(Value* v);

#endif //TA3_VALUE_H
