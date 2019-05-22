#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int myAtoi(string str) 
    {
        int sign = 1, i = 0, res = 0;
        while (i < str.size() && str[i] == ' ') i++;
        if (str[i] == '+') sign = 1, i++;
        else if (str[i] == '-') sign = -1, i++;
        while (i < str.size() && isdigit(str[i]))
        {
            int x = sign * (str[i] - '0');
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && x > 7)) return INT_MAX;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && x < -8)) return INT_MIN;
            res = res * 10 + x;
            i++;
        }
        return res;
    }
};
int main()
{
    Solution AC;
    string s;
    while (getline(cin, s))
    {
        printf("%d\n", AC.myAtoi(s));
    }
    return 0;
}
/*
42
   -42
4193 with words
words and 987
-91283472332
*/