# Браконьеры

**Браконьеры** — это консольная программа, моделирующая поиск браконьеров на сетке с использованием алгоритма Дейкстры для нахождения кратчайшего пути. Главный герой программы, лесник по имени "Дед", должен найти всех браконьеров, которые перемещаются по сетке согласно заданным маршрутам.

---

## 📂 Структура проекта

Проект организован следующим образом:

- **`ver2.0/`** — Основная папка проекта, содержащая все ключевые файлы:
  - **`header.h`** — Заголовочный файл с объявлениями структур и функций.
  - **`functions.cpp`** — Реализация алгоритмов и вспомогательных функций.
  - **`main.cpp`** — Точка входа в программу.
- **`tests/`** — Тесты, написанные с использованием библиотеки `doctest`.
- **`CMakeLists.txt`** — Файл для сборки проекта с использованием CMake.

---

## ⚙️ Зависимости

Для работы программы необходимо:

- **Компилятор C++** с поддержкой стандарта C++11 или выше (например, GCC, Clang, MSVC).
- **CMake** версии 3.10 или выше (для удобной сборки).
- **CLion** *(опционально, для IDE-компиляции и отладки)*.

---

## 🚀 Сборка и запуск

Вы можете собрать проект несколькими способами: 

### 1. Сборка в CLion

1. Откройте проект в CLion.
2. Нажмите кнопку **Run** для автоматической сборки и запуска программы.

### 2. Сборка вручную через терминал

#### Статическая сборка:

1. Убедитесь, что в `CMakeLists.txt` указаны настройки статической линковки.
2. Выполните команды:

```bash
cmake -S . -B build
```

3.
```bash
cd build
make
```

После этого будет создан исполняемый файл в текущей папке.


#### Динамическая сборка:

Аналогично статической, но с включением `BUILD_SHARED_LIBS=ON` в `CMakeLists.txt`.

---

## 🎮 Запуск программы

Для запуска программы вручную выполните следующие команды:

```bash
cd ver2.0
g++ main.cpp functions.cpp -o poachers
./poachers
```

Программа запросит ввод необходимых данных:

1. Размер сетки (например, 10).
2. Количество браконьеров, их имена и маршруты.
3. Начальную позицию лесника.

Пример ввода:

```
Введите размер сетки: 10
Введите количество браконьеров (или 0 для выхода): 2
Введите имя браконьера #1: Ivan
Введите количество точек маршрута для браконьера Ivan:
5
Введите координаты точки маршрута #1 (x y): 9 0
Введите координаты точки маршрута #2 (x y): 9 1
Введите координаты точки маршрута #3 (x y): 9 2
Введите координаты точки маршрута #4 (x y): 9 3
Введите координаты точки маршрута #5 (x y): 9 4
Введите имя браконьера #2: s1mple
Введите количество точек маршрута для браконьера s1mple:
5
Введите координаты точки маршрута #1 (x y): 9 0
Введите координаты точки маршрута #2 (x y): 8 0
Введите координаты точки маршрута #3 (x y): 7 0
Введите координаты точки маршрута #4 (x y): 7 1 
Введите координаты точки маршрута #5 (x y): 7 2
Введите начальную позицию для Деда (x y): 9 9
```

---

## 📊 Пример работы

Программа отобразит сетку леса с позицией лесника (D) и браконьеров (P). Вот пример вывода:

```
 .  .  .  .  .  .  .  .  .  . 
 .  .  .  .  .  .  .  .  .  . 
 .  .  .  .  .  .  .  .  .  . 
 .  .  .  .  .  .  .  .  .  . 
 .  .  .  .  .  .  .  .  .  . 
 .  .  .  .  .  .  .  .  .  . 
 .  .  .  .  .  .  .  .  .  . 
 P  P  P  .  .  .  .  .  .  . 
 P  .  .  .  .  .  .  .  .  . 
 P  P  P  P  D  .  .  .  .  . 

Нашли браконьера: Ivan на позиции (9, 4).
 .  .  .  .  .  .  .  .  .  . 
 .  .  .  .  .  .  .  .  .  . 
 .  .  .  .  .  .  .  .  .  . 
 .  .  .  .  .  .  .  .  .  . 
 .  .  .  .  .  .  .  .  .  . 
 .  .  .  .  .  .  .  .  .  . 
 .  .  .  .  .  .  .  .  .  . 
 P  P  D  .  .  .  .  .  .  . 
 P  .  .  .  .  .  .  .  .  . 
 P  P  P  P  .  .  .  .  .  . 

Нашли браконьера: s1mple на позиции (7, 2).
Общее расстояние, пройденное дедoм: 7
Браконьеры найдены в следующем порядке:
- Ivan
- s1mple
```

---

## 💡 Особенности реализации

- [**Алгоритм Дейкстры**](https://skillbox.ru/media/code/algoritm-deykstry-chto-eto-takoe-kak-rabotaet-i-gde-ispolzuetsya/) используется для нахождения кратчайшего пути.
- **Динамическая визуализация** сетки для наглядного отображения действий лесника.
- **Проверка ввода** предотвращает ошибки, например, ввод букв вместо чисел.

---

## 🛠 Основные компоненты

### Структуры данных:
- **`Position`**: Координаты на сетке.
- **`Poacher`**: Браконьер с именем и маршрутом.
- **`Node`**: Узел в графе для алгоритма Дейкстры.

### Ключевые функции:
- **`dijkstra()`** — Находит кратчайший путь.
- **`visualizeGrid()`** — Визуализирует состояние сетки.
- **`findPoachers()`** — Организует поиск браконьеров.
- **`getValidIntegerInput()`** — Обеспечивает корректный ввод данных.

---

## 🔬 Тестирование

Тесты для проверки корректности алгоритмов находятся в папке `tests`. Запустите их следующим образом:

```bash
cd tests
g++ -o tests test.cpp -lstdc++ -ldoctest
./tests
```

---
