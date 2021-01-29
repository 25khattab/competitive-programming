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
int tc;
void solve()
{
}
vector<pair<string, string>> ans[80];
bool uni(int a, int b)
{
    int dig = log10(b) + 1;
    int freq[10] = {0};
    if (dig == 4)
        freq[0]++;
    while (a)
    {
        freq[a % 10]++;
        a /= 10;
    }
    while (b)
    {
        freq[b % 10]++;
        b /= 10;
    }
    int flag = 1;
    FOR(i, 0, 10)
    {
        if (freq[i] > 1)
            flag = 0;
    }
    return flag;
}
void seive()
{
    for (int c = 2; c < 80; c++)
    {
        for (int b = 1234; b <= 98765; b++)
        {
            int a = b * c;
            int dig = log10(a) + 1;
            if (dig == 5)
            {
                if (uni(a, b))
                {
                    string s1, s2;
                    s1 = to_string(a);
                    s2 = to_string(b);
                    if (s2.size() == 4)
                        s2.insert(0, 1, '0');
                    ans[c].push_back({s1, s2});
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    seive();
    int n;
    int f = 1;
    while (cin >> n && n)
    {
        if (!f)
            cout << endl;
        f = 0;
        if (ans[n].size())
        {
            for (auto it : ans[n])
            {
                cout << it.first << " / " << it.second << " = " << n << endl;
            }
        }
        else
        {
            cout << "There are no solutions for " << n << "." << endl;
        }
    }
}
