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
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if(a.first.second != b.first.second)
    {
        return a.first.second < b.first.second;
    }
    else 
    {
        return a.second < b.second;
    }
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        int n, x; cin >> n >> x;
        vector<pair<pair<int, int>, int>> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i].first.first;
            a[i].second = i;
            a[i].first.second = abs(a[i].first.first - x);
        }
        sort(a.begin(), a.end(), cmp);
        for(auto x: a)
        {
            cout << x.first.first << " ";
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