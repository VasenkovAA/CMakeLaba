#ifndef _TVECTORITERATOR_H_
#define _TVECTORITERATOR_H_


/*
    Конструкторы:
        vector(): создает пустой вектор.
        vector(size_type n): создает вектор из n элементов.
        vector(size_type n, const T& value): создает вектор из n элементов, каждый из которых равен value.
        vector(const vector& x): создает копию вектора x.
        vector(vector&& x): перемещает ресурсы из x в новый вектор.
    Операторы:
        operator[]: доступ к элементу по индексу.
        operator=: присваивание вектора другому вектору.
    Методы:
        size(): возвращает количество элементов в векторе.
        empty(): возвращает true, если вектор пуст.
        push_back(const T& x): добавляет элемент x в конец вектора.
        pop_back(): удаляет последний элемент вектора.
        clear(): удаляет все элементы из вектора.
        resize(size_type n): изменяет размер вектора на n.
        reserve(size_type n): выделяет память для n элементов.
    Итераторы:
        begin(): возвращает итератор на начало вектора.
        end(): возвращает итератор на конец вектора.
*/


template <typename T>
class TVector {
public:
    // Конструкторы
    TVector() : size_(0), capacity_(0), data_(nullptr) {}
    TVector(size_t size) : size_(size), capacity_(size), data_(new T[size]) {}
    TVector(size_t size, const T& value) : size_(size), capacity_(size), data_(new T[size]) {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = value;
        }
    }
    TVector(const TVector& other) : size_(other.size_), capacity_(other.capacity_), data_(new T[other.capacity_]) {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    TVector(TVector&& other) noexcept : size_(other.size_), capacity_(other.capacity_), data_(other.data_) {
        other.size_ = 0;
        other.capacity_ = 0;
        other.data_ = nullptr;
    }
    ~TVector() {
        delete[] data_;
    }

    // Операторы
    TVector& operator=(const TVector& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }
    TVector& operator=(TVector&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = other.data_;
            other.size_ = 0;
            other.capacity_ = 0;
            other.data_ = nullptr;
        }
        return *this;
    }
    T& operator[](size_t index) {
        return data_[index];
    }
    const T& operator[](size_t index) const {
        return data_[index];
    }

    // Итераторы
    typedef T* iterator;
    typedef const T* const_iterator;

    iterator begin() {
        return data_;
    }
    const_iterator begin() const {
        return data_;
    }
    iterator end() {
        return data_ + size_;
    }
    const_iterator end() const {
        return data_ + size_;
    }

    // Методы
    void push_back(const T& value) {
        if (size_ == capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data_[size_++] = value;
    }
    void pop_back() {
        --size_;
    }
    void reserve(size_t new_capacity) {
        if (new_capacity > capacity_) {
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < size_; ++i) {
                new_data[i] = data_[i];
            }
            delete[] data_;
            data_ = new_data;
            capacity_ = new_capacity;
        }
    }
    void resize(size_t new_size) {
        if (new_size > capacity_) {
            reserve(new_size);
        }
        size_ = new_size;
    }
    size_t size() const {
        return size_;
    }
    size_t capacity() const {
        return capacity_;
    }
    bool empty() const {
        return size_ == 0;
    }
    void clear() {
        size_ = 0;
    }

private:
    size_t size_;
    size_t capacity_;
    T* data_;
};
#endif //_TVECTORITERATOR_H_