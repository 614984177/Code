#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    bool isPowerOfTwo(int n) 
    {
        return (n > 0) && !(n & (n - 1));
    }
};
int main()
{
    Solution AC;
    int n;
    while (cin >> n)
    {
        if (AC.isPowerOfTwo(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
/*
1
16
218
*/