#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int ans = 0;
        for (auto i : nums) ans ^= i;
        return ans;
    }
};
int main()
{
    Solution AC;
    int n;
    while (cin >> n)
    {
        vector<int> a;
        for (int i = 1; i <= n; i++)
        {
            int x; scanf("%d", &x);
            a.emplace_back(x);
        }
        cout << AC.singleNumber(a) << endl;
    }
    return 0;
}
/*
3
2 2 1
5
4 1 2 1 2
*/