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
    cout.tie(0);
    int n;
    while (cin >> n, n)
    {
        string arr[n];
        FOR(i, 0, n)
        {
            arr[i] = "";
        }
        int tmp = n;
        int idx = -1;
        while (tmp--)
        {
            string s1, s2;
            cin >> s1 >> s2;
            int l = s2.length();
            while (l--)
            {
                idx=(idx+1)%n;
                if (arr[idx] != "")
                    l++;
            }
            arr[idx%n]=s1;
        }
        FOR(i, 0, n)
        {
            cout << arr[i] << " \n"[i==n-1];
        }
    }
}
