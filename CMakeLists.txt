# указывайте последнюю доступную вам версию CMake
cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

# название проекта
project(ProgrammingLabsWork_2022_2023)

# затем следует список инструкций для подключения проектов из подкаталогов

include(cmake/function.cmake)    # подхватываем функции, реализованные в файле function.cmake
                                 # для простоты мы объединили наборы команд для создания статической библиотеки
								 # и для создания исполняемого проекта в отдельные функции

add_subdirectory(main)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем main

add_subdirectory(bit_fild)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем bit_fild
add_subdirectory(set)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем set

add_subdirectory(list)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем list
add_subdirectory(stack_on_list)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем stack_on_list
add_subdirectory(queue_on_list)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем queue_on_list

add_subdirectory(stack_on_mass)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем stack_on_mass
add_subdirectory(queue_on_mass)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем queue_on_mass

add_subdirectory(vector)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем vector
add_subdirectory(matrix)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем matrix

add_subdirectory(string_parser)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем string_parser
add_subdirectory(math_functions)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем math_functions

add_subdirectory(vector_with_iterators)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем vector_with_iterators

option(BTEST "build test?" ON)   # указываем подключаем ли google-тесты (ON или YES) или нет (OFF или NO)

if(BTEST)                        # если тесты подключены
    add_subdirectory(gtest)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем gtest
    add_subdirectory(tests)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем test
endif()
