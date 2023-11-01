#ifndef _TVECTOR_H_
#define _TVECTOR_H_
// Copyright 2023 Vasenkov Andrey

/*
RU:
Данный код представляет собой реализацию шаблонного класса TVector, который представляет собой динамический массив. Каждая функция и переменная имеет свою роль в работе класса:
TVector(): конструктор по умолчанию, создает пустой массив.
TVector(size_t size): конструктор, создающий массив заданного размера и заполняющий его значениями по умолчанию.
TVector(const TVector<T>& other): конструктор копирования, создает копию переданного массива.
TVector(TVector<T>&& other) noexcept: конструктор перемещения, перемещает данные из переданного массива в новый массив.
*TVector(const T data, size_t size)**: конструктор, создающий массив заданного размера и заполняющий его значениями из переданного массива.
~TVector(): деструктор, освобождает память, занятую массивом.
T& operator[](size_t index): оператор доступа к элементу массива по индексу.
const T& operator[](size_t index) const: оператор доступа к элементу массива по индексу (константная версия).
T& at(size_t index): функция доступа к элементу массива по индексу с проверкой выхода за границы массива.
const T& at(size_t index) const: функция доступа к элементу массива по индексу с проверкой выхода за границы массива (константная версия).
T& front(): функция доступа к первому элементу массива.
const T& front() const: функция доступа к первому элементу массива (константная версия).
T& back(): функция доступа к последнему элементу массива.
const T& back() const: функция доступа к последнему элементу массива (константная версия).
bool empty() const: функция, возвращающая true, если массив пустой, и false в противном случае.
size_t size() const: функция, возвращающая размер массива.
size_t capacity() const: функция, возвращающая ёмкость массива.
void reserve(size_t new_capacity): функция, увеличивающая ёмкость массива до заданного значения.
void clear(): функция, очищающая массив.
void push_back(const T& value): функция, добавляющая элемент в конец массива.
void resize(size_t new_size): функция, изменяющая размер массива.
void swap(TVector<T>& other): функция, меняющая местами данные двух массивов.
Переменные класса:
size_t m_size: размер массива.
size_t m_capacity: ёмкость массива.
T m_data*: указатель на данные массива.
*/

/*
ENG:

The TVector class is a template vector class that can store elements of any data type. It contains methods for adding, deleting, modifying and accessing vector elements. The TVector class also provides dynamic memory allocation for storing vector elements, allowing it to change its size during program execution.
TVector class description
The TVector class has the following methods:

    TVector(): default constructor, creates an empty vector.
    TVector(int size): constructor, creates a vector of the given size.
    TVector(const TVector& other): copy constructor, creates a copy of another vector.
    ~TVector(): destructor, frees the memory occupied by the vector.
    int Size() const: returns the size of the vector.
    bool Empty() const: returns true if the vector is empty and false otherwise.
    void Clear(): removes all elements from the vector.
    void PushBack(const T& value): adds an element to the end of the vector.
    void PopBack(): removes the last element from the vector.
    T& operator[](int index): returns a reference to an element of the vector by index.
    const T& operator[](int index) const: returns a constant reference to the element of the vector by index.

Translated with www.DeepL.com/Translator (free version)

*/

#include <iostream>
#define MAX_VECTOR_SIZE 1000
using namespace std;
template <typename T>
class TVector {
public:

    TVector() : m_size(0), m_capacity(0), m_data(nullptr) {}
    TVector(size_t size) : m_size(size), m_capacity(size), m_data(new T[size]) {
        if (size > MAX_VECTOR_SIZE) {
            throw std::out_of_range("Vector size exceeds maximum allowed size");
        }
    }
    TVector(const TVector<T>& other) : m_size(other.m_size), m_capacity(other.m_capacity), m_data(new T[other.m_capacity]) {
        for (size_t i = 0; i < m_size; i++) {
            m_data[i] = other.m_data[i];
        }
    }
    TVector(TVector<T>&& other) noexcept : m_size(other.m_size), m_capacity(other.m_capacity), m_data(other.m_data) {
        other.m_size = 0;
        other.m_capacity = 0;
        other.m_data = nullptr;
    }
    TVector(const T* data, size_t size) : m_size(size), m_capacity(size), m_data(new T[size]) {
        if (size > MAX_VECTOR_SIZE) {
            throw std::out_of_range("Vector size exceeds maximum allowed size");
        }
        for (size_t i = 0; i < size; i++) {
            m_data[i] = data[i];
        }
    }
    ~TVector() {
        delete[] m_data;
        m_data = nullptr;
    }
    TVector<T> operator+(const T& scalar) const {
        TVector<T> result(m_size);
        for (size_t i = 0; i < m_size; i++) {
            result[i] = m_data[i] + scalar;
        }
        return result;
    }
    TVector<T> operator-(const T& scalar) const {
        TVector<T> result(m_size);
        for (size_t i = 0; i < m_size; i++) {
            result[i] = m_data[i] - scalar;
        }
        return result;
    }
    TVector<T>& operator=(const TVector<T>& other) {
        if (this != &other) {
            delete[] m_data;
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_data = new T[m_capacity];
            for (size_t i = 0; i < m_size; i++) {
                m_data[i] = other.m_data[i];
            }
        }
        return *this;
    }
    TVector<T>& operator=(TVector<T>&& other) noexcept {
        if (this != &other) {
            delete[] m_data;
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_data = other.m_data;
            other.m_size = 0;
            other.m_capacity = 0;
            other.m_data = nullptr;
        }
        return *this;
    }
    TVector<T> operator+(const TVector<T>& other) const {
        if (m_size != other.m_size) {
            throw std::invalid_argument("Vectors have different sizes");
        }
        TVector<T> result(m_size);
        for (size_t i = 0; i < m_size; i++) {
            result[i] = m_data[i] + other.m_data[i];
        }
        return result;
    }
    TVector<T> operator*(const T& scalar) const {
        TVector<T> result(m_size);
        for (size_t i = 0; i < m_size; i++) {
            result[i] = m_data[i] * scalar;
        }
        return result;
    }
    TVector<T> operator-(const TVector<T>& other) const {
        if (m_size != other.m_size) {
            throw std::invalid_argument("Vectors have different sizes");
        }
        TVector<T> result(m_size);
        for (size_t i = 0; i < m_size; i++) {
            result[i] = m_data[i] - other.m_data[i];
        }
        return result;
    }
    bool operator==(const TVector<T>& other) const {
        if (m_size != other.m_size) {
            return false;
        }
        for (size_t i = 0; i < m_size; i++) {
            if (m_data[i] != other.m_data[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const TVector<T>& other) const {
        return !(*this == other);
    }
    T& operator[](size_t index) {
        return m_data[index];
    }
    const T& operator[](size_t index) const {
        return m_data[index];
    }
    T& at(size_t index) {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }
    const T& at(size_t index) const {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }
    T& front() {
        return m_data[0];
    }
    const T& front() const {
        return m_data[0];
    }
    T& back() {
        return m_data[m_size - 1];
    }
    const T& back() const {
        return m_data[m_size - 1];
    }

    bool empty() const {
        return m_size == 0;
    }
    size_t size() const {
        return m_size;
    }
    size_t capacity() const {
        return m_capacity;
    }



    void clear() {
        delete[] m_data;
        m_size = 0;
        m_capacity = 0;
        m_data = nullptr;
    }
    
    void push_back(const T& value) {
        if (m_size == MAX_VECTOR_SIZE) {
            throw std::out_of_range("Vector size exceeds maximum allowed size");
        }
        if (m_size == m_capacity) {
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);
        }
        m_data[m_size++] = value;
    }
    void resize(size_t new_size) {
        if (new_size > m_capacity) {
            reserve(new_size);
        }
        for (size_t i = m_size; i < new_size; i++) {
            m_data[i] = T();
        }
        m_size = new_size;
    }

    void swap(TVector<T>& other) {
        std::swap(m_size, other.m_size);
        std::swap(m_capacity, other.m_capacity);
        std::swap(m_data, other.m_data);
    }

private:
    void reserve(size_t new_capacity) {
        if (new_capacity > m_capacity) {
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < m_size; i++) {
                new_data[i] = m_data[i];
            }
            delete[] m_data;
            m_data = new_data;
            m_capacity = new_capacity;
        }
    }
    size_t m_size;
    size_t m_capacity;
    T* m_data;
}; 
#endif 