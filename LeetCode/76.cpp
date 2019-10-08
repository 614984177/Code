#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        if (s.size() < t.size() || t.empty()) return "";
        const int INF = 0x3f3f3f3f;
        vector<int> dict(256, 0), window(256, 0);
        for (auto i : t) dict[i]++;
        int l = 0, r = 0, cnt = 0, MIN = INF, L = 0;
        for (auto i : dict) if (i > 0) cnt++; 
        while (r < s.size())
        {
            window[s[r]]++;
            if (window[s[r]] == dict[s[r]])
                cnt--;
            while (l <= r && cnt == 0)
            {
                if (MIN == -1 || r - l + 1 < MIN)
                {
                    MIN = r - l + 1;
                    L = l;
                }
                window[s[l]]--;
                if (window[s[l]] < dict[s[l]])
                    cnt++;
                l++;
            }
            r++;
        }
        return MIN == INF ? "" : s.substr(L, MIN);
    }
};
int main()
{
    Solution AC;
    string a, b; cin >> a >> b;
    cout << AC.minWindow(a, b) << endl;
    return 0;
}
/*
ADOBECODEBANC
ABC
*/