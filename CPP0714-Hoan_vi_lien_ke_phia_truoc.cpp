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
void back_track(int j, vector<int> &a, int n, map<int, int> mp)
{
    for(int i = 1; i <= 6; i++)
    {
        if(mp[i] == 0)
        {
        a[j] = i;
        if(j == n)
        {
            for(int ix = 1; ix <= n; ix++)
            {
                cout << a[ix];
            }
            cout << " ";
        }
        else
        {
            mp[i] = 1;
            back_track(j + 1, a, n, mp);
            mp[i] = 0;
        }
        }
    }
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int ii = n - 1;
        while(ii >= 1 && a[ii] < a[ii + 1])
        {
            ii--;
        }
        //cout << "this is" << ii << endl;
        if(ii == 0)
        {
            for(int i = n; i >= 1; i--)
            {
                cout << a[i] << " ";
            }
            cout << endl;
            continue;
        }
        for(int i = ii; i < n; i++)
        {
            int check_max = INT_MIN;
            int vtri_max = -1;
            int tep = -1;
            int vtri = -1;
            for(int j = i + 1; j <= n; j++)
            {
                if(a[j] < a[i])
                {
                    tep = max(tep, a[j]);
                    vtri = j;
                }
                check_max = a[j];
                vtri_max = j;
            }
            //cout << "max" << check_max << " vtri_max" << vtri_max << " tep" << tep << " vtri" << vtri << endl;
            if(vtri == -1)
            {
                swap(a[i], a[vtri_max]);
                break;
            }
            else
            {
                swap(a[i], a[vtri]);
            }
            // for(int i = 1; i <= n; i++) cout << a[i] << " ";
            // cout << endl;
        }
        for(int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
void solve1()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n; 
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        prev_permutation(a.begin(), a.end());
        for(auto x: a)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
int main()
{
    fast();
    solve1(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/