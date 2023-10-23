#include <iostream>

using namespace std;
template <typename T>
class vector {
public:
    vector() : m_size(0), m_capacity(0), m_data(nullptr) {}
    vector(size_t size) : m_size(size), m_capacity(size), m_data(new T[size]) {}
    vector(const vector<T>& other) : m_size(other.m_size), m_capacity(other.m_capacity), m_data(new T[other.m_capacity]) {
        for (size_t i = 0; i < m_size; i++) {
            m_data[i] = other.m_data[i];
        }
    }
    vector(vector<T>&& other) noexcept : m_size(other.m_size), m_capacity(other.m_capacity), m_data(other.m_data) {
        other.m_size = 0;
        other.m_capacity = 0;
        other.m_data = nullptr;
    }
    ~vector() {
        delete[] m_data;
    }

    vector<T>& operator=(const vector<T>& other) {
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
    vector<T>& operator=(vector<T>&& other) noexcept {
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
        if (m_size == m_capacity) {
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);
        }
        m_data[m_size++] = value;
    }
    void pop_back() {
        if (m_size > 0) {
            m_size--;
        }
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

    void swap(vector<T>& other) {
        std::swap(m_size, other.m_size);
        std::swap(m_capacity, other.m_capacity);
        std::swap(m_data, other.m_data);
    }

private:
    size_t m_size;
    size_t m_capacity;
    T* m_data;
};
