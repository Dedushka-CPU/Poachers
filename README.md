# Браконьеры и лесники
## Финальный проект в 3-ем семестре
### О чём сама программа:
Лесники идут по следам браконьеров с целью предотвратить нарушение покоя в лесу

### Функции и их действия:
1. _**Алгоритм Дейсктры**_ для нахождения _минимального пути_ до браконьеров 
`int dijkstra(const vector<vector<vector<Poacher>>>& grid, Position start, Position end);`
2. Функция _**по поиску**_ Браконьеров
`void findPoachers(const vector<vector<vector<Poacher>>>& grid, int startX, int startY);`
3. Функция _**генерирующая случайный путь**_ браконьеров
`void generateRandomPaths(vector<vector<vector<Poacher>>>& grid, int numPoachers, int maxSteps);`
