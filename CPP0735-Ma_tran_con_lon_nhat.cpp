#include<iostream>
#include<unistd.h>
#include<math.h>
#include<string.h>
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
#define fast() ios::sync_with_stdio(false); cin.tie(0);

void task1()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        int ans = -1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(a[i][j] == 1)
                {
                    f[i][j] = min(f[i - 1][j] + 1, min(f[i][j - 1] + 1, f[i - 1][j - 1] + 1));
                    ans = max(ans, f[i][j]);
                }
            }
        }
        cout << ans << endl;
    }
}
int main()
{
    fast();
    task1();
}