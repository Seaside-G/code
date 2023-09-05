#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
const int M = 5e2 + 10;
#define all(s) s.begin(), s.end()
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> p;
    priority_queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        p.push(t);
        q.push(t);
    }
    int a = 0, b = 0;
    while (q.size() > 1)
    {
        int t = q.top();
        q.pop();
        t += q.top();
        q.pop();
        a += t;
        q.push(t);
    }
    cout << a << ' ';
    while(p.size()%(k-1)!=1)
        p.push(0);
    while (p.size() > 1)
    {
        int sum = 0;
        for (int i = 0; i < k && p.size(); i++)
        {
            int t = p.top();
            p.pop();
            sum += t;
        }
        b += sum;
        p.push(sum);
    }
    cout << b << '\n';
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