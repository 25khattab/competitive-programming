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
    int a;
    int b;
    int c;
};
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
int arr[10];
int per[10];
int valid[10];
int n, m, cnt = 0;
ans s[20];
void solve(int idx)
{
    if (idx == n)
    {

        int flag = 0;
        FOR(i, 0, m)
        {
            //cout<<abs(arr[s[i].a] - arr[s[i].b])<<" "<<s[i].b<<" "<<s[i].c<<endl;
            if ((s[i].c > 0 && abs(arr[s[i].a] - arr[s[i].b]) <= s[i].c))flag++;
            else if(s[i].c < 0 && abs(arr[s[i].a] - arr[s[i].b]) >= abs(s[i].c))
             {
             flag++;
            }
        }
        if (flag==m)
            cnt++;
        //cout<<endl<<endl;
        return;
    }
    FOR(i, 0, n)
    {
        if (valid[i])
            continue;
        valid[i] = 1;
        per[idx] = i;
        arr[i] = idx;
        solve(idx + 1);
        valid[i] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m, n)
    {

        cnt = 0;

        FOR(i, 0, m)
        {
            cin >> s[i].a >> s[i].b >> s[i].c;
        }
        solve(0);

        cout << cnt << endl;
    }
}
