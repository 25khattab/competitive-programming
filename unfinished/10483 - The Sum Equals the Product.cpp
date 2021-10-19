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
void solve()
{
}
bool arr[25600][25600];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double h, j;
    cin >> h >> j;
    int x = (h * 100) + .5;
    int y = (j * 100) + .5;
    while (x <= y)
    {
        for (int a = 1; a <= y; a += 1)
        {
            for (int b = a; b <= y; b += 1)
            {

                int c = x - a - b;
                if (x == 585 && a == 100 && b == 225)
                {
                    cout << a << " " << b << " " << c << endl;
                    cout << ((double)a / 100) + ((double)b / 100) + ((double)c / 100) << endl;
                    cout<<((double)a / 100) * ((double)b / 100) * ((double)c / 100)<<endl;
                }
                if (((double)a / 100) + ((double)b / 100) + ((double)c / 100) == ((double)a / 100) * ((double)b / 100) * ((double)c / 100)&&x==585)
                {
                    cout << fixed << setprecision(2) << ((double)x / 100) << " = " << ((double)a / 100) << " + " << ((double)b / 100) << " + " << ((double)c / 100) << " = " << ((double)a / 100) << " * " << ((double)b / 100) << " * " << ((double)c / 100) << endl;
                    break;
                }
            }
        }
        x += 1;
    }
}
