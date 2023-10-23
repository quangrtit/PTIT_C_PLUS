#include<iostream>
#include<math.h>
#include<cmath>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<set>
#include<limits.h>
#include<map>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<deque>
#include<bitset>
using namespace std;
#define MOD 1000000007
#define endl '\n'
#define fast() ios::sync_with_stdio(false); cin.tie(0);

void solve()
{
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        int dd[26];
        memset(dd, 0, sizeof(dd));
        map<int, int> mp; int size = 0;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        int l = 0;
        size = mp.size();
        int vtri = 0;
        map<int, int> mpx;
        for(int i = 0; i < s.size(); i++)
        {
            dd[s[i] - 'a']++;
            mpx[s[i]]++;
            if(mpx.size() == size)
            {
                vtri = i; dd[s[i] - 'a']--; break;
            }
        }
        int ans = vtri + 1;
        // cout << "rs" << ans << endl;
        for(int i = vtri; i < s.size(); i++)
        {
            dd[s[i] - 'a']++;
            while(dd[s[l] - 'a'] > 1)
            {
                if(dd[s[l] - 'a'] > 1) dd[s[l] - 'a']--;
                l++;
            }
            ans = min(ans, i - l + 1);
        }
        cout << ans << endl;
    }
}
int main()
{
    fast();
    solve();
}
