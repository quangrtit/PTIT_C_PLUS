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
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        int n, d; cin >> n >> d;
        int* f = new int[n + 1];
        int* a = new int[n + 1];
        for(int i = 1; i <= n; i++)
        {
            cin >> f[n + 1 - i];
            if(n + 1 - i + d > n) a[(n + 1 - i + d) % n] = f[n + 1 - i];
            else a[(n + 1 - i + d)] = f[n + 1 - i];
        }
        for(int i = 1; i <= n; i++)
        {
            cout << a[n + 1 - i] << " ";
        }
        cout << endl;
        delete [] a;
        delete [] f;
    }
}
int main()
{
    fast();
    solve();
}