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
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        int n, r; cin >> n >> r;
        if(n == 0 || n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        // C(n, r) suy ra n! / r!(n - r)! = (n.... n - r + 1) / r!
        vector<pair<int, int>> a;
        vector<pair<int, int>> b;
        map<int, int> a1;
        for(int f1 = n - r + 1; f1 <= n; f1++)
        {
            int f = f1;
            for(int i = 2; i <= sqrt(f); i++)
            {
                if(f % i == 0)
                {
                    int cnt = 0;
                    while(f % i == 0)
                    {
                        cnt++;
                        f = f / i;
                    }
                    a1[i] += cnt;
                }
            }
            if(f != 1) a1[f] += 1;
        }
        map<int, int> b1;
        for(int f1 = 2; f1 <= r; f1++)
        {
            int f = f1;
            for(int i = 2; i <= sqrt(f); i++)
            {
                if(f % i == 0)
                {
                    int cnt = 0;
                    while(f % i == 0)
                    {
                        cnt++;
                        f = f / i;
                    }
                    b1[i] += cnt;
                }
            }
            if(f != 1) b1[f] += 1;
        }
        vector<pair<int, int>> result;
        for(auto x: a1)
        {
            a.push_back({x.first, x.second});
        }
        for(auto x: b1)
        {
            b.push_back({x.first, x.second});
        }
        int ii = 0, jj = 0;
        while(ii < a.size() && jj < b.size())
        {
            if(a[ii].first == b[jj].first)
            {
                if(a[ii].second != b[jj].second)
                {
                    result.push_back({a[ii].first, a[ii].second - b[jj].second});
                }
                ii++; jj++;
            }
            else if(a[ii].first != b[jj].first)
            {
                result.push_back({a[ii].first, a[ii].second});
                ii++;
            }
        }
        if(ii < a.size())
        {
            for(int i = ii; i < a.size(); i++)
            {
                result.push_back({a[i].first, a[i].second});
            }
        }
        // for(auto x: a)
        // {
        //     cout << x.first << "^" << x.second << " . ";
        // }
        // cout << endl;
        // for(auto x: b)
        // {
        //     cout << x.first << "^" << x.second << " . ";
        // }
        // cout << endl;
        // for(auto x: result)
        // {
        //     cout << x.first << "^" << x.second << " . ";
        // }
        // cout << endl;
        long long product_check = 1;
        for(int i = 0; i < result.size(); i++)
        {
            product_check *= pow_mod(result[i].first, result[i].second);
            product_check %= MOD;
        }
        cout << product_check << endl;
    }
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/