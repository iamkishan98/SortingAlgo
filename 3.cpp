#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

using cd = complex<double>;

double pi = acos(-1);

void fft(vector<cd> & a, bool invert){
  int n = a.size();
  if(n==1){return;}

  vector<cd> a0(n/2), a1(n/2);
  for(int i=0;2*i<a.size();i++){
    a0[i]=a[2*i];
    a1[i]=a[2*i+1];
  }

  fft(a0, invert);
  fft(a1, invert);

  double ang = 2*pi/n*(invert?-1:1);
  cd w(1), wn(cos(ang), sin(ang));
  for(int i=0;2*i<n;i++){
    a[i] = a0[i]+w*a1[i];
    a[i+n/2] = a0[i] - w*a1[i];
    if(invert){
      a[i] /= 2;
      a[i+n/2] /= 2;
    }
    w*=wn;
  }
}

vector<int> mul(vector<int> const& a, vector<int> const&   b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n=1;
  while(n<a.size()+b.size()){
    n<<=1;
  }
  fa.resize(n);
  fb.resize(n);


  fft(fa, false);
  cout << "Elem of A: ";
  for(auto u:fa){cout << u.real() << " " << u.imag()<< ", ";}cout << endl;
  fft(fb, false);
  cout << "Elem of B: ";
  for(auto u:fb){cout << u.real() << " " << u.imag()<< ", ";}cout << endl;

  for(int i=0;i<n;i++){
    fa[i] *= fb[i];
  }
  fft(fa, true);

  vector<int> result(n);
  for(int i=0;i<n;i++){
    result[i]=round(fa[i].real());
  }

  return result;
}

int main(){
  vector<int> a{ 1, 2, 3};
  vector <int> b{2, 0, 5};

  vector<int> res = mul(a, b);
  for(int i=0;i<res.size();i++){
    cout << res[i]<<" ";
  }
  cout << endl;

}
