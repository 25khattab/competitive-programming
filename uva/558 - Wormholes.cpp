#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define FOR(i, s, e) for (int i = s; i < e; i++)
#define ROF(i, s, e) for (int i = e - 1; i >= s; i--)
#define mk(x, y) make_pair(x, y)
int const sz = 2e5;
const int oo = 0x3f3f3f3f;
const double EPS = 1e-6;
ll const MOD = 1e9 + 7;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
int tc, n, m;
vector<pair<pair<int, int>, int>> edges;
void solve()
{
    int dist[n + 2];
    for (int i = 1; i <= n; i++)
        dist[i] = oo;
    dist[1] = 0;
    for (int i = 1; i < n; i++)
    {
        bool update = false;
        for (auto edge : edges)
        {
            int f = edge.first.first, t = edge.first.second, w = edge.second;
            if (dist[f] + w < dist[t])
            {
                dist[t] = dist[f] + w;
                update = true;
            }
        }
        if (!update)
            break;
    }
    for (auto edge : edges)
    {
        int f = edge.first.first, t = edge.first.second, w = edge.second;
        if (dist[f] + w < dist[t])
        {
            cout << "possible\n";

            return;
        }
    }
    cout << "not possible\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            int t, f, w;
            cin >> f >> t >> w;
            edges.push_back({{f, t}, w});
        }
        solve();
        edges.clear();
    }
}
