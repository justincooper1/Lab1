#pragma once

#include "BagADT.h"

template <class E>
class ABag : public Bag<E> {
private:
    static const int DEFAULT_CAPACITY = 10;
    E* data;  // Array to store bag items
    int capacity; // Current capacity of the bag
    int size; // Current number of items in the bag

public:
    // Constructor with initial capacity
    ABag(size_t initialCapacity = DEFAULT_CAPACITY) : capacity(initialCapacity), size(0) {
        data = new E[capacity];
    }

    // Destructor
    ~ABag() override {
        delete[] data;
    }

    // Insert a new item into the bag
    bool addItem(const E& item) override {
        if (size < capacity) {
            data[size++] = item;
            return true;
        }
        return false;
    }

    // Looks for item in the bag and if found updates 'item' with the bag value and returns true
    bool remove(E& item) override {
        for (int i = 0; i < size; ++i) {
            if (data[i] == item) {
                item = data[i];
                for (int j = i; j < size - 1; ++j) {
                    data[j] = data[j + 1];
                }
                size--;
                return true;
            }
        }
        return false;
    }

    // Removes the top record from the bag puts it in returnValue and returns true if the bag is not empty
    bool removeTop(E& returnValue) override {
        if (size > 0) {
            returnValue = data[size - 1];
            size--;
            return true;
        }
        return false;
    }

    // Finds the record using returnValue and if the record is found updates returnValue based on the contents of the bag and returns true
    bool search(E& returnValue) const override {
        for (int i = 0; i < size; ++i) {
            if (data[i] == returnValue) {
                returnValue = data[i];
                return true;
            }
        }
        return false;
    }

    // Inspect the top of the bag.
    bool inspectTop(E& item) const override {
        if (size > 0) {
            item = data[size - 1];
            return true;
        }
        return false;
    }

    // empties the bag
    void emptyBag() override {
        size = 0;
    }

    // use the += operator to add an item to the bag
    bool operator+=(const E& addend) override {
        return addItem(addend);
    }

    // get the number of items in the bag
    int numItems() const override {
        return size;
    }

    // get the capacity of the bag
    int bagCapacity() const override {
        return capacity;
    }
};
