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
string isprime(int n)
{
    if(n < 2)
    {
        return "NO";
    }
    else if(n == 2)
    {
        return "YES";
    }
    else
    {
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                return "NO";
            }
        }
        return "YES";
    }
}
void solve()
{
    int n; cin >> n;
    cout << isprime(n) << endl;
}
int main()
{
    fast();
    solve();
}