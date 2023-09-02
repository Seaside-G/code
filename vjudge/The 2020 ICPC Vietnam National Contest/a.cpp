#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <set>
// #include <bits/stdc++.h>
#define endl '\n'
#define x first
#define y second
#define falg flag
// #define int long long
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define dbug(x) cout << #x << '=' << x << endl;
#define Dbug(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl;
#define SugarT               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = ((int)2e5) + 10;
const int M = ((int)5e2) + 10;
const int P = 1331;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

map<string, int> mp;

void solve()
{
    mp["Mar"] = 3;
    mp["Apr"] = 4;
    mp["May"] = 5;
    mp["Jun"] = 6;
    mp["Jul"] = 7;
    mp["Aug"] = 8;
    mp["Sep"] = 9;
    mp["Oct"] = 10;
    mp["Nov"] = 11;
    mp["Dec"] = 12;
    mp["Jan"] = 1;
    mp["Feb"] = 2;
    int k;
    cin >> k;
    string s;
    cin >> s;
    int yue = mp[s];
    // cout << yue << endl;
    if ((yue == 3 && k >= 21) || (yue == 4 && k <= 20))
        cout << "Aries" << endl;
    else if ((yue == 4 && k >= 21) || (yue == 5 && k <= 20))
        cout << "Taurus" << endl;
    else if ((yue == 5 && k >= 21) || (yue == 6 && k <= 21))
        cout << "Gemini" << endl;
    else if ((yue == 6 && k >= 22) || (yue == 7 && k <= 22))
        cout << "Cancer" << endl;
    else if ((yue == 7 && k >= 23) || (yue == 8 && k <= 22))
        cout << "Leo" << endl;
    else if ((yue == 8 && k >= 23) || (yue == 9 && k <= 21))
        cout << "Virgo" << endl;
    else if ((yue == 9 && k >= 22) || (yue == 10 && k <= 22))
        cout << "Libra" << endl;
    else if ((yue == 10 && k >= 23) || (yue == 11 && k <= 22))
        cout << "Scorpio" << endl;
    else if ((yue == 11 && k >= 23) || (yue == 12 && k <= 21))
        cout << "Sagittarius" << endl;
    else if ((yue == 12 && k >= 22) || (yue == 1 && k <= 20))
        cout << "Capricorn" << endl;
    else if ((yue == 1 && k >= 21) || (yue == 2 && k <= 19))
        cout << "Aquarius" << endl;
    else if ((yue == 2 && k >= 20) || (yue == 3 && k <= 20))
        cout << "Pisces" << endl;
}

int main()
{
    SugarT int Tcase = 1;
    cin >> Tcase;
    while (Tcase--)
        solve();
    return 0;
}