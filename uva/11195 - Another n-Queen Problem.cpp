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
int n, cases = 1, cnt = 0;
char arr[15][15];
int ans[15];
int rc1[50],rc2[50];
bool isValid(int r, int c)
{
    if (arr[r][c] == '*')
        return 0;
    FOR(i, 0, r)
    {
        if (ans[i] == c || abs(r - i) == abs(ans[i] - c))
            return 0;
    }
    return 1;
}
void solve(int r)
{
    if (r == n)
    {

        // FOR(i, 0, n)
        // {
        //     FOR(j, 0, n)
        //     {
        //        cout<<arr[i][j];
        //     }
        //     cout<<endl;
        // }
        // cout<<"_________________________________\n";
        cnt++;
        return;
    }
    FOR(c, 0, n)
    {
        if (arr[r][c] == '*' || ans[c] || rc1[n-1+r-c] || rc2[c + r])
            continue;
        ans[c] = 1;
        rc1[n-1+r-c] = rc2[c + r] = 1;
        arr[r][c] = 'Q';
        solve(r + 1);
        arr[r][c] = '.';
        ans[c] = rc1[n-1+r-c] = rc2[c + r] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n, n)
    {
        cnt = 0;
        FOR(i, 0, n)
        {
            FOR(j, 0, n)
            {
                cin >> arr[i][j];
            }
        }
        solve(0);
        cout << "Case " << cases++ << ": " << cnt << endl;
    }
}
