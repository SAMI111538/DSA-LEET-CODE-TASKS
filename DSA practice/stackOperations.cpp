#include <iostream>
using namespace std;
#define n 100

class Stack
{
    int *arr; // Declare arr as a pointer to int
    int top;

public:
    Stack()
    {
        arr = new int[n]; // Allocate memory for the array
        top = -1; // Initialize top 
    }

        void push(int x)
        {
            if(top == n-1)
            {
                cout<<"Stack Overflow!";
            }
            top++;
            arr[top] = x;
        }
        void pop()
        {
            if(top==-1)
            {
                cout<<"no element to pop!"<<endl;
            }
            top--;
        }
        int Top()
        {
            if(top==-1)
            {
                cout<<"stack is empty!"<<endl;
                return -1;
            }
            return arr[top];
        }

        bool empty()
        {
            return top==-1;
        }
    
};


int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.empty();
    
    return 0;
}