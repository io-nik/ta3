cmake_minimum_required(VERSION 3.25)
project(ta3)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

#add_executable(ta3
#        main.cpp
#        Value.cpp
#        eval.cpp
#        Environment.cpp
#        parser.tab.cpp
#)

add_executable(
        ta3
        main.cpp
        Value.cpp
        Value.h
        eval.cpp
        eval.h
        Statement.h
        Environment.cpp
        Environment.h
        FunctionDef.h
        ExprStmt.h
        AssignStmt.h
        IfStmt.h
        LoopStmt.h
        #FunctionCallStmt.h
        interpreter.h
        Robot.h
        #RobotCommandStmt.h
        globals.h
        PrintStmt.h
        parser.tab.cpp
        parser.tab.hpp
        lexer.cpp
        CellTypes.h
        AssignArrayStmt.h
        AssignDefStmt.h
        Robot.cpp
        interpreter.cpp
        Expression.h
)

target_include_directories(ta3 PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
)
