
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    vector<int> a;
    void partition(int L, int R, int &l, int &r)
    {
        int i = L, base = a[L + rand() % (R - L + 1)];
        while (i < r)
        {
            if (a[i] < base) swap(a[i], a[++l]), i++;
            else if (a[i] > base) swap(a[i], a[--r]);
            else i++;
        }
        return ;
    }
    void Sort(int L, int R)
    {
        if (L >= R) return ;
        int l = L - 1, r = R + 1;
        partition(L, R, l, r);
        Sort(L, l);
        Sort(r, R);
    }
    vector<int> sortArray(vector<int>& nums)
    {
        a = nums;
        Sort(0, a.size() - 1);
        return a;
    }
};
int main()
{
    Solution AC;
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans = AC.sortArray(a);
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    return 0;
}
/*
5
4 3 5 1 2
*/