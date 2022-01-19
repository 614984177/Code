#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        s = " " + s + " ";
        int r = 0;
        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i + 1] == ' ' && s[i] != ' ') {
                r = i;
            }
            if (r != 0 && s[i] == ' ') {
                return r - i;
            }
        }
        return 0;
    }
};
// @lc code=end

int main()
{
    Solution AC;
    string s;
    while (getline(cin, s)){
        cout << AC.lengthOfLastWord(s) << endl;
    }
    return 0;
}
/*
Hello World
   fly me   to   the moon  
luffy is still joyboy
Today is a nice day
*/