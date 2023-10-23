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
        if(s.size() == 1)
        {
            cout << -1 << endl;
            continue;
        }
        // kiểm tra xem có là dãy giảm xét từ cuối không
        int ii = s.size() - 2;
        while(s[ii] <= s[ii + 1])
        {
            ii--;
        }
        if(ii < 0)
        {
            cout << -1 << endl;
            continue;
        }
        int vtri = ii + 1;
        int check_max = s[ii] - s[ii + 1];
        for(int i = ii + 1; i < s.size(); i++)
        {
            if(s[i] < s[ii])
            {
                if(s[ii] - s[i] < check_max)
                {
                    check_max = s[ii] - s[i];
                    vtri = i;
                }
            }
        }
        swap(s[ii], s[vtri]);
        cout << s << endl;
    }   
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/