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
#define MIN = LLONG_MIN
#define MAX = LLONG_MAX
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
        int k;
        map<char, int> mp;
        string s; cin >> s; cin >> k;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        // cout << mp.size() << " " << s.size() << "\n";
        // for(auto x: mp)
        // {
        //     cout << x.first << " " << x.second << endl;
        // }
        if(k <= s.size() - mp.size() && k >= 26 - mp.size())
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
/*AUTHOR: KHỔNG VĂN QUẢNG - D22CQCN06-B
            QuảngQuả            QuảngQuả
         QuảngQuảngQu       QuảngQuảngQuảng
       QuảngQuảngQuảngQu   QuảngQuảngQuảngQuả
      QuảngQuảngQuảngQuảngQuảngQuảngQuảngQuảngQ
     QuảngQuảngQuảngQuảngQuảngQuảngQuảngQuảngQuản
    QuảngQuảngQuảngQuảngQuảngQuảngQuảngQuảngQuảngQ 
    QuảngQuảngQuảngQuảngQuảngQuảngQuảngQuảngQuảngQ 
   QuảngQuảngQuảngQuảngQuảngQuảngQuảngQuảngQuảngQu
   QuảngQuảngQuảngQuảngQuảngQuảngQuảngQuảngQuảngQu
   QuảngQuảngQuảngQuảngQuảngQuảngQuảngQuảngQuảngQ
   QuảngQuảngQuảngQuảngQuảngQuảngQuảngQuảngQuảng
    QuảngQuảngQuảngQuảngQuảngQuảngQuảngQuảngQuả
     QuảngQuảngQuảngQuảngQuảngQuảngQuảngQuảngQ
       QuảngQuảngQuảngQuảngQuảngQuảngQuảngQuả
         QuảngQuảngQuảngQuảngQuảngQuảngQuản
            QuảngQuảngQuảngQuảngQuảngQu
              QuảngQuảngQuảngQuảngQuả
                 QuảngQuảngQuảngQủa
                   QuảngQuảngQủa
                     QuảngQuản
                       QuảngQ
                        Quản
                         Qu
*/
