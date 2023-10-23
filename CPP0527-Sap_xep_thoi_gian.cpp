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
class Timexx
{
public:
    long long hour, minute, secondx, sum_Timexx = 0;
    Timexx(){}
    friend istream& operator >> (istream& in, Timexx& other){in >> other.hour >> other.minute >> other.secondx; other.sum_Timexx = other.hour * 3600 + other.minute * 60 + other.secondx; return in;}
    friend ostream& operator << (ostream& out, Timexx& other){out << other.hour << " " << other.minute << " " << other.secondx << endl; return out;}
    ~Timexx(){}
};
bool cmp(Timexx a, Timexx b){return a.sum_Timexx < b.sum_Timexx;}
void solve()
{
    fast();
    int n; cin >> n;
    vector<Timexx> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < n; i++) cout << a[i];
}
int main()
{
    solve();
}