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
bool prime(int n)
{
    if(n < 2)
    {
        return false;
    }
    else if(n == 2)
    {
        return true;
    }
    else
    {
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}
void kt(int n)
{
    for(int i = 2; i <= n; i++)
    {
        if(n % i == 0 && prime(i) == true)
        {
            cout << i << " ";
            return;
        }

    }
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        cout << 1 << " ";
        for(int i = 2; i <= n; i++)
        {
            kt(i);
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