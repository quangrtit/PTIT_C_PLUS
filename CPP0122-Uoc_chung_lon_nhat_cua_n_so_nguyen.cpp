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
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        long long n; cin >> n;
        long long lcm = 1;
        for(int i = 2; i <= n; i++)
        {
            long long gcd = __gcd(lcm, (long long)i);
            lcm = lcm * i / gcd;
        }
        cout << lcm << endl;
    }
}
int main()
{
    fast();
    solve();
}