#include <iostream>

#include "data_structures/dsu.h"
#include "utilies/log.h"
#include "reader/parcer.h"
#include "utilies/optimize.h"

using namespace std;

int main () {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int v, b = 0;
    while (ReadInt(v)) {
        ++b;
    }
    cout << b << "\n";
    
    return 0;
}