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

class SinhVien
{
public:
    string key = "B20DCCN001", name, grade, birth;
    float GPA;
    SinhVien(){name = ""; grade = ""; birth = "";}
    friend istream& operator>>(istream& in, SinhVien& other)
    {
        getline(in, other.name);
        in >> other.grade;
        in >> other.birth;
        in >> other.GPA;
        return in;
    }
    friend ostream& operator<<(ostream& out, SinhVien& other)
    {
        out << other.key << " " << other.name << " " << other.grade << " ";
        string s = other.birth;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '/') s[i] = ' ';
        }
        stringstream ss(s); string tmp;
        while(ss >> tmp)
        {
            if(tmp.size() == 4) out << tmp << " ";
            else if(tmp.size() == 1) out << "0" << tmp << "/";
            else out << tmp << "/";
        }
        out << setprecision(2) << fixed << other.GPA << endl;
        return out;
    }
    ~SinhVien(){}
};
int main(){
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;
}
/*AUTHOR: KHỔNG VĂN QUẢNG - PTIT*/