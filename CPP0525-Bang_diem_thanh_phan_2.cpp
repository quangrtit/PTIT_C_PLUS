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


typedef struct SinhVien
{
    string key, name, grade;
    float score1, score2, score3;
    int cnt = 0;
} sv;
void nhap(sv& a)
{
    cin.ignore();
    getline(cin, a.key);
    getline(cin, a.name);
    getline(cin, a.grade);
    cin >> a.score1 >> a.score2 >> a.score3;
}
bool cmp(sv a, sv b)
{
    return a.name < b.name;
}
void sap_xep(sv *a, int n)
{
    sort(a, a + n, cmp);
}
void in_ds(sv *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << i + 1 << " " << (a + i)->key << " " << (a + i)->name << " " << (a + i)->grade << " " << setprecision(1) << fixed << (a + i)->score1 << " " << (a + i)->score2 << " " << (a + i)->score3 << endl;
    }
}
int main(){
    int n;
    cin >> n;
    struct SinhVien *ds = new SinhVien[n];
    for(int i = 0; i < n; i++) {
    	nhap(ds[i]);
	}
	sap_xep(ds, n);
    in_ds(ds,n);
    return 0;
}