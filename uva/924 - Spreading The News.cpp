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
int n, tc, x;

int dis[2505];
vector<int> adj[2505];

void bfs(int src)
{
    memset(dis, oo, sizeof dis);
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (auto child : adj[parent])
        {
            if (dis[child] == oo)
            {
                dis[child] = dis[parent] + 1;
                q.push(child);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    FOR(i, 0, n)
    {
        cin >> tc;
        while (tc--)
        {

            cin >> x;
            adj[i].push_back(x);
        }
    }
    cin >> tc;
    while (tc--)
    {
        cin >> x;
        bfs(x);
        int arr[2505] = {0};
        for (int i = 0; i < 2500; i++)
        {
            if (dis[i] != oo)
                arr[dis[i]]++;
        }
        int d;
        int maxi = -oo;
        for (int i = 1; i <= 2500; i++)
        {
            if (arr[i] > maxi)
            {
                d = i;
                maxi = arr[i];
            }
        }
        if (maxi > 0)
            cout << maxi << " " << d << endl;
        else
            cout << 0 << endl;
    }
}
