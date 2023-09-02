#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <set>
// #include <bits/stdc++.h>
#define endl '\n'
#define x first
#define y second
#define falg flag
#define int long long
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define dbug(x) cout << #x << '=' << x << endl;
#define Dbug(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl;
#define SugarT               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = ((int)2e5) + 10;
const int M = ((int)5e2) + 10;
const int P = 1331;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
int get(int x)
{
    if (x & 1)
        return x * 2 - 1;
    return x * 2;
}
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int dy = abs(b - d), tx1 = a, tx2 = a, tx3 = a, tx4 = a;
    int ans1 = 0, ans2 = 0;
    if (dy != 0)
    {
        ans1 = max(dy * 2 - 1, 0LL);
        tx1 = a + dy - 1;
        tx2 = a - dy + 1;
        ans2 = dy * 2;
        tx3 = a + dy;
        tx4 = a - dy;
    }
    int dx1 = abs(c - tx1);
    int dx2 = abs(c - tx2);
    int dx3 = abs(c - tx3);
    int dx4 = abs(c - tx4);
    ans1 += min(get(dx1), get(dx2));
    ans2 += min(get(dx3), get(dx4));
    int res1 = 0, res2 = 0, ty1 = b, ty2 = b, ty3 = b, ty4 = b;
    int dx = abs(a - c);
    if (dx != 0)
    {
        res1 = max(dx * 2 - 1, 0LL);
        ty1 = b + dx - 1;
        ty2 = b - dx + 1;
        res2 = dx * 2;
        ty3 = b + dx;
        ty4 = b - dx;
    }
    int dy1 = abs(d - ty1);
    int dy2 = abs(d - ty2);
    int dy3 = abs(d - ty3);
    int dy4 = abs(d - ty4);
    res1 += min(get(dy1), get(dy2));
    res2 += min(get(dy3), get(dy4));
    cout << min({res1, res2, ans1, ans2}) << endl;
}

signed main()
{
    SugarT int Tcase = 1;
    cin >> Tcase;
    while (Tcase--)
        solve();
    return 0;
}