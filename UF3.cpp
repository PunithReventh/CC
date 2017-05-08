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
    void FindMax();
    void Ans();
};

UF::UF(int V){
  v =  V + 1;
  count = V;
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

void UF::FindMax(){
  int max = 0, i;
  for(i = 1; i < v; i++){
    if(sz[i] > max)
      max = sz[i];
  }
  cout<< max <<endl;
}

void UF::Ans(){
  long long ans = 1;
  for(int i = 1; i < v; i++)
    if(sz[i] > 1)
      ans = (ans * sz[i]) % MOD;
  cout << count << " " << ans << endl;
}

int main(){
  int t = 1, v, q, m, n;
  //cin >> t;
  while(t--){
  cin >> v >> q;
  UF u(v);
  while(q--){
    cin >> m >> n;
    u.Union(m,n);
  }
  u.FindMax();
  //u.Ans();
  }
  return 0;
}
