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
bool check(long long n)
{
    long long n1 = n;
    int tmp1 = -1;
    bool kt1 = true, kt = true;
    while(n1 > 0)
    {
        if(n1 % 10 <= tmp1)
        {
            kt1 = false;
            break;
        }
        tmp1 = n1 % 10;
        n1 = n1 / 10;
    }
    int tmp = 10;
    while(n > 0)
    {
        if(n % 10 >= tmp)
        {
            kt = false;
            break;
        }
        tmp = n % 10;
        n = n / 10;
    }
    if(kt == true || kt1 == true) return true;
    else return false;
}
bool prime(long long n)
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
void solve()
{
    int t; cin >> t;
    cin.ignore();
    while(t--)
    {
        int n; cin >> n;
        long long cnt = 0;
        for(long long f = pow(10, n - 1); f < pow(10, n); f++)
        {
            if(check(f) == true)
            {
                if(prime(f) == true)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}

int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/