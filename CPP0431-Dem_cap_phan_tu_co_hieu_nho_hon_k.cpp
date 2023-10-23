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
        int n, k, b; cin >> n >> k >> b;
        vector<int> a(n);
        map<int, int> mp;
        for(int i = 0; i < b; i++)
        {
            cin >> a[i];
            mp[a[i]] = mp.size() + 1;
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < n - 1; i++)
        {
            if(a[i] + k <= a[n - 1] - 1)
            {
                
            }
        }
    }   
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/