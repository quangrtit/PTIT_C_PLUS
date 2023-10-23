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
    vector<int> a(n + 1);
    map<int, int> mp;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        cout << (*it).first << " ";
    }

}
int main()
{
    fast();
    solve();
}
/*AUTHOR: KHỔNG VĂN QUẢNG - D22CQCN06-B*/