#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int> s;
        s.push(-1);
        int MAX = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            while (s.top() != -1 && heights[i] < heights[s.top()])
            {
                int t = s.top(); s.pop();
                MAX = max(MAX, heights[t] * (i - s.top() - 1));
                
            }
            s.push(i);
        }
        while (s.top() != -1)
        {
            int t = s.top(); s.pop();
            MAX = max(MAX, heights[t] * ((int)heights.size() - s.top() - 1));
        }
        return MAX;
    }
};
int main()
{
    Solution AC;
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << AC.largestRectangleArea(a) << endl;
    return 0;
}
/*
6
2 1 5 6 2 3
*/