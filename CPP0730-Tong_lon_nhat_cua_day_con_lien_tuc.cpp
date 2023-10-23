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
#define fast() ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
void solve()
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
        long long sum_check = LLONG_MIN;
        long long sum_tmp = 0;
        for(int i = 0; i < n; i++)
        {
            sum_tmp += a[i];
            sum_check = max(sum_check, sum_tmp);
            if(sum_tmp < 0)
            {
                sum_tmp = 0;
            }
            else 
            {
                sum_check = max(sum_check, sum_tmp);
            }
        }
        cout << sum_check << endl;
    }
}
int main()
{
    fast();
    solve(); 

}
/*AUTHOR: KHỔNG VĂN QUẢNG*/