#include "Eratosphen.h"

#include <cstring>

const size_t PAGE = 4096 ;

inline void clear_array(std::vector<char>& arr) {
    std::fill(arr.begin(), arr.end(), 0);
}

std::vector<size_t> Eratosphen(size_t n, size_t page_count = 1) {
    std::vector<size_t> primes;
    std::vector<char> block(PAGE * page_count, false);
    clear_array(block);
    for (size_t i = 2, k = 0; i <= n; ++i, ++k) {
        if (k < PAGE) {
            if (!block[k]) {
                primes.push_back(i);
                if (i * i <= n) {
                    for (size_t j = i*i - (i - k); j <= n && j < PAGE; j += i) {
                        block[j] = true;
                    }
                }
            }
        } else {
            clear_array(block);
            for (const auto& p : primes) {
                for (size_t j = p - (i % p); j < PAGE && i + j <= n; j += p) {
                    block[j] = true;
                }
            }
            k = 0;
        }
    }
    return primes;
}