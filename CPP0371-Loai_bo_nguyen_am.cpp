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
    string s;
    vector<char> best = {'a', 'e', 'i', 'o', 'u', 'y'};
    ptit(){};
    friend istream& operator>>(istream& in, ptit &other)
    {
        in >> other.s;
        return in;
    }
    void menu()
    {
        map<int, int> mp;
        for(auto x: best)
        {
            mp[x] = 1;
            mp[x - 32] = 1;
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(mp[s[i]] == 0)
            {
                cout << "." << (char)tolower(s[i]);
            }
        }
        cout << endl;  
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