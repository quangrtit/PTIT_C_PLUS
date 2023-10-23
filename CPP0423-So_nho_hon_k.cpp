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
#define fast() ios::sync_with_stdio(false); cin.tie(0);
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<long long> a(n);
        long long min_k = 0;
        map<long long, int> mp;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] <= k)
            {
                mp[a[i]]++; min_k++;
            }
        }
        long long check = 0;
        for(int i = 0; i < min_k; i++)
        {
            if(a[i] <= k) check++;
        }
        long long check_max = check;
        int ii = 0;
        // cout << "this is" << check << endl;
        for(int i = min_k; i < n; i++)
        {
            if(mp[a[i]] != 0) check++;
            if(mp[a[ii]] != 0) check--;
            check_max = max(check, check_max);
            ii++;
        }
        cout << min_k - check_max << endl;
    }   
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/