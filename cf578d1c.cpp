#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
#define forn(i,x,y) for(i = (x) ; i <= (y) ; ++i)
#define forr(i,y,x) for(i = (y) ; i >= (x) ; --i)
#define forv(v,i) for(i=v.begin();i!=v.end();++i)
#define forvr(v,i) for(i=v.end()-1;i!=v.begin();--i)
#define FA(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define PB push_back
#define PF push_front
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define MOD(x,y) (((x%M)*(y%M))%M)
#define CLR(x,y) memset(x,y,sizeof(x))
#define precisionvalue printf("%.6lf\n",ans);
ll M=1000000007;
const double INF = 1e10;
//while(~scanf("%d",&n))
/*------------------------- Template Ends --------------------------------*/

int n;
double val[200005],updated[200005];

double kadane(double *arr, int length) {
	double maxsum = -DBL_MAX, minsum = -DBL_MAX, current = 0.0, negCurrent = 0.0;
	for(int i = 0; i < length; ++i) {
		current += arr[i];
		maxsum = max(maxsum, current);
		current = max(0.0, current);

		negCurrent -= arr[i];
		negCurrent = max(0.0, negCurrent);
		minsum = max(minsum, negCurrent);
	}
	return max(maxsum, minsum);
}

double func(double x) {
	for(int i = 0; i < n; ++i) updated[i] = val[i] - x;
	return kadane(updated, n);
}

double ternarySearch(double l, double r) {
	double m1,m2;
	for(int i = 0; i <= 200; ++i) {
		m1 = (l + l + r) / 3;
		m2 = (l + r + r) / 3;
		if(func(m1) > func(m2)) l = m1;		// > if minimizing else < if maximizing
		else r = m2;
	}
	return func(l);
}

int main()
{
	cin >> n;
	cout.precision(10);
	for(int i = 0; i < n; ++i) cin >> val[i];
	cout << ternarySearch(-INF,INF) << endl;
	return 0;
}
