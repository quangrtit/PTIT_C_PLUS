#include<iostream>
#include<unistd.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<set>
#include<limits.h>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
#define MOD 1000000007
#define endl '\n'
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}
bool check(int n1)
{
    int cnt = 0;
    int snt = 0;
    int n = n1;
    while(n > 0)
    {
        if((n % 10) % 2 == 0)
        {
            cnt++;
        }
        else 
        {
            snt++;
        }
        n = n / 10;
    }
    if(cnt == snt)
    {
        return true;
    }
    return false;
}
void solve()
{
    int n; cin >> n;
    int cnt = 0;
    for(int i = pow(10, n - 1); i < pow(10, n); i++)
    {
        if(check(i) == true && cnt != 9)
        {
            cout << i << " ";
            cnt++;
        }
        else if(check(i) == true && cnt == 9)
        {
            cout << i << endl;
            cnt = 0;
        }
    }

}
int main()
{
    fast();
    solve();
}