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
vector<int> adj[50009];
int arr[50009];
int vis[50009];
int c;
void dfs(int src)
{
    if (!vis[src])
    {
        c++;
        vis[src] = 1;
        for (auto child : adj[src])
        {
            if (!vis[child])
                dfs(child);
        }
        vis[src] = 0;
        arr[src] = 1;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    FOR(k, 1, tc + 1)
    {

        cout << "Case " << k << ": ";
        int n;
        cin >> n;

        memset(arr, 0, sizeof arr);
        memset(vis, 0, sizeof vis);
        FOR(i, 0, n)
        {
            int f, t;
            cin >> f >> t;
            adj[f].push_back(t);
        }
        int mini = 0, ans;
        FOR(i, 1, n + 1)
        {
            c = 0;
            if (!arr[i])
            {
                dfs(i);
                if (c > mini)
                {
                    mini = c;
                    ans = i;
                }
                else if (c == mini)
                    ans = min(ans, i);
            }
        }
        cout << ans << endl;
        FOR(i, 1, n + 1)
        adj[i].clear();
    }
}
