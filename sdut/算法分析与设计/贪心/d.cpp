#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 1e2 + 10;
#define all(s) s.begin(), s.end()
#define endl '\n'
struct node
{
    int l, r, id;
} p[M];
bool cmp(node a, node b)
{
    if (a.r == b.r)
    {
        return a.id < b.id;
    }
    return a.r < b.r;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].l >> p[i].r;
        p[i].id = i;
    }
    sort(p, p + n, cmp);
    vector<int> ans;
    ans.push_back(p[0].id + 1);
    int r = p[0].r;
    for (int i = 1; i < n; i++)
    {
        if (p[i].l >= r)
        {
            ans.push_back(p[i].id + 1);
            r = max(r, p[i].r);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (i)
            cout << "," << ans[i];
        else
            cout << ans[i];
    }
}
signed main()
{
    int _ = 1;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // cin>>_;
    while (_--)
        solve();
    return 0;
}