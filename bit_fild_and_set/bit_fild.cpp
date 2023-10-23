// Copyright 2023 Vasenkov Andrey

#include "..\bit_fild_and_set\bit_fild.h"
TBitField::TBitField(unsigned int size) {
    this->size = size;
    // calculate array size in ints
    int dataSize = (size + kBitsInByte_-1) / kBitsInByte_;
    data = new unsigned int[dataSize];
    for (int i = 0; i < dataSize; i++) {
        data[i] = 0;  // initialize the array with zeros
    }
}

TBitField::TBitField() {
    size = 0;
    data = nullptr;
}

TBitField::TBitField(const TBitField& other) {
    size = other.size;
    int dataSize = (size + kBitsInByte_-1) / kBitsInByte_;
    data = new unsigned int[dataSize];
    for (int i = 0; i < dataSize; i++) {
        data[i] = other.data[i];
    }
}

TBitField::TBitField(TBitField&& other) noexcept {
    size = other.size;
    data = other.data;
    other.data = nullptr;
}

TBitField& TBitField::operator=(TBitField&& other) noexcept {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = other.data;
        other.data = nullptr;
    }
    return *this;
}

TBitField& TBitField::operator=(const TBitField& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        int dataSize = (size + kBitsInByte_ - 1) / kBitsInByte_;
        data = new unsigned int[dataSize];
        for (int i = 0; i < dataSize; i++) {
            data[i] = other.data[i];  // initialize the array with zeros
        }
    }
    return *this;
}

bool TBitField::operator==(const TBitField& other) const {
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

bool TBitField::operator!=(const TBitField& other) const {
    return !(*this == other);
}

TBitField TBitField::operator&(const TBitField& other) const {
    TBitField result(size);
    int dataSize = (size + kBitsInByte_ - 1) / kBitsInByte_;
    for (int i = 0; i < dataSize; i++) {
        result.data[i] = data[i] & other.data[i];
    }
    return result;
}

TBitField TBitField::operator|(const TBitField& other) const {
    TBitField* result;
    if (size < other.size) { result = new TBitField(other); } else {
        result = new TBitField(*this); }
    for (int i = 0; i < std::min(getSize(), other.getSize()); i++) {
        if (this->getBit(i) > 0 || other.getBit(i) > 0) { result->setBit(i); }
    }
    return *result;
}

TBitField TBitField::operator~() const {
    TBitField result(size);
    int dataSize = (size + kBitsInByte_ - 1) / kBitsInByte_;
    for (int i = 0; i < dataSize; i++) {
        result.data[i] = ~data[i];
    }
    return result;
}

TBitField::~TBitField() {
    delete[] data;
}

void TBitField::setBit(int index) {
    // index of the int where the required bit is located
    int intIndex = index / kBitsInByte_;
    int bitIndex = index % kBitsInByte_;  // bit index within an int
    data[intIndex] |= (1 << bitIndex);  // set the bit
}

void TBitField::clearBit(int index) {
    int intIndex = index / kBitsInByte_;
    int bitIndex = index % kBitsInByte_;
    data[intIndex] &= ~(1 << bitIndex);  // return the bit value
}

bool TBitField::getBit(int index) const {
    int intIndex = index / kBitsInByte_;
    int bitIndex = index % kBitsInByte_;
    // возвращаем значение бита
    return (data[intIndex] & (1 << bitIndex)) != 0;
}
