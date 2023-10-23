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

class item
{
public:
    int key;
    string name, group;
    double cost_buy, cost_sell, has;
    item(){}
    friend istream& operator >> (istream& in, item& other)
    {
        in.ignore();
        getline(in, other.name);
        getline(in, other.group);
        in >> other.cost_buy;
        in >> other.cost_sell;
        other.has = other.cost_sell - other.cost_buy;
        return in;
    }
    friend ostream& operator << (ostream& out, item other)
    {
        out << other.key << " " << other.name << " " << other.group << " ";
        cout << setprecision(2) << fixed << other.has;
        return out;
    }
    ~item(){}
};
bool cmp(item a, item b)
{
    return a.has > b.has;
}
int main()
{
    fast();
    int n; cin >> n;
    vector<item> food(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> food[i];
        food[i].key = i;
    }
    sort(food.begin() + 1, food.end(), cmp);
    for(int i = 1; i <= n; i++)
    {
        cout << food[i];
        cout << endl;
    }
}