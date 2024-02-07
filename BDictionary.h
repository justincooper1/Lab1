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

    // Insert a record
    bool insert(const Key& k, const E& e) override {
        KVpair<Key, E> newPair(k, e);
        return bag.addItem(newPair);
    }

    // Remove a record using key
    bool remove(const Key& k, const E& rtnVal) override {
        KVpair<Key, E> temp;
        if (find(k, rtnVal)) {
            bag.remove(temp);
            return true;
        }
        return false;
    }


};