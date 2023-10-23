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
int main()
{
    fast();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<pair<int, int>> input;
        map<int, int> mp;
        vector<int> demo(n);
        for(int i = 0; i < n; i++)
        {
            cin >> demo[i];
            mp[demo[i]]++;
        }
        for(auto x: mp)
        {
            input.push_back({x.first, x.second});
        }
        sort(input.begin(), input.end(), [](pair<int, int> a, pair<int, int> b)
        {
            if(a.second != b.second) return a.second > b.second;
            else return a.first < b.first;
        });
        for(auto x: input)
        {
            int cnt = x.second;
            while(cnt--)
            {
                cout << x.first << " ";
            }
        }
        cout << endl;
    }
}