#include <iostream>
#include <map>
#include "Robot.h"
#include "globals.h"
#include "parser.tab.hpp"
#include "interpreter.h" // eval_function
#include <cstdio>

extern FILE* yyin;
extern int yyparse();           // парсер из Bison

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Usage: ./robot_prog <map.txt> <prog.txt>" << std::endl;
        return 1;
    }

    try {
        int startX, startY;
        bool hasBox;
        Field* field = read_field(argv[1], startX, startY, hasBox);

        robot = new Robot(field, startX, startY, hasBox);
        env = new Environment(); // корневая область видимости

        std::cout << "Field loaded. Starting at (" << startX << ", " << startY << ") with box: " << (hasBox ? "yes" : "no") << "\n";

        yyin = fopen(argv[2], "r");
        if (!yyin) {
            std::cerr << "Cannot open program file: " << argv[2] << std::endl;
            return 1;
        }

        yyparse();  // запускаем синтаксический разбор

        // ищем main
        auto it = functionTable.find("main");
        if (it == functionTable.end()) {
            std::cerr << "Error: main() function not found!" << std::endl;
            return 2;
        }

        std::ofstream out("../tests/RobotLog.txt"); // rewriting file
        out.close();

        std::cout << "Running main()...\n";
        eval_function(it->second, env);

    } catch (const std::exception& ex) {
        std::cerr << "Runtime error: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}

/*
*/