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
        for(int i = 0; i < n; i++)
        {
            cin >> f[i];
        }
        sort(f, f + n);
        int check = abs(f[0] - f[1]);
        for(int i = 0; i < n - 1; i++)
        {
            check = min(check, abs(f[i] - f[i + 1]));
        }
        cout << check << endl;
        delete [] f;
    }
}
int main()
{
    fast();
    solve();
}