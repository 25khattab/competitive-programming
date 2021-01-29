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
int t, n;
int popCount(int k)
{
    int ans = 0;
    while (k)
    {
        ans += k & 1;
        k >>= 1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("reduced.in","r",stdin);

    cin >> t;
    while (t--)
    {
        int arr[100]={0};
        bool vis[100]={0};
        vector<int> v;
        cin >> n;
        FOR(i, 0, n)
        {
            int x;
            cin >> x;
            int dig=popCount(x);
            arr[dig] ^= x;
            vis[dig]=true;
        }
        FOR(i, 0, 100)
        {
            if (vis[i]== 0)
                continue;
            v.push_back(arr[i]);
        }
        sort(v.begin(), v.end());
        for (auto it : v)
            cout << it << " ";
        cout << endl;
    }
    cout<<popCount(100000^64);
}
