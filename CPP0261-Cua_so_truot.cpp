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
void solve()
{
    int n; cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    int m; cin >> m;
    vector<vector<int>> b(m + 1, vector<int>(m + 1));
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> b[i][j];
        }
    }
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    int stt = n / m;
    for(int e = 1; e <= n; e += m)
    {
        for(int f = 1; f <= n; f += m)
        {
            int ii = 1;
            for(int i = e; i <= e + m - 1; i++)
            {
                int jj = 1;
                for(int j = f; j <= f + m - 1; j++)
                {
                    v[i][j] = a[i][j] * b[ii][jj];
                    jj++;
                }
                ii++;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/