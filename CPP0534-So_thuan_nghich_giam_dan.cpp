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
#define fast() ios::sync_with_stdio(false); cin.tie(0);

struct pari
{
    string s; int cnt = 0;
    pari(string ss, int cnt1){s = ss; cnt = cnt1;}
};
vector<pari> v;
bool check(string s)
{
    for(int i = 0; i < s.size() / 2; i++)
    {
        if(s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}
void what(string s1)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].s == s1)
        {
            v[i].cnt++;  return;
        }
    }
    v.push_back(pari(s1, 1));
}
bool cmp(pari a, pari b)
{
    if(a.s.size() != b.s.size())
    {
        return a.s.size() > b.s.size();
    }
    else
    {
        return a.s > b.s;
    }
}
int main()
{   
    string s;
    while(cin >> s)
    {
        if(check(s))
        {
            what(s);
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(auto x: v)
    {
        if(x.s.size() != 1)cout << x.s << " " << x.cnt << endl;
    }
}