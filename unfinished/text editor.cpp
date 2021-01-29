#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define FOR(i, s, e) for (int i = s; i < e; i++)
#define ROF(i, s, e) for (int i = e - 1; i >= s; i--)
#define mk(x, y) make_pair(x, y)
int const sz = 1e5;
int const oo = 1e9;
ll const MOD = 1e9 + 7;
struct ans
{
    int x;
};
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
int arr[101];

int main()
{
    int n, r, c, re, ce, cnt = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    FOR(i, 1, n + 1)
    {
        cin >> arr[i];
    }
    cin >> r >> c >> re >> ce;

    while (r != re || c != ce)
    {
        if ((arr[r + 1] < abs(c - ce)))
            if (r == re && r != n && arr[r + 1] < abs(c - ce) && ce < c)
            {
                c = arr[r + 1] + 1;
                r++;
                cnt++;
            }

            else if (arr[r - 1] < abs(c - ce))
                if (r == re && r != 1 && arr[r - 1] < abs(c - ce) && c > ce)
                {
                    c = arr[r - 1] + 1;
                    r--;
                    cnt++;
                }
        if (r < re)
        {
            if (arr[r + 1] < c)
            {
                c = arr[r + 1] + 1;
            }
            r++, cnt++;
        }
        if (r > re)
        {
            if (arr[r - 1] < c)
            {
                c = arr[r - 1] + 1;
            }
            r--, cnt++;
        }
        if (c < ce && r == re)
        {
            c++, cnt++;
        }
        if (c > ce && r == re)
        {
            cnt++, c--;
        }
    }
    cout << cnt;
}
