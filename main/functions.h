#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structures.h"

// Алгоритм Дейкстры для нахождения минимального пути
int dijkstra(const vector<vector<vector<Poacher>>>& grid, Position start, Position end);

void findPoachers(const vector<vector<vector<Poacher>>>& grid, int startX, int startY);

void generateRandomPaths(vector<vector<vector<Poacher>>>& grid, int numPoachers, int maxSteps);

#endif // FUNCTIONS_H
