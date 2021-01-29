#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define FOR(i, s, e) for (int i = s; i < e; i++)
#define ROF(i, s, e) for (int i = e - 1; i >= s; i--)
#define mk(x, y) make_pair(x, y)
int const sz = 1e5 + 20;
int const oo = 1e9;
ll const MOD = 1e9 + 7;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
ll n, m;
ll memo[sz];
ll solve(int j, vector<ll> &v)
{
    if (j >= v.size())
        return 0;
    ll &ret = memo[j];
    if (~ret)
        return ret;
    return ret = max(v[j] + solve(j + 2, v), solve(j + 1, v));
}
vector<vector<ll>> arr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m, n)
    {
        arr = vector<vector<ll>>(n, vector<ll>(m));
        memset(memo, -1, sizeof(memo));
        vector<ll> row;
        FOR(i, 0, n)
        {

            FOR(j, 0, m)
            {
                cin >> arr[i][j];
            }
            memset(memo, -1, sizeof(memo));
            row.push_back(solve(0, arr[i]));
        }
        memset(memo, -1, sizeof(memo));
        cout << solve(0, row) << endl;
    }
}
