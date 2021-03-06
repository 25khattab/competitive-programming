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
int arr[]={10000,5000,2000,1000,500,200,100,50,20,10,5};
double n;
int x;
ll dp[11][30000];
ll solve(int pos,int amount){
    if(amount==x)return 1;
    if(pos==11)return 0;
    ll& ret=dp[pos][amount];
    if(~ret)return ret;
    ll pick=(amount+arr[pos]<=x)?solve(pos,amount+arr[pos]):0;
    ll leave=solve(pos+1,amount);
    return ret=pick+leave;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n,n){
        memset(dp,-1,sizeof(dp));
        x=(n*100+.5);
        cout<<fixed<<setprecision(2);
        cout.width(6);cout<<right<<n;
        cout.width(17);cout<<solve(0,0)<<endl;
    }
}
