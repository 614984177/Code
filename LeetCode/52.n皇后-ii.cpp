#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    unordered_set<int> col, d1, d2;
    int ans;
    
    int totalNQueens(int n) {
        ans = 0;
        dfs(n, 0);
        return ans;
    }

    void dfs(const int &n, int row) {
        if (row == n) {
            ans++;
            return ;
        }
        
        for (int i = 0; i < n; i++) {
            int x = row - i, y = row + i;
            if (col.count(i)) continue;            
            if (d1.count(x)) continue;
            if (d2.count(y)) continue;
            col.insert(i);
            d1.insert(x);
            d2.insert(y);
            dfs(n, row + 1);
            col.erase(i);
            d1.erase(x);
            d2.erase(y);
        }
    }
};
// @lc code=end

int main()
{
    Solution AC;
    int n;
    while (cin >> n) {
        cout << AC.totalNQueens(n) << endl;
    }
    return 0;
}
/*
4
*/