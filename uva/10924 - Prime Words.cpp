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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
bool isPrime(ll x)
{
    for (int i = 2; i <= x / i; i += 1 + (i & 1))
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while (cin >> s)
    {
        ll sum=0;
        for (char c : s)
        {

            if(c>='A'&&c<='Z')
                sum+=c-'A'+27;
            
                else sum+=c-'a'+1;
        }
        //cout<<sum<<" ";
        isPrime(sum)?cout<<"It is a prime word.\n":cout<<"It is not a prime word.\n";
    }
}
