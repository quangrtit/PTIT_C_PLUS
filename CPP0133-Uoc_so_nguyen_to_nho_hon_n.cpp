


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
void ucd(long long n)
{
    long long check = 1;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            check = i;
            while(n % i == 0)
            {
                n = n / i;       
            }
        }
    }
    if(n != 1)
    {
        check = max(check, n);
    }
    cout << check << endl;
    
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        long long n; cin >> n;
        for(int i = 2; i <= n; i++)
        {
            if(isprime(i))
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    fast();
    solve();
}