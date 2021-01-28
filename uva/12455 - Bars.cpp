
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    string s;
    cin >> t;
    while (t--)
    {
        int flag = 0;
        int l, n;
        cin >> l >> n;
        int arr[n];
        FOR(i, 0, n)
            cin >> arr[i];
        FOR(i, 0, (1 << n))
        {
            int sum = 0;
            FOR(j, 0, n)
            {
                if (i & (1 << j))
                    sum += arr[j];
            }
            if (sum == l)
                flag = 1;
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}