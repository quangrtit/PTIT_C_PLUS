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
        bool check = true;
        int a, m; cin >> a >> m;
        for(int i = 1; i <= m - 1; i++)
        {
            if((a * i) % m == 1)
            {
                cout << i << endl;
                check = false;
                break;
            }
        }
        if(check) cout << -1 << endl;
    }
}
int main()
{
    fast();
    solve();
}