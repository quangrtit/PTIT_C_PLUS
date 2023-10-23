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

struct PhanSo
{
    long long son = 1, mom = 1;
    friend istream& operator>>(istream& in, PhanSo& other)
    {
        in >> other.son >> other.mom; return in;
    }
    friend ostream& operator<<(ostream& out, PhanSo& other)
    {
        out << other.son << "/" << other.mom << endl;
        return out;
    }
    void compact()
    {
        long long gcd = __gcd(son, mom);
        son = son / gcd;
        mom = mom / gcd;
    }
};
void nhap(PhanSo& a)
{
    cin >> a;
}
void rutgon(PhanSo& a)
{
    a.compact();
}
void in(PhanSo& a)
{
    cout << a;
    //a.son != 0 ? cout << a : cout << 0 << endl;
}
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

struct SinhVien
{
    string name, grade, birth, key;
    float GPA;
};
void nhap(SinhVien& a)
{
    getline(cin, a.name);
    getline(cin, a.grade);
    getline(cin, a.birth);
    a.key = "B20DCCN001";
    cin >> a.GPA;
}
void in(SinhVien& a)
{
    cout << a.key << " " << a.name << " " << a.grade << " ";
    for(int i = 0; i < a.birth.size(); i++)
    {
        if(a.birth[i] == '/')
        {
            a.birth[i] = ' ';
        }
    }
    string tmp = a.birth;
    stringstream ss(tmp);
    while(ss >> tmp)
    {
        if(tmp.size() == 4)
        {
            cout << tmp << " ";
        }
        else if(tmp.size() == 2)
        {
            cout << tmp << "/";
        }
        else 
        {
            cout << "0" << tmp << "/"; 
        }
    }
    cout << setprecision(2) << fixed << a.GPA << endl;
}
int main(){
    struct SinhVien a;
    nhap(a);
    in(a);
    return 0;
}