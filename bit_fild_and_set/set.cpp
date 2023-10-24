// Copyright 2023 Vasenkov Andrey
#include "set.h"

TSet::TSet(int mp) : bitField(mp), maxPower(mp) {}
TSet::TSet(const TSet& s) : bitField(s.bitField), maxPower(s.maxPower) {}
TSet::operator TBitField() {
    return bitField;
}
size_t TSet::GetMaxPower() const noexcept {
    return maxPower;
}
void TSet::InsElem(size_t Elem) {
    bitField.setBit(Elem);
}
void TSet::DelElem(size_t Elem) {
    bitField.clearBit(Elem);
}
bool TSet::IsMember(size_t Elem) const {
    return bitField.getBit(Elem);
}
TSet TSet::operator + (const int Elem) {
    TSet tmp(*this);
    tmp.InsElem(Elem);
    return tmp;
}
TSet TSet::operator - (const int Elem) {
    TSet tmp(*this);
    tmp.DelElem(Elem);
    return tmp;
}
TSet TSet::operator + (const TSet& s) {
    TSet tmp(*this);
    if (s.maxPower > maxPower) {
        tmp.maxPower = s.maxPower;
    }
    else {
        tmp.maxPower = maxPower;
    }
    tmp.bitField = bitField | s.bitField;
    return tmp;
}
TSet TSet::operator * (const TSet& s) {
    TSet tmp(*this);
    tmp.bitField = bitField & s.bitField;
    tmp.maxPower = tmp.bitField.getSize();
    return tmp;
}
TSet TSet::operator~() {
    TSet tmp(*this);
    tmp.bitField = ~bitField;
    return tmp;
}
bool TSet::operator == (const TSet& s) const {
    return s.bitField == bitField;
}
bool TSet::operator != (const TSet& s) const {
    return s.bitField != bitField;
}
TSet& TSet::operator = (const TSet& s) {
    if (this == &s) {
        return *this;
    }
    bitField = s.bitField;
    maxPower = s.maxPower;
    return *this;
}
std::istream& operator >> (std::istream& in, TSet& bf) {
    int elem;
    in >> elem;
    bf = bf + elem;
    return in;
}
std::ostream& operator << (std::ostream& out,
    const TSet& bf) {
    for (int i = 0; i < bf.maxPower; i++) {
        if (bf.bitField.getBit(i) == 1) {
            out << i << " ";
        }
    }
    return out;
}