


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
void ucd(long long n, long long k)
{
    vector<long long> vx;
    for(int i = 2; i <= sqrt(n); i++)
    {
        while(n % i == 0)
        {
            vx.push_back(i);
            n = n / i;
        }
    }
    if(n != 1)
    {
        vx.push_back(n);
    }
    if(vx.size() < k)
    {
        cout << -1 << endl;
    }
    else 
    {
        cout << vx[k - 1] << endl;
    }

}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        long long n, k; cin >> n >> k;
        ucd(n, k);
    }
}
int main()
{
    fast();
    solve();
}