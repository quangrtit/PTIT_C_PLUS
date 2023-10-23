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
            int n; cin >> n;
            int cnt = 0; 
            long long x;
            vector<long long> v;
            for(int i = 0; i < n; i++)
            {
                cin >> x;
                if(x == 0)
                {
                    cnt++;
                }
                else
                {
                    v.push_back(x);
                }
            }
            for(auto x: v)
            {
                cout << x << " ";
            }
            while(cnt--)
            {
                cout << 0 << " ";
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