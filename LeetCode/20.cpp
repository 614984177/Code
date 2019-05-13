#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> sta;
        for (auto& i : s)
        {
            if (i == '(' || i == '{' || i == '[') sta.push(i);
            else
            {
                if (sta.empty()) return false;
                else if (sta.top() == '(' && i == ')') sta.pop();
                else if (sta.top() == '{' && i == '}') sta.pop();
                else if (sta.top() == '[' && i == ']') sta.pop();
                else return false;
            }
        }
        return sta.empty();
    }
};
int main()
{
    Solution AC;
    string s;
    while (cin >> s)
    {
        if (AC.isValid(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
/*
()
()[]{}
(]
([)]
{[]}
*/