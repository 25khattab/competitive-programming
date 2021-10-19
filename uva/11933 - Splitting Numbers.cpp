#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define ll long long
#define mk(x, y) make_pair(x, y)
const int oo = 0x3f3f3f3f;
const double EPS = 1e-6;
ll const MOD = 1e9 + 7;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
int const N = 1e5 + 2;
int tc;
void solve()
{
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> tc && tc)
    {
        string number = "";
        while (tc != 0)
        {
            if (tc % 2 == 0)
                number += '0';
            else
                number += '1';
            tc /= 2;
        }
        reverse(number.begin(), number.end());
        string a = "", b = "";
        bool flag = 0;
        for (int i = number.size() - 1; i >= 0; i--)
        {
            if (number[i] == '0')
                a += '0', b += '0';
            else
            {
                if (!flag)
                {
                    a += '1', b += '0';
                }
                else
                {
                    a += '0', b += '1';
                }
                flag = !flag;
            }
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        cout<<stoi(a,0,2)<<" "<<stoi(b,0,2)<<endl;
    }
}
