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
#include<vector>
using namespace std;
#define MOD 1000000007
#define endl '\n'
#define fast() ios::sync_with_stdio(false); cin.tie(0);


int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m, l; cin >> n >> m >> l;
        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
            }
        }
        // for(int i = 1; i <= n; i++)
        // {
        //     for(int j = 1; j <= m; j++)
        //     {
        //         cout << f[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int i = l; i <= n; i++)
        {
            for(int j = l; j <= m; j++)
            {
                cout << (f[i][j] - f[i][j - l] - f[i - l][j] + f[i - l][j  - l]) / (l * l) << " ";
            }
            cout << endl;
        }
    }
}