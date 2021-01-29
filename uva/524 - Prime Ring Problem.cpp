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
ll const MOD = 1e9 + 7;
struct ans
{
    int x;
};
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
ll fact(int n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}
int prime[32] = {0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1};
int ans[20], n, cases = 1;
;
bool Valid[20];
void solve(int idx, int lst)
{
    if (idx == n)
    {
        if (prime[ans[0] + ans[n - 1]])
        {
            FOR(i, 0, n)
            cout << ans[i] << " \n"[i == n - 1];    
        }
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (Valid[i])
            continue;
        if (prime[i + lst])
        {
            Valid[i] = 1;

            ans[idx] = i;
            solve(idx + 1, i);
            Valid[i] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ans[0] = 1;
    int flag = 0;
    while (cin >> n)
    {
        if (flag)
            cout << endl;
        flag = 1;
        cout << "Case " << cases++ << ":\n";
        
        solve(1, 1);
    }
}
