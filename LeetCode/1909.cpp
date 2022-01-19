#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, pre = nums[0];
        for (int i = 1; i < n; i++){
            if (pre >= nums[i]) {
                cnt++;
            } else {
                pre = nums[i];
            }   
        }
        return cnt <= 1;
    }
};
int main()
{
    Solution AC;
    int n;
    while (~scanf("%d", &n))
    {
        vector<int> a;
        while (n--)
        {
            int x; scanf("%d", &x);
            a.emplace_back(x);
        }
        bool ans = AC.canBeIncreasing(a);
        printf("%s\n", ans?"true":"false");
    }
    return 0;
}
/*
4
2 3 1 2
5
1 2 10 5 7
6
1 2 3 1 2 3
*/
