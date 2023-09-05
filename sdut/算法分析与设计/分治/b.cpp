#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int, int> mp;
int dfs(int x)
{
    if (mp.count(x))
        return mp[x];
    int res = 1;
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            if (i * i == x)
                res += dfs(i);
            else
                res += dfs(i) + dfs(x / i);
        }
    }
    mp[x] = res;
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    cout << dfs(n) << '\n';
}