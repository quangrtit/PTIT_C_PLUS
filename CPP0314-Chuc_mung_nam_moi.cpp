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
    int n; cin >> n;
    map<string, int> mp;
    string tmp;
    cin.ignore();
    while(n--)
    {
        getline(cin, tmp);
        mp[tmp]++;
    }
    cout << mp.size() << endl;
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
