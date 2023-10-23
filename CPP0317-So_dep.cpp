#include<iostream>
#include<unistd.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
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
// class ptit
// {
// public:
//     int t;
//     string n;
//     ptit(){};
//     friend ifstream& operator>>(ifstream& in, ptit &other)
//     {
//         in >> other.n;
//         return in;
//     }
//     friend ofstream& operator<<(ofstream& out, ptit other)
//     {
//         out << other.n;
//     } 
//     ~ptit(){}
// }
bool nice(string s)
{
    for(int i = 0; i < s.size() / 2; i++)
    {
        if(s[i] != s[s.size() - 1 - i])
        {
            return false;
        }
    }
    int cnt = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if((s[i] - '0') % 2 == 1)
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        string n; cin >> n;
        nice(n) == true ? cout << "YES" << endl : cout << "NO" << endl;
    }
}
int main()
{
    fast();
    solve(); 
}