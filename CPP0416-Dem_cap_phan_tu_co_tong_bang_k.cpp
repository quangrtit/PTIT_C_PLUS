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
class ptit
{
public:
    int t; 
    ptit(){};
    friend istream& operator>>(istream& in, ptit &other)
    {
        in >> other.t;
        return in;
    }
    void menu()
    {
        while(t--)
        {
            int n, k; cin >> n >> k;
            vector<int> a(n);
            map<int, int> mp;
            for(int i = 0; i < n; i++)
            {
                cin >> a[i];
                mp[a[i]]++;
            }
            long long cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if(mp[a[i]] > 0 && mp[k - a[i]] > 0)
                {
                    if(a[i] != k - a[i])
                    {
                        cnt += mp[a[i]] * mp[k - a[i]];
                    }
                    else
                    {
                        cnt += mp[a[i]] * (mp[k - a[i]] - 1) / 2;
                    }
                    mp[a[i]] = 0; mp[k - a[i]] = 0;
                }
            }
            cout << cnt << endl;
        }
    } 
    ~ptit(){}
};
void solve()
{
    ptit a;
    cin >> a;
    a.menu();
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/