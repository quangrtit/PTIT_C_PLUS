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
    cin.ignore();
    while(t--)
    {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        stringstream s11(s1);
        stringstream s22(s2);
        string tmp1, tmp2;
        vector<string> v1, v2;
        map<string, int> mp2;
        while(s11 >> tmp1)
        {
            v1.push_back(tmp1);
        }
        while(s22 >> tmp2)
        {
            v2.push_back(tmp2);
            mp2[tmp2]++;
        }
        set<string> s;
        for(auto x: v1)
        {
            if(mp2[x] <= 0)
            {
                s.insert(x);
            }
        }
        for(auto x: s)
        {
            cout << x << " ";
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