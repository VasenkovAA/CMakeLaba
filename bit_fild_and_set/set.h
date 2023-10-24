// Copyright 2023 Vasenkov Andrey
#ifndef _SET_H_
#define _SET_H_

/*
RU:
Класс TSet имеет следующие методы и поля: Поля:

    maxPower - максимальная мощность множества
    bitField - битовое поле для хранения множества

Методы:

    TSet(int mp) - конструктор, который принимает максимальную мощность множества в качестве аргумента
    TSet(const TSet& s) - конструктор копирования
    operator TBitField() - преобразование типа к битовому полю
    size_t GetMaxPower() const noexcept - метод, который возвращает максимальную мощность множества
    void InsElem(size_t Elem) - метод, который включает элемент в множество
    void DelElem(size_t Elem) - метод, который удаляет элемент из множества
    bool IsMember(size_t Elem) const - метод, который проверяет наличие элемента в множестве
    void insert(size_t Elem) - метод, который включает элемент в множество
    TSet operator+ (const int Elem) - метод, который выполняет объединение множества с элементом
    TSet operator- (const int Elem) - метод, который выполняет разность множества с элементом
    TSet operator+ (const TSet& s) - метод, который выполняет объединение множеств
    TSet operator* (const TSet& s) - метод, который выполняет пересечение множеств
    TSet operator~ () - метод, который выполняет дополнение множества
    bool operator== (const TSet& s) const - метод, который проверяет равенство множеств
    bool operator!= (const TSet& s) const - метод, который проверяет неравенство множеств
    TSet& operator=(const TSet& s) - оператор присваивания
    friend std::istream& operator>>(std::istream& in, TSet& bf) - дружественная функция, которая перегружает оператор ввода
    friend std::ostream& operator<<(std::ostream& out, const TSet& bf) - дружественная функция, которая перегружает оператор вывода

    TSet(int mp) - конструктор, который принимает максимальную мощность множества в качестве аргумента
    TSet(const TSet& s) - конструктор копирования

Также в классе TSet определены операторы присваивания и перегружены операторы ввода и вывода.
Использование конструкторов в классе TSet позволяет инициализировать данные объектов класса при их создании.
Это удобно и позволяет избежать ошибок при работе с объектами класса.
*/

/*
ENG:
The TSet class has the following methods and fields: Fields:

    maxPower - maximum power of the set
    bitField - bit field for storing the set

Methods:

    TSet(int mp) - constructor that takes the maximum power of the set as an argument
    TSet(const TSet& s) - copy constructor
    operator TBitField() - type conversion to a bit field
    size_t GetMaxPower() const noexcept - method that returns the maximum power of the set
    void InsElem(size_t Elem) - method that includes an element into the set
    void DelElem(size_t Elem) - method that removes an element from the set
    bool IsMember(size_t Elem) const - method that checks if an element is present in the set
    void insert(size_t Elem) - method that includes an element into the set
    TSet operator+ (const int Elem) - a method that performs the union of a set with an element
    TSet operator- (const int Elem) - method that performs the difference of a set with an element
    TSet operator+ (const TSet& s) - a method that performs the union of sets
    TSet operator* (const TSet& s) - a method that performs intersection of sets
    TSet operator~ () - a method that performs set addition
    bool operator== (const TSet& s) const - a method that checks the equality of sets
    bool operator!= (const TSet& s) const - a method that checks the inequality of sets
    TSet& operator=(const TSet& s) - assignment operator

    friend std::istream& operator>>(std::istream& in, TSet& bf) - a friendly function that overloads the input operator
    friend std::ostream& operator<<(std::ostream& out, const TSet& bf) - a friendly function that overloads the output operator

    TSet(int mp) - a constructor that takes the maximum power of a set as an argument
    TSet(const TSet& s) - copy constructor

The TSet class also defines assignment operators and overloads input and output operators.
The use of constructors in the TSet class allows you to initialize the data of class objects when creating them.
This is convenient and allows you to avoid errors when working with class objects.
*/

#include <iostream>

#include "..\bit_fild_and_set\bit_fild.h"

class TSet {
private: size_t maxPower;
    TBitField bitField;
public: TSet(int mp);
    TSet(const TSet& s);
    operator TBitField();
    size_t GetMaxPower() const noexcept;
    void InsElem(size_t Elem);
    void DelElem(size_t Elem);
    bool IsMember(size_t Elem) const;
    void insert(size_t Elem);
    TSet operator + (const int Elem);
    TSet operator - (const int Elem);
    TSet operator + (const TSet& s);
    TSet operator * (const TSet& s);
    TSet operator~();
    bool operator == (const TSet& s) const;
    bool operator != (const TSet& s) const;
    TSet& operator = (const TSet& s);
    friend std::istream& operator >> (std::istream& in, TSet& bf);
    friend std::ostream& operator << (std::ostream& out, const TSet& bf);
};
#endif