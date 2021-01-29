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
    string s ,s1,s2;
    stack<string> st;
    while (cin >> s)
    {
        while(st.size())st.pop();
        s1 = "", s2 = "";
        int flag = 0;
        for (char c : s)
        {
            if (c == '[')
            {
                flag=1;
                if (flag)
                {
                    st.push(s1);
                    s1 = "";
                }
                
            }
            else if (c == ']')
            {
                if (flag)
                {
                    flag=0;
                    st.push(s1);
                    s1="";
                }
            }
            else if (flag)
            {
                s1 += c;
            }
            else
            {
                s2 += c;
            }
        }
        if(flag)st.push(s1);
        string temp = "";
        while (st.size())
        {
            temp += st.top();
            st.pop();
        }
        cout << temp << s2 << endl;
    }
}
