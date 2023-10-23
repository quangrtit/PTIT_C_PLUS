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
// long long a[93];
// map<long long, int> mp;
// void fibo()
// {
//     a[0] = 0;
//     a[1] = 1;
//     a[2] = 1;
//     mp[1] = 1;
//     int ii = 3;
//     while(ii < 93)
//     {
//         a[ii] = a[ii - 1] + a[ii - 2];
//         mp[a[i]] = 1;
//     } 
// }
void solve()
{
    int test; cin >> test;
    while(test--)
    {
        long long n; cin >> n;
        if(n <= 1)
        {
            cout << "YES" << endl;
            continue;
        }
        long long a1 = 1, a2 = 1;
        long long tmp = 0;
        bool check = true;
        while(tmp <= n)
        {
            tmp = a1 + a2;
            if(tmp == n)
            {
                cout << "YES" << endl;
                check = false; break;
            }
            a1 = a2;
            a2 = tmp;
        }
        if(check) cout << "NO" << endl;
    }
}

int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/