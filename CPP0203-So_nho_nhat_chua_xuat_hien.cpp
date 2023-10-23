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
        int n; cin >> n;
        int* f = new int[n];
        map<int, int> mp;
        for(int i = 0; i < n; i++)
        {
            cin >> f[i];
            mp[f[i]]++;
        }
        int ii = 1;
        while(1)
        {
            if(mp[ii] == 0)
            {
                cout << ii << endl;
                break;
            }
            ii++;
        }
        delete [] f;
    }
}
int main()
{
    fast();
    solve();
}