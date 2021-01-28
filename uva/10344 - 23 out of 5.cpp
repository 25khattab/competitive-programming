#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
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
int arr[5] = {1, 2, 3, 4, 5};
bool vis[5];
int p[5];
bool flag = 0;
void possible(int ans, int idx)
{
    if (idx == 5){
        if(ans==23)flag=1;
        return;
    }
    possible(ans + p[idx], idx + 1);
    possible(ans - p[idx], idx + 1);
    possible(ans * p[idx], idx + 1);
}
void solve(int idx)
{
    //base case
    if (idx == 5)
    {
        possible(p[0],1); 
      
        return;
    }
    //subproblem
    FOR(i, 0, 5)
    {
        if (vis[i])
            continue;
        vis[i] = true;
        p[idx] = arr[i];
        solve(idx + 1);
        vis[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> arr[0], arr[0])
    {
        flag=0;
        FOR(i,1,5)cin>>arr[i];
        solve(0);
        if (flag)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}
