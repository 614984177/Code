#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
//DFS
class Solution
{
private:
    vector<int> candidates;
    int target;
    vector<vector<int>> ans;
    vector<int> a;

public:
    void dfs(int cur, int sum)
    {
        if (sum == target)
        {
            ans.emplace_back(a);
            return;
        }
        for (int i = cur; i < candidates.size(); i++)
        {
            if (sum + candidates[i] > target)
                continue;
            a.emplace_back(candidates[i]);
            dfs(i, sum + candidates[i]);
            a.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        this->candidates = candidates;
        this->target = target;
        sort(candidates.begin(), candidates.end());
        dfs(0, 0);
        return ans;
    }
};

//DP递推
class Solution2
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res[target + 1];
        for (int i = candidates[0]; i <= target; i++)
        {
            for (auto it : candidates)
            {
                if (i == it)
                    res[i].emplace_back(vector<int>{it});
                if (i > it)
                {
                    for (auto j : res[i - it])
                    {
                        if (it < j.back()) break;
                        j.emplace_back(it);
                        res[i].emplace_back(j);
                    }
                }
            }
        }
        return res[target];
    }
};

int main()
{
    Solution2 AC;
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> ans = AC.combinationSum(a, k);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
4 7
2 3 6 7
*/