#pragma once

template <typename T>
class CustomArr {
public:
    CustomArr();
    virtual ~CustomArr(){};

    bool Add(const T& data);
    int GetSize() const;

private:
    enum { MAX = 3 };
    int mSize;
    T mArr[MAX];
};

template <typename T>
inline CustomArr<T>::CustomArr() : mSize(0){};

template <typename T>
inline bool CustomArr<T>::Add(const T& data) {
    if (mSize >= MAX) {
        return false;
    } else {
        mArr[mSize++] = data;
        return true;
    }
}

template <typename T>
inline int CustomArr<T>::GetSize() const {
    return mSize;
}