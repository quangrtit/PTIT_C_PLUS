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
#define fast() ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);

long long Mod(long long a, long long b, long long c)
{
    if(b == 0) return 0;
    if(b % 2 == 0)
    {
        return (Mod(a, b / 2, c) * 2) % c;
    }
    else 
    {
        return (Mod(a, b / 2, c) * 2 + a) % c;
    }
}

void solve()
{
    int t; cin >> t;
    while(t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << Mod(a, b, c) << endl;
    }
}
int main()
{
    fast();
    solve(); 

}
/*AUTHOR: KHỔNG VĂN QUẢNG*/