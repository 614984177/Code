#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int reverse(int x) 
    {
        long long ans = 0;
        while (x)
        {
            int t = x % 10;
            x /= 10;
            ans = ans * 10 + t;
        }
        if (ans < INT_MIN || ans > INT_MAX) return 0;
        return static_cast<int>(ans);
    }
};
int main()
{
    Solution AC;
    int n;
    while (~scanf("%d", &n))
    {
        printf("%d\n", AC.reverse(n));
    }
    return 0;
}
/*
123
-123
120
*/