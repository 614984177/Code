#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        if (needle == "") return 0;
        if (haystack.size() < needle.size()) return -1; 
        for (int i = 0; i <= haystack.size() - needle.size(); i++)
        {
            bool ok = true;
            for (int j = 0; j < needle.size(); j++)
                if (haystack[i + j] != needle[j]) { ok = false; break; }
            if (ok) return i;
        }
        return -1;
    }
};
int main()
{
    Solution AC;
    string a, b;
    while (cin >> a >> b)
    {
        cout << AC.strStr(a, b) << endl;
    }
    return 0;
}
/*
hello ll
aaaaa bba
abb abaaa
*/