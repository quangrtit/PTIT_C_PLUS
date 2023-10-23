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
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second != b.second)
    {
        return a.second > b.second;
    }
    else 
    {
        return a.first < b.first;
    }
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        int check_max = (*mp.begin()).second;
        for(auto x: mp)
        {
            check_max = max(check_max, x.second);
        }
        if(check_max > (s.size() + 1)/ 2)
        {
            cout << 0 << endl;
        }
        else 
        {
            cout << 1 << endl;
        }
        
    }
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/