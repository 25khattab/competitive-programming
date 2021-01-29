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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<string, double> mp;
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    getline(cin, s);
    while (t--)
    {
        mp.clear();
        int cnt = 0;
        while (getline(cin, s) && s!="")
        {
            mp[s]++;
            cnt++;
        }
        for (auto it : mp)
        {
            cout << it.first << " " << fixed << setprecision(4) << (it.second / cnt) * 100 << endl;
        }
        if(t>0)cout<<endl;
    }
}
