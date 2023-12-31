﻿# указывайте последнюю доступную вам версию CMake
cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

# название проекта
project(ProgrammingLabsWork_2022_2023)

# затем следует список инструкций для подключения проектов из подкаталогов

include(cmake/function.cmake)    # подхватываем функции, реализованные в файле function.cmake
                                 # для простоты мы объединили наборы команд для создания статической библиотеки
								 # и для создания исполняемого проекта в отдельные функции

add_subdirectory(main)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем main
add_subdirectory(bit_fild)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем bit_fild
add_subdirectory(list)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем set
add_subdirectory(vector)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем vector_and_matrix
add_subdirectory(stack)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем stack
add_subdirectory(matrix)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем string_parser
add_subdirectory(set)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем string_parser
add_subdirectory(string_parser)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем string_parser
add_subdirectory(dispoint_sets_union)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем dispoint_sets_union
add_subdirectory(maze)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем maze

add_subdirectory(ilands_count)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем ilands_count

option(BTEST "build test?" ON)   # указываем подключаем ли google-тесты (ON или YES) или нет (OFF или NO)

if(BTEST)                        # если тесты подключены
    add_subdirectory(gtest)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем gtest
    add_subdirectory(tests)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем test
endif()
