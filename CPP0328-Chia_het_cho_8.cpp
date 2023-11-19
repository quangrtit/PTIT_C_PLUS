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
#define endl '\n'
#define fast() ios::sync_with_stdio(false); cin.tie(0);

int Convert(string s)
{
    int ans = 0;
    for(int i = 0; i < s.size(); i++) ans = ans * 10 + s[i] - '0';
    return ans;
}
int main()
{
   
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        int result = 0;
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = s[0] - '0';
        for(int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1] + s[i] - '0';
        }
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i; j < s.size(); j++)
            {
                string tmp;
                int what;
                if(j - i + 1 <= 3)
                {
                    tmp = s.substr(i, j - i + 1);
                    what = Convert(tmp);
                }
                else 
                {
                    tmp = s.substr(j - 2, 3);
                    what = Convert(tmp); 
                }
                if(what % 8 != 0)
                {
                    continue;
                }
                else 
                {
                    int check;
                    if(i == 0) check = dp[j];
                    else check = dp[j] - dp[i - 1];
                    if(check % 3 == 0)
                    {
                        continue;
                    }
                    else 
                    {
                        result++;
                    }
                }
            }
        }
        cout << result << endl;
    }
}