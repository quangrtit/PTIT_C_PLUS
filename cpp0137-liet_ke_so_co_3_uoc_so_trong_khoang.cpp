#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<limits.h>
#include<iomanip>
#include<string.h>
#include<ctype.h>
#define MOD 1000000007
using namespace std;

vector<int> a(1000001);
void sang()
{
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i <= sqrt(1000000); i++)
    {
        if(a[i] == 0)
        {
            for(int j = i * i; j <= 1000000; j += i)
            {
                a[j] = 1;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    sang();
    int t; cin >> t;
    while(t--)
    {
        int cnt = 0;
        long long l, r; cin >> l >> r;
        for(int i = sqrt(l); i <= sqrt(r); i++)
        {
            if((long long)i * i >= l && (long long)i * i <= r)
            {
                if(a[i] == 0)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}