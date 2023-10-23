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
    int n, m; cin >> n;
    m = 3;
    int a[n + 1][m + 1];
    int f_i[n + 1];
    memset(f_i, 0, sizeof(f_i));
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j]; 
            if(a[i][j] == 1)
            {
                cnt++;
            }
        }
        f_i[i] = cnt;
    }  
    int cnx = 0;
    for(int i = 1; i <= n; i++)
    {
        if(f_i[i] > m - f_i[i])
        {
            cnx++;
        }
    }
    cout << cnx << endl;

}
int main()
{
    fast();
    solve();
}
/*AUTHOR: KHỔNG VĂN QUẢNG - D22CQCN06-B*/