#pragma once

#include <iostream>

#define LOG(message) do { \
    std::cout << __FILE__ << ": " << __LINE__ << " <<< " << message << "\n"; \
} while (0);
