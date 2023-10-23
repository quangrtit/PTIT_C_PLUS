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
long long sqrt_a(string a, long long m)
{
    long long sum = 0;
    for(int i = 0; i < a.size(); i++)
    {
        sum = (sum * 10 + a[i] - '0') % m; 
    }
    return sum;
}
long long mod(long long a, long long b, long long m)
{
    return ((a % m) * (b % m)) % m;
}
long long pow_mod(long long tmp, long long b, long long m)
{
    if(b == 0) return 1;
    if(b % 2 == 0)
    {
        long long tem = pow_mod(tmp, b / 2, m);
        return mod(tem, tem, m);
    }
    else 
    {
        long long tem = pow_mod(tmp, b / 2, m);
        return mod(mod(tem, tem, m), tmp, m);
    }
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        string a; cin >> a;
        long long b, m; cin >> b >> m;
        long long result_begin = sqrt_a(a, m);
        long long tmp = result_begin;
        cout << pow_mod(tmp, b, m) << endl;
    }   
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/