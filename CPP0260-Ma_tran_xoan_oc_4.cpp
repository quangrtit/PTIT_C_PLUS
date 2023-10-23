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
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}
void solve()
{

    int n; cin >> n;
    vector<int> a(n * n);
    for(int i = 0; i < n * n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int sxe = 0, n1 = n;
    vector<vector<int>> v(n, vector<int>(n));
    int ii = 0; int jj = 0;
    while(n > 0)
    {   
        for(int j = jj; j < jj + n - 1; j++)
        {
            v[ii][j] = a[sxe];
            sxe++;
        }
        for(int i = ii; i < ii + n - 1; i++)
        {
            v[i][jj + n - 1] = a[sxe];
            sxe++;
        }
        for(int j = jj + n - 1; j > jj; j--)
        {
            v[ii + n - 1][j] = a[sxe];
            sxe++;
        }
        for(int i = ii + n - 1; i > ii; i--)
        {
            v[i][jj] = a[sxe];
            sxe++;
        }
        ii++; jj++;
        n -= 2;
    }
    if(n1 % 2 == 1) v[n1 / 2][n1 / 2] = a[sxe];
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    } 
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/