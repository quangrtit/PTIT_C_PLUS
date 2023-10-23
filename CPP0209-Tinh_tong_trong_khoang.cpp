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
#define MIN = LLONG_MIN
#define MAX = LLONG_MAX
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
        int n, q; cin >> n >> q; 
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        long long f[n + 1] = {0};
        f[0] = 0;
        f[1] = a[1];
        for(int i = 2; i <= n; i++)
        {
            f[i] = f[i - 1] + a[i];
        }
        while(q--)
        {
            int l, r; cin >> l >> r;
            cout << f[r] - f[l - 1] << endl;
        }
    }
}
int main()
{
    fast();
    solve();
}
/*AUTHOR: KHỔNG VĂN QUẢNG - D22CQCN06-B*/