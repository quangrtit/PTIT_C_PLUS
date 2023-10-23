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
class person
{
public:
    string name, birth;
    long long time = 0;
    person(){}
    void detached()// detached birthday to day
    {
        for(int i = 0; i < this->birth.size(); i++)
        {
            if(this->birth[i] == '/') this->birth[i] = ' ';
        }
        string s = this->birth;
        stringstream ss(s);
        string tmp;
        vector<string> kt_birth;
        while(ss >> tmp)
        {
            kt_birth.push_back(tmp);
        }
        this->time = this->time + stoll(kt_birth[0]) + 30 * stoll(kt_birth[1]) + 365 * stoll(kt_birth[2]);
    }
    ~person(){}
};
bool cmp(person a, person b)
{
    return a.time > b.time;
}
void solve()
{
    int n; cin >> n;
    vector<person> pp(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> pp[i].name >> pp[i].birth;
        pp[i].detached();
    }
    sort(pp.begin() + 1, pp.end(), cmp);
    cout << pp[1].name << "\n" << (*pp.rbegin()).name << endl;
}
int main()
{
    solve();
}