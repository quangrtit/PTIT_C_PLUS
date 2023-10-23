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

void fix(vector<vector<float>> &a, int n, int m)
{
    for(int i = 1; i <= n; i++)
    {
        for(int i1 = i + 1; i1 <= n; i1++)
        {
            int cnt1 = 0, cnt2 = 0;
            for(int j = 1; j <= m; j++)
            {
                if(a[i][j] == 0) 
                {
                    cnt1++;
                }
                else 
                {
                    break;
                }
            }
            for(int j = 1; j <= m; j++)
            {
                if(a[i1][j] == 0) 
                {
                    cnt2++;
                }
                else 
                {
                    break;
                }
            }
            if(cnt1 > cnt2)
            {
                for(int j = 1; j <= m; j++)
                {
                    swap(a[i][j], a[i1][j]);
                }
            }
        }
    }
}
void p_matrix(vector<vector<float>> a, int n, int m)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << a[i][j] << " ";

        }
        cout << endl;
    }
}
int main()
{
    fast();
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        vector<vector<float>> a(n + 1, vector<float>(m + 1));
        vector<int> b(n + 1);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        fix(a, n, m);
        for(int i = 1; i <= n; i++)
        {
            for(int i1 = i + 1; i1 <= n; i1++)
            {
                int jj = 1;
                while(a[i1][jj] == 0 && a[i][jj] == 0)
                {
                    jj++;
                }
                if(!(a[i1][jj] != 0 && a[i][jj] != 0)) continue;
                float tmp = a[i1][jj] / a[i][jj];
                for(int j = 1; j <= m; j++)
                {
                    a[i1][j] = a[i1][j] - a[i][j] * tmp;
                }
            }
            fix(a, n, m);
            //p_matrix(a, n, m);
        }
        //p_matrix(a, n, m);
        int result = n;
        for(int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for(int j = 1; j <= m; j++)
            {
                if(a[i][j] == 0) cnt++;
                else break;
            }
            //cout << cnt << endl;
            if(cnt == m)
            {
                result--;
            }
        }
        cout << result << endl;
    }
}