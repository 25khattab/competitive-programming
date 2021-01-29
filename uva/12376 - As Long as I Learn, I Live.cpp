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
int n, e;
int node = 0;
priority_queue<pair<int, int>> adj[110];
int traverse(int src)
{
    if (adj[src].empty())
    {
        node = src;
        return 0;
    }
    return traverse(adj[src].top().second) + adj[src].top().first;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    FOR(tc,1,t+1)
    {
        
        cout<<"Case "<<tc<<": ";
        cin >> n >> e;
        FOR(i,0,n){
            while(adj[i].size())adj[i].pop();
        }
        int cost[n];
        FOR(i, 0, n)
        cin >> cost[i];
        FOR(i, 0, e)
        {
            int f, to;
            cin >> f >> to;
            adj[f].push({cost[to], to});
        }
        int sum = 0;
        node = 0;
        cout <<traverse(0)<<" " <<node << endl;
        // FOR(i, 0, n)
        // {
        //     while (adj[i].size())
        //     {
        //         auto it = adj[i].top();
        //         cout << it.first << " " << it.second << endl;
        //         adj[i].pop();
        //     }
        // }
    }
}
