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
#define PI 3.141592653589793238
#define fast() ios::sync_with_stdio(false); cin.tie(0);

class sv
{
public:
    string key, name, grade, email;
    string course;
    sv(){}
    friend istream& operator >> (istream& in, sv& other)
    {
        getline(in, other.key);
        getline(in, other.name);
        getline(in, other.grade);
        getline(in, other.email);
        other.course = "20" + other.grade.substr(1, 2);
        return in;
    }
    friend ostream& operator << (ostream& out, sv& other)
    {
        out << other.key << " " << other.name << " " << other.grade << " " << other.email << endl;
        return out;
    }
    ~sv(){}
};
int main()
{
    fast();
    int n; cin >> n;
    cin.ignore();
    vector<sv> uni(n);
    for(int i = 0; i < n; i++) cin >> uni[i];
    int q; cin >> q;
    string grade_tmp;
    while(q--)
    {
        cin >> grade_tmp;
        cout << "DANH SACH SINH VIEN KHOA " << grade_tmp << ":\n";
        for(auto x: uni)
        {
            if(x.course == grade_tmp)
            {
                cout << x;
            }
        }
    }
}