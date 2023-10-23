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
long long f[40];
map<long long, int> mp;
void fibo()
{
    f[0] = 0;
    f[1] = 1;
    mp[0] = 1;
    mp[1] = 1;
    for(int i = 2; i <= 39; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        mp[f[i]] = 1;
    }
}
void solve()
{
    fibo();
    int test; cin >> test;
    while(test--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++)
        {
            if(mp[a[i]] == 1)
            {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/