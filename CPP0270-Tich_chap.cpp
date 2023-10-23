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
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        vector<vector<int>> h(4, vector<int>(4));
        for(int i = 1; i <= 3; i++)
        {
            for(int j = 1; j <= 3; j++)
            {
                cin >> h[i][j];
            }
        }
        long long sum_check = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(i + 2 <= n && j + 2 <= m)
                {
                    for(int u = 1; u <= 3; u++)
                    {
                        for(int v = 1; v <= 3; v++)
                        {
                            sum_check += h[u][v] * a[i + u - 1][j + v - 1];
                        }
                    }
                }
            }
        }
        cout << sum_check << endl;
    }
}