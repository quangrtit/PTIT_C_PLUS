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
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        for(int i = 0; i < s.size(); i++)
        {
            if(!isdigit(s[i]))
            {
                s[i] = ' ';
            }
        }
        stringstream ss(s);
        string tmp;
        long long sum_digit = 0;
        while(ss >> tmp)
        {
            sum_digit += stoll(tmp);
        }
        cout << sum_digit << endl;
    }   
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/