#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    string multiply(string num1, string num2) 
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int lena = num1.size(), lenb = num2.size();
        string ans(lena + lenb, 0);
        for (int i = lena - 1; i >= 0; i--)
        {
            for (int j = lenb - 1; j >= 0; j--)
            {
                ans[i + j] += (num1[i] - '0') * (num2[j] - '0');
                ans[i + j + 1] += ans[i + j] / 10;
                ans[i + j] %= 10;
            }
        }
        for (int i = 0; i < lena + lenb - 1; i++) 
        {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
        for (auto &i : ans) i += '0';
        while (ans.back() == '0' && ans.size() > 1) ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution AC;
    string a, b;
    while (cin >> a >> b)
    {
        cout << AC.multiply(a, b) << endl;
    }
    return 0;
}
/*

*/