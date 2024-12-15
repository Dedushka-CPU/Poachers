#include "functions.h"
#include <iostream>
#include <vector>
#include <random>
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

int dijkstra(const vector<vector<vector<Poacher>>> &MainWindow, Position start, Position end)
{
    int rows = MainWindow.size();
    int cols = MainWindow[0].size();

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    vector<vector<int>> dist(rows, vector<int>(cols, std::numeric_limits<int>::max()));
    dist[start.x][start.y] = 0;

    priority_queue<Node, vector<Node>, std::greater<Node>> pq;
    pq.push(Node{start.x, start.y, 0});

    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();

        if (current.x == end.x && current.y == end.y)
        {
            return dist[end.x][end.y];
        }

        for (int i = 0; i < 4; ++i)
        {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols)
            {
                int newDist = current.distance + 1;
                if (newDist < dist[newX][newY])
                {
                    dist[newX][newY] = newDist;
                    pq.push(Node{newX, newY, newDist});
                }
            }
        }
    }

    return std::numeric_limits<int>::max();
}

void findPoachers(const vector<vector<vector<Poacher>>> &MainWindow, int startX, int startY)
{
    int rows = MainWindow.size();
    int cols = MainWindow[0].size();

    vector<Position> poacherPositions;
    vector<string> poacherNames;

    for (int x = 0; x < rows; ++x)
    {
        for (int y = 0; y < cols; ++y)
        {
            for (const auto &poacher : MainWindow[x][y])
            {
                poacherPositions.push_back(Position(x, y));
                poacherNames.push_back(poacher.getName());
            }
        }
    }

    Position start(startX, startY);
    set<string> visitedPoachers;
    vector<string> poacherOrder;
    int totalDistance = 0;
    Position currentPos = start;

    while (visitedPoachers.size() < poacherNames.size())
    {
        int minDistance = std::numeric_limits<int>::max();
        int poacherIndex = -1;

        for (size_t i = 0; i < poacherPositions.size(); ++i)
        {
            if (visitedPoachers.find(poacherNames[i]) == visitedPoachers.end())
            {
                int distance = dijkstra(MainWindow, currentPos, poacherPositions[i]);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    poacherIndex = i;
                }
            }
        }

        if (poacherIndex != -1)
        {
            totalDistance += minDistance;
            visitedPoachers.insert(poacherNames[poacherIndex]);
            poacherOrder.push_back(poacherNames[poacherIndex]);
            currentPos = poacherPositions[poacherIndex];
        }
        else
        {
            break;
        }
    }

    cout << "Old deda found poerchers:\n";
    for (const auto &name : poacherOrder)
    {
        cout << name << "\n";
    }

    cout << "Total distance: " << totalDistance << "\n";
}

void generateRandomPaths(vector<vector<vector<Poacher>>> &MainWindow, int numPoachers, int maxSteps)
{
    if (MainWindow.empty() || MainWindow[0].empty())
    {
        throw std::invalid_argument("MainWindow cannot be empty.");
    }
    if (numPoachers <= 0)
    {
        throw std::invalid_argument("Number of poachers must be greater than 0.");
    }
    if (maxSteps <= 0)
    {
        throw std::invalid_argument("Max steps must be greater than 0.");
    }

    int rows = MainWindow.size();
    int cols = MainWindow[0].size();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> orientation(0, 3);

    for (int i = 0; i < numPoachers; ++i)
    {
        string poacherName = "Poacher_" + std::to_string(i + 1);
        int x = rows - 1;
        int y = 0;
        MainWindow[x][y].emplace_back(poacherName);
        int LastOrientation = -1;

        int steps = maxSteps;
        while (steps > 0)
        {
            int orientat;

            do
            {
                orientat = orientation(gen);
            } while ((orientat == 0 && LastOrientation == 2) ||
                     (orientat == 1 && LastOrientation == 3) ||
                     (orientat == 2 && LastOrientation == 0) ||
                     (orientat == 3 && LastOrientation == 1));

            int newX = x;
            int newY = y;

            if (orientat == 0 && x > 0)
            {
                newX = x - 1;
            }
            else if (orientat == 1 && y < cols - 1)
            {
                newY = y + 1;
            }
            else if (orientat == 2 && x < rows - 1)
            {
                newX = x + 1;
            }
            else if (orientat == 3 && y > 0)
            {
                newY = y - 1;
            }
            else
            {
                continue;
            }

            x = newX;
            y = newY;
            MainWindow[x][y].emplace_back(poacherName);

            LastOrientation = orientat;
            --steps;
        }
    }
}
