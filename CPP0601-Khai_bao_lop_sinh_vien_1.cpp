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
    string key = "B20DCCN001", name, birth, grade;
    float GPA;
    void nhap()
    {
        getline(cin, name);
        cin >> grade;
        cin >> birth;
        cin >> GPA;
    }
    void xuat()
    {
        string s = birth;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '/') s[i] = ' ';
        }
        stringstream ss(s); string tmp;
        cout << key << " " << name << " " << grade << " ";
        while(ss >> tmp)
        {
            if(tmp.size() == 4) cout << tmp << " ";
            else if(tmp.size() == 1) cout << "0" << tmp << "/";
            else cout << tmp << "/";
        }
        cout << setprecision(2) << fixed << GPA << endl;
    }
};
int main(){
    SinhVien a;
    a.nhap();
    a.xuat();
    return 0;
}
/*AUTHOR: KHỔNG VĂN QUẢNG - PTIT*/