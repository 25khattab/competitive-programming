#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define FOR(i, s, e) for (int i = s; i < e; i++)
#define ROF(i, s, e) for (int i = e - 1; i >= s; i--)
#define mk(x, y) make_pair(x, y)
int const sz = 2e5;
int const oo = 1e9;
const double EPS = 1e-6;
ll const MOD = 1e9 + 7;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
int n, t, cnt, x, src, flag;
vector<int> lis[sz];
 vector<int> ans;
int vis[sz];
void dfs(int v)
{
    if (flag )
        vis[v] = 1;
    flag = 1;
    for (auto ch : lis[v])
    {
        if (!vis[ch])
            dfs(ch);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n, n)
    {
        FOR(i, 0, n + 1)
        lis[i].clear();
        int v;
        while (cin >> v, v)
        {
            int e;
            while (cin >> e, e)
                lis[v].push_back(e);
        }
        cin >> t;
        while (t--)
        {
            memset(vis, 0, sizeof vis);
            int v;
            cin >> v;
            src = v;
            flag = 0;
            cnt = 0;
            dfs(v);

           ans.clear();
            FOR(i, 1, n + 1)
            {
                if (!vis[i])
                    ans.push_back(i);
            }
            if (ans.size())
            {
                cout << ans.size();
                FOR(i, 0, ans.size())
                    cout << " " << ans[i];
                cout << endl;
            }
            else
                cout << 0 << endl;
        }
    }
}
