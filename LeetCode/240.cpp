#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if (matrix.empty()) return false;
        int n = matrix.size(), m = matrix[0].size();
        int i = n - 1, j = 0;
        while (i >= 0 && j < m)
        {
            if (matrix[i][j] < target) j++;
            else if (matrix[i][j] > target) i--;
            else return true;
        }
        return false;
    }
};
int main()
{
    Solution AC;
    int n, m, key;
    while (cin >> n >> m >> key)
    {
        vector<vector<int>> matrix;
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < m; j++)
            {
                int x; cin >> x;
                tmp.emplace_back(x);
            }
            matrix.emplace_back(tmp);
        }
        cout << AC.searchMatrix(matrix, key) << endl;
    }
    return 0;
}
/*
5 5 5
1   4  7 11 15
2   5  8 12 19
3   6  9 16 22
10 13 14 17 24
18 21 23 26 30
*/