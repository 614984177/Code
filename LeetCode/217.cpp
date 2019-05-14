#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> s;
        for (auto i : nums)
        {
            if (s.count(i)) return true;
            s.emplace(i);
        }
        return false;
    }
};
int main()
{
    Solution AC;
    int n;
    while (cin >> n)
    {
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) cin >> v[i];
        if (AC.containsDuplicate(v)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
/*
4
1 2 3 1
4
1 2 3 4
10
1 1 1 3 3 4 3 2 4 2
*/