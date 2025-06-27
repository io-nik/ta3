//
// Created by ionik on 17.06.2025.
//

#ifndef TA3_FUNCTIONDEF_H
#define TA3_FUNCTIONDEF_H

#include <iostream>
#include <vector>

#include "Statement.h"


struct FunctionDef {
    std::string name;
    std::vector<Statement*>* body;
};

//extern std::unordered_map<std::string, FunctionDef*> function_table;


#endif //TA3_FUNCTIONDEF_H
