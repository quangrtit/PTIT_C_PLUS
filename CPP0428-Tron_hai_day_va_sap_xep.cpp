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
            vector<int> a(n), b(m);
            vector<int> x;
            for(int i = 0; i < n; i++)
            {
                cin >> a[i];
                x.push_back(a[i]);
            }
            for(int i = 0; i < m; i++)
            {
                cin >> b[i];
                x.push_back(b[i]);
            }
            sort(x.begin(), x.end());
            for(auto xz: x)
            {
                cout << xz << " ";
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