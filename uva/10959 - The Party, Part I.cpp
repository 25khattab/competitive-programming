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
int r, c;
int arr[1001][1001];
int dis[1001];
int dx[] = {-1, 0, 1, 0}; //up - right - down- left
int dy[] = {0, 1, 0, -1};
queue<int> q;
int tc;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tc;
    int flag=1;
    while (tc--)
    {
        if(!flag){cout<<endl;}
        flag=0;
        int n, e;
        cin >> n >> e;
        while (e--)
        {
            int f, t;
            cin >> f >> t;
            arr[f][t] = 1;
            arr[t][f] = 1;
        }
        memset(dis, oo, sizeof dis);
        dis[0] = 0;
        q.push(0);
        while (!q.empty())
        {
            int parent = q.front();
            q.pop();
            FOR(i, 0, n)
            {
                if(arr[parent][i]){
                    if(dis[i]==oo){
                        dis[i]=dis[parent]+1;
                        q.push(i);
                    }
                }
            }
        }

        // FOR(i, 0, r)
        // {
        //     FOR(j, 0, c)
        //     {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // cout<<ex<<" "<<ey<<endl;
        FOR(i,1,n)cout << dis[i] << endl;
        memset(arr, 0, sizeof arr);
        
    }
}
