#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int prefixEvaluation(string s)
{
    stack<int> st;
    for (int idx = s.length() - 1; idx >= 0; idx--)
    {
        if (s[idx] >= '0' && s[idx] <= '9')
        {
            st.push(s[idx] - '0');//s[idx] - '0' calculates the numerical value of the digit character
        }
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[idx])
            {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                case '^':
                    st.push(pow(op1, op2));
                    break;
            }
        }
    }
    return st.top();
}

int main()
{
    string expression = "-+7*45+20";
    cout << "Result: " << prefixEvaluation(expression) << endl;
    return 0;
}
