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
bool check(string s)
{
    if(s[0] == '0')
    {
        return false;
    }
    for(int i = 0; i < s.size(); i++)
    {
        if(!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        if(check(s) == false)
        {
            cout << "INVALID" << endl;
            continue;
        }
        map<char, int> mp;
        for(auto x: s)
        {
            mp[x]++;
        }
        if(mp.size() == 10)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }   
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/