

# Браконьеры

**Браконьеры** — это консольная программа, которая моделирует поиск браконьеров на сетке с использованием алгоритма Дейкстры для нахождения кратчайшего пути. В этой игре "Дед" (персонаж-игрок) должен найти всех браконьеров, которые движутся по сетке, следуя своим маршрутам.

## Содержание

- [Описание](#описание)
- [Структура проекта](#структура-проекта)
- [Зависимости](#зависимости)
- [Сборка и запуск](#сборка-и-запуск)
  - [Сборка в CLion](#сборка-в-clion)
  - [Статическая сборка](#статическая-сборка)
  - [Динамическая сборка](#динамическая-сборка)
  - [Запуск программы](#запуск-программы)
- [Пример работы программы](#пример-работы-программы)
- [Описание кода](#описание-кода)

## Описание

Пустует пока что

## Структура проекта

Проект состоит из нескольких исходных файлов:

- **header.h** — Заголовочный файл, содержащий все объявления структур данных и функций.
- **functions.cpp** — Реализация функций для поиска кратчайшего пути, обработки входных данных и вывода информации.
- **main.cpp** — Основной файл, запускающий программу и обрабатывающий пользовательский ввод.
- **CMakeLists.txt** — Конфигурационный файл для сборки проекта с помощью CMake.

## Зависимости

Для сборки и запуска проекта требуется:

- Компилятор C++11 или выше (например, **GCC**, **Clang**, **MSVC**).
- Установленный **CMake** версии 3.10 и выше.
- **CLion** (рекомендуется для удобства работы).

## Сборка и запуск

### Сборка в CLion



### Статическая сборка

Если вы хотите собрать проект с использованием **статической линковки** (все библиотеки включаются в исполнимый файл), выполните следующие шаги:

1. Откройте **CMakeLists.txt** и убедитесь, что он содержит настройки для статической сборки:

```cmake
cmake_minimum_required(VERSION 3.10)

project(PoachersFind)

set(CMAKE_CXX_STANDARD 17)

# Статическая сборка
set(CMAKE_STATIC_LIBRARY_FLAGS "-static")

add_executable(PoachersFind main.cpp functions.cpp)

target_include_directories(PoachersFind PRIVATE ${CMAKE_SOURCE_DIR})
```

2. В терминале проекта выполните команду для сборки:

```bash
cmake -DCMAKE_BUILD_TYPE=Release .
make
```

3. После завершения сборки вы получите исполнимый файл в каталоге `./build/Release/`.

### Динамическая сборка

Для динамической сборки, удалите строки, отвечающие за статическую линковку, и используйте стандартный конфиг:

```cmake
cmake_minimum_required(VERSION 3.10)

project(PoachersFind)

set(CMAKE_CXX_STANDARD 17)

add_executable(PoachersFind main.cpp functions.cpp)

target_include_directories(PoachersFind PRIVATE ${CMAKE_SOURCE_DIR})
```

Для сборки с динамическими библиотеками выполните следующие команды:

```bash
cmake -DCMAKE_BUILD_TYPE=Release .
make
```

### Запуск программы

После сборки программы, вы можете запустить её следующим образом:

1. Перейдите в каталог с собранным исполнимым файлом.
2. Запустите программу с помощью команды:

```bash
./PoacherFinder
```

### Пример работы программы

После запуска программа запросит:

1. **Размер сетки**: Размер леса(?).
2. **Количество браконьеров**: Введите количество браконьеров и их данные (имена и маршруты).
3. **Начальная позиция "Деда"**: Укажите стартовую позицию для лесника.

Программа будет искать всех браконьеров, используя алгоритм Дейкстры, и отображать их позицию на сетке в процессе поиска.

### Пример интерфейса:

```
Введите размер сетки: 10
Введите количество браконьеров (или 0 для выхода): 2
Введите имя браконьера #1: Ivan
Введите количество точек маршрута для браконьера Ivan:
5
Введите координаты точки маршрута #1 (x y): 9 0 9 1 9 2 9 3 9 4
Введите координаты точки маршрута #2 (x y): Введите координаты точки маршрута #3 (x y): Введите координаты точки маршрута #4 (x y): Введите координаты точки маршрута #5 (x y): Введите имя браконьера #2: s1mple
Введите количество точек маршрута для браконьера s1mple:
5
Введите координаты точки маршрута #1 (x y): 9 0 8 0 7 0 7 1 7 2
Введите координаты точки маршрута #2 (x y): Введите координаты точки маршрута #3 (x y): Введите координаты точки маршрута #4 (x y): Введите координаты точки маршрута #5 (x y): Введите начальную позицию для Деда (x y): 9 9
```

Программа выведет информацию о ходе поиска и текущих позициях "Деда" и браконьеров:

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
### Описание кода:
Основные моменты:
1. **Алгоритм Дейкстры** для нахождения кратчайшего пути рейнджера к точке маршрута каждого браконьера.
2. **Визуализация сетки**, где отображаются позицию лесника, браконьеров и пустые клетки.
3. **Поиск браконьеров**, где лесник проходит по маршруту каждого браконьера, находит их и отображает путь на сетке.

### Основные компоненты

1. **Структуры данных**:
   - **`Position`** — представляет координаты на сетке.
   - **`Poacher`** — браконьер с именем и маршрутом (набор позиций).
   - **`Node`** — представляет позицию на сетке с расстоянием для использования в алгоритме Дейкстры.

2. **Алгоритм Дейкстры**:
   - Функция `dijkstra()` находит кратчайший путь от стартовой позиции до целевой, используя приоритетную очередь.

3. **Визуализация сетки**:
   - Функция `visualizeGrid()` выводит сетку с отображением текущей позиции рейнджера и позиций браконьеров.

4. **Поиск браконьеров**:
   - Функция `findPoachers()` последовательно находит браконьеров, используя алгоритм Дейкстры для каждого маршрута.

5. **Ввод данных**:
   - Функция `inputPoachers()` запрашивает у пользователя данные о браконьерах и их маршрутах.

6. **Ввод целых чисел**:
   - Функция `getValidIntegerInput()` обеспечивает безопасный ввод целых чисел.Необходим для припядствия ввода букв,вместо цифр.

---

### Основные функции

- **`dijkstra()`** — Находит кратчайший путь с использованием алгоритма Дейкстры.
- **`visualizeGrid()`** — Отображает текущее состояние сетки.
- **`findPoachers()`** — Поиск всех браконьеров по очереди и визуализация пути.
- **`getValidIntegerInput()`** — Обеспечивает корректный ввод целых чисел.
- **`inputPoachers()`** — Ввод данных о браконьерах и их маршрутах.

```
