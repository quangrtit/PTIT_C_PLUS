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
int a[10000];
void sang()
{
    for(int i = 0; i < 10000; i++)
    {
        a[i] = 0;
    }
    a[0] = 1; a[1] = 1;
    for(int i = 2; i < 10000; i++)
    {
        for(int j = i * 2; j < 10000; j = j + i)
        {
            a[j] = 1;
        }
    }
}
void solve()
{
    sang();
    int t; cin >> t;
    while(t--)
    {
        int ii = 0;
        int n; cin >> n;
        for(int i = 2; i <= 1000; i++)
        {
            if(a[i] == 0)
            {
                if(i * i <= n)
                {
                    cout << i * i << " ";
                }
                else 
                {
                    break;
                }
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