#pragma once

#include "dictionaryADT.h"
#include "KVpair.h"
#include "ABag.h"
#include <memory>

template <class Key, class E>
class BDictionary : public Dictionary<Key, E> {
private:
    std::unique_ptr<ABag<KVpair<Key, E>>> bag; // Smart pointer

public:
    // Constructor
    BDictionary() {
        bag = std::make_unique<ABag<KVpair<Key, E>>>(); // Initialize the pointer
    }

    // Constructor with initial size argument
    BDictionary(size_t initialSize) {
        bag = std::make_unique<ABag<KVpair<Key, E>>>(initialSize);
    }

    // Destructor
    ~BDictionary() override {}

    // Reinitialize dictionary
    // Uses emptyBag from ABag.h
    void clear() override {
        bag->emptyBag();
    }

    // Insert a record
    // Uses addItem from ABag.h
    bool insert(const Key& k, const E& e) override {
        KVpair<Key, E> newPair(k, e);
        return bag->addItem(newPair);
    }

    // Remove a record using key
    // Uses remove from ABag.h
    bool remove(const Key& k, E& rtnVal) override {
        KVpair<Key, E> temp;
        if (find(k, rtnVal)) {
            bag->remove(temp);
            rtnVal = temp.value();
            return true;
        }
        return false;
    }

    // Remove any record from the dictionary
    // Uses inspectTop and removeTop from ABag.h
    bool removeAny(E& returnValue) override {
        KVpair<Key, E> temp;
        if (bag->removeTop(temp)) {
            returnValue = temp.value();
            return true;
        }
        return false;
    }

    // Find a record using a key
    // Uses search from ABag.h
    bool find(const Key& k, E& returnValue) const override {
        KVpair<Key, E> temp;
        temp.setKey(k);
        if (bag->search(temp)) {
            returnValue = temp.value();
            return true;
        }
        return false;
    }

    // Return the size of the dictionary
    // Uses numitems from ABag.h
    int size() const override {
        return bag->numItems();
    }
};
