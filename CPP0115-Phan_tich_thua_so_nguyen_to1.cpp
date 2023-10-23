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
        int n; cin >> n;
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                int cnt = 0;
                while(n % i == 0)
                {
                    n = n / i;
                    cnt++;
                }
                cout << i << " " << cnt << " ";
            }
        }
        if(n != 1)
        {
            cout << n << " " << 1;
        }
        cout << endl;   
    }
}
int main()
{
    fast();
    solve();
}