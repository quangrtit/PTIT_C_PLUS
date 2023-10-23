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
    string s;
    person(){}
    void standardized(string &a)
    {
        for(int i = 0; i < a.size(); i++)
        {
            if(i == 0)
            {
                a[i] = (char)toupper(a[i]);
            }
            else
            {
                a[i] = (char)tolower(a[i]);
            }
        }
    }
    void menu()
    {
        int t; cin >> t;
        while(t--)
        {
            int n; cin >> n;
            cin.ignore();
            getline(cin, s);
            vector<string> v;
            stringstream ss(s);
            string tmp;
            while(ss >> tmp)
            {
                this->standardized(tmp);
                v.push_back(tmp);
            }
            if(n == 1)
            {
                cout << (*v.rbegin()) << " ";
                for(int i = 0; i < v.size() - 1; i++)
                {
                    cout << v[i] << " ";
                }
                cout << endl;
            }
            else 
            {
                for(int i = 1; i < v.size(); i++)
                {
                    cout << v[i] << " ";
                }
                cout << v[0] << endl;
            }
        }
    }
    ~person(){}
};
void solve()
{
    person a;
    a.menu();
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/