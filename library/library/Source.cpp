#include <iostream>
#include "Header.h"
#include <stack>
using namespace std;

int main()
{
    StaticStack<int> s1(4); // Specify the capacity in the constructor

    s1.Push(4);
    s1.Push(3);
    s1.Push(2);
    s1.Push(1);

    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
    s1.pop();

    return 0;
}
