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
int tcs(int n)
{
    int cnt = 0;
    while(n > 0)
    {
        cnt += n % 10;
        n = n / 10;
    }
    return cnt;
}
void check(int n)
{
    if(n <= 9)
    {
        if(n == 9)
        {
            cout << 1 << endl;
        }
        else 
        {
            cout << 0 << endl;
        }
        return;
    }
    check(tcs(n));
}

void solve()
{
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++)
        {
            cnt += s[i] - '0';
        }
        if(cnt < 9)
        {
            cout << 0 << endl;
            continue;
        }
        else if(cnt == 9)
        {
            cout << 1 << endl;
            continue;
        }
        else 
        {
            check(cnt);
        }
    }   
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/