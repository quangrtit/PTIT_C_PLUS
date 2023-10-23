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

void backtrack(vector<vector<char>> &a, int i, int j, int n, int m)
{
    if(a[i][j] == 'O')
    {
        a[i][j] = 'Y';
        if(i + 1 <= n)
        {
            backtrack(a, i + 1, j, n, m);
        }
        if(i - 1 >= 1)
        {
            backtrack(a, i - 1, j, n, m);
        }
        if(j + 1 <= m)
        {
            backtrack(a, i, j + 1, n, m);
        }
        if(j - 1 >= 1)
        {
            backtrack(a, i, j - 1, n, m);
        }
    }
}
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        vector<vector<char>> a(n + 1, vector<char>(m + 1));
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
                if(a[i][j] == 'O' && (i == 1 || j == 1 || i == n || j == m))
                {
                    backtrack(a, i, j, n, m);
                } 
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(a[i][j] != 'Y')
                {
                    cout << "X" << " ";
                }
                else 
                {
                    cout << "O" << " ";
                }
            }
            cout << endl;
        }
    }
}