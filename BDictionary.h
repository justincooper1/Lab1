#pragma once

#include "dictionaryADT.h"
#include "KVpair.h" // Assuming this is required for the dictionary implementation

template <class Key, class E>
class BDictionary : public Dictionary<Key, E> {
private:
    ABag<KVpair<Key, E>> bag; // Use an array-based bag to store key-value pairs

public:
    // Constructor
    BDictionary() {}

    // Destructor
    ~BDictionary() {}

    // Reinitialize dictionary
    void clear() override {
        bag.emptyBag();
    }
};