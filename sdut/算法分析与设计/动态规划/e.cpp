#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 2e2 + 10;
#define all(s) s.begin(), s.end()
#define endl '\n'
int a[M], mx[M][M], mn[M][M], s[M];
void solve()
{
    int n;
    cin >> n;
    memset(mn, 0x3f, sizeof(mn));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[n + i] = a[i];
    }
    for (int i = 1; i <= 2 * n; i++)
        s[i] += s[i - 1] + a[i];
    for (int sz = 1; sz <= n; sz++)
        for (int l = 1, r = l + sz - 1; r <= 2 * n; l++, r++)
        {
            if (sz == 1)
                mx[l][r] = mn[l][r] = 0;
            else
            {
                for (int k = l; k < r; k++)
                {
                    mx[l][r] = max(mx[l][r], mx[l][k] + mx[k + 1][r] + s[r] - s[l - 1]);
                    mn[l][r] = min(mn[l][r], mn[l][k] + mn[k + 1][r] + s[r] - s[l - 1]);
                }
            }
        }
    int mxx = 0, mnn = 0x3f3f3f3f;
    for (int i = 1; i <= n + 1; i++)
    {
        mxx = max(mxx, mx[i][n + i - 1]);
        mnn = min(mnn, mn[i][i + n - 1]);
    }
    cout << mnn << '\n'
         << mxx << endl;
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