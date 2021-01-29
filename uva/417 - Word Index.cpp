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
map<string, int> mp;
int cnt = 1;
void preprocc(string s, int len)
{
    if (s.size() == len)
    {
        mp[s] = cnt++;
        return;
    }
    char lastLetter;
    if (s.empty())
        lastLetter = 'a';
    else
        lastLetter = s[s.size() - 1] + 1;

    for (char c=lastLetter;c<='z';c++){
        preprocc(s+c,len);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     for (size_t len = 1; len <= 5; ++len)
        preprocc("", len);

    string word;
    while (cin >> word)
        cout << mp[word] << endl;
}
