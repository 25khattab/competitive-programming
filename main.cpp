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
int tc, a, b, cnt;
int row[8];

bool place(int r, int c)
{
    for (int prev = 0; prev < r; prev++) 
        if (row[prev] == c || (abs(row[prev] - c) == abs(prev - r)))
            return false; 
    return true;
}
void solve(int c)
{
    if (c == 8 && row[b] == a)
    {
        cout << setw(2) << cnt++ << "      ";
        FOR(i, 0, 8)
        cout << row[i] + 1 << " \n"[i == 7];
        return;
    }
    for (int r = 0; r < 8; r++)
    {
        if (place(c, r))
            row[c] = r, solve(c + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tc;
    while (tc--)
    {
        cnt = 1;
        memset(row, 0, sizeof row);
        cin >> a >> b;
        --a, --b;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        solve(0);
        if (tc)
            cout << endl;
    }
}
