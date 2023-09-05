#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 5e2 + 10;
#define all(s) s.begin(), s.end()
#define endl '\n'
int mp[110][110];
void insert(int x1, int yy, int x2, int y2, int c)
{
    mp[x1][yy] += c;
    mp[x1][y2 + 1] -= c;
    mp[x2 + 1][yy] -= c;
    mp[x2 + 1][y2 + 1] += c;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        insert(a + 1, c + 1, b, d, 1);
    }
    for (int i = 1; i <= 105; i++)
        for (int j = 1; j <= 105; j++)
            mp[i][j] += mp[i - 1][j] + mp[i][j - 1] - mp[i - 1][j - 1];
    int sum = 0;
    for (int i = 1; i <= 105; i++)
    {
        for (int j = 1; j <= 105; j++)
        {
            if (mp[i][j] > 0)
                sum++;
        }
    }
    cout << sum << endl;
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