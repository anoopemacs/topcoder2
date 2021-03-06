#include <bits/stdc++.h>
#define debug(args...) // Just strip off all debug tokens
using namespace std;

// CUT begin
#undef debug
#define debug(args...) {dbg,args;cout<<endl;}
struct debugger{template<typename T> debugger& operator ,(const T& v){cout<<v<<" ";return *this;}}dbg;
template <typename T1,typename T2> inline ostream& operator<<(ostream& os,const pair<T1,T2>& p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>inline ostream&operator<<(ostream& os,const vector<T>& v){string delim="[";for(unsigned int i=0;i < v.size();i++){os<<delim<<v[i];delim=", ";}return os<<"]";}
template<typename T>inline ostream&operator<<(ostream& os,const set<T>& v){string delim="[";for (typename set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
template<typename T1,typename T2>inline ostream&operator<<(ostream& os,const map<T1,T2>& v){string delim="[";for (typename map<T1,T2>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
// CUT end

vector<long long> dp(60, 0);
// dp is 1 indexed

class HandsShaking {
public:
    void myAux(int n) {
	if(n%2 != 0) {
	    dp[n] = 0;
	    return;
	}
	long long topush = 0;
	for(int i=1; i<=n-1; ++i) {
	    topush = topush + dp[i-1] * dp[n-i-1];
	}
	dp[n] = topush;
	return;
    }

    long long countPerfect(int n) {
	//persons [1, n]
	dp[0]=1; // sentinel
	//dp[2] = 1;
	//dp[4] = 2;
	
	for(int i=1; i<=n; ++i) {
	    myAux(i);
	}
	return dp[n];
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
    { { 2 }, {1LL} },
    { { 4 }, {2LL} },
    { { 8 }, {14LL} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;

        long long run(HandsShaking* x) {
            return x->countPerfect(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<HandsShaking>(
            getTestCases<input, Tester::output<long long>>(), disabledTest, 
            500, 1486399850, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
