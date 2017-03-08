#include <bits/stdc++.h>
#define debug(args...) // Just strip off all debug tokens
#define dump(x) // Just strip off all dump tokens
using namespace std;
typedef long long int64;

// CUT begin
#undef dump
#define dump(x) cerr << #x << " = " << (x) << endl;
#undef debug
#define debug(args...) {dbg,args;cout<<endl;}
struct debugger{template<typename T> debugger& operator ,(const T& v){cout<<v<<" ";return *this;}}dbg;
template <typename T1,typename T2> inline ostream& operator<<(ostream& os,const pair<T1,T2>& p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>inline ostream&operator<<(ostream& os,const vector<T>& v){string delim="[";for(unsigned int i=0;i < v.size();i++){os<<delim<<v[i];delim=", ";}return os<<"]";}
template<typename T>inline ostream&operator<<(ostream& os,const set<T>& v){string delim="[";for (typename set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
template<typename T1,typename T2>inline ostream&operator<<(ostream& os,const map<T1,T2>& v){string delim="[";for (typename map<T1,T2>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
// CUT end

int64 dp[110][25];

class MaximalProduct {
 public:
    long long maximalProduct(int S, int K) {
	memset(dp, 0, sizeof(dp));

	for(int64 s=1; s<=100; ++s) {
	    dp[s][1] = s;
	    dp[s][2] = s/2 * (s-s/2);
	}

	for(int64 k=3; k<=K; ++k) {
	    for(int64 s=1; s<=S; ++s) {

		int64 topush = 1;
		for(int64 a=1; a<=s-k+1; ++a) {
		    topush = max(topush, a*dp[s-a][k-1]);
		}
		dp[s][k] = topush;
		
	    }
	}

	return dp[S][K];
    }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 10, 3 }, {36LL} },
    { { 10, 1 }, {10LL} },
    { { 10, 10 }, {1LL} },
    { { 13, 8 }, {32LL} },
    { { 7, 2 }, {12LL} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;

        long long run(MaximalProduct* x) {
            return x->maximalProduct(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<MaximalProduct>(
            getTestCases<input, Tester::output<long long>>(), disabledTest, 
            500, 1488970520, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
