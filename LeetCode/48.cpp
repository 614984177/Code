#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};
class Solution2
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < (n + 1) / 2; j++)
            {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = t;
            }
        }
    }
};
int main()
{
    Solution2 AC;
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    AC.rotate(a);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
3
1 2 3
4 5 6
7 8 9
*/