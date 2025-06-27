//
// Created by ionik on 17.06.2025.
//

#ifndef TA3_ROBOT_H
#define TA3_ROBOT_H

#include <vector>
#include <fstream>
#include <iostream>
#include "CellTypes.h"
#include "Value.h"


struct Field {
    std::vector<std::vector<CellType>> grid;

    Field(int width, int height) {
        grid.resize(height, std::vector<CellType>(width, CellType::CELL_EMPTY));
    }

    explicit Field(std::vector<std::vector<CellType>> gr): grid(gr) {}


    CellType get(int x, int y) {
        if(y < 0 or y >= grid.size() or x < 0 or x >= grid[0].size())
            return CellType::CELL_UNDEF;
        else
            return grid[y][x];
    }

    void set(int x, int y, CellType cell) {
        if(y < 0 or y >= grid.size() or x < 0 or x >= grid[0].size())
            throw std::runtime_error("Trying to write outside the field");
        grid[y][x] = cell;
    }

    char cast(CellType x) {
        switch (x) {
            case CELL_UNDEF: return '?';
            case CELL_EMPTY: return '.';
            case CELL_WALL: return '#';
            case CELL_BOX: return 'B';
            case CELL_EXIT: return 'E';
            default: return '~';
        }
    }

    void print(int x, int y, bool is) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if(i == y and j == x)
                    if(is) std::cout << 'R';
                    else std::cout << 'r';
                else
                    std::cout << cast(grid[i][j]);
            }
            std::cout << std::endl;
        }
    }

    int width() const { return grid[0].size(); }
    int height() const { return grid.size(); }
};


Field* read_field(const std::string& filename, int& startX, int& startY, bool& hasBox);


struct Robot {
    int x = 0;
    int y = 0;
    int visibility_radius = 5;
    bool hasBox = false;
    Field* field = nullptr;

    Robot(Field* f, int startX = 0, int startY = 0) : field(f), x(startX), y(startY) {}


    Robot(Field* field, int startX, int startY, bool hasBox): x(startX), y(startY), hasBox(hasBox), field(field) {}


    void set_visibility(int radius) { visibility_radius = std::max(1, radius); }


    int get_visibility() const { return visibility_radius; }


    CellType getCellTypeAround(Direction dir) const {
        switch (dir) {
            case Direction::DIR_DOWN:
                return field->get(x, y + 1);
            case Direction::DIR_LEFT:
                return field->get(x - 1, y);
            case Direction::DIR_UP:
                return field->get(x, y - 1);
            case Direction::DIR_RIGHT:
                return field->get(x + 1, y);
            default:
                throw std::runtime_error("There is no such direction");
        }
    }


    std::pair<int, int> delta(Direction dir) {
        switch (dir) {
            case Direction::DIR_UP: return {0, -1};
            case Direction::DIR_DOWN: return {0, 1};
            case Direction::DIR_LEFT: return {-1, 0};
            case Direction::DIR_RIGHT: return {1, 0};
            default:
                throw std::runtime_error("Invalid direction");
        }
    }


    Value* go(Direction dir) {
        auto result = new Value(ValueType::BOOL);
        auto [dx, dy] = delta(dir);

        CellType target = getCellTypeAround(dir);
        if (target == CellType::CELL_EMPTY or target == CellType::CELL_EXIT) {
            x += dx;
            y += dy;
            result->data.push_back(1);
            return result;
        }
        result->data.push_back(0);
        return result;
    }


    Value* pick(Direction dir) {
        auto result = new Value(ValueType::BOOL);

        if(hasBox) {
            result->data.push_back(0);
            return result;
        }

        if(getCellTypeAround(dir) == CellType::CELL_BOX) {
            auto [dx, dy] = delta(dir);
            field->set(x + dx, y + dy, CellType::CELL_EMPTY);
            hasBox = true;

            result->data.push_back(1); // истина
            return result;
        }
        else {
            result->data.push_back(0);
        }

        return result;
    }


    Value* drop(Direction dir) { // Если там пусто и у него есть коробка
        auto result = new Value(ValueType::BOOL);
        if(hasBox and getCellTypeAround(dir) == CellType::CELL_EMPTY) {
            auto [dx, dy] = delta(dir);
            field->set(x + dx, y + dy, CellType::CELL_BOX);
            hasBox = false;
            result->data.push_back(1);
            return result;
        }

        result->data.push_back(0);
        return result;
    }


    Value* look(Direction dir) {
        auto result = new Value(ValueType::CELL);
        int sx = x, sy = y;
        int seen = 0;

        for (int i = 1; i <= visibility_radius; ++i) {
            auto [dx, dy] = delta(dir);
            sx += dx;
            sy += dy;

            CellType cell = field->get(sx, sy);
            result->data.push_back(static_cast<int>(cell));

            if (cell == CellType::CELL_WALL || cell == CellType::CELL_BOX || cell == CellType::CELL_EXIT) {
                ++seen; // Прекращаем осмотр, если встретили препятствие
                break;
            }
            ++seen;
        }

        while (seen < visibility_radius) { // Дополняем результат неопределёнными клетками, если что-то осталось
            result->data.push_back(static_cast<int>(CellType::CELL_UNDEF));
            ++seen;
        }

        return result;
    }


    void print_field() const {
        std::cout << "Robot at (x = " << x << ", y = " << y << "), with box: " << (hasBox ? "yes" : "no") << std::endl;
        field->print(x, y, hasBox);
    }
};


#endif //TA3_ROBOT_H
