#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000000007
using namespace std;

class UF{
  private:
    int v , count;
    vector<int> rt, sz;
  public:
    UF(int V);
    int Root(int n);
    void Union(int m, int n);
    bool Find(int m, int n);
    int RetCount();
};

UF::UF(int V){
  v = count = V + 1;
  rt.resize(v);
  sz.resize(v);
  for(int i = 0; i < v; i++){
    rt[i] = i;
    sz[i] = 1;
  }
}

int UF::Root(int n){
  return (n == rt[n])? n : (rt[n] = Root(rt[n]));
}

void UF::Union(int m, int n){
  int Rm = Root(m), Rn = Root(n);
  if(Rm == Rn)
    return;
  if(sz[Rm] < sz[Rn]){
    rt[Rm] = Rn;
    sz[Rn] += sz[Rm];
    sz[Rm] = 0;
  }
  else if(sz[Rm] >= sz[Rn]){
    rt[Rn] = Rm;
    sz[Rm] += sz[Rn];
    sz[Rn] = 0;
  }
  count--;
}

bool UF::Find(int m, int n){
  return Root(m) == Root(n);
}

int UF::RetCount(){
  return count;
}

int main(){
  int v, m, n;
  cin >> v;
  UF u(v);
  while(cin >> m >> n){
    u.Union(m,n);
  }
  cin.sync();
  cin.clear();
  while(cin >> m >> n){
    cout << u.Find(m,n) << endl;
  }
  return 0;
}
