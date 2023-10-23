#include<iostream>
#include<math.h>
#include<cmath>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<set>
#include<limits.h>
#include<map>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<deque>
#include<bitset>
using namespace std;
#define MOD 1000000007
#define endl '\n'
#define fast() ios::sync_with_stdio(false); cin.tie(0);


struct save 
{
    int map_l = -1, map_r = -1;
};
bool check(map<int, int> mp, vector<pair<int, int>> b)
{
    for(int i = 0; i < b.size(); i++)
    {
        if(mp[b[i].first] < b[i].second)
        {
            return false;
        }
    }
    return true;
}
// void ktx(int a1, int b1, int a2, int b2, string s)
// {
//     int ii = a1, jj = a2;
//     while(ii < b1 && jj < b2)
//     {

//     }
// }
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        string in, out; cin >> in >> out;
        map<int, int> mp;
        for(int i = 0; i < out.size(); i++)
        {
            mp[out[i]]++;
        }
        vector<pair<int, int>> vp;
        for(auto x: mp)
        {
            vp.push_back({x.first, x.second});
        }
        int size = vp.size();
        save a;
        for(int i = 0; i < in.size(); i++)
        {
            map<int, int> mp_in;
            for(int j = i; j < in.size(); j++)
            {
                if(mp[in[j]] != 0)
                {
                    mp_in[in[j]]++;
                }
                if(mp_in.size() == size)
                {
                    if(check(mp_in, vp) == true)
                    {
                        if(a.map_l == -1 && a.map_r == -1) 
                        {
                            a.map_l = i; a.map_r = j;
                        }
                        else
                        {
                            if(j - i + 1 < a.map_r - a.map_l + 1)
                            {
                                a.map_l = i; a.map_r = j;
                            }
                        }
                    }
                }
            }
        }
        if(a.map_l != -1 && a.map_r != -1)
        {
            for(int i = a.map_l; i <= a.map_r; i++)
            {
                cout << in[i];
            }
            cout << endl;
        }
        else 
        {
            cout << -1 << endl;
        }
    }
}
int main()
{
    fast();
    solve();
}
