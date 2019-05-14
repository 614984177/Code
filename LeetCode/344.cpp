#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    void reverseString(vector<char>& s) 
    {
        for (int i = 0; i < s.size() / 2; i++)
            swap(s[i], s[s.size() - i - 1]);
    }
};
int main()
{
    Solution AC;
    int n;
    while (cin >> n)
    {
        vector<char> a(n, '\0');
        for (int i = 0; i < n; i++) cin >> a[i];
        AC.reverseString(a);
        for (auto i : a) cout << i;
        cout << endl;
    }
    return 0;
}
/*
5
hello
6
Hannah
*/