#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool fr = false, fc = false;
        for (int i = 0; i < m; i++)
            if (!matrix[0][i]) fr = true;
        for (int i = 0; i < n; i++)
            if (!matrix[i][0]) fc = true;
        printf("%d %d\n", fc, fr);
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (!matrix[i][j])
                    matrix[i][0] = matrix[0][j] = 0;
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (!matrix[i][0] || !matrix[0][j])
                    matrix[i][j] = 0;
        if (fr)
            for (int i = 0; i < m; i++) matrix[0][i] = 0;
        if (fc)
            for (int i = 0; i < n; i++) matrix[i][0] = 0;
    }
};
// @lc code=end

int main()
{
    Solution AC;
    int n, m;
    while (cin >> n >> m)
    {
        vector<vector<int>> a(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        AC.setZeroes(a);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
            
    }
    return 0;
}
/*
3 3
1 1 1
1 0 1
1 1 1
*/


