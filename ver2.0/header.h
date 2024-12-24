#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <climits>
#include <utility>
#include <limits>
#include <windows.h>

struct Position {
    int x, y;
    bool operator==(const Position &other) const;
    bool operator<(const Position &other) const;
};

struct Poacher {
    std::string name;
    std::vector<Position> route;
};

struct Node {
    Position pos;
    int distance;
    bool operator>(const Node &other) const;
};

int dijkstra(const std::vector<std::vector<int>> &grid, const Position &start, const Position &end);
void visualizeGrid(const std::vector<std::vector<int>> &grid, const Position &current, const std::set<Position> &poachersPos);
void findPoachers(std::vector<std::vector<int>> &grid, Position &rangerStart, std::vector<Poacher> &poachers,bool visualizete);
int getValidIntegerInput();
std::vector<Poacher> inputPoachers(int numPoachers, int size);

#endif // HEADER_H
