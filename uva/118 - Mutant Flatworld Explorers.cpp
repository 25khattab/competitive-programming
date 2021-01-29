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

int dx[] = {1, 0, -1, 0}; // {right , down , left , up}
int dy[] = {0, -1, 0, 1}; //4 Direction
int x, y, ex, ey;
int arr[60][60];
char c;
string dir;
bool valid_point(int x, int y)
{
    return ((x <= ex && 0 <= x) && (y <= ey && 0 <= y));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> ex >> ey)
    {
        memset(arr, 0, sizeof arr);
        while (cin >> x >> y)
        {
            int flag = 0;
            cin >> c;
            cin >> dir;
            int d;
            if (c == 'E')
                d = 0;
            else if (c == 'N')
                d = 3;
            else if (c == 'W')
                d = 2;
            else
                d = 1;
            for (int idx = 0; idx < dir.size(); idx++)
            {
                if (dir[idx] == 'R')
                    d++, d %= 4;
                else if (dir[idx] == 'L')
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
                        x = nx, y = ny;
                    }
                    else
                    {
                        if (!arr[x][y])
                        {
                            arr[x][y] = 1;
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            if (d == 0)
                c = 'E';
            else if (d == 1)
                c = 'S';
            else if (d == 2)
                c = 'W';
            else if (d == 3)
                c = 'N';
            cout << x << " " << y << " " << c;
            if (flag)
                cout << " LOST\n";
            else
                cout << endl;
        }
    }
}
