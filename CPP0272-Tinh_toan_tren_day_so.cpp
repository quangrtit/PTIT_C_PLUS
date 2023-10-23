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
#include<vector>
using namespace std;
#define MOD 1000000007
#define endl '\n'
#define fast() ios::sync_with_stdio(false); cin.tie(0);

long long mod(long long a, long long b)
{
    return ((a % MOD) * (b % MOD)) % MOD; 
}
long long pow_mod(long long a, long long b)
{
    if(b == 0) return 1;
    if(b % 2 == 0)
    {
        long long tem = pow_mod(a, b / 2);
        return mod(tem, tem);
    }
    else 
    {
        long long tem = pow_mod(a, b / 2);
        return mod(a, mod(tem, tem));
    }
}
int main()
{
    fast();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        long long hx = 1, gcd = 1;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            hx = mod(a[i], hx);
        }
        gcd = a[0];
        for(int i = 0; i < n; i++)
        {
            gcd = __gcd(gcd, (long long)a[i]);
        }
        cout << pow_mod(hx, gcd) << endl;
        // solve  hx ^ gcd
    }
}