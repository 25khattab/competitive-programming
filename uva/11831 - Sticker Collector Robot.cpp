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
int dy[] = {0, 1, 0, -1}; // {up , right , down , left}
int dx[] = {-1, 0, 1, 0}; //4 Direction
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
int n, m, t;
char arr[110][110];
bool valid_point(int x, int y)
{
    return ((x <= n-1 && 0 <= x) && (y <= m-1 && 0 <= y)&&arr[x][y]!='#');
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m >> t,n)
    {
        int d;
        int x,y;
        FOR(i, 0, n)
        {
            FOR(j, 0, m)
            {
                cin >> arr[i][j];
                if (arr[i][j] >= 'A' && arr[i][j] <= 'Z')
                    x = i, y = j;
                if (arr[i][j] == 'N')
                    d = 0;
                else if (arr[i][j] == 'S')
                    d = 2;
                else if (arr[i][j] == 'L')
                    d = 1;
                else if (arr[i][j] == 'O')
                    d = 3;
            }
        }
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'D')
                d++, d %= 4;
            else if (s[i] == 'E')
            {
                d--;
                if (d < 0)
                    d = 3;
            }
            else
            {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (valid_point(nx, ny))
                {
                    if (arr[nx][ny] == '*')
                        cnt++, arr[nx][ny] = '.';
                    x = nx, y = ny;
                }
            }
        }
        cout<<cnt<<endl;
    }
}
