#include <bits/stdc++.h>
#define debug(args...) // Just strip off all debug tokens
using namespace std;

typedef long long llint;

// CUT begin
#undef debug
#define debug(args...) {dbg,args;cout<<endl;}
struct debugger{template<typename T> debugger& operator ,(const T& v){cout<<v<<" ";return *this;}}dbg;
template <typename T1,typename T2> inline ostream& operator<<(ostream& os,const pair<T1,T2>& p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>inline ostream&operator<<(ostream& os,const vector<T>& v){string delim="[";for(unsigned int i=0;i < v.size();i++){os<<delim<<v[i];delim=", ";}return os<<"]";}
template<typename T>inline ostream&operator<<(ostream& os,const set<T>& v){string delim="[";for (typename set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
template<typename T1,typename T2>inline ostream&operator<<(ostream& os,const map<T1,T2>& v){string delim="[";for (typename map<T1,T2>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
// CUT end

class ImprovingStatistics {
public:
    long display(long p, long w) {
	return (w*100)/p;
    }
    int howManyGames(int played, int won) {
	long p=played, w=won;
	if(display(p, w)==99 || p==w) return -1;

	//binary search:
	long ming=0, maxg=1;
	while(display(p+maxg, w+maxg) == display(p,w)) maxg=2*maxg;

	for(;(maxg-ming)>1;) {
	    long mid = (ming+maxg)/2;
	    if (display(p+mid, w+mid) == display(p,w)) {
		ming=mid;
	    } else {
		maxg=mid;
	    }
	}
	return maxg;
    }
};

//mathematical:
/*
  int howManyGames(int played, int won) {
  if(played==won) return -1;

  
  long X=played, Y=won;
  int ret=0;
  while( ((Y+ret)*100*X
  -Y*100*(X+ret)) < X*(X+ret) ) {
  ++ret;
  }
  

long P=played, W=won;
long Z=(W*100)/P;
debug(Z);

if(Z==99) return -1;
long double m = 1.0*(100*W-Z*P-P)/(Z-99);
debug(m);

return ceil(m);
}

 */

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 10, 8 }, {1} },
    { { 100, 80 }, {6} },
    { { 47, 47 }, {-1} },
    { { 99000, 0 }, {1000} },
    { { 1000000000, 470000000 }, {19230770} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;

        int run(ImprovingStatistics* x) {
            return x->howManyGames(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<ImprovingStatistics>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1485782450, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
