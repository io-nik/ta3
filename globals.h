//
// Created by ionik on 20.06.2025.
//

#ifndef TA3_GLOBALS_H
#define TA3_GLOBALS_H

#include <map>
#include "Environment.h"
#include "Robot.h"
#include "FunctionDef.h"

// Глобальные переменные интерпретатора
inline Environment* env = nullptr;
inline Robot* robot = nullptr;
inline Environment* current_env = nullptr;

// Таблица определённых функций (глобальная)
inline std::map<std::string, FunctionDef*> functionTable;

#endif // TA3_GLOBALS_H

