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
int n;
void solve()
{
    int arr[sz] = {0};
    int c, p, flag = 0;
    FOR(i, 1, n + 1)
    {
        cin >> c >> p;
        if (p + i > n || p + i < 1)
        {
            flag = 1;
            continue;
        }
        if (arr[i + p])
        {
            flag = 1;
        }
        else
        {
            arr[p + i] = c;
        }
    }
    if (flag)
    {
        cout << -1 << endl;
        return;
    }
    FOR(i, 1, n + 1)
    {
        cout << arr[i];
        if (n > i)
            cout << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n, n)
    {
        solve();
    }
}
