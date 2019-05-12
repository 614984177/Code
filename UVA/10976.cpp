#include <bits/stdc++.h>
using namespace std;
int MAXN = 1e5 + 5;
int k;
int main()
{
    while (scanf("%d", &k) != EOF)
    {
        vector<pair<int, int>> v;
        for (int x = k + 1; x <= 2 * k; x++)
        {
            if (k * x % (x - k) == 0)
            {
                v.emplace_back(x, k * x / (x - k));
            }
        }
        sort(v.begin(), v.end());
        printf("%d\n", v.size());
        for (auto i : v) printf("1/%d = 1/%d + 1/%d\n", k, i.second, i.first);
    }
    return 0;
}