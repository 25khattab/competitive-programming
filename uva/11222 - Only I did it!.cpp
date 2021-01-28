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
    int tc;
    cin >> tc;
    FOR(c, 1, tc + 1)
    {
        cout << "Case #" << c << ":\n";
        int freq[10001]={0};
        vector<int> f[3];
        FOR(i, 0, 3)
        {
            set<int> s;
            int x;
            cin >> x;
            FOR(j, 0, x)
            {
                int y;
                cin >> y;
                s.insert(y);
            }
            for (auto it : s)
                f[i].push_back(it);
            for(auto it :f[i])
                freq[it]++;
        }
        vector<int> a[3];
        int maxi = 0;
        FOR(i, 0, 3)
        {
            int uni = 0;
            FOR(j, 0, f[i].size())
            {
                if (freq[f[i][j]] == 1)
                {
                    uni++;
                    a[i].push_back(f[i][j]);
                }
            }
            maxi = max(maxi, uni);
        }
        FOR(i, 0, 3)
        {
            if (a[i].size() == maxi)
            {
                cout << i + 1 << " " << a[i].size();
                if (maxi != 0)
                {
                    cout << " " << a[i][0];
                    for (int j = 1; j < a[i].size(); j++)
                        cout << " " << a[i][j];
                }
                cout << endl;
            }
        }
    }
}
