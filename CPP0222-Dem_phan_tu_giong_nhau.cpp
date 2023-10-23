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
template<typename T, typename X>
int b_s(T valua, int l, int r, X z)
{
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(valua[mid] == z)
        {
            return mid;
        }
        else if(valua[mid] < z)
        {
            l++;
        }
        else if(valua[mid] > z)
        {
            r--;
        }
    }
    return -1;  
}
void segment_tree(int id, int l, int r, vector<int> &save, vector<int> demo)
{
    if(l == r)
    {
        save[id] = demo[l]; return;
    }
    int mid = (l + r) / 2;
    segment_tree(2 * id, l, mid, save, demo);
    segment_tree(2 * id + 1, mid + 1, r, save, demo);
    //cout << id << save[2 * id] << save[2 * id + 1] << endl;
    save[id] = min(save[2 * id], save[2 * id + 1]);
}
bool check(vector<int> a, int l, int r)
{
    if(l == r || l + 1 == r) return true;
    int ii = r - 1;
    while(a[ii] >= a[ii + 1])
    {
        ii--;
    }
    for(int i = l; i < ii; i++)
    {
        if(a[i] > a[i + 1])
        {
            return false;
        }
    }
    return true;

}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<vector<int>> a(n + 1, vector<int>(n + 1));
        map<int, int> mp;
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                if(mp[a[i][j]] == i - 1)
                {
                    mp[a[i][j]] = i;
                }
            }
        }
        for(auto x: mp)
        {
            if(x.second == n)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}

int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/