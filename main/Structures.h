#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <limits>
#include <unordered_map>

using std::cout;
using std::priority_queue;
using std::set;
using std::string;
using std::vector;

class Position
{
public:
    int x, y;
    Position(int x, int y) : x(x), y(y) {}
};

class Poacher
{
public:
    string name;
    Poacher(string name) : name(name) {}
    string getName() const { return name; }
};

struct Node
{
    int x, y, distance;
    bool operator>(const Node &other) const { return distance > other.distance; }
};

#endif // STRUCTURES_H
