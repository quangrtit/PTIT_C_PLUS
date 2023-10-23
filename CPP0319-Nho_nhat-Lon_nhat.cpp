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
    int m, s; cin >> m >> s;
    if(s <= 9)
    {
        cout << 1 << s - 1 << " " << s - 1 << 1 << endl;
        return;
    }
    vector<int> v;
    while(m--)
    {
        v.push_back(9);
        s -= 9;
    }
    if(s > 10)
    {
        cout << -1 << " " << -1 << endl;
        return;
    }
    if(m > 0)
    {
        cout << -1 << " " << -1 << endl;
        return;
    }
    v.push_back(s);
    vector<int> v2 = v;
    sort(v.begin(), v.end());
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it;
    }
    cout << " ";
    for(auto x: v2)
    {
        cout << x;
    }
    cout << endl;
}
int main()
{
    fast();
    solve(); 
}