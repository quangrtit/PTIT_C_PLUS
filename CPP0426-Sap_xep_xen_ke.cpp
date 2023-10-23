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
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> b;
        sort(a, a + n, greater<int>());
        int ii = 0, jj = n - 1;
        while(ii <= jj)
        {
            if(ii == jj)
            {
                b.push_back(a[ii]);
                ii++; jj--;
                continue;
            }
            b.push_back(a[ii]);
            ii++;
            b.push_back(a[jj]);
            jj--;
        }
        for(vector<int>::iterator it = b.begin(); it != b.end(); it++)
        {
            cout << *it << " ";
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