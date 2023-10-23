#include<iostream>
#include<string.h>
#include<ctype.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<thread>
using namespace std;

class company
{
public:
    string key, name;
    int quantity = 0;
};
void solve()
{
    int n; cin >> n;
    vector<company> cp(n);
    for(int i = 0; i < n; i++)
    {
        cin.ignore();
        getline(cin, cp[i].key);
        getline(cin, cp[i].name);
        cin >> cp[i].quantity;
    }
    sort(cp.begin(), cp.end(), [](company a, company b){
        if(a.quantity != b.quantity) return a.quantity > b.quantity;
        else return a.key < b.key;
    });
    int q; cin >> q;
    int a, b;
    while(q--)
    {
        cin >> a >> b;
        cout << "DANH SACH DOANH NGHIEP NHAN TU " << a << " DEN " << b << " SINH VIEN:\n";
        for(auto x: cp)
        {
            if(x.quantity >= a && x.quantity <= b) cout << x.key << " " << x.name << " " << x.quantity << endl;
        }
    }
}
int main()
{
    solve();
}