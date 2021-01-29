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
ll const MOD = 1e9 + 7;
struct ans
{
    int x;
};
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

vector<pair<int, int>> adj[sz];
int n, m, s, t;
int dijkstra(int src, int dis)
{

     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int d[sz];
    memset(d, oo, sizeof d);
    d[src] = 0;
    q.push({d[src], src});
    while (!q.empty())
    {
        auto it = q.top();
        q.pop();
        for (auto child : adj[it.second])
        {
            int v=child.first;
            int w=child.second;
           // cout<<v<<" "<<w<<endl;
            if(d[v]>d[it.second]+w){
                d[v]=d[it.second]+w;
                q.push({d[v],v});
            }
        }
    }
    return d[dis];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
    
        cin >> n >> m >> s >> t;
        FOR(i,0,n+1)adj[i].clear();
        while (m--)
        {
            int from, to, w;
            cin>>from>>to>>w;
            adj[from].push_back({to, w});
            adj[to].push_back({from, w});
        }
        int ans=dijkstra(s, t);
        cout << "Case #" << i << ": " ;  
        if(ans==oo)
        cout<<"unreachable" << endl;
        else cout<<ans<<endl;
    }
}