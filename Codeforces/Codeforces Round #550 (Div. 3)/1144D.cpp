#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, a[MAXN], cnt[MAXN];
struct Node
{
    int a, b, c;
    Node (int a, int b, int c) : a(a), b(b), c(c) {}
};
int main()
{
    scanf("%d", &n);
    int pos = 0;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
        if (cnt[a[i]] > cnt[pos]) pos = a[i];
    }
    vector<Node> ans;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == pos)
        {
            int l = i - 1, r = i + 1;
            while (l >= 0 || r < n)
            {
                if (l >= 0 && a[l] != pos) 
                    ans.emplace_back(a[l] < pos ? 1 : 2, l, l + 1);
                if (r < n && a[r] != pos) 
                    ans.emplace_back(a[r] < pos ? 1 : 2, r, r - 1);  
                l--, r++;
            }
            break;
        }
    }
    printf("%d\n", ans.size());
    for (auto i : ans) printf("%d %d %d\n", i.a, i.b + 1, i.c + 1);
    return 0;
}
/*
5
2 4 6 6 6
*/