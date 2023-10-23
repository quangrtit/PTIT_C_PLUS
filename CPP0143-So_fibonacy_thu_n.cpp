#include<iostream>
#include<unistd.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
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
bool isprime(int n)
{

    if(n < 2)
    {
        return false;
    }
    else if(n == 2)
    {
        return true;
    }
    else
    {
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}
long long f[100];
void fibo()
{
    f[1] = 1;
    f[2] = 1;
    int ii = 3;
    while(ii <= 92)
    {
        f[ii] = f[ii - 1] + f[ii - 2];
        ii++;
    }
}
void solve()
{
    fibo();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        cout << f[n] << endl;
    }
}
int main()
{
    fast();
    solve();
}