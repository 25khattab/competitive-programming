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
int arr[]={50,25,10,5,1};
ll n;
ll dp[5][30000+10];
ll solve(int pos,int amount){
    if(amount==0)return 1;
    if(pos==5)return 0;
    ll& ret=dp[pos][amount];
    if(~ret)return ret;
    ll pick=(amount>=arr[pos])?solve(pos,amount-arr[pos]):0;
    ll leave=solve(pos+1,amount);
    return ret=pick+leave;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    while(cin>>n){
        //memset(dp,-1,sizeof(dp));
        ll ways= solve(0,n);
        ways==1?printf("There is only %lld way to produce %d cents change.\n",ways,n):printf("There are %lld ways to produce %d cents change.\n",ways,n);
    }
}
