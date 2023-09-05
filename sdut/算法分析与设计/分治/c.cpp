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
// #include <bits/stdc++.h>
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

const int N = ((int)2e5) + 10;
const int M = ((int)5e2) + 10;
const int P = 1331;
const int INF = 0x3f3f3f3f;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
int cnt, a[N];
int get(int l, int r)
{
    cnt++;
    if (l == r)
        return max(0, a[l]);
    else
    {
        int mid = l + r >> 1;
        int ll = get(l, mid);
        int rr = get(mid + 1, r);
        int mx = 0, sum = 0;
        for (int i = l; i <= r; i++)
        {
            if (sum + a[i] <= 0)
                sum = 0;
            else
            {
                sum += a[i];
                mx = max(mx, sum);
            }
        }
        mx = max({mx, ll, rr});
        return mx;
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << get(1, n) << ' ' << cnt << endl;
}

signed main()
{
    JK int Tcase = 1;
    // cin >> Tcase;
    while (Tcase--)
        solve();
    return 0;
}