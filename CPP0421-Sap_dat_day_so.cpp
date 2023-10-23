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
            long long n; cin >> n;
            vector<long long> a(n);
            map<long long, long long> mp;
            for(int i = 0; i < n ; i++)
            {
                cin >> a[i];
                if(a[i] <= n - 1 && a[i] >= 0)
                {
                    mp[a[i]]++;
                }
            }
            for(int i = 0; i < n ; i++)
            {
                mp[i] > 0 ? cout << i << " " : cout << -1 << " ";
            }
            cout << endl;
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