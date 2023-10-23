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
vector<int> xx = {-1, -1, -1, 0, 1, 1, 1, 0};
vector<int> yy = {-1, 0, 1, 1, 1, 0, -1, -1};
void dfs(vector<vector<int>> &a, int i, int j, int m1, int n1)
{
    a[i][j] = 0;
    for(int e = 0; e < 8; e++)
    {
        int m = xx[e] + i;
        int n = yy[e] + j;
        if(1 <= n && n <= n1 && 1 <= m && m <= m1 && a[m][n] == 1)
        {
            dfs(a, m, n, m1, n1);
        }
    }
}
void solve()
{
    int test; cin >> test;
    while(test--)
    {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        vector<vector<int>> f(n + 1, vector<int>(m + 1));   
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(a[i][j] == 1)
                {
                    dfs(a, i, j, m, n);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/