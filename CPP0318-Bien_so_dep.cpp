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
bool task1(string s)
{
    if(s[5] < s[6] && s[6] < s[7] && s[7] < s[9] && s[9] < s[10])
    {
        return true;
    }
    if(s[5] == s[6] && s[6] == s[7] && s[7] == s[9] && s[9] == s[10])
    {
        return true;
    }
    return false;
}
bool task2(string s)
{
    if(s[5] == s[6] && s[6] == s[7] && s[9] == s[10])
    {
        return true;
    }
    return false;
}
bool task3(string s)
{
    vector<char> v = {s[5], s[6], s[7], s[9], s[10]};
    for(auto x: v)
    {
        if(x != '6' && x != '8')
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
        (task1(s) == true || task2(s) == true || task3(s) == true) ? cout << "YES" << endl : cout << "NO" << endl;
    }   
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/