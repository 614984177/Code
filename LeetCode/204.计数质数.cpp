#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    vector<bool> isPrime;
    vector<int> primes;

    void getPrime1(int n) {
        isPrime = vector<bool>(n, 1);
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i < n; i++) {
            if (!isPrime[i] || (long long)i * i >= n) continue;
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    void getPrime2(int n) {
        isPrime = vector<bool>(n, 1);
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) primes.emplace_back(i);
            for (int j = 0; j < primes.size() && i * primes[j] < n; j++) {
                printf("%d %d %d\n", primes[j], i, i * primes[j]);
                isPrime[i * primes[j]] = 0;
                if (i % primes[j] == 0) break;
            }
            printf("\n");
        }
    }

    int countPrimes(int n) {
        getPrime2(n + 2);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += int(isPrime[i]);
        }
        return cnt;
    }
};
// @lc code=end

int main()
{
    Solution AC;
    int n;
    while (cin >> n) {
        cout << AC.countPrimes(n) << endl;
    }
    return 0;
}
/*
15
*/