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
    cin.ignore();
    while(t--)
    {
        string s; getline(cin, s);
        stringstream ss(s);
        string tmp;
        int cnt = 0;
        while(ss >> tmp)
        {
            cnt++;
            // cout << tmp << endl;
        }
        cout << cnt << endl;
    }
}

int main()
{
    fast();
    solve();
}
/*AUTHOR: KHỔNG VĂN QUẢNG - D22CQCN06-B*/