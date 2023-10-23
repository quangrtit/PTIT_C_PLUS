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
        string s1, s2;
        cin >> s1 >> s2;
        string s1_min = s1, s1_max = s1;
        string s2_min = s2, s2_max = s2;
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] == '6')
            {
                s1_min[i] = '5';
            }
            if(s1[i] == '5')
            {
                s1_max[i] = '6';
            }
        }
        for(int i = 0; i < s2.size(); i++)
        {
            if(s2[i] == '6')
            {
                s2_min[i] = '5';
            }
            if(s2[i] == '5')
            {
                s2_max[i] = '6';
            }
        }
        long long p_min = stoll(s1_min) + stoll(s2_min);
        long long p_max = stoll(s1_max) + stoll(s2_max);
        cout << p_min << " " << p_max << endl;
    }
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/