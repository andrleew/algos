#pragma once

#include <vector>
#include <functional>
#include <iterator>



template <typename T>
class TSegmentTree {
public:
    TSegmentTree(const std::vector<T>& buildVector)
    : Left (0)
    {
        STVector.resize(buildVector.size() * 4, 0);
        Right = buildVector.size() - 1;
        Build(buildVector, Left, Right);
    }

    void Update(size_t pos, const T& new_val) {
        _Update(pos, new_val, Left, Right);
    }

    T Get(size_t left, size_t right) const {
        return _Get(left, right, Left, Right);
    }



protected:
    inline
    virtual T Func(const T& t1, const T& t2) const {
        return t1 + t2;
    }

private:
    T& Build(const std::vector<T>& buildVector, size_t left, size_t right, size_t idx = 1) {
        if (left == right) return STVector[idx] = buildVector[left];
        else {
            size_t middle = (left + right) >> 1;
            return STVector[idx] = Func(
                    Build(buildVector, left, middle, idx * 2),
                    Build(buildVector, middle + 1, right, idx * 2 + 1));
        }
    }

    void _Update(size_t pos, const T& newVal, size_t left, size_t right, size_t idx = 1) {
        if (left == right) STVector[idx] = newVal;
        else {
            size_t middle = (left + right) >> 1;
            if (pos < middle) _Update(pos, left, middle, idx << 1, newVal);
            else _Update(pos, middle + 1, right, (idx << 1) + 1, newVal);
            STVector[idx] = Func(STVector[idx * 2], STVector[idx * 2 + 1]);
        }
    }

    T _Get (size_t l, size_t r, size_t left, size_t right, size_t idx = 1) const {
        if (l > r) return 0;
        if (left == l && right == r) return STVector[idx];
        size_t middle = (left + right) >> 1;
        return Func(_Get(l, std::min(middle, r), left, middle, idx * 2),
                    _Get(std::max(middle + 1, l), r, middle + 1, right, idx * 2 + 1));
    }


private:
    std::vector<T> STVector;
    size_t Left, Right;
};