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

struct NhanVien
{
   string key = "00001", name, sex, birth, adress, key_tx, day;         
};
void nhap(NhanVien& a)
{
    getline(cin, a.name);
    getline(cin, a.sex);
    getline(cin, a.birth);
    getline(cin, a.adress);
    getline(cin, a.key_tx);
    getline(cin, a.day);
}
void in(NhanVien& a)
{
    cout << a.key << " " << a.name << " " << a.sex << " " << a.birth << " " << a.adress << " " << a.key_tx << " " << a.day << endl;
}
int main(){
    struct NhanVien a;
    nhap(a);
    in(a);
    return 0;
}
/*AUTHOR: KHỔNG VĂN QUẢNG - PTIT*/