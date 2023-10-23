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
    string s; getline(cin, s);
    string f; cin >> f;
    int vtri = s.find(f);
    for(int i = 0; i < s.size(); i++)
    {
        if(i < vtri)
        {
            cout << s[i];
        }
        else if(i >= vtri + f.size())
        {
            cout << s[i];
        }
    }
    cout << endl;
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
