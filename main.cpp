#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define FOR(i, s, e) for (int i = s; i < e; i++)
#define ROF(i, s, e) for (int i = e - 1; i >= s; i--)
#define mk(x, y) make_pair(x, y)
int const sz = 2e5 + 2;
const int oo = 0x3f3f3f3f;
const double EPS = 1e-6;
ll const MOD = 1e9 + 7;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
int tc;
ll point[sz], n, m, mem[sz];
map<pair<int, int>, int> memo;
ll ans(int pos, ll tot)
{
    if (pos == n)
        return tot >= m ? 0 : oo;

    if (memo[{pos,tot}])
        return memo[{pos,tot}];
    if (tot >= m)
        return ans(pos + 1, tot);
    else
    {
        int pick = ans(pos + 1, tot + mem[pos]) + point[pos];
        int leave = ans(pos + 1, tot);
        return memo[{pos,tot}] = min(pick, leave);
    }
}
void solve()
{
    cin >> n >> m;
    FOR(i, 0, n)
    cin >> mem[i];
    FOR(i, 0, n)
    cin >> point[i];
    memo.clear();
    int a = ans(0, 0);
    if (a != oo)
        cout << a << endl;
    else
        cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}