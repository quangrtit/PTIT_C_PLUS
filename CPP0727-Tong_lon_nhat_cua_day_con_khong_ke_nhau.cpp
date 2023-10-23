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
#define fast() ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        // sort(a.begin(), a.end());
        vector<long long> f(n);
        multiset<long long> s;
        int ii = 0;
        for(int i = 0; i < n; i++)
        {
            if(i <= 1)
            {
                f[i] = a[i];
                continue;
            }
            s.insert(f[ii]); ii++;
            auto tmp = s.rbegin();
            f[i] = *tmp + a[i];
        }
        long long check_max = f[0];
        for(int i = 0; i < n; i++)
        {
            check_max = max(check_max, f[i]);
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