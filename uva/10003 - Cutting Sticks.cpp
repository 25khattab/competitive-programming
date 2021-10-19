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
int len, n, arr[sz];
int mem[55][55];
int solve(int l, int r)
{
    if (l + 1 == r)
        return 0;
    int &ret = mem[l][r];
    if (~ret)
        return ret;
    ret = oo;
    for (int i = l + 1; i < r; i++)
    {
        ret = min(ret, solve(i, r) +
                           solve(l, i) +
                           arr[r] - arr[l]);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> len, len)
    {
        cin >> n;
        memset(mem, -1, sizeof mem);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        arr[0] = 0;
        arr[n + 1] = len;
        cout << "The minimum cutting is " << solve(0, n + 1) << "." << endl;
    }
}
