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
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        int result = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(i % 2 == 0)
            {
                result += s[i] - '0';
            }
            else
            {
                result -= s[i] - '0';
            }
        }
        result % 11 == 0 ? cout << 1 << endl : cout << 0 << endl;
    }
}
int main()
{
    fast();
    solve(); 
}