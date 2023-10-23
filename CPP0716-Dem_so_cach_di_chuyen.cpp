#include<iostream>
#include<unistd.h>
#include<math.h>
#include<string>
#include<cctype>
#include<set>
#include<limits.h>
#include<map>
#include<queue>
#include<algorithm>
#include<iomanip>
using namespace std;
#define MOD 1000000007
#define endl '\n'
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}
bool check(int ii, int jj, int n)
{
    if(ii >= 1 && ii <= n && jj >= 1 && jj <= n)
    {
        return true;
    }
    return false;
}
void backtrack(vector<vector<int>> a, long long n, int ii, int jj, long long &cnt, long long k, long long sum)
{
    if(sum + a[ii][jj] > k)
    {
        return;
    }
    if(ii == n && jj == n)
    {
        if(sum + a[ii][jj]== k) cnt++;
        return;
    }
    if(check(ii + 1, jj, n) == true)
    {
        backtrack(a, n, ii + 1, jj, cnt, k, sum + a[ii][jj]);
    }
    if(check(ii, jj + 1, n) == true)
    {
        backtrack(a, n, ii, jj + 1, cnt, k, sum + a[ii][jj]);
    }
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        long long n, k; cin >> n >> k;
        vector<vector<int>> a(n + 1, vector<int>(n + 1));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
            }
        }
        long long sum = 0;
        long long cnt = 0;
        backtrack(a, n, 1, 1, cnt, k, sum);
        cout << cnt << endl;
    }   
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/