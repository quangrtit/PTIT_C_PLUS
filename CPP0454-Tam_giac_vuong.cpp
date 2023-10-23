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
long long Mod(long long a, long long b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
long long pow_mod(long long a, long long b)
{
    if(b == 0) return 1;
    if(b % 2 == 0)
    {
        long long tem = pow_mod(a, b / 2);
        return Mod(tem, tem);
    }
    else
    {
        long long tem  = pow_mod(a, b / 2);
        return Mod(a, Mod(tem, tem));
    }
}
bool cmp(string a, string b)
{
    return a + b > b + a;
}
template<typename A, typename B>
int b_s(A a, int l, int r, B bi)
{
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(a[mid] == bi)
        {
            return mid;
        }
        else if(a[mid] > bi)
        {
            l++;
        }
        else 
        {
            r--;
        }
    }
    return -1;
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] = a[i] * a[i];
        }
        sort(a.begin(), a.end());
        string result = "NO";
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(binary_search(a.begin() + j, a.end(), a[i] + a[j]))
                {
                    result = "YES";
                    break;
                }
            }
            if(result == "YES") break;
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