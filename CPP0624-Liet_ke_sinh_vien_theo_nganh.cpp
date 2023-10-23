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
        other.course = other.key.substr(5, 2);
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
    int q; cin >> q; cin.ignore();
    string grade_tmp;
    while(q--)
    {
        getline(cin, grade_tmp);
        for(int i = 0; i < grade_tmp.size(); i++) grade_tmp[i] = toupper(grade_tmp[i]);
        cout << "DANH SACH SINH VIEN NGANH " << grade_tmp << ":\n";
        string s = grade_tmp;
        string grade_tmp1 = ""; string tmp; int cnt = 0; 
        stringstream ss(s);
        while(ss >> tmp)
        {
            if(cnt < 2) grade_tmp1 += toupper(tmp[0]);
            cnt++;
        }
        for(auto x: uni)
        {
            if(x.course == grade_tmp1 && !(x.grade[0] == 'E' && (grade_tmp1[0] == 'C' || grade_tmp1[0] == 'A')))
            {
                cout << x;
            }
        }
    }
}