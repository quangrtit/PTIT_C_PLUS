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
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        int i = 0;
        while(i < s.size())
        {
            if(s[i] == '0' && s[i + 1] == '8' && s[i + 2] == '4' && i <= s.size() - 3)
            {
                i = i + 3;
            }
            else
            {
                cout << s[i];
                i++;
            }
        }
        cout << endl;
    }
}
int main()
{
    fast();
    solve();
}