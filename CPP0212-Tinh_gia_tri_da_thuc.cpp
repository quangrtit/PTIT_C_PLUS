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
template<typename T, typename X>
int b_s(T valua, int l, int r, X z)
{
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(valua[mid] == z)
        {
            return mid;
        }
        else if(valua[mid] < z)
        {
            l++;
        }
        else if(valua[mid] > z)
        {
            r--;
        }
    }
    return -1;  
}
long long Mod(long long x, long long n)
{
    if(n == 0) return 1;
    long long check = x;
    while(n > 1)
    {
        check = check * x;
        check = check % MOD;
        n--;
    }
    return check;
}
void solve()
{
    int test; cin >> test;
    while(test--)
    {
        long long n, x; cin >> n >> x;
        vector<int> a(n);
        for(int i = n - 1; i >= 0; i--)
        {
            cin >> a[i];
        }
        long long tmp = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            tmp += a[i] * Mod(x, i);
            tmp %= MOD;
        }
        cout << tmp << endl;
    }
}

int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/