#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int climbStairs(int n) 
    {
        int a = 0, b = 1;
        while (--n)
        {
            int c = a + b;
            a = b, b = c; 
        }
        return a + b;
    }
};
int main()
{
    Solution AC;
    int n;
    while (cin >> n)
    {
        cout << AC.climbStairs(n) << endl;
    }
    return 0;
}
/*
2
3
*/