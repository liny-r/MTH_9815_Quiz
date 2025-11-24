//
// Created by Yueqi Lin on 24/11/2025.
//
#include <vector>
#include <list>
#include <stdexcept>

#ifndef MTH_9815_QUIZ_HASHTABLE_HPP
#define MTH_9815_QUIZ_HASHTABLE_HPP

// -----------------------------
// Base classes
// -----------------------------

template <typename K>
class Hasher {
public:
    virtual ~Hasher() = default;
    // Pure virtual hash function
    virtual size_t operator()(const K& key) const = 0;
};

template <typename K>
class EqualityPredicate {
public:
    virtual ~EqualityPredicate() = default;
    // Pure virtual equality check
    virtual bool operator()(const K& a, const K& b) const = 0;
};

// -----------------------------
// HashTable class
// -----------------------------

template <typename K, typename V>
class Hashtable {
private:
    std::vector<std::list<std::pair<K, V>>> buckets;
    const Hasher<K>& hasher;
    const EqualityPredicate<K>& equals;

public:
    explicit Hashtable(size_t bucket_count,
                       const Hasher<K>& hasher,
                       const EqualityPredicate<K>& equals)
        : buckets(bucket_count), hasher(hasher), equals(equals) {}

    // Insert or update
    void insert(const K& key, const V& value) {
        size_t h = hasher(key) % buckets.size();
        for (auto& kv : buckets[h]) {
            if (equals(kv.first, key)) {
                kv.second = value;   // update existing
                return;
            }
        }
        buckets[h].push_back({key, value}); // insert new
    }

    // Lookup
    V& at(const K& key) {
        size_t h = hasher(key) % buckets.size();
        for (auto& kv : buckets[h]) {
            if (equals(kv.first, key)) {
                return kv.second;
            }
        }
        throw std::out_of_range("Key not found");
    }

    bool contains(const K& key) const {
        size_t h = hasher(key) % buckets.size();
        for (const auto& kv : buckets[h]) {
            if (equals(kv.first, key)) {
                return true;
            }
        }
        return false;
    }
};

// -----------------------------
// Example concrete function objects
// -----------------------------

// Simple integer hasher
class IntHasher : public Hasher<int> {
public:
    size_t operator()(const int& x) const override {
        return std::hash<int>{}(x);
    }
};

class IntEquality : public EqualityPredicate<int> {
public:
    bool operator()(const int& a, const int& b) const override {
        return a == b;
    }
};

#endif //MTH_9815_QUIZ_HASHTABLE_HPP