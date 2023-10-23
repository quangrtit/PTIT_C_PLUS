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
            int n, m; cin >> n >> m;
            vector<int> a(n);
            vector<int> b(m);
            long long max_a = LLONG_MIN, min_b = LLONG_MAX;
            for(int i = 0; i < n; i++)
            {
                cin >> a[i];
                max_a = max(max_a, (long long)a[i]);
            }
            for(int i = 0; i < m; i++)
            {
                cin >> b[i];
                min_b = min(min_b, (long long)b[i]);
            }
            cout << max_a * min_b << endl;
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