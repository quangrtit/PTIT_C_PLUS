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
#define MIN = LLONG_MIN
#define MAX = LLONG_MAX
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
            vector<int> a(n);
            for(int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            sort(a.begin(), a.end(), greater<int>());
            map<int, int> mp;
            for(int i = 0; i < n; i++)
            {
                if(mp[i] == 0)
                {
                    if(i != a.size() - i - 1) cout << a[i] << " " << a[a.size() - 1 - i] << " ";
                    else cout << a[i] << " ";
                    mp[i] = 1; mp[a.size() - 1 - i] = 1;
                }
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