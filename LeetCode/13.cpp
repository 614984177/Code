#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int romanToInt(string s) 
    {
        int ans = 0;
        if (s.find("IV") != string::npos) ans += 4, s.erase(s.find("IV"), 2);
        if (s.find("IX") != string::npos) ans += 9, s.erase(s.find("IX"), 2);
        if (s.find("XL") != string::npos) ans += 40, s.erase(s.find("XL"), 2);
        if (s.find("XC") != string::npos) ans += 90, s.erase(s.find("XC"), 2);
        if (s.find("CD") != string::npos) ans += 400, s.erase(s.find("CD"), 2);
        if (s.find("CM") != string::npos) ans += 900, s.erase(s.find("CM"), 2);
        unordered_map<char, int> mp;
        mp.emplace('I', 1), mp.emplace('V', 5), mp.emplace('X', 10);
        mp.emplace('L', 50), mp.emplace('C', 100); mp.emplace('D', 500); mp.emplace('M', 1000);
        for (auto& i : s) ans += mp.at(i);
        return ans;
    }
};
int main()
{
    Solution AC;
    string str;
    while (cin >> str)
    {
        cout << AC.romanToInt(str) << endl;
    }
    return 0;
}
/*
III
IV
IX
LVIII
MCMXCIV
*/