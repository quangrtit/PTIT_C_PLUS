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
long long *a;
void sang()
{
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i <= sqrt(1000000); i++)
    {
        if(a[i] == 0)
        {
            for(int j = i * i; j <= 1000000; j += i)
            {
                a[j] = 1;
            }
        }
    }
}
void solve()
{
    a = new long long[1000000];
    sang();
    int t; cin >> t;
    while(t--)
    {
        long long n; cin >> n;
        long long ii = 2;
        long long cnt = 0;
        while(ii * ii <= n)
        {
            if(a[ii] == 0)
            {
                cnt++;
            }
            ii++;
        }
        cout << cnt << endl;
    }
    delete [] a;
}

int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/