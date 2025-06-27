//
// Created by ionik on 17.06.2025.
//

#include "Environment.h"
#include "unordered_map"

Environment::Environment(Environment *parent): parent(parent) {}


ValueType Environment::getType(const std::string &name) {
    auto it = table.find(name);
    if(it != table.end()) {
        Value* v = it->second;
        return v->type;
    }
    if(parent)
        return parent->getType(name);
    throw std::runtime_error("Variable not found '" + name + "'");
}


bool Environment::has(const std::string &name) const {
    return table.count(name) or (parent and parent->has(name));
}

bool Environment::hasHere(const std::string &name) const {
    return table.count(name);
}


Value *Environment::get(const std::string &name, int index) const {
    auto it = table.find(name);
    if(it != table.end()) {
        Value* v = it->second;
        if(index >= v->size())
            throw std::runtime_error("Index of '" + it->first + "' is out of bounds");
        return new Value(v->type, v->data[index]);
    }
    if(parent)
        return parent->get(name, index);
    throw std::runtime_error("Variable not found '" + name + "'");
}


Value* Environment::get_full(const std::string& name) const {
    auto it = table.find(name);
    if(it != table.end()) {
        Value* v = it->second;
        return new Value(v->type, v->data);
    }
    if(parent)
        return parent->get_full(name);
    throw std::runtime_error("Full variable not found '" + name + "'");
}


void Environment::set(const std::string& name, int index, Value* val) {
    if(table.count(name)) { // 1. Если переменная есть здесь
        Value* var = table[name];
        if(var->type != val->type)
            throw std::runtime_error("Type mismatch on assignment to " + name);

        if(index >= var->data.size())
            var->data.resize(index + 1, 0);

        var->data[index] = val->data[0];
        return;
    }

    if(parent && parent->has(name)) { // 2. Если есть в parent → рекурсивно туда
        parent->set(name, index, val);
        return;
    }

    Value* newVar = new Value(val->type); // 3. Иначе — создаём новую переменную в текущей области
    newVar->data.resize(index + 1, 0);
    newVar->data[index] = val->data[0];
    table[name] = newVar;
}


void Environment::assign(const std::string& name, Value* val) {
    auto it = table.find(name);
    if (it != table.end()) {
        if (it->second->type != val->type)
            throw std::runtime_error("Type mismatch in assignment to " + name);
        it->second->data = val->data;
        return;
    }

    if (parent && parent->has(name)) {
        parent->assign(name, val);
        return;
    }

    throw std::runtime_error("Assignment to undefined variable: " + name); // Переменная не найдена — ошибка
}


void Environment::define(const std::string& name, Value* val) {
    if (hasHere(name)) {
        throw std::runtime_error("Redefinition of variable: " + name);
    }

    table[name] = new Value(*val);
}
