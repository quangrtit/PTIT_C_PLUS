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
#include<vector>
using namespace std;
#define MOD 1000000007
#define endl '\n'
#define fast() ios::sync_with_stdio(false); cin.tie(0);

int main()
{
    fast();
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        vector<int> a1(n);
        vector<int> a2(m);
        for(int i = 0; i < n; i++)
        {
            cin >> a1[i];
        }
        map<int, int> mp2;
        for(int i = 0; i < m; i++)
        {
            cin >> a2[i];
            mp2[a2[i]]++;
        }
        map<int, int> mp1;
        for(int i = 0; i < n; i++)
        {
            if(mp2[a1[i]] != 0) mp1[a1[i]]++;
        }
        vector<pair<int, int>> result;
        vector<int> kq;
        for(int i = 0; i < m; i++)
        {
            result.push_back({a2[i], mp1[a2[i]]});
            mp1[a2[i]] = -1;
        }
        for(auto x: result)
        {
            for(int i = 0; i < x.second; i++)
            {
                cout << x.first << " ";
            }
        }
        sort(a1.begin(), a1.end());     
        for(auto x: a1)
        {
            if(mp1[x] != -1) cout << x << " ";
        }
        cout << endl;
    }
}