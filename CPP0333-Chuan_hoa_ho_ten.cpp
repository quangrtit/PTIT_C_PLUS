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
void fix(string &ok, int check)
{
    ok[0] = toupper(ok[0]);
    for(int i = 1; i < ok.size(); i++)
    {
        if(check == 1) ok[i] = tolower(ok[i]);
        if(check == 0) ok[i] = toupper(ok[i]);
    }
} 
class ptit
{
public:
    string s;
    vector<string> ss;
    ptit(){};
    friend istream& operator>>(istream& in, ptit &other)
    {
        getline(in, other.s);
        return in;
    }
    void menu()
    {
        stringstream sx(s);
        string tmp;
        while(sx >> tmp)
        {
            ss.push_back(tmp);
        }
        for(int i = 0; i < ss.size(); i++)
        {
            if(i == ss.size() - 1)
            {
                fix(ss[i], 0);
                cout << ss[i];
            }
            else if(i == ss.size() - 2)
            {
                fix(ss[i], 1);
                cout << ss[i] << ", ";
            }
            else 
            {
                fix(ss[i], 1);
                cout << ss[i] << " ";
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