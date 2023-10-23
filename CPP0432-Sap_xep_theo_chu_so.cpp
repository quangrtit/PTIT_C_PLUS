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
long long Mod(long long a, long long b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
long long pow_mod(long long a, long long b)
{
    if(b == 0) return 1;
    if(b % 2 == 0)
    {
        long long tem = pow_mod(a, b / 2);
        return Mod(tem, tem);
    }
    else
    {
        long long tem  = pow_mod(a, b / 2);
        return Mod(a, Mod(tem, tem));
    }
}
bool cmp(string a, string b)
{
    return a + b > b + a;
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<string> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), cmp);
        // for(int i = 1; i < a.size(); i++)
        // {
        //     cout << a[i - 1] + a[i] << " " << a[i] + a[i - 1] << endl;
        //     if(a[i - 1] + a[i] < a[i] + a[i - 1])
        //     {
        //         swap(a[i - 1], a[i]);
        //     }
        // }
        for(auto x: a)
        {
            cout << x;
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