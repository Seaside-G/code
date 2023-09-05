#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
const int M = 5e2 + 10;
#define all(s) s.begin(),s.end()
#define endl '\n'
void solve(){
    int n, m, p;
    cin >> n >> m >> p;
    n -= m;
    if(n<0)
        cout << 0 << endl;
    else{
        int ans = 1;
        n /= p;
        ans += n;
        cout << ans << endl;
    }
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