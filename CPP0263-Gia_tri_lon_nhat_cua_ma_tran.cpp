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
    int n; cin >> n;
    int a[n + 1][n + 1];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> f(2 * n + 1, vector<int>(n + 1));
    for(int i = 2; i <= 2 * n; i++)
    {
        if(i <= n + 1)
        {
            int ii = i - 1;
            int vtri = 1;
            while(ii > 0 && vtri <= n)
            {
                f[i][vtri] = f[i][vtri - 1] + a[ii][vtri];
                vtri++; ii--;
            }
        }
        else if(i >= n + 2)
        {
            int jj = i - n;
            int vtri = n;
            while(vtri > 0 && jj <= n)
            {
                f[i][jj] = f[i][jj - 1] + a[vtri][jj];
                vtri--; jj++;
            }
        }
    }
    int check_max = 0;
    vector<vector<int>> result(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            result[i][j] = a[i][j];
            for(int d = 1; d <= n; d++)
            {
                if(i + d <= n && j + d <= n) result[i + d][j + d] = result[i + d - 1][j + d - 1] + a[i + d][j + d];
                if(i + d <= n && j + d <= n) check_max = max(check_max, result[i + d][j + d] - (f[i + j + d][j + d] - f[i + j + d][j - 1]));
            }   
        }
    }
    cout << check_max << endl;
}