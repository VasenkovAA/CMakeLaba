// Copyright 2023 Vasenkov Andrey
#include "bit_fild.h"
#include <iostream>
TBitField::TBitField(unsigned int size)
{
    this->size = size;
    //if (size >= INT_MAX - kBitsInByte_ + 1) { throw std::logic_error("Invalid index, index > INT_MAX-31"); }
    int dataSize = (size + kBitsInByte_-1) / kBitsInByte_; // вычисляем размер массива в int-ах
    //std::cout << dataSize <<" "<< INT_MAX << std::endl;
    data = new unsigned int[dataSize];
    for (int i = 0; i < dataSize; i++) {
        data[i] = 0; // инициализируем массив нулями
    }
}

TBitField::TBitField()
{
    size = 0;
    data = nullptr;
}

TBitField::TBitField(const TBitField& other)
{
    size = other.size;
    int dataSize = (size + kBitsInByte_-1) / kBitsInByte_;
    data = new unsigned int[dataSize];
    for (int i = 0; i < dataSize; i++) {
        data[i] = other.data[i];
    }
}

TBitField::TBitField(TBitField&& other) noexcept
{
    size = other.size;
    data = other.data;
    other.data = nullptr;
}

TBitField& TBitField::operator=(TBitField&& other) noexcept
{
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = other.data;
        other.data = nullptr;
    }
    return *this;
}

TBitField& TBitField::operator=(const TBitField& other)
{
    if (this != &other) {
        delete[] data;
        size = other.size;      
        int dataSize = (size + kBitsInByte_ - 1) / kBitsInByte_; // вычисляем размер массива в int-ах
        data = new unsigned int[dataSize];
        for (int i = 0; i < dataSize; i++) {
            data[i] = other.data[i]; // инициализируем массив нулями
        }
    }
    return *this;

}

bool TBitField::operator==(const TBitField& other) const
{
    if (size != other.size) {
        return false;
        
    }
    for (int i = 0; i < size; i++) {
        if (getBit(i) != other.getBit(i)) {
            return false;
        }
    }
    return true;
}

bool TBitField::operator!=(const TBitField& other) const
{
    return !(*this == other);
}

TBitField TBitField::operator&(const TBitField& other) const
{
    TBitField result(size);
    int dataSize = (size + kBitsInByte_ - 1) / kBitsInByte_;
    for (int i = 0; i < dataSize; i++) {
        result.data[i] = data[i] & other.data[i];
    }
    return result;
}

TBitField TBitField::operator|(const TBitField& other) const
{
    TBitField* result;
    if (size < other.size) { result = new TBitField(other); }
    else { result = new TBitField(*this); }
    
 
    for (int i = 0; i < std::min(getSize(), other.getSize()); i++) {
        if (this->getBit(i)>0 || other.getBit(i) > 0) { result->setBit(i); }
        //result->setBit(getBit(i) ? '1' : '0'/*this->getBit(i) | other.getBit(i)*/);
    }
    return *result;
}

TBitField TBitField::operator~() const
{
    TBitField result(size);
    int dataSize = (size + kBitsInByte_ - 1) / kBitsInByte_;
    for (int i = 0; i < dataSize; i++) {
        result.data[i] = ~data[i];
    }
    return result;
}

TBitField::~TBitField()
{
    delete[] data;
}

void TBitField::setBit(int index)
{
    int intIndex = index / kBitsInByte_; // индекс int-а, в котором находится нужный бит
    int bitIndex = index % kBitsInByte_; // индекс бита внутри int-а
    data[intIndex] |= (1 << bitIndex); // устанавливаем бит
}

void TBitField::clearBit(int index)
{
    int intIndex = index / kBitsInByte_;
    int bitIndex = index % kBitsInByte_;
    data[intIndex] &= ~(1 << bitIndex); // сбрасываем бит
}

bool TBitField::getBit(int index) const
{
    int intIndex = index / kBitsInByte_;
    int bitIndex = index % kBitsInByte_;
    return (data[intIndex] & (1 << bitIndex)) != 0; // возвращаем значение бита
}
