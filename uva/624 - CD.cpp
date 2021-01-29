#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define FOR(i, s, e) for (int i = s; i < e; i++)
#define ROF(i, s, e) for (int i = e - 1; i >= s; i--)
#define mk(x, y) make_pair(x, y)
int const sz = 2e5;
const int oo = 0x3f3f3f3f;
const double EPS = 1e-6;
ll const MOD = 1e9 + 7;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
int tc;
void solve()
{
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    while (cin >> t)
    {
        int n, maxidx = 0, maxsum = 0, arr[30],idx=0;
        vector<vector<int>> a;
        cin >> n;
        FOR(i, 0, n)
        cin >> arr[i];
        for (int msk = 1; msk < (1 << n); msk++)
        {
            vector<int> ans;
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (msk & (1 << i))
                {
                    ans.push_back(arr[i]);
                    sum += arr[i];
                }
            }
            if (sum <= t)
            {
                a.push_back(ans);
                if(sum>maxsum||(sum>maxsum&&a[maxidx].size()<=ans.size())){
                    maxidx=idx;
                    maxsum=sum;
                }
                idx++;
            }
        }
        for(auto it:a[maxidx]){
            cout<<it<<" ";
        }
        cout<<"sum:"<<maxsum<<endl;
    }
}
