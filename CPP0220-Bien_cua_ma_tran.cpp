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
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n;
        m = n;
        int a[n + 1][m + 1];
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j]; 
            }
        }  
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(i == 1 || j == 1 || j == m || i == n)
                {
                    cout << a[i][j] << " ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
}
int main()
{
    fast();
    solve();
}
/*AUTHOR: KHỔNG VĂN QUẢNG - D22CQCN06-B*/