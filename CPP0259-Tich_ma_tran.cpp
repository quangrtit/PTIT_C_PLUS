#include<iostream>
#include<unistd.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<set>
#include<limits.h>
#include<map>
#include<queue>
#include<algorithm>
#include<iomanip>
using namespace std;
#define MOD 1000000007
#define endl '\n'
#define MIN = LLONG_MIN
#define MAX = LLONG_MAX
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}
void solve()
{
    int n, m, p; cin >> n >> m >> p;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<int>> b(m + 1, vector<int>(p + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= p; j++)
        {
            cin >> b[i][j];
        }
    }
    vector<vector<int>> result(n + 1, vector<int>(p + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= p; j++)
        {
            int sum_rc = 0;
            for(int e = 1; e <= m; e++)
            {
                sum_rc += a[i][e] * b[e][j];
            }
            result[i][j] = sum_rc;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= p; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    fast();
    solve();
}
/*AUTHOR: KHỔNG VĂN QUẢNG - D22CQCN06-B*/