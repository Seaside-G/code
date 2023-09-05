#include <bits/stdc++.h>
using namespace std;
int cnt[100010];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        cnt[t]++;
    }
    int ans = 0, mx = 0;
    for (int i = 0; i < 1e5; i++)
    {
        if (mx < cnt[i])
        {
            mx = cnt[i];
            ans = i;
        }
    }
    cout << ans << '\n'
         << mx << '\n';
}