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
        int n; cin >> n; 
        vector<int> a(n + 1);
        map<int, int> mp;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        long long cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(mp[a[i]] >= 2)
            {
                cnt += mp[a[i]];
                mp[a[i]] = 0;
            }
        }
        cout << cnt << endl;
    }
}

int main()
{
    fast();
    solve();
}
/*AUTHOR: KHỔNG VĂN QUẢNG - D22CQCN06-B*/