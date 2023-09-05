#pragma GCC optimize(2)

#include <bits/stdc++.h>
using namespace std;
const int N = 20;
#define all(s) s.begin(),s.end()
#define endl '\n'
vector<pair<int, int>> mp[N];
long long ans = 0,ss[10];
bool st[N];
int n, mx = 0;
void dfs(int d,long long s){
    if(s+ss[(n-d)/2]<=ans)
        return;
    if(d+2>n){
        ans = max(ans, s);
        return;
    }
    for (int i = 1; i < n;i++){
        if(st[i])
            continue;
        for(auto [w,v]:mp[i]){
            if(st[v])
                continue;
            st[i] = st[v] = 1;
            dfs(d + 2, s + w);
            st[i] = st[v] = 0;
        }
    }
}
void solve(){
    cin >> n;
    priority_queue<int> q;
    for (int i = 1; i < n;i++){
        for (int j = i + 1; j <= n;j++){
            int t;
            cin >> t;
            q.push(t);
            mp[i].emplace_back(t,j);
        }
        sort(all(mp[i]), greater<pair<int, int>>());
    }
    int t = n / 2;
    for (int i = 1; i <= t;i++){
        ss[i] = q.top();
        q.pop();
        ss[i] += ss[i - 1];
    }
    dfs(0, 0);
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