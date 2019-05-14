#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    bool canWinNim(int n) 
    {
        return n % (3 + 1);
    }
};
int main()
{
    Solution AC;
    int n;
    while (cin >> n)
    {
        if (AC.canWinNim(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
/*
3
*/