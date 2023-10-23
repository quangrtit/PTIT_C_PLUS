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
void check(string &n1, string &n2)
{
    string tmp = n1;
    if((n1 < n2 && n1.size() == n2.size())|| n1.size() < n2.size())
    {
        n1 = n2;
        n2 = tmp;
    }
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        string n1, n2; cin >> n1 >> n2;
        check(n1, n2);
        deque<int> a, b;
        for(int i = 0; i < n1.size(); i++)
        {
            a.push_back(n1[i] - '0');
        }
        for(int i = 0; i < n2.size(); i++)
        {
            b.push_back(n2[i] - '0');
        }
        if(n1.size() > n2.size())
        {
            int odd = n1.size() - n2.size();
            while(odd--)
            {
                b.push_front(0);
            }
        }
        deque<int> result;
        int cnt = 0;
        while(!a.empty() && !b.empty())
        {
            if(a.back() + cnt >= b.back())
            {
                result.push_front(a.back() + cnt - b.back());
                a.pop_back(); b.pop_back();
                cnt = 0;
            }
            else 
            {
                result.push_front(a.back() + cnt + 10 - b.back());
                cnt = -1;
                a.pop_back();
                b.pop_back();
            }
        }
        for(auto x: result)
        {
            cout << x;
        }
        cout << endl;
    }   
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/