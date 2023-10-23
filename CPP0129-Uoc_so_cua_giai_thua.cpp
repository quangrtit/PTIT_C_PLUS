#include<iostream>
#include<unistd.h>
#include<math.h>
#include<string.h>
#include<cctype>
#include<set>
#include<limits.h>
#include<map>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<deque>
using namespace std;
#define MOD 1000000007
#define endl '\n'
#define fast() ios::sync_with_stdio(false); cin.tie(0);

// log(p)(n) = log10(n) / log10(p)
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, p; cin >> n >> p;
        double tmp = log10(n) / log10(p);
        int cnt = 0;
        for(int i = p; i <= n; i += p)
        {
            int check_p = i;
            while(check_p % p == 0)
            {
                cnt += 1;
                check_p = check_p / p;
            }
        }
        cout << cnt << endl;
    }
}
/*AUTHOR: KHỔNG VĂN QUẢNG - PTIT*/