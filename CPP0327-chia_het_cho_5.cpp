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
void solve();
int main()
{
    fast();
    solve(); 
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        long long sum_digit;
        if(s[(int)s.size() - 1] == '0') sum_digit = 0;
        else sum_digit = 1;
        int cnt = 1;
        for(int i = (int)s.size() - 2; i >= 0; i--)
        {
            if(s[i] != '0')
            {
                if(cnt % 4 == 1) sum_digit += 2;
                else if(cnt % 4 == 2) sum_digit += 4;
                else if(cnt % 4 == 3) sum_digit += 8;
                else if(cnt % 4 == 0) sum_digit += 6;
            }
            cnt++;
        }
        // cout << sum_digit << endl;
        sum_digit % 5 == 0 ? cout << "Yes" << endl : cout << "No" << endl;
    }

}
