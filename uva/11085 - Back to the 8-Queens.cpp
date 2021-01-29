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
struct ans
{
    int x;
};
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
int n = 8, cases ,t=0, cnt = 0,idx=0;
int arr[92][8];
int a[8];
int ans[15];
int rc1[50], rc2[50];
void solve(int r)
{
    if (r == n)
    {

        FOR(i, 0, n)
        {
           arr[idx][i]=ans[i];
        }
        ++idx;
        return;
    }
    FOR(c, 0, n)
    {
        if (ans[c] || rc1[n - 1 + r - c] || rc2[c + r])
            continue;
        ans[c] = r+1;
        rc1[n - 1 + r - c] = rc2[c + r] = 1;
        solve(r + 1);
        ans[c] = rc1[n - 1 + r - c] = rc2[c + r] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve(0);
    while (cin >> cases)
    {
        cnt = oo;
        a[0] = cases;
        FOR(i, 1, n)
        {
            cin >> a[i];
        }
        
        FOR(i,0,92){
            int tmp=0;
            FOR(j,0,n){
                if(arr[i][j]!=a[j])tmp++;
            }
            cnt=min(cnt,tmp);
        }
        cout << "Case "<<++t<<": "<<cnt << endl;

    }
}
