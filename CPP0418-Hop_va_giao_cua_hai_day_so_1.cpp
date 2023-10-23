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
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        map<int, int> mp, mp_a, mp_b;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
            mp_a[a[i]]++;
        }
        for(int i = 0; i < m; i++)
        {
            cin >> b[i];
            mp[b[i]]++;
            mp_b[b[i]]++;
        }
        for(auto x: mp)
        {
            cout << x.first << " ";
        }
        cout << endl;
        sort(a.begin(), a.end());
        for(int i = 0; i < a.size(); i++)
        {
            if(mp_b[a[i]] > 0)
            {
                cout << a[i] << " ";
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
/*AUTHOR: KHỔNG VĂN QUẢNG*/