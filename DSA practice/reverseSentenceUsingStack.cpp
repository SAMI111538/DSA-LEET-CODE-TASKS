#include <iostream>
#include <stack>
using namespace std;

void reverseSentence(string s)
{
    stack<string> st;
    for(int idx = 0; idx < s.length(); idx++) // Initialize idx and fix condition
    {
        string word="";
        while(s[idx] != ' ' && idx < s.length()) // Fix condition here as well
        {
            word += s[idx];
            idx++;
        }
        st.push(word);
    }

    while(!st.empty())
    {
        cout << st.top() << " "; // Modify to print without a new line
        st.pop();
    }
    cout << endl;
}

int main()
{
    string s = "Hey, what are you doing!";
    reverseSentence(s);
    
    return 0;
}