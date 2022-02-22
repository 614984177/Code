#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    unordered_set<int> col, d1, d2;
    vector<int> queens;
    vector<vector<string>> ans;
    
    vector<vector<string>> solveNQueens(int n) {
        queens = vector<int>(n, -1);
        dfs(n, 0);
        return ans;
    }

    void dfs(const int &n, int row) {
        if (row == n) {
            vector<string> v;
            for (int i = 0; i < n; i ++) {
                string s = string(n, '.');
                if (queens[i] != -1) s[queens[i]] = 'Q';
                v.emplace_back(s);
            }
            ans.emplace_back(v);
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
            queens[row] = i;
            dfs(n, row + 1);
            col.erase(i);
            d1.erase(x);
            d2.erase(y);
            queens[row] = -1;
        }
    }
};
// @lc code=end

int main()
{
    Solution AC;
    int n;
    while (cin >> n) {
        vector<vector<string>> ans = AC.solveNQueens(n);
        for (auto i: ans) {
            for (auto j: i) {
                cout << j << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
/*
4
*/