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
void compact(string& s)
{
    string s1 = "";
    stringstream ss(s);
    string tmp;
    while(ss >> tmp)
    {
        s1 = s1 + tmp + " ";
    }
    s = s1;
    s.pop_back();
}
class sv
{
public:
    int stt; string key, name, grade, email, company;
    sv(){}
    friend istream& operator >> (istream& in, sv& other)
    {
        getline(in, other.key);
        compact(other.key);
        getline(in, other.name);
        compact(other.name);
        getline(in, other.grade);
        compact(other.grade);
        getline(in, other.email);
        compact(other.email);
        getline(in, other.company);
        compact(other.company); 
        return in;
    }
    friend ostream& operator << (ostream& out, sv& other)
    {
        out << other.stt << " ";
        out<< other.key << " ";
        out << other.name << " ";
        out << other.grade << " ";
        out << other.email << " ";
        out << other.company << endl;
        return out;
    }
    ~sv(){}
};
bool cmp(sv a, sv b)
{
    return a.key < b.key;
}
void solve()
{
    fast();
    int n; cin >> n;
    vector<sv> a(n);
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i].stt = i + 1;
    }
    int q; cin >> q; cin.ignore();
    sort(a.begin(), a.end(), cmp);
    while(q--)
    {
        string check; getline(cin, check);
        for(int i = 0; i < n; i++) if(a[i].company == check) cout << a[i];
    }

}
int main()
{
    solve();
}