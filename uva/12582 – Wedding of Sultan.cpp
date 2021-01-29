#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

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
    //freopen("cubes.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string s;
        cin >> s;
        stack<char> st;
        map<char, int> mp;
        st.push(s[0]);
        FOR(i, 1, s.size())
        {
            if (s[i] == st.top())
                st.pop();
            else
            {
                mp[st.top()]++;
                st.push(s[i]);
                mp[st.top()]++;
            }
        }
        cout<<"Case "<<i<<endl;
        for (auto it : mp)
        {
            cout<<it.first<<" = "<<it.second<<endl;
        }
    }
}
