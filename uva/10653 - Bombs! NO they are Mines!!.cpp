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
int dis[1001][1001];
int dx[] = {-1, 0, 1, 0}; //up - right - down- left
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> q;
bool valid(int x, int y)
{
    return ((x < r && x >= 0) && (y < c && y >= 0) && (!arr[x][y]) && (dis[x][y] == oo));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> r >> c, r)
    {
        int rows;
        cin >> rows;
        while (rows--)
        {
            int x, k;
            cin >> x >> k;

            for (int i = 0; i < k; i++)
            {
                int y;
                cin >> y;
                arr[x][y] = 1;
            }
        }
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        // FOR(i, 0, r)
        // {
        //     FOR(j, 0, c)
        //     {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        

        memset(dis, oo, sizeof dis);
        dis[sx][sy] = 0;
        q.push({sx, sy});
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            FOR(i, 0, 4)
            {
                int nx = dx[i] + x, ny = dy[i] + y;
                if (valid(nx, ny))
                {
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
       // cout<<ex<<" "<<ey<<endl;
        cout << dis[ex][ey]<<endl;
        memset(arr,0,sizeof arr);
    }
}
