//
// Created by stuft2 on 12/12/17.
//

#ifndef LAB9_CS235_BYU_VECTOR_H
#define LAB9_CS235_BYU_VECTOR_H

#include <stdexcept>
#include <sstream>
#include <string>

template<typename T>
class vector {
    friend QSInterface;
private:
    T *items = nullptr;
    int size = 0;
    int capacity = 0;
public:
    vector(int number) {
        if (number <= 0) throw std::invalid_argument( "Received non-positive value" );
        T array[number];
        items = array;
        capacity = number;
    }

    vector() {}

    ~vector() {
        clear();
    };

    int length() {
        return size;
    };

    bool full() {
        return size == capacity;
    };

    bool empty() {
        return size == 0;
    };

    T back() {
        return items[size-1];
    };

    T front() {
        return items;
    };

    T at(int index) {
        if (index > size - 1 || index < 0) return nullptr;
        return items[index];
    }

    int find(T value) {
        for(int i = 0; i < size; i++) {
            if (items[i] == value) return i;
        }
        return -1;
    }

    bool push(T value) {
        if (full()) capacity = capacity * 2;            // Increase the array capacity if needed
        T temp[capacity];                               // Create temporary array
        temp[0] = value;                                // Assign new item to first element
        for (int i = 0; i < size; i++) {                // Copy the old array to the temp array
            temp[i + 1] = items[i];
        }
        size++;                                         // Increment the size of the array
        for (int i = size - 1; i < capacity; i++) {     // Fill the rest of the array with null values
            temp[i] = nullptr;
        }
        items = temp;                                   // Assign new array to items.
    };

    bool push_back(T value) {
        if (full()) {                                   // Increase the array capacity if needed
            capacity = capacity * 2;
            T temp[capacity];                           // Create temporary array
            for (int i = 0; i < size; i++) {            // Copy the old array to the temp array
                temp[i] = items[i];
            }
            temp[size] = value;                         // Assign new item to next position in the array
            size++;                                     // Increment the size of the array
            for (int i = size - 1; i < capacity; i++) { // Fill the rest of the array with null values
                temp[i] = T {};
            }
            items = temp;                               // Assign new array to items
        }
    };

    bool insert(T value, int index) {
        if (index > size - 1 || index < 0) return false;// Validate index number
        if (full()) capacity = capacity * 2;            // Increase capacity if needed
        T temp[capacity];                               // Create temporary array
        for(int i = 0; i < index; i++) {                // Copy first partition to temp
            temp[i] = items[i];
        }
        temp[index] = value;                            // Insert new value
        size++;                                         // Increment size
        for(int i = index; i < size; i++) {             // Continue copying old array to temp
            temp[i + 1] = items[i];
        }
        items = temp;                                   // Assign new array to items
    };

    bool exchange(T i, T j) {
        T temp = items[i];
        items[i] = items[j];
        items[j] = temp;
    };

    void clear() {
        delete[] items;
        items = nullptr;
    };

    string to_string() {
        stringstream ss;
        ss << "[ ";
        for (int i = 0; i < size; i++) {
            ss << items[i] << ",";
            if (i != size - 1) ss << " ";
        }
        ss << " ]";
        return ss.str();
    }

};


#endif //LAB9_CS235_BYU_VECTOR_H
