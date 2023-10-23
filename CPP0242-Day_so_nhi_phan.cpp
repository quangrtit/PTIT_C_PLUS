#include<iostream>
#include<unistd.h>
#include<math.h>
#include<string>
#include<cctype>
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
    int test; cin >> test;
    while(test--)
    {
        int n; cin >> n;
        vector<int> a(n + 1), b(n + 1);
        vector<int> mp_a(n + 1), mp_b(n + 1);
        mp_a[0] = 0; mp_b[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            mp_a[i] = mp_a[i - 1] + a[i];
        }
        for(int i = 1; i <= n; i++)
        {
            cin >> b[i];
            mp_b[i] = mp_b[i - 1] + b[i];
        }
        // for(auto x: mp_a)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        // for(auto x: mp_b)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        int check_max = 0;
        int result = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i; j <= n; j++)
            {
                if(mp_b[j] - mp_b[i - 1] == mp_a[j] - mp_a[i - 1])
                {
                    check_max = max(check_max, j - i + 1);
                    result = mp_b[j] - mp_b[i - 1];
                }
            }
        }
        cout << check_max << endl;
    }
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/