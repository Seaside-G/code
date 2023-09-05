#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 5e2 + 10;
#define all(s) s.begin(),s.end()
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 0, now = n;
    for (int i = 0; i < k + 1; i++)
    {
        int t;
        cin >> t;
        if (t > n)
        {
            cout << "No Solution!" << endl;
            return;
        }
        if (now >= t)
            now -= t;
        else
        {
            now = n - t;
            ans++;
        }
    }
    cout << ans << endl;
}
signed main(){
    int _=1;
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    //cin>>_;
    while(_--)
        solve();
    return 0;
}