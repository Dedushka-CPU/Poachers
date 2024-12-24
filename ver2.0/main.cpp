#include "header.h"

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int size;
    std::cout << "Введите размер сетки: ";
    std::cin >> size;
    bool visualizete;
    while (size <= 0)
    {
        std::cout << "Размер сетки должен быть больше 0!\n";
        std::cout << "Введите размер сетки: ";
        std::cin >> size;
    }
    std::cout<<"Включить визуализацию?[y/n]\n";
    std::string command;
    std::getline(std::cin,command);
    if(command=="y" || command=="Y"){
        visualizete=true;
    }else{
        visualizete=false;
    }
    while (true)
    {
        std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));

        int numPoachers;
        std::cout << "Введите количество браконьеров (или 0 для выхода): ";
        std::cin >> numPoachers;

        if (numPoachers == 0) {
            break;
        }

        std::vector<Poacher> poachers = inputPoachers(numPoachers, size);
        Position rangerStart;

        std::cout << "Введите начальную позицию для Деда (x y): ";
        std::cin >> rangerStart.x >> rangerStart.y;

        findPoachers(grid, rangerStart, poachers,visualizete);
    }

    return 0;
}
