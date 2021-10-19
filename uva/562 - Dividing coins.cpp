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
int tc, n, arr[sz], maxSum;
ll mem[101][50001];
ll solve(int pos, int sum)
{

    if (pos == n)
        return sum;
    ll &ret = mem[pos][sum];
    if (~ret)
        return ret;
    int take = 0;
    if (sum + arr[pos] <= (maxSum + 1) / 2)
        take = solve(pos + 1, sum + arr[pos]);
    int leave = solve(pos + 1, sum);
    return ret = max(take, leave);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        maxSum = 0;
        memset(mem, -1, sizeof mem);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxSum += arr[i];
        }
        int ans = solve(0, 0);
        cout << abs((maxSum - ans) - ans) << endl;
    }
}
