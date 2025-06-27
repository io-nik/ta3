//
// Created by ionik on 19.06.2025.
//

#ifndef TA3_ROBOTCOMMANDSTMT_H
#define TA3_ROBOTCOMMANDSTMT_H

#include "Statement.h"
#include "Robot.h"
#include "CellTypes.h"
#include "Value.h"

enum class RobotCommandType {
    GO,
    PICK,
    DROP,
    LOOK
};

struct RobotCommandStmt : public Statement {
public:
    RobotCommandType command;
    Direction direction;
    Robot* robot;

    RobotCommandStmt(RobotCommandType cmd, Direction dir, Robot* r)
            : command(cmd), direction(dir), robot(r) {}

    Value* execute(Environment* env) override {
        Value* result = nullptr;

        switch (command) {
            case RobotCommandType::GO:
                result = robot->go(direction);
                break;
            case RobotCommandType::PICK:
                result = robot->pick(direction);
                break;
            case RobotCommandType::DROP:
                result = robot->drop(direction);
                break;
            case RobotCommandType::LOOK:
                result = robot->look(direction);
                break;
        }

        print_value(result);
        return result;
    }
};


#endif //TA3_ROBOTCOMMANDSTMT_H