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
    string check(vector<int> vx)
    {
        
    }
    void menu()
    {
        while(t--)
        {
            string s; cin >> s;
            vector<pair<char, int>> v;
            char tmp = s[0];
            for(int i = 0; i < s.size(); i++)
            {
                if(v.empty())
                {
                    v.push_back({s[0], 1});
                    tmp = s[0];
                    continue;
                }
                if(s[i] == tmp)
                {
                    v[v.size() - 1].second++;
                    tmp = s[i];
                }
                else
                {
                    v.push_back({s[i], 1});
                    tmp = s[i];
                }
            }
            for(auto x: v)
            {
                cout << x.first << x.second;
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