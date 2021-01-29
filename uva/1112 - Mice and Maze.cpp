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
int tc;
int n, e, ti, x,cnt;
vector<pair<int, int>> adj[101];
int dijkstra(int src){
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> p;
    int dis[101];
    memset(dis,oo,sizeof dis);
    dis[src]=0;
    p.push({0,src});
    while(p.size()){
        int parent=p.top().second;
        int cost=p.top().first;
        p.pop();
        if(cost>dis[parent])continue;
        for(auto child:adj[parent]){
            if(dis[child.first]>dis[parent]+child.second){
                dis[child.first]=dis[parent]+child.second;
                p.push({dis[child.first],child.first});
            }
        }
    }
    return dis[e];

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tc;
    int flag = 0;
    while (tc--)
    {
        if (flag)
            cout << endl;
        flag = 1;
        cin >> n >> e >> ti >> x;
        while (x--)
        {
            int f, t, c;
            cin >> f >> t >> c;
            adj[f].push_back({t, c});
        }
        for(int i=1;i<=n;i++){
            int ans =dijkstra(i);
            if(ans<=ti)cnt++;
        }
        cout<<cnt<<endl;
        cnt=0;
        for(int i=0;i<=n;i++)adj[i].clear();
    }
}
