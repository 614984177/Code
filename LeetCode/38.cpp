#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    string countAndSay(int n) 
    {
        string ans = "1";
        while (--n)
        {
            int cnt = 1, num = ans[0] - '0';
            string cur;
            for (int i = 1; i < ans.size(); i++)
            {
                if (ans[i] != ans[i - 1]) 
                {
                    cur += to_string(cnt) + to_string(num);
                    cnt = 1, num = ans[i] - '0';
                }
                else cnt++;
            }
            cur += to_string(cnt) + to_string(num);
            ans = cur;
        }
        return ans;
    }
};
int main()
{
    Solution AC;
    int n;
    while (cin >> n)
    {
        cout << AC.countAndSay(n) << endl;
    }
    return 0;
}
/*
1
4
*/