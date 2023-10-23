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
void solve();
void fix(string &s);
int main()
{
    fast();
    solve(); 
}
void fix(string &s)
{
    for(int i = 0; i < s.size(); i++)
    {
        if(isupper(s[i]))
        {
            s[i] = tolower(s[i]);
        }
    }
}
void solve()
{   
    string s; getline(cin, s);
    stringstream ss(s);
    string tmp;
    string name = "";
    while(ss >> tmp)
    {
        name += tmp[0];
    }
    fix(tmp);
    cout << tmp;
    for(int i = 0; i < name.size() - 1; i++)
    {
        cout << (char)tolower(name[i]);
    }
    cout << "@ptit.edu.vn" << endl;
}
