#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    string reverseWords(string s) 
    {
        string ans;
        stringstream ss(s);
        while (ss >> s) 
        {
            reverse(s.begin(), s.end());
            if (ans != "") ans += " ";
            ans += s;
        }
        return ans;
    }
};
int main()
{
    Solution AC;
    string s;
    while (getline(cin, s))
    {
        cout << AC.reverseWords(s) << endl;
    }
    return 0;
}
/*
Let's take LeetCode contest
*/