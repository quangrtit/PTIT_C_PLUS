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
        int f[n] = {1};
        f[0] = 1;
        for(int i = 1; i < n; i++)
        {
            int check = 1;
            for(int j = 0; j < i; j++)
            {
                if(a[i] > a[j])
                {
                    check = max(f[j] + 1, check);
                }
            }
            f[i] = check;
        }
        int kq = f[n - 1];
        for(int i = 0; i < n; i++)
        {
            kq = max(kq, f[i]);
        }
        cout << kq << endl;
    }   
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/