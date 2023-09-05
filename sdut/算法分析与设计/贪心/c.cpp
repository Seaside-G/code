#include <bits/stdc++.h>
using namespace std;
const int N = 1e1 + 10;
const int M = 5e2 + 10;
#define all(s) s.begin(),s.end()
#define endl '\n'
struct node{
    int w, p;
} p[N];
bool cmp(node a,node b){
    return a.p > b.p;
}
void solve(){
    int m;
    cin >> m;
    int ans = 0;
    for (int i = 0; i < 10;i++){
        int a, b;
        cin >> a >> b;
        p[i].w = b;
        p[i].p = a / b;
    }
    sort(p, p + 10, cmp);
    for (int i = 0; i < 10&&m;i++){
        int d = min(p[i].w, m);
        m -= d;
        ans += d * p[i].p;
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