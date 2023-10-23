#include<iostream>
#include<unistd.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
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
        if(s[s.size() - 1] == '6' && s[s.size() - 2] == '8')
        {
            cout << 1 << endl;  
        }
        else
        {
            cout << 0 << endl;
        }
    }
}
int main()
{
    fast();
    solve();
}