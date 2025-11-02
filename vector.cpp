#include <iostream>
using namespace std;

template<typename T>

class Vector {
private:
    T* arr;
    int capacity;
    int sz;

    void resize() {
        if (capacity == 0) {
            capacity++;
        }
        capacity *= 2;
        T* nwarr = new T[capacity];
        for (int i = 0; i < sz; i++) {
            nwarr[i] = arr[i];
        }
        delete[] arr;
        arr = nwarr;
    }

public:
    Vector() {
        capacity = 0;
        sz = 0;
        arr = nullptr;
    }

    Vector(const Vector& other) {
        capacity = other.capacity;
        sz = other.sz;
        arr = new T[capacity];
        for (int i = 0; i < sz; i++) {
            arr[i] = other.arr[i];
        }
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            sz = other.sz;
            arr = new T[capacity];
            for (int i = 0; i < sz; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    void push_back(T x) {
        if (sz == capacity) {
            resize();
        }
        arr[sz] = x;
        sz++;
    }

    void pop_back() {
        if (sz > 0) {
            sz--;
        }
    }

    void reverse() {
        for (int i = 0; i < sz / 2; i++) {
            swap(arr[i], arr[sz - i - 1]);
        }
    }

    void sort() {
        for (int i = 0; i < sz - 1; i++) {
            for (int j = 0; j < sz - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    int size() {
        return sz;
    }

    T get(int index) {
        if (index < 0 || index >= sz) {
            return -1;
        }
        return arr[index];
    }

    T& operator[](int index) {
        if (index < 0 || index >= sz) {
            return nullptr;
        }
        return arr[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= sz) {
            return nullptr;
        }
        return arr[index];
    }

    ~Vector() {
        delete[] arr;
    }
};