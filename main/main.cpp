#include "Structures.h"
#include "functions.h"

int main()
{
    const int gridSize = 10;
    vector<vector<vector<Poacher>>> grid(gridSize, vector<vector<Poacher>>(gridSize));

    try
    {
        generateRandomPaths(grid, 3, 20);
        for (int x = 0; x < gridSize; ++x)
        {
            for (int y = 0; y < gridSize; ++y)
            {
                if (!grid[x][y].empty())
                {
                    std::cout << "Cell (" << x << ", " << y << "): ";
                    for (const auto &poacher : grid[x][y])
                    {
                        std::cout << poacher.name << " ";
                    }
                    std::cout << "\n";
                }
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
    findPoachers(grid, 9, 9);

    return 0;
}
