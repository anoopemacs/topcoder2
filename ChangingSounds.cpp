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

int dp[50][1001];

class ChangingSounds {
public:
    int maxFinal(vector<int> cis, int B, int M) {
	int N = cis.size();
	for(int b=0; b<=1000; ++b) {
	    int u = b+cis[N-1];
	    int l = b-cis[N-1];
	    if(u<=M) dp[N-1][b] = u;
	    else if (l>=0) dp[N-1][b] = l;
	    else dp[N-1][b] = -1;
	}
	
	for(int i=N-2; i>=0; --i) {
	    for(int b=0; b<=1000; ++b) {
                int u = b+cis[i];
                int l = b-cis[i];
		int topush = -1;
                
		if(u<=M) topush = max(topush, dp[i+1][u]);
		if (l>=0) topush = max(topush, dp[i+1][l]);
		
		dp[i][b] = topush;
            }    
        }
	
	return dp[0][B];
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
    { { {5,3,7}, 5, 10 }, {10} },
    { { {15,2,9,10}, 8, 20 }, {-1} },
    { { {74,39,127,95,63,140,99,96,154,18,137,162,14,88}, 40, 243 }, {238} },
    // Your custom test goes here:
    //{ { {}, , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;int p1;int p2;

        int run(ChangingSounds* x) {
            return x->maxFinal(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };
    
    int main() {
        return Tester::runTests<ChangingSounds>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1487708009, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
