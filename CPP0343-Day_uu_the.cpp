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
        int odd = 0, even = 0;
        for(int i = 0; i < vx.size(); i++)
        {
            if(vx[i] % 2 == 1)
            {
                odd++;
            }
            else 
            {
                even++;
            }
        }
        if((int)vx.size() % 2 == 0)
        {
            if(even > odd) return "YES";
            else return "NO";
        }
        else 
        {
            if(even < odd) return "YES";
            else return "NO";
        }
    }
    void menu()
    {
        cin.ignore();
        while(t--)
        {
            string s; getline(cin, s);
            vector<int> v;
            stringstream ss(s);
            string tmp;
            while(ss >> tmp)
            {
                v.push_back(stoi(tmp));
            }
            cout << this->check(v) << endl;
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