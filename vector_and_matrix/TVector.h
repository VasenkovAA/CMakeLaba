// Copyright 2023 Vasenkov Andrey
#ifndef _TVECTOR_H_
#define _TVECTOR_H_

/*
RU:

Класс TVector представляет собой шаблонный класс вектора, который может хранить элементы любого типа данных. Он содержит методы для добавления, удаления, изменения и доступа к элементам вектора. Класс TVector также обеспечивает динамическое выделение памяти для хранения элементов вектора, что позволяет ему изменять свой размер во время выполнения программы.
Описание класса TVector
Класс TVector имеет следующие методы:

    TVector(): конструктор по умолчанию, создает пустой вектор.
    TVector(int size): конструктор, создающий вектор заданного размера.
    TVector(const TVector& other): конструктор копирования, создает копию другого вектора.
    ~TVector(): деструктор, освобождает память, занятую вектором.
    int Size() const: возвращает размер вектора.
    bool Empty() const: возвращает true, если вектор пустой, и false в противном случае.
    void Clear(): удаляет все элементы из вектора.
    void PushBack(const T& value): добавляет элемент в конец вектора.
    void PopBack(): удаляет последний элемент из вектора.
    T& operator[](int index): возвращает ссылку на элемент вектора по индексу.
    const T& operator[](int index) const: возвращает константную ссылку на элемент вектора по индексу.

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
template < typename T >
class TVector {
public: TVector() : m_size(0),
    m_capacity(0),
    m_data(nullptr) {}
      TVector(size_t size) : m_size(size),
          m_capacity(size),
          m_data(new T[size]) {
          if (size > MAX_VECTOR_SIZE) {
              throw std::out_of_range("Vector size exceeds maximum allowed size");
          }
      }
      TVector(const TVector < T >& other) : m_size(other.m_size),
          m_capacity(other.m_capacity),
          m_data(new T[other.m_capacity]) {
          for (size_t i = 0; i < m_size; i++) {
              m_data[i] = other.m_data[i];
          }
      }
      TVector(TVector < T >&& other) noexcept : m_size(other.m_size),
          m_capacity(other.m_capacity),
          m_data(other.m_data) {
          other.m_size = 0;
          other.m_capacity = 0;
          other.m_data = nullptr;
      }
      TVector(const T* data, size_t size) : m_size(size),
          m_capacity(size),
          m_data(new T[size]) {
          if (size > MAX_VECTOR_SIZE) {
              throw std::out_of_range("Vector size exceeds maximum allowed size");
          }
          for (size_t i = 0; i < size; i++) {
              m_data[i] = data[i];
          }
      }
      ~TVector() {
          delete[] m_data;
      }
      TVector < T > operator + (const T& scalar) const {
          TVector < T > result(m_size);
          for (size_t i = 0; i < m_size; i++) {
              result[i] = m_data[i] + scalar;
          }
          return result;
      }
      TVector < T > operator - (const T& scalar) const {
          TVector < T > result(m_size);
          for (size_t i = 0; i < m_size; i++) {
              result[i] = m_data[i] - scalar;
          }
          return result;
      }
      TVector < T >& operator = (const TVector < T >& other) {
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
      TVector < T >& operator = (TVector < T >&& other) noexcept {
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
      TVector < T > operator + (const TVector < T >& other) const {
          if (m_size != other.m_size) {
              throw std::invalid_argument("Vectors have different sizes");
          }
          TVector < T > result(m_size);
          for (size_t i = 0; i < m_size; i++) {
              result[i] = m_data[i] + other.m_data[i];
          }
          return result;
      }
      TVector < T > operator * (const T& scalar) const {
          TVector < T > result(m_size);
          for (size_t i = 0; i < m_size; i++) {
              result[i] = m_data[i] * scalar;
          }
          return result;
      }
      TVector < T > operator - (const TVector < T >& other) const {
          if (m_size != other.m_size) {
              throw std::invalid_argument("Vectors have different sizes");
          }
          TVector < T > result(m_size);
          for (size_t i = 0; i < m_size; i++) {
              result[i] = m_data[i] - other.m_data[i];
          }
          return result;
      }
      bool operator == (const TVector < T >& other) const {
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
      bool operator != (const TVector < T >& other) const {
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

      void swap(TVector < T >& other) {
          std::swap(m_size, other.m_size);
          std::swap(m_capacity, other.m_capacity);
          std::swap(m_data, other.m_data);
      }

private: size_t m_size;
       size_t m_capacity;
       T* m_data;
};
#endif  