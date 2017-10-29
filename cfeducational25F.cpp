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
//while(~scanf("%d",&n) )

/*-------------------------Template Ends--------------------------------*/

int values[8192];
int dp[8192],timesrep[8192][8192];
string st;

void findZvalues(string s, int start) {
/* aabxaabxcaabxaabxay */
	// std::cout << "in for " << start << '\n';
	int i,j,k,left,right,len;
	len = s.size();
	// std::cout << len << '\n';
	left = right = 0;
	values[0] = 0;

	for(i = 1; i < len; ++i) {
		k = i - left;
		if(right < i) {
			left = right = i;
			while((right < len) && (s[right] == s[right - i])) {
				right++;
			}
			right--;
			values[i] = right - left + 1;
		}
		else if((values[k] + i - 1) < right) { //value of z[k] !crossing the frontier
			values[i] = values[k];
		}
		else {
			left = i;
			right++;
			while((right < len) && (s[right] == s[right - i])) {
				right++;
			}
			right --;
			values[i] = right - left + 1;
		}
		if(timesrep[start][start + i - 1] > 1) continue;

		int temp = values[i] - values[i]%i;
		for(int step = i+i-1; step <= temp+i-1; step += i)
			timesrep[start][start + step]=max((step+1)/i,timesrep[start][start + step]);
	}
}

void precompute() {
	// std::cout << "precomputing" << '\n';
	int i,j;
	for(i = 0; i < st.size(); ++i) for(j = i; j < st.size(); ++j) timesrep[i][j] = 1;
	for(i = 0; i < st.size(); ++i) {
		findZvalues(st.substr(i),i);
	}
	// for(i = 0; i < st.size(); ++i) {
	// 	for(j = i; j < st.size(); ++j) {
	// 		std::cout << "i = " << i << " j = " << j << " " << timesrep[i][j] << endl;
	// 	}
	// }
}

int finddigits(int no) {
	int c = 0;
	while(no>0) ++c,no/=10;
	return c;
}

int main()
{
	int i,j,k,ans,count,mini;
	cin >> st;
	precompute();
	int len = st.size();
	dp[0] = 2;
	for(i = 1; i < st.size(); ++i) {
		// std::cout << "in for i" << i << '\n';
		mini = 0 + finddigits(timesrep[0][i]) + (i - 0 + 1)/timesrep[0][i];
		// std::cout << "mini = " << finddigits(timesrep[0][i])  << " + " << (i - 0 + 1)/timesrep[0][i]<< '\n';
		for( j = 1; j < i; ++j) {
			mini = min(mini, dp[j-1] + finddigits(timesrep[j][i]) + (i - j + 1)/timesrep[j][i]);
			// cout << "mini j= " << j << " "<< mini  << " = "<< dp[j-1] << " + "<< finddigits(timesrep[j][i])  << " + " << (i - 0 + 1)/timesrep[j][i]<< '\n';
		}
		dp[i] = min(dp[i-1] + 2, mini);
	}
	// for(i = 0; i < st.size(); ++i) {
	// 	std::cout << dp[i] << '\n';
	// }
	std::cout << dp[st.size()-1] << '\n';
	return 0;
}
