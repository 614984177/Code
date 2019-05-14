#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        string t = "$#";
        for (int i = 0; i < s.size(); i++){ t += s[i]; t += '#'; }
        vector<int> p(t.size(), 0);
        int id = 0, MAX = 0, resLen = 0, resCenter = 0;
        for (int i = 1; i < t.size(); i++)
        {
            if (MAX > i) p[i] = min(p[2 * id - i], MAX - i);
            else p[i] = 1;
            while(t[i - p[i]] == t[i + p[i]]) p[i]++;
            if(MAX < p[i] + i)
            {
                MAX = p[i] + i;
                id = i;
            }
            if (resLen < p[i])
            {
                resLen = p[i];
                resCenter = i;
            }
        }
        return s.substr((resCenter - resLen) / 2, resLen - 1);
    }
};
int main()
{
    Solution AC;
    string s;
    while (cin >> s)
    {
        cout << AC.longestPalindrome(s) << endl;
    }
    return 0;
}
/*
babad
cbbd
*/