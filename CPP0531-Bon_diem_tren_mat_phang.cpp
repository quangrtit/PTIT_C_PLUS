#include<iostream>
#include<string.h>
#include<ctype.h>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
class point
{
public:
    int x, y, z;
    point(){}
    point(int x, int y, int z){this->x = x; this->y = y; this->z = z;}
};
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        vector<point> p(5);
        for(int i = 1; i < 5; i++)
        {
            cin >> p[i].x >> p[i].y >> p[i].z;
        }
        point a(p[2].x - p[1].x, p[2].y - p[1].y, p[2].z - p[1].z);
        point b(p[3].x - p[2].x, p[3].y - p[2].y, p[3].z - p[2].z);
        point n(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
        int denta = n.x * p[1].x + n.y * p[1].y + n.z * p[1].z;
        if(n.x * p[4].x + n.y * p[4].y + n.z * p[4].z == denta)
        {
            cout << "YES" << endl;
        }
        else 
        {
            cout << "NO" << endl;
        }
    }
}
int main()
{
    solve();
}