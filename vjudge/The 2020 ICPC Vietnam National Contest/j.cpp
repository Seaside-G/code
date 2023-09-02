#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("abm,avx,mmx,popcnt,sse,sse2,sse3,ssse3,sse4")
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <array>
// #include <bitsdc++.h>
#define endl '\n'
#define x first
#define y second
#define falg flag
#define whlie while
// #define int long long
#define PI acos(-1)
#define ARR array<int, 3>
#define all(s) s.begin(), s.end()
#define dbug(x) cout << #x << '=' << x << endl
#define Dbug(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define JK                   \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
// typedef __int128 i128;
typedef pair<int, int> pii;

const int N = ((int)10) + 10;
const int M = ((int)5e2) + 10;
const int P = 1331;
const int INF = 0x3f3f3f3f;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
int h[N], n, a[N];
ll ans;
// set<int> s;
void dfs(int u, int v)
{
    if (u == n + 1 || v == 0)
    {
        // s.clear();
        ll res = 0;
        for (int i = 1; i <= n; i++)
            a[i] = h[i];
        vector<int> lh(n + 3), rh(n + 3);
        for (int i = 1; i <= n; i++)
            lh[i] = max(lh[i - 1], a[i]);
        for (int i = n; i >= 1; i--)
            rh[i] = max(rh[i + 1], a[i]);
        int maxv = 0;
        int hd;
        for (int i = 1; i <= n; i++)
        {
            if (maxv < a[i])
            {
                maxv = a[i];
                hd = i;
            }
        }
        for (int i = hd - 1; i >= 1; i--)
        {
            res += 1LL * lh[i] - a[i];
        }
        for (int i = hd + 1; i <= n; i++)
        {
            res += 1LL * rh[i] - a[i];
        }
        ans = max(ans, res);
        return;
    }
    int res = h[u];
    for (int i = 0; i <= v; i++)
    {
        h[u] += i;
        dfs(u + 1, v - i);
        h[u] = res;
    }
}
void solve()
{
    int k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    dfs(1, k);
    cout << ans << '\n';
}

signed main()
{
    JK int Tcase = 1;
    // cin >> Tcase;
    while (Tcase--)
        solve();
    return 0;
}
