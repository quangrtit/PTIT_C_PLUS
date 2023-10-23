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
#define MOD 1000000007
#define endl '\n'
using namespace std;
#define fast() ios::sync_with_stdio(false); cin.tie(0);
// cach 1 tao 1 class 
class arr
{
public: 
    int* A;
    int n;// số lượng phần tử của arr 
    arr(){this->n = 0; this->A = new int[n];}
    arr(int n);
    friend istream& operator >> (istream& in, arr& other);
    friend ostream& operator << (ostream& out, arr& other);
    void Resize(int n);
    void Insert(int index, int x);
    void Delete(int index);
    int Size();
    int& operator[] (int index)
    {
        return A[index];
    }
    ~arr();
};
arr::arr(int n)
{
    this->n = n;
    this->A = new int[n];
}
void arr::Resize(int n) {this->n = n;}
void arr::Insert(int index, int x)
{
    int* B = new int[this->n + 1];
    for(int i = 0; i < index; i++) B[i] = this->A[i];
    B[index] = x;
    for(int i = index; i < this->n; i++) B[i + 1] = this->A[i];
    delete [] this->A;
    this->A = new int[n + 1];
    for(int i = 0; i <= this->n; i++) this->A[i] = B[i];
    this->n = this->n + 1;
    delete [] B;
}
void arr::Delete(int index)
{
    int* B = new int[this->n - 1];
    for(int i = 0; i < this->n; i++) 
    {
        if(i < index) B[i] = this->A[i];
        else if(i > index) B[i - 1] = this->A[i];
    }
    delete [] this->A;
    this->A = new int [this->n - 1];
    for(int i = 0; i < this->n - 1; i++) this->A[i] = B[i];
    this->n = this->n - 1;
    delete [] B;
}
int arr::Size(){return this->n;}
istream& operator >> (istream& in, arr& other)
{
    for(int i = 0; i < other.n; i++) in >> other.A[i];
    return in;
}
ostream& operator << (ostream& out, arr& other)
{
    for(int i = 0; i < other.n; i++) out << other.A[i] << " ";
    return out;
}
arr::~arr()
{
    delete[] A;
}
void thaotac1(int& n, arr& a)
{
    cin >> n;
    a.Resize(n); cin >> a;
}
void thaotac2(int& n, arr& a)
{
    int k; cin >> k;
    int x; cin >> x;
    a.Insert(k, x);
}
void thaotac3(int& n, arr& a)
{
    // tìm những vị trí chẵn mà phần tử tại đó dương rồi chèn thêm x vào
    int x; cin >> x;
    int n_tmp = n;
    for(int i = ((n_tmp - 1) / 2) * 2; i >= 0; i -= 2)
    {
        if(a[i] > 0)
        {
            a.Insert(i, x);
        }
    }  
}
void thaotac4(int& n, arr& a)
{
    int index;// vị trí cần xoá 
    cin >> index;
    a.Delete(index);
}
void thaotac5(int& n, arr& a)
{
    int x; cin >> x; // xoá các giá trị bằng x
    int i = 0;
    while(i < a.Size())
    {
        if(a[i] == x) 
        {
            a.Delete(i);
        }
        else 
        {
            i++;
        }
    }
    n = a.Size();
}
void thaotac6(int& n, arr& a)
{
    map<int, int> mp;
    for(int i = 0; i < n; i++) mp[a[i]]++;
    int i = 0;
    while(i < a.Size())
    {
        if(mp[a[i]] > 1)
        {
            mp[a[i]]--;
            a.Delete(i);          
        }
        else 
        {
            i++;
        }      
    }
    n = a.Size();
}
void testcase()
{
    int n; 
    arr a(n);
    cout << "thao tác 1: \n";
    thaotac1(n, a); cout << a << endl;
    cout << "thao tác 2: \n";
    thaotac2(n, a); cout << a << endl;
    cout << "thao tác 3: \n";
    thaotac3(n, a); cout << a << endl;
    cout << "thao tác 4: \n";
    thaotac4(n, a); cout << a << endl;
    cout << "thao tác 5: \n";
    thaotac5(n, a); cout << a << endl;
    cout << "thao tác 6: \n";
    thaotac6(n, a); cout << a << endl;
}

int main()
{
    testcase();
}

