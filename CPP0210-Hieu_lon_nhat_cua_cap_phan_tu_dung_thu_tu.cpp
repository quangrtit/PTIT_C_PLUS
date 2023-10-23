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
bool check(long long a, long long n)
{
    string s = to_string(a);
    if(s.size() <= n)
    {
        return true;
    }
    return false;
}
vector<int> a(100002);
void sang()
{
    a[0] = 1; a[1] = 1;
    for(int i = 2; i <= sqrt(100001); i++)
    {
        if(a[i] == 0)
        {
            for(int j = i * i; j <= 100001; j += i)
            {
                a[j] = 1;
            }
        }
    }
}
void solve()
{
    sang();
    int test; cin >> test;
    while(test--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        int check_max = -1;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                check_max = max(check_max, a[j] - a[i]);
            }
        }
        cout << check_max << endl;
    }
}

int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/