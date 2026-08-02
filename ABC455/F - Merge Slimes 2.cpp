#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef modint998244353 mint;
struct S{
	mint he,pw;
	int len;
	S():he(0),pw(0),len(0){}
	S(mint he,mint pw,int len):he(he),pw(pw),len(len){}
}
;
S op(S l,S r){
	return S(l.he+r.he,l.pw+r.pw,l.len+r.len);
}
S e(){
	return S(0,0,1);
}
S mapping(mint f,S s){
	mint he = s.he+f*s.len;
	mint pw = s.pw+2*f*s.he+f*f*s.len;
	return S(he,pw,s.len);
}
mint composition(mint a,mint b){
	return a +b;
}
mint id(){
	return 0;
}
typedef lazy_segtree<S,op,e,mint,mapping,composition,id> tree;
int main(){
	int n,q;
	cin>>n>>q;
	tree tr(n);
	for(int i = 0;i<q;i++){
	int l,r,v;
		cin>>l>>r>>v;
		l--;
		tr.apply(l,r,v);
		S res = tr.prod(l,r);
		cout<<((res.he*res.he-res.pw)/2).val()<<endl;
	}
}