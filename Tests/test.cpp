#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "header.h"


TEST_CASE("Testing dijkstra function") {
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}
    };

    Position start = {0, 0};
    Position end = {3, 3};

    CHECK(dijkstra(grid, start, end) == 4);

    Position unreachable = {3, 1};
    CHECK(dijkstra(grid, start, unreachable) == 3);
}

TEST_CASE("Testing findPoachers function") {
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    Position rangerStart = {0, 0};
    std::vector<Poacher> poachers = {
        {"Poacher1", {{3, 3}}},
        {"Poacher2", {{2, 2}}}
    };

    SUBCASE("All poachers are reachable") {
        std::stringstream buffer;
        std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf());

        findPoachers(grid, rangerStart, poachers);

        std::cout.rdbuf(oldCout);

        std::string output = buffer.str();
        CHECK(output.find("Нашли браконьера: Poacher2 на позиции (2, 2).") != std::string::npos);
        CHECK(output.find("Нашли браконьера: Poacher1 на позиции (3, 3).") != std::string::npos);
        CHECK(output.find("Общее расстояние, пройденное дедoм: 3") != std::string::npos);
    }
}

