//
// Created by ionik on 21.06.2025.
//

#include "Robot.h"

Field* read_field(const std::string& filename, int& startX, int& startY, bool& hasBox) {
    std::ifstream in(filename);
    if(!in)
        throw std::runtime_error("Can't open file");

    int rows, cols;
    in >> rows >> cols;
    std::string line;
    std::getline(in, line);

    std::vector<std::vector<CellType>> grid(rows, std::vector<CellType>(cols));
    bool robot_found = false;

    for (int y = 0; y < rows; ++y) {
        std::getline(in, line);
        if(line.size() < cols)
            throw std::runtime_error("Line is too short in map");

        for (int x = 0; x < cols; ++x) {
            char c = line[x];
            switch (c) {
                case '.': grid[y][x] = CellType::CELL_EMPTY;
                    break;
                case '#': grid[y][x] = CellType::CELL_WALL;
                    break;
                case 'B': grid[y][x] = CellType::CELL_BOX;
                    break;
                case 'E': grid[y][x] = CellType::CELL_EXIT;
                    break;
                case 'r':
                case 'R':
                    if(robot_found)
                        throw std::runtime_error("Multiple robots found in map");
                    grid[y][x] = CellType::CELL_EMPTY;
                    startX = x;
                    startY = y;
                    hasBox = (c == 'R');
                    robot_found = true;
                    break;
                default:
                    grid[y][x] = CellType::CELL_UNDEF;
            }
        }
    }

    if(!robot_found)
        throw std::runtime_error("Robot position not specified in map");

    return new Field(grid);
}