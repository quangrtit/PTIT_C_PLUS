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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second != b.second)
    {
        return a.second < b.second;
    }
    else 
    {
        return a.first < b.first;
    }
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {         
        string n; cin >> n;
        map<int, int> mp;
        for(int i = 0; i < n.size(); i++)
        {
            mp[int(n[i] - '0')]++;
        }
        vector<pair<int, int>> odd, even;
        for(auto x: mp)
        {
            if(x.second % 2 == 0)
            {
                even.push_back({x.first, x.second});
            }
            else 
            {
                odd.push_back({x.first, x.second});
            }
        } 
        deque<int> l, r;
        sort(odd.begin(), odd.end(), cmp);
        if(odd.empty())
        {
            for(int i = even.size() - 1; i >= 0; i--)
            {
                int cnt = even[i].second / 2;
                while(cnt--)
                {
                    l.push_back(even[i].first);
                    r.push_front(even[i].first);
                }
            }
            for(auto x: l)
            {
                cout << x;
            }
            for(auto x: r) 
            {
                cout << x;
            }
            cout << endl;
            continue;
        }
        if(even.empty())
        {
            int ii = odd.size() - 1;
            while(odd.back().first == 0)
            {
                odd.pop_back(); 
            }
            for(int i = 0; i < odd[odd.size() - 1].second; i++)
            {
                cout << odd[odd.size() - 1].first;
            }
            cout << endl;
            continue;
        }
        even.push_back({odd[odd.size() - 1].first, odd[odd.size() - 1].second - 1});
        sort(even.begin(), even.end());
        for(int i = even.size() - 1; i >= 0; i--)
        {
            int cnt = even[i].second / 2;
            while(cnt--)
            {
                l.push_back(even[i].first);
                r.push_front(even[i].first);
            }
        }
        // for(auto x: l) cout << x << " ";
        // cout << endl;
        // for(auto x: r) cout << x << " ";
        // cout << endl;
        while(l.front() == 0 && r.back() == 0 && !l.empty() && !r.empty())
        {
            l.pop_front();
            r.pop_back();
        }
        for(auto x: l)
        {
            cout << x;
        }
        cout << odd[odd.size() - 1].first;
        for(auto x: r)
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