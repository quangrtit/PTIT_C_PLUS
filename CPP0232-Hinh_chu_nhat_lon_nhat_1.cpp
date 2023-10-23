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
#define PI 3.141592653589793238
#define fast() ios::sync_with_stdio(false); cin.tie(0);

bool check(int i, int i1, int j, vector<vector<int>> a)
{
    for(int e = i; e <= i1; e++)
    {
        if(a[e][j] == 0)
        {
            return false;
        }
    }
    return true;
}
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
        int check_max = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int i1 = i; i1 <= n; i1++)
            {
                int cnt = 0;
                for(int j = 1; j <= m; j++)
                {
                    if(check(i, i1, j, a))
                    {
                        cnt += i1 - i + 1;
                    }
                }
                check_max = max(check_max, cnt);
                //cout << i << " " << i1 << " " << cnt << endl;
            }
        }
        cout << check_max << endl;
    }
}