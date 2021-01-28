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
int arr[25][25], n, m, a, b;
int bl[25][25];
int maxi = -oo;
int cnt = 0;
void solve(int i, int j)
{
    //base case
    maxi = max(cnt, maxi);
    if (j == n || i == n)
    {
        return;
    }

    if (arr[i][j] && !(bl[i][j] && bl[j][i]))
    {

        bl[i][j] = true;
        bl[j][i] = true;
        cnt++;
        //cout<<i<<" "<<j<<" "<<cnt<<endl;
        solve(j, 0);
        maxi = max(cnt, maxi);
        bl[i][j] = false;
        bl[j][i] = false;

        cnt--;
    }
    solve(i, j + 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m, n)
    {
        memset(arr, 0, sizeof(arr));
        memset(bl, false, sizeof(bl));
        cnt=0;
        maxi=-oo;
        while (m--)
        {
            cin >> a >> b;
            arr[a][b] = 1;
            arr[b][a] = 1;
        }
        // cout << "    ";
        // FOR(j, 0, n)
        // cout << j << "\t";
        // cout << endl;
        // FOR(i, 0, n)
        // {
        //     cout << i << ":\t";
        //     FOR(j, 0, n)
        //     cout << arr[i][j] << "\t";
        //     cout << endl;
        // }

        FOR(i, 0, n)
            solve(i, 0);

        cout << maxi << endl;
    }
}
