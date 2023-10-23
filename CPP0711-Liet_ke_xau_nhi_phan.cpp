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
void back_track(int j, vector<int> &a, int n)
{
    for(int i = 0; i <= 1; i++)
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
            back_track(j + 1, a, n);
        }
    }
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n + 1);
        back_track(1, a, n);
        cout << endl;
    }
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/