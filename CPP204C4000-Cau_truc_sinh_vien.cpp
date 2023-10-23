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
    string key = "N20DCCN001", name, grade, birth; float GPA;
};
typedef struct SinhVien sv; 
void nhapThongTinSV(sv &a)
{
    getline(cin, a.name);
    cin >> a.grade;
    cin >> a.birth;
    cin >> a.GPA; 
}
void inThongTinSV(sv &a)
{
    cout << a.key << " " << a.name << " " << a.grade << " ";
    string s = a.birth;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '/') s[i] = ' ';
    }
    stringstream ss(s);
    string tmp;
    while(ss >> tmp)
    {
        if(tmp.size() == 4) cout << tmp << " ";
        else if(tmp.size() == 1) cout << "0" << tmp << "/";
        else cout << tmp << "/";
    }
    cout << setprecision(2) << fixed << a.GPA << endl;
}
int main(){
    struct SinhVien a;
    nhapThongTinSV(a);
    inThongTinSV(a);
    return 0;
}
/*AUTHOR: KHỔNG VĂN QUẢNG - PTIT*/