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
int a[10005];
void sang()
{
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i <= sqrt(10004); i++)
    {
        if(a[i] == 0)
        {
            a[i] = i;
            for(int j = i * i; j <= 10004; j += i)
            {
                if(a[j] == 0) a[j] = i;
            }
        }
    }
}
void solve()
{
    sang();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] != 0) cout << a[i] << " ";
            else cout << i << " ";
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