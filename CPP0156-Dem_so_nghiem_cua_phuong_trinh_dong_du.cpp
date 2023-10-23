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
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        long long b, p; cin >> b >> p;
        long long check_mod = 0;
        for(int i = 1; i <= p - 1; i++)
        {
            if(((long long)i * i) % p == 1 && i <= b)
            {
                long long tmp = (b - i) / p;
                check_mod += tmp + 1;
            }
        }
        cout << check_mod << endl;
    }   
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/