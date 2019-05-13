#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++)
            ans += (prices[i] - prices[i - 1] > 0 ? prices[i] - prices[i - 1] : 0);
        return ans;
    }
};
int main()
{
    Solution AC;
    int n;
    while (cin >> n)
    {
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        cout << AC.maxProfit(a) << endl; 
    }
    return 0;
}
/*
6
7 1 5 3 6 4
5
1 2 3 4 5
5
7 6 4 3 1
*/