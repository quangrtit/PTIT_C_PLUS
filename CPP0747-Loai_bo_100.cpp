#include<iostream>
#include<unistd.h>
#include<math.h>
#include<string.h>
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
#define fast() ios::sync_with_stdio(false); cin.tie(0);

void backtrack(string &s, bool f[], long long &cnt, int ii, int jj)
{
    if(ii >= 0 && jj < s.size() && f[ii] == false && f[jj] == false)
    {
        //cout << ii << " " << jj << endl;
        string tmp = "";
        int ii1 = ii, jj1 = jj;
        while(f[ii1] == false && ii1 <= jj1)
        {
            tmp += s[ii1];
            ii1++;
        }
        while(f[jj1] == false && ii1 <= jj1)
        {
            tmp += s[jj1];
            jj1--;
        }
        if(tmp == "100")
        {
            cnt += 3;
            int ii2 = ii, jj2 = jj;
            while(f[ii2] == false && ii2 <= jj2)
            {
                f[ii2] = true;
                ii2++;
            }
            while(f[jj2] == false && ii2 <= jj2)
            {
                f[jj2] = true;
                jj2--;
            }
            if(ii - 1 >= 0 && jj + 2 < s.size()) backtrack(s, f, cnt, ii - 1, jj + 2);
            if(ii - 2 >= 0 && jj + 1 < s.size()) backtrack(s, f, cnt, ii - 2, jj + 1);
            if(ii - 3 >= 0 && jj < s.size()) backtrack(s, f, cnt, ii - 3, ii - 1);
            if(ii >= 0 && jj + 3 < s.size()) backtrack(s, f, cnt, jj + 1, jj + 3);
        }
    }
}
void demo()
{
    fast();
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        int n = s.size();

        int ii = -1, jj = -1;
        for(int i = 2; i < s.size(); i++)
        {
            if(s[i - 2] == '1' && s[i - 1] == '0' && s[i] == '0')
            {
                ii = i - 2; jj = i;
                break;
            }
        }
        //vector<bool> f(n, false);
        bool f[n];
        memset(f, false, sizeof(f));
        if(ii == -1 && jj == -1)
        {
            cout << 0 << endl; continue;
        }
        long long check_max = 0;
        for(int i = 2; i < s.size(); i++)
        {
            if(s[i - 2] == '1' && s[i - 1] == '0' && s[i] == '0' && f[i - 2] == false && f[i - 1] == false && f[i] == false) 
            {
                long long cnt = 0;
                backtrack(s, f, cnt, i - 2, i);
                check_max = max(check_max, cnt);
                memset(f, true, sizeof(f));
            }
        }
        cout << check_max << endl;
    }
}
int main()
{
    demo();
}