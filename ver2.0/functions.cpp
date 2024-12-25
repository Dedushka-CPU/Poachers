#include "header.h"

bool Position::operator==(const Position &other) const
{
    return x == other.x && y == other.y;
}

bool Position::operator<(const Position &other) const
{
    return std::tie(x, y) < std::tie(other.x, other.y);
}

bool Node::operator>(const Node &other) const
{
    return distance > other.distance;
}

int dijkstra(const std::vector<std::vector<int>> &grid, const Position &start, const Position &end)
{
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> dist(rows, std::vector<int>(cols, INT_MAX));
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;

    dist[start.x][start.y] = 0;
    pq.push({start, 0});

    std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();

        if (current.pos == end)
            return current.distance;

        for (const auto &dir : directions)
        {
            int nx = current.pos.x + dir.first;
            int ny = current.pos.y + dir.second;

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 0)
            {
                int newDist = current.distance + 1;
                if (newDist < dist[nx][ny])
                {
                    dist[nx][ny] = newDist;
                    pq.push({{nx, ny}, newDist});
                }
            }
        }
    }
    return INT_MAX;
}

void visualizeGrid(const std::vector<std::vector<int>> &grid, const Position &current, const std::set<Position> &poachersPos)
{
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            if (current.x == i && current.y == j)
            {
                std::cout << " D "; // Deda
            }
            else if (poachersPos.count({i, j}))
            {
                std::cout << " P "; // Браконьер
            }
            else
            {
                std::cout << " . ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void findPoachers(std::vector<std::vector<int>> &grid, Position &rangerStart, std::vector<Poacher> &poachers)
{
    Position current = rangerStart;
    int totalDistance = 0;
    std::set<std::string> visited;
    std::set<Position> poachersPos;
    std::vector<std::string> foundPoachers;

    for (const auto &poacher : poachers)
    {
        for (const auto &pos : poacher.route)
        {
            poachersPos.insert(pos);
        }
    }

    while (visited.size() < poachers.size())
    {
        int minDistance = INT_MAX;
        int closestPoacherIdx = -1;
        Position closestPoacherPos;

        for (int i = 0; i < poachers.size(); ++i)
        {
            if (visited.count(poachers[i].name))
            {
                continue;
            }
            for (const auto &pos : poachers[i].route)
            {
                int distance = dijkstra(grid, current, pos);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    closestPoacherIdx = i;
                    closestPoacherPos = pos;
                }
            }
        }

        if (closestPoacherIdx == -1)
        {
            std::cout << "Not found!\n";
            break;
        }

        totalDistance += minDistance;
        visited.insert(poachers[closestPoacherIdx].name);
        foundPoachers.push_back(poachers[closestPoacherIdx].name);
        current = closestPoacherPos;
        poachersPos.erase(current);
        visualizeGrid(grid, current, poachersPos);

        std::cout << "Нашли браконьера: " << poachers[closestPoacherIdx].name << " на позиции (" << current.x << ", " << current.y << ").\n";
    }

    std::cout << "Общее расстояние, пройденное дедoм: " << totalDistance << "\n";
    std::cout << "Браконьеры найдены в следующем порядке:\n";
    for (const auto &name : foundPoachers)
    {
        std::cout << "- " << name << "\n";
    }
}

int getValidIntegerInput()
{
    int value;
    while (true)
    {
        std::cin >> value;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Пожалуйста, введите целое число.\n";
        }
        else
        {
            return value;
        }
    }
}

std::vector<Poacher> inputPoachers(int numPoachers, int size)
{
    std::vector<Poacher> poachers;

    for (int i = 0; i < numPoachers; ++i)
    {
        Poacher poacher;
        std::cout << "Введите имя браконьера #" << (i + 1) << ": ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, poacher.name);

        int routeLength;
        while (true)
        {
            std::cout << "Введите количество точек маршрута для браконьера " << poacher.name << ":\n";
            routeLength = getValidIntegerInput();
            if (routeLength > 0)
            {
                break;
            }
            std::cout << "Количество точек маршрута должно быть больше 0!\n";
        }

        for (int j = 0; j < routeLength; ++j)
        {
            Position pos;
            while (true)
            {
                std::cout << "Введите координаты точки маршрута #" << (j + 1) << " (x y): ";
                std::cin >> pos.x >> pos.y;
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Пожалуйста, введите целые числа для координат.\n";
                }
                else if (pos.x >= size || pos.y >= size || pos.x < 0 || pos.y < 0)
                {
                    std::cout << "Введите правильные координаты в диапазоне 0-" << size - 1 << "\n";
                }
                else
                {
                    poacher.route.push_back(pos);
                    break;
                }
            }
        }
        poachers.push_back(poacher);
    }

    return poachers;
}
