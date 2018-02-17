#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void build(){

}
LL xi;
void init(){
  cin >> xi;
}
void solve(){
  for( LL ni = 1 ; ni <= 1e5 ; ni ++ ){
    LL goal = ni * ni - xi;
    if( goal < 0 ) continue;
    LL g = sqrt( goal );
    if( g * g != goal ) continue;
    if( g == 0 ) continue;
    LL mi = max( 1LL , ni / g );
    if( ni / mi != g ) continue;
    printf( "%lld %lld\n" , ni , mi );
    return;
  }
  puts( "-1" );
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		ll x, i;
		scanf("%lld", &x);
		if (x == 0) {
			printf("1 1\n");
			continue;
		}

		for (i = 1; i * i < x; i++) {
			if (x%i) continue;

			ll t1 = i, t2 = x / i;
			if ((t1 + t2) % 2) continue;
			ll N = (t1 + t2) / 2, NM = (t2 - t1) / 2;
			ll M = N / NM;
			if (N*N - (N/M)*(N/M) == x) {
                cout<<"N "<<N<<" M "<<M<<endl;//
				printf("%lld %lld\n", N, M);
				break;
			}
		}
		if (i*i >= x) printf("-1\n");
	}
	return 0;
}
