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
void solve()
{
    int test; cin >> test;
    while(test--)
    {
        long long x, y, z; cin >> x >> y >> z;
        int n; cin >> n;
        long long a = __gcd(x, y);
        long long tmp = x * y / a;
        long long b = __gcd(tmp, z);
        long long lcm = tmp * z / b;
        long long ii = max((long long)1, ((long long)pow(10, n - 1) / lcm - 1));
        long long result = -1;
        // cout << lcm << endl;
        while(check(ii * lcm, n))
        {
            string s = to_string(ii * lcm);
            if(s.size() == n)
            {
                result = ii * lcm;
                break;
            }
            ii++;
        }
        cout << result << endl;
    }
}

int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/