#pragma once

template <typename T, int N>
class FixedVector {
public:
    FixedVector();
    virtual ~FixedVector(){};

    bool Add(const T& data);
    int GetSize() const;
    int GetCap() const;

private:
    T mArr[N];
    int mSize;
};

template <typename T, int N>
inline FixedVector<T, N>::FixedVector() : mSize(0) {
}

template <typename T, int N>
inline bool FixedVector<T, N>::Add(const T& data) {
    if (mSize > N) {
        return false;
    } else {
        mArr[mSize++] = data;
        return true;
    }
}

template <typename T, int N>
inline int FixedVector<T, N>::GetSize() const {
    return mSize;
}

template <typename T, int N>
inline int FixedVector<T, N>::GetCap() const {
    return N;
}
