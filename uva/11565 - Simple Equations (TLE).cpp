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
int per[3];
map<int, int> vis;
int flag = 0;
int n, a, b, c;
bool check()
{
    return (per[0] + per[1] + per[2] == a &&
            per[0] + per[1] + per[2] == b &&
            (per[0] * per[0]) + (per[1] * per[1]) + (per[2] * per[2]) == c);
}
void solve(int idx)
{
    if (idx == 3)
    {
        if (check())
            flag = 1;

        return;
    }
    for (int i = -100; i <= 100; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        per[idx] = i;
        solve(idx + 1);
        vis[i] = 0;
        if (flag)
            break;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--)
    {
        flag = 0;
        cin >> a >> b >> c;
        solve(0);
        if (flag)
        {
            cout << per[0] << " " << per[1] << " " << per[2] << endl;
        }
        else
            cout << "No solution." << endl;
    }
}
