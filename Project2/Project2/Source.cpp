#include <iostream>
#include "Header.h"
using namespace std;
int main() {
    AutoGrowingArray<int> arr;
    for (int i = 0; i < 15; i++) {
        arr.PushBack(i);
    }

    cout << arr << std::endl;
    return 0;
}
