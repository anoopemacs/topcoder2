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

class Chocolate {
public:
    int minSplitNumber(int width, int height, int nTiles) {
	long w=width;
	long h=height;
	long long N=w*h;
	debug(N, nTiles);
	if(nTiles>N) return -1;
	if(nTiles==N) return 0;
	if(nTiles%w==0 || nTiles%h==0) return 1;  
	
	for(long i=1; i*i<=nTiles; ++i) {
	    if(nTiles%i==0) {
		long whr=nTiles/i;
		if((i<=w && whr<=h) || (i<=h && whr<=w)) return 2;
	    }
	}
	
	return -1;
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
	{ { 5, 4, 12 }, {1} },
	{ { 12, 10, 120 }, {0} },
	{ { 2, 2, 1 }, {2} },
	{ { 17, 19, 111 }, {-1} },
	{ {100000, 9998244, 426746880}, {2}},
	{ {10000000, 10000000, 916034129}, {-1}},
	{ {1000000000, 99856, 956536183}, {2}},
	{ {282475249, 282475249, 656641603}, {-1}},
	// Your custom test goes here:
	//{ { , , }, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    int p0;int p1;int p2;

    int run(Chocolate* x) {
	return x->minSplitNumber(p0,p1,p2);
    }
    void print() { Tester::printArgs(p0,p1,p2); }
};
    
int main() {
    return Tester::runTests<Chocolate>(
				       getTestCases<input, Tester::output<int>>(), disabledTest, 
				       500, 1484629302, CASE_TIME_OUT, Tester::COMPACT_REPORT
				       );
}
// CUT end
