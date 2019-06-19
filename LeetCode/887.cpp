#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int superEggDrop(int K, int N) 
    {
        vector<int> dp(K + 1, 0);
        for (int i = 1; i <= N; ++i)
        {
            for (int j = K; j >= 1; --j)
            {
                // dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + 1;
                dp[j] = dp[j] + dp[j - 1] + 1;
                if (dp[j] >= N) return i;
            }
        }
        return N;
    }
};
int main()
{
    Solution AC;
    int n, k;
    while (cin >> k >> n)
    {
        cout << AC.superEggDrop(k, n) << endl;
    }
    return 0;
}
/*
1 2
2 6
3 14
*/