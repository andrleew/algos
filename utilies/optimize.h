#pragma once

#if defined(__clang__)
    #pragma clang optimize on 
#else
    #pragma GCC optimize("O3")
    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif