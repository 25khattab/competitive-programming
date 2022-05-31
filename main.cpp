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
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int sz = 0;
    int flag = -1;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        ans[v[i]].push_back(i+1);
    }

    for (auto i : ans)
    {
        if(i.second.size()==1){
            cout<<-1<<endl;
            return;
        }
        cout<< i.second[i.second.size()-1]<<" ";
        for (int it=0; it<i.second.size()-1;it++ )
            cout << i.second[it] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}
