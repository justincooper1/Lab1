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
    // Uses emptyBag from ABag.h
    void clear() override {
        bag.emptyBag();
    }

    // Insert a record
    // Uses addItem from ABag.h
    bool insert(const Key& k, const E& e) override {
        KVpair<Key, E> newPair(k, e);
        return bag.addItem(newPair);
    }

    // Remove a record using key
    // Uses remove from ABag.h
    bool remove(const Key& k, const E& rtnVal) override {
        KVpair<Key, E> temp;
        if (find(k, rtnVal)) {
            bag.remove(temp);
            return true;
        }
        return false;
    }

    // Remove any record from the dictionary
    // Uses inspectTop and removeTop from ABag.h
    bool removeAny(E& returnValue) override {
        if (bag.inspectTop(returnValue)) {
            bag.removeTop(returnValue);
            return true;
        }
        return false;
    }

    // Find a record using a key
    // Uses search from ABag.h
    bool find(const Key& k, E& returnValue) const override {
        KVpair<Key, E> temp;
        temp.setKey(k);
        return bag.search(temp);
    }
};