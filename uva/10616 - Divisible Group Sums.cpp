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
ll n, q, d, m, s, qs;
ll arr[sz];
ll memo[300][20][30];
ll solve(int pos, int size, int tot)
{
    if (pos == n){
        if(size==m)
            return tot%d==0;
        return 0;
    }
    ll& ret=memo[pos][size][tot%d];
    if(~ret)return ret;
    if (size == m){
        //cout<<tot<<endl;
        return (tot%d==0);}
    ll pick=solve(pos + 1, size + 1, (tot + arr[pos]+d*(ll)10e10)%d);
    ll leave=solve(pos + 1, size, tot);
    return ret=pick+leave;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n >> q, n)
    {

        cout << "SET " << ++s << ":\n";
        qs = 0;
        FOR(i, 0, n)
        cin >> arr[i];
        while (q--)
        {
            memset(memo,-1,sizeof(memo));
            cin >> d >> m;
            cout << "QUERY " << ++qs << ": " << solve(0, 0, 0) <<endl;
        }
    }
}
