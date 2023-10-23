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
#include<iomanip>
using namespace std;
#define MOD 1000000007
#define endl '\n'
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}
double dis(double x1, double y1, double x2, double y2)
{
    double kq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    double result = sqrt(kq);
    return result;
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << setprecision(4) << fixed << dis(x1, y1, x2, y2) << endl;
    }
}
int main()
{
    fast();
    solve();
}