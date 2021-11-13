#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


void countSort(vector<int> &v, int a)
{
    vector<int>v1(v.size());
    int niz[10]= {0};

    for(int i=0; i<v.size(); i++) {
        niz[(v[i]/a)%10]++;
    }

    for(int i=1; i<10; i++)
        niz[i]+=niz[i-1];


    for(int i=v.size()-1; i>=0; i--) {
        v1[niz[(v[i]/a)%10]-1]=v[i];
        niz[(v[i]/a)%10]--;
    }

    for(int i=0; i<v.size(); i++) {
        v[i]=v1[i];
    }
}

int dajMax(vector<int> &a)
{
    int max=a[0];
    for(int i=1; i<a.size(); i++) {
        if(a[i]>max) max=a[i];
    }
    return max;
}


void radixSort(vector<int> &a)
{
    int max=dajMax(a);

    for(int i=1; max/i>0; i*=10)
        countSort(a,i);
}



void popraviGore(vector<int> &v, int i)
{
    while(i!=0 && v[i] > v[(i-1)/2]) {
        swap(v[i], v[(i-1)/2]);
        i=(i-1)/2;

    }
}

void popraviDolje(vector<int> &a, int i, int &velicina)
{

    while (!(i>=velicina/2 && i<velicina)) {

        int veci1=2*i+1;
        int el=2*i+2;

        if(el<velicina && a[el]>a[veci1]) veci1=el;
        if(a[i]>a[veci1]) return;
        swap(a[i], a[veci1]);
        i=veci1;
    }
}

void stvoriGomilu(vector<int> &a)
{
    int vel=a.size();
    for(int i=vel/2; i>=0; i--)
        popraviDolje(a,i,vel);
}


void umetniUGomilu(vector<int> &a, int umetnuti, int &velicina)
{

    a.push_back(umetnuti);
    velicina++;
    popraviGore(a, velicina-1);
}

int izbaciPrvi(vector<int> &a, int &velicina)
{
    if(velicina==0) throw "Gomila je prazna";
    velicina--;
    swap(a[0], a[velicina]);

    if(velicina!=0) popraviDolje(a, 0, velicina);

    return a[velicina];
}

void gomilaSort(vector<int>&a)
{
    stvoriGomilu(a);
    int velicina= a.size();
    for(int i=0; i<=a.size()-2; i++) {
        izbaciPrvi(a, velicina);
    }
}


int main()
{

    vector<int>a;
    a.push_back(246);
    a.push_back(821);
    a.push_back(333);
    a.push_back(365);
    a.push_back(222);
    stvoriGomilu(a);

    gomilaSort(a);

    for(int i=0; i<a.size(); i++) {
        cout<<a[i]<<endl;
    }
    std::cout << "Zadaća 3, Zadatak 1";
    return 0;
}
