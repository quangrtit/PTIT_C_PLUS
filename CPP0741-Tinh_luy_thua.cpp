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
void back_track(int j, vector<int> &a, int n, map<int, int> mp)
{
    for(int i = 1; i <= 6; i++)
    {
        if(mp[i] == 0)
        {
        a[j] = i;
        if(j == n)
        {
            for(int ix = 1; ix <= n; ix++)
            {
                cout << a[ix];
            }
            cout << " ";
        }
        else
        {
            mp[i] = 1;
            back_track(j + 1, a, n, mp);
            mp[i] = 0;
        }
        }
    }
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        long long x, y, p; cin >> x >> y >> p;
        long long tmp = 1;
        while(y--)
        {
            tmp *= x;
            tmp %= p;
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