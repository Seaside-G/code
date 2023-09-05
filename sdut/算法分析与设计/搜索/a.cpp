#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int M = 5e2 + 10;
#define all(s) s.begin(), s.end()
#define endl '\n'
int n, k;
int a[N],ss[N];
bool st[N];
vector<int> ans;
void dfs(int u,int s){
    if(s>k||u==n)
        return;
    if(s+ss[u]<k)
        return;
    if(s==k){
        for(auto i:ans)
            cout << i << ' ';
        exit(0);
    }
    for (int i = 0; i < n;i++){
        if(st[i])
            continue;
        st[i] = 1;
        ans.push_back(a[i]);
        dfs(u + 1, s + a[i]);
        st[i] = 0;
        ans.pop_back();
    }
}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    for (int i = n; i >= 0;i--)
        ss[i] = ss[i + 1] + a[i];
    dfs(0, 0);
    cout << "No Solution!" << endl;
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