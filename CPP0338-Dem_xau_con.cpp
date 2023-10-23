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
        string s; cin >> s;
        int k; cin >> k;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++)
        {
            map<char, int> mp;
            for(int j = i; j < s.size(); j++)
            {
                mp[s[j]]++;
                if(mp.size() == k)
                {
                    cnt++;
                }
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
/*AUTHOR: KHỔNG VĂN QUẢNG*/