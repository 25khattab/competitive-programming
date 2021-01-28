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
ll fact(ll n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}
int grid[8][8];
int notSafe[8][8];
int ans[8];
int queens[8][8];
int tmp=0,maxi=-oo;
bool isValid(int r, int c)
{
    return r < 8 && c < 8 && r >= 0 && c >= 0;
}
void Do(int r, int c)
{
    queens[r][c]=1;
    FOR(i, 0, 8)
    {
        notSafe[r][i] +=1, notSafe[i][c] += 1;
    }
    FOR(i, 0, 8)
    {
        if (isValid(r + i, c + i))
            notSafe[r + i][c + i] += 1;

        if (isValid(r + i, c - i))
            notSafe[r + i][c - i] += 1;

        if (isValid(r - i, c + i))
            notSafe[r - i][c + i] += 1;

        if (isValid(r - i, c - i))
            notSafe[r - i][c - i] += 1;
    }
}
void Undo(int r, int c)
{
    queens[r][c]=0;
    FOR(i, 0, 8)
    {
        notSafe[r][i] -=1, notSafe[i][c] -= 1;
    }
    FOR(i, 0, 8)
    {
        if (isValid(r + i, c + i))
            notSafe[r + i][c + i] -= 1;

        if (isValid(r + i, c - i))
            notSafe[r + i][c - i] -= 01;

        if (isValid(r - i, c + i))
            notSafe[r - i][c + i] -= 01;

        if (isValid(r - i, c - i))
            notSafe[r - i][c - i] -= 01;
    }
}
void solve(int row)
{
    if (row == 8)
    {
        FOR(i, 0, 8)
        {
            FOR(j, 0, 8)
                tmp+=grid[i][j]*queens[i][j];
        }
        // cout<<"_______________________"<<endl;  
        maxi=max(maxi,tmp);
        tmp=0;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        if (notSafe[row][i]>0)
            continue;
        Do(row,i);
        solve(row+1);
        Undo(row,i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        maxi=-oo;
        FOR(i,0,8){
            FOR(j,0,8){
                cin>>grid[i][j];
            }
        }
        solve(0);
        cout<<setw(5)<<maxi<<endl;
        
    }
    
}
