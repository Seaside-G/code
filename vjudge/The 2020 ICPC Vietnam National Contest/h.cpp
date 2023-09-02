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
#define int long long
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

const int N = ((int)1e5) + 10;
const int M = ((int)5e2) + 10;
const int P = 1331;
const int INF = 0x3f3f3f3f;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
int a[N];
string s[N];
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> cnt(60, vector<int>(26));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m, idx = 0;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string t;
        cin >> t;
        int sz = t.size();
        if (sz == n)
            s[idx++] = t;
        cnt[sz][t[0] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < idx; i++)
    {
        cnt[n][s[i][0] - 'a']--;
        int res = 1;
        for (int j = 0; j < n; j++)
        {
            if (cnt[a[j]][s[i][j] - 'a'] > 0)
                (res *= cnt[a[j]][s[i][j] - 'a']) %= mod;
            else
                res = 0;
            cnt[a[j]][s[i][j] - 'a']--;
        }
        for (int j = 0; j < n; j++)
            cnt[a[j]][s[i][j] - 'a']++;
        ans = (ans + res) % mod;
        cnt[n][s[i][0] - 'a']++;
    }
    cout << ans << endl;
}

signed main()
{
    JK int Tcase = 1;
    cin >> Tcase;
    while (Tcase--)
        solve();
    return 0;
}