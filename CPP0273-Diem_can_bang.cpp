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
        vector<int> a(n + 1);
        long long result = 0;
        vector<long long> f(n + 1);
        f[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            result += a[i];
            f[i] = f[i - 1] + a[i];
        }
        int pivot = -1;
        for(int i = 1; i <= n; i++)
        {
            if(f[i] == result - f[i] + a[i])
            {
                pivot = i;
                break;
            }
        }
        cout << pivot << endl;
    }
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/