// Copyright 2023 Vasenkov Andrey
#ifndef _BITFILD_H_
#define _BITFILD_H_

#define BIT_IN_BYTE 8
#include <iostream>
class TBitField {
private:
    unsigned int size; // размер битового поля в битах
    unsigned int* data; // указатель на массив, хранящий биты
    const short kBitsInByte_ = (BIT_IN_BYTE * sizeof(int));
public:
    TBitField(unsigned int size);

    TBitField();

    TBitField(const TBitField& other);

    TBitField(TBitField&& other) noexcept;

    TBitField& operator=(TBitField&& other)noexcept;

    TBitField& operator=(const TBitField& other);

    bool operator==(const TBitField& other) const;

    bool operator!=(const TBitField& other) const;

    TBitField operator&(const TBitField& other) const;

    TBitField operator|(const TBitField& other) const;

    TBitField operator~() const;

    unsigned int getSize() const {
        return size;
    }

    ~TBitField();

    void setBit(int index);

    void clearBit(int index);

    bool getBit(int index) const;

    friend std::ostream& operator<<(std::ostream& os, const TBitField& bitField) {
        for (int i = 0; i <= bitField.size - 1; i++) {
            os << (bitField.getBit(i) ? '1' : '0');
        }
        return os;
    }
    std::string to_string() {
        std::string str;
        for (int i = 0; i <= size - 1; i++) {
            str += (getBit(i) ? '1' : '0');
        }
        return str;
    }
    void swap(TBitField& other) noexcept {
        std::swap(size, other.size);
        std::swap(data, other.data);
    }
};
#endif