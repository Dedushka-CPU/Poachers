#ifndef POARCHER_H
#define POARCHER_H

#include <iostream>
#include <string>
#include <vector>
#include <utility> //юзаем для пар

class Poarcher {
private:
    std::string name;                          // имя плохого человека
    std::vector<std::pair<int, int>> steps;    // куда он успел уйти
    bool isFound=false;
public:
    
    Poarcher(const std::string& name, const std::vector<std::pair<int, int>>& steps)
        : name(name), steps(steps) {}

    
    std::string getName() const { return name; }//тут геттер имени
    const std::vector<std::pair<int, int>>& getSteps() const { return steps; }//тут геттер шагов

    
    void addStep(int x, int y) { steps.emplace_back(x, y); }//добавляем шаги

    
    void printInfo() const {
        std::cout << "Poarcher Name: " << name << "\nSteps:\n";
        for (const auto& step : steps) {
            std::cout << "(" << step.first << ", " << step.second << ")\n";
        }
    }
};

#endif // POARCHER_H
