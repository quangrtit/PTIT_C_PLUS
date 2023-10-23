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
int cnt = 0;
void back_track(int j, vector<int> &a, int n, map<int, int> mp)
{
    for(int i = 1; i <= n; i++)
    {
        if(mp[i] == 0)
        {
            a[j] = i;
            if(j == n)
            {
                for(int e = 1; e <= n; e++)
                {
                    cout << a[e];
                }
                cout << " ";
            }
            else 
            {
                mp[i] = 1;
                back_track(j + 1, a, n, mp);
                mp[i] = 0;
            }
        }
    }
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n + 1);
        map<int, int> mp;
        a[0] = -1;
        back_track(1, a, n, mp);
        cout << endl;
    }   
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/