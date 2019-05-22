#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        return KthSort(nums, k - 1, 0, nums.size() - 1);
    }
private:
    void partition(vector<int> &a, int l, int r, int base, int &L, int &R)
    {
        int i = l;
        while (i < R)
        {
            if (a[i] > base) swap(a[++L], a[i]), i++;
            else if (a[i] < base) swap(a[--R], a[i]);
            else i++;
        }
    }
    int KthSort(vector<int> &a, int k, int l, int r)
    {
        if (l > r) return -1;
        int base = a[l + rand() % (r - l + 1)];
        int L = l - 1, R = r + 1;
        partition(a, l, r, base, L, R);
        if (L < k && k < R) return a[k];
        if (L >= k) return KthSort(a, k, l, L);
        return KthSort(a, k, R, r);
    }
};
int main()
{
    Solution AC;
    int n, k;
    while (cin >> n >> k)
    {
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << AC.findKthLargest(a, k) << endl;
    }
    return 0;
}
/*
6 2
3 2 1 5 6 4
*/