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
        vector<int> a(n);
        int check_zero = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n - 1; i++)
        {
            if(a[i] == a[i + 1] && a[i + 1] != 0)
            {
                
                a[i] = a[i] * 2;
                a[i + 1] = 0;
            }
        }
        // for(auto x: a)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == 0) check_zero++;
        }
        for(int i = 0; i < n; i++)
        {
            if(a[i] != 0) cout << a[i] << " ";
        }
        while(check_zero--)
        {
            cout << 0 << " ";
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