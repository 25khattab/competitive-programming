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
ll fact(ll n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}
int notSafe[8][8];
int ans[8];
int queens[8][8];
int cnt = 1;
int a, b;
bool cwpq(int r, int c)
{
    FOR(i, 0, r)
    {
        if (ans[i] == c || abs(r - i) == abs(ans[i] - c))
            return 0;
    }
    return 1;
}
void solve(int row)
{
    if (row == 8)
    {
        if (ans[b] == a)
        {
            cout <<setw(2)<< cnt++ << "      ";
            FOR(i, 0, 8)
                cout << ans[i] + 1 << " \n"[i==7];

        }
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        if (!cwpq(row, i))
            continue;
        ans[row] = i;
        solve(row + 1);
        ans[row] = -1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cnt=1;
        cin >> a >> b;
        --a, --b;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        solve(0);
        if(t)cout<<endl;
    }
}
