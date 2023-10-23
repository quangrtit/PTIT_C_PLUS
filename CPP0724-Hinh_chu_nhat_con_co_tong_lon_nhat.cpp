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

int main()
{
    fast();
    int t; cin >> t;
    while(t--)
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
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                f[i][j] = f[i - 1][j] + f[i][j - 1] + a[i][j] - f[i - 1][j - 1];
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
        long long check_max = LLONG_MIN;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                for(int e_i = 0; e_i < i; e_i++)
                {
                    for(int e_j = 0; e_j < j; e_j++)
                    {
                        if(!(e_i == i && e_j == j))
                        {
                            check_max = max(check_max, f[i][j] - f[e_i][j] - f[i][e_j] + f[e_i][e_j]);
                            //cout << i << " " << j << " " << e_i << " " << e_j << " " << f[i][j] - f[e_i][j] - f[i][e_j] + f[e_i][e_j] << endl;
                        }
                    }
                }
            }
        }
        cout << check_max << endl;
    }
}