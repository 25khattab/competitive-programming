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
struct ans
{
    pair<int, int> pa;
    int solve = 0;
};
int solved[101];
bool comp(ans i, ans j)
{
    if (i.pa.second == j.pa.second)
    {
        if (i.solve == j.solve)
            return i.pa.first < j.pa.first;
        return i.solve < j.solve;
    }
    return i.pa.second > j.pa.second;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    string s;
    cin >> t;
    getline(cin, s);
    getline(cin, s);
    while (t--)
    {

        ans mp[101];
        int arr[101][9];
        int vis[101][9];
        FOR(i, 0, 101)
        {
            FOR(j, 0, 10)
            {
                vis[i][j] = 0;
                arr[i][j] = 0;
            }
        }
        while (getline(cin, s), s.size())
        {

            stringstream sin(s);
            int c, p, t;
            char l;
            sin >> c >> p >> t >> l;
            mp[c].pa.first = c;
            if (l == 'I')
                arr[c][p] += 20;
            else if (l == 'C')
            {
                if (!vis[c][p])
                {
                    mp[c].pa.second++;
                    mp[c].solve += arr[c][p];
                    mp[c].solve += t;

                    vis[c][p]++;
                }
            }
        }
        sort(mp, mp + 101, comp);
        for (int i = 0; i < 101; i++)
        {
            if (mp[i].pa.first > 0)
                cout << mp[i].pa.first << " " << mp[i].pa.second << " " << mp[i].solve << endl;
        }

        if (t > 0)
            cout << endl;
    }
}