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
    int s, b;
    while (cin >> s >> b&& s)
    {
        set<int> ss;
        FOR(i, 1, s + 1)
        {
            ss.insert(i);
        }
        FOR(i, 0, b)
        {
            int x, y;
            cin >> x >> y;
            FOR(i, x, y + 1)
            {
                ss.erase(i);
            }
            //cout << *--ss.lower_bound(x) << " ";
            //cout << *ss.lower_bound(y);

            if (ss.lower_bound(x) != ss.begin())
                cout << (*--ss.lower_bound(x)) << " ";
            else
                cout << "* ";
            if (ss.lower_bound(y) != ss.end())
                cout << (*ss.lower_bound(y)) ;
            else
                cout << "*";

            cout << endl;
        }
        cout << '-' << endl;
    }
}
