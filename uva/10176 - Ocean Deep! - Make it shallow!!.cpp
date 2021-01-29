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
bool isPrime(int x)
{
    for (int i = 2; i <= x / i; i += 1 + (i & 1))
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
ll fastPow(int x, int p, int m)
{
    int ret = 1;
    while (p)
    {
        if (p & 1)
            ret = ret * x % m;
        x = x * x % m;
        p >>= 1;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int ans = 0;
    while (cin >> s)
    {
        if (s.back() == '#')
        {

            for (int i = 0; i < s.size() - 1; i++)
                ans = ((ans << 1) + (s[i] - '0')) % 131071;
            if (ans == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
            ans = 0;
        }
        else
            for (int i = 0; i < s.size(); i++)
                ans = ((ans << 1) + (s[i] - '0')) % 131071;
    }
}