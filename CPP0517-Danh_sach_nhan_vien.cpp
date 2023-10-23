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

int cnt = 0;
struct NhanVien
{
   string key = "00001", name, sex, birth, adress, key_tx, day;    
   int keyx = 1;   
};
void nhap(NhanVien& a)
{
    cin.ignore();
    getline(cin, a.name);
    cin >> a.sex;
    cin >> a.birth;
    cin.ignore();
    getline(cin, a.adress);
    cin >> a.key_tx;
    cin >> a.day;
    cnt++;
    a.keyx = cnt;
}
void in(NhanVien a)
{
    if(a.keyx >= 10) cout << "000" << to_string(a.keyx) << " ";
    else cout << "0000" << a.keyx << " ";
    cout << a.name << " " << a.sex << " " << a.birth << " " << a.adress << " " << a.key_tx << " " << a.day << endl;
}
void inds(NhanVien ds[], int n)
{
    for(int i = 0; i < n; i++)
    {
        in(ds[i]);
    }
}
int main(){
    struct NhanVien ds[50];
    int N,i;
    cin >> N;
    //cin.ignore();
    for(i = 0; i < N; i++) nhap(ds[i]);
    inds(ds,N);
    return 0;
}
/*AUTHOR: KHỔNG VĂN QUẢNG - PTIT*/