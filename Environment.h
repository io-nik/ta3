//
// Created by ionik on 17.06.2025.
//

#ifndef TA3_ENVIRONMENT_H
#define TA3_ENVIRONMENT_H

#include <unordered_map>
#include <string>
#include "Value.h"

class Environment {
public:
    Environment* parent = nullptr;

    Environment(Environment* parent = nullptr);

    ValueType getType(const std::string &name);

    bool has(const std::string& name) const; // Ищет переменную рекурсивно по областям видимости

    bool hasHere(const std::string &name) const;  // Ищет переменную в области видимости

    Value* get(const std::string& name, int index = 0) const; // Возвращает копию значения переменной по индексу

    Value* get_full(const std::string& name) const; // Возвращает копию значения всей переменной

    void set(const std::string& name, int index, Value* val); // Меняет существующую переменную либо создаёт новую в текущей области

    void assign(const std::string& name, Value* val); // Меняет значение только если переменная уже определена

    void define(const std::string& name, Value* val); // Жёстко задаёт переменную однократно, используется при первом присваивании

private:
    std::unordered_map<std::string, Value*> table;
};

#endif //TA3_ENVIRONMENT_H
