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
    if(s.size() == 2)
    {
        if(abs(s[0] - s[1]) == 1)
        {
            return true;
        }
        return false;
    }
    for(int i = 1; i < s.size() - 1; i++)
    {
        if(!(abs(s[i] - s[i - 1]) == 1 && 1 == abs(s[i] - s[i + 1])))
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
        if(check(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
int main()
{
    fast();
    solve();
}