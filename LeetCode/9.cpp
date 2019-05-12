#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int rev = 0;
        while (x > rev)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return x == rev || x == rev / 10;
    }
};
int main()
{
    Solution AC;
    int n;
    while (~scanf("%d", &n))
    {
        printf("%s\n", AC.isPalindrome(n) ? "YES" : "NO");
    }
    return 0;
}
/*
121
-121
10
*/