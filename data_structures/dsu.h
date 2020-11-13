#pragma once

#include <vector>
#include <array>
#include <unordered_map>

#include "../utilies/general.h"
#include "../utilies/optimize.h"


class THashDsu {
public:

    void MakeSet(const size_t key) {
        Set[key] = key;
        Sizes[key] = 0;
    }

    size_t FindSet(const size_t key) {
        auto& [k, v] = *Set.find(key);
        if (k == v) return k;
        else return v = FindSet(v);
    }

    void UnionSets(const size_t key1, const size_t key2) {
        const auto a = FindSet(key1);
        const auto b = FindSet(key2);
        if (a == b) return;
        auto& aSize = Sizes[a], bSize = Sizes[b];
        if (aSize < bSize) {
            Set[a] = b;
            bSize += aSize;
        } else {
            Set[b] = a;
            aSize = bSize;
        }
    }

    __GEN_STL_COMPATIBILITY(Set)

private:
    std::unordered_map<size_t, size_t> Set;
    std::unordered_map<size_t, size_t> Sizes;
};

template<size_t Size=1024>
class TConstDsu {
public:
    void MakeSet(size_t v) {
        Set[v] = v;
        Sizes[v] = 0;
    }

    size_t FindSet(const size_t v) {
        auto& p = Set[v];
        if (p == v) return v;
        else return p = FindSet(p);
    }

    void UnionSets(const size_t k1, const size_t k2) {
        const auto p1 = FindSet(k1), p2 = FindSet(k2);
        if (p1 == p2) return;
        auto& size1 = Sizes[p1], size2 = Sizes[p2];
        if (size1 < size2) {
            Set[p1] = p2;
            size2 += size1;
        } else {
            Set[p2] = p1;
            size1 += size2;
        }
    }

    __GEN_STL_COMPATIBILITY(Set)

private:
    std::array<size_t, Size> Set;
    std::array<size_t, Size> Sizes;
};