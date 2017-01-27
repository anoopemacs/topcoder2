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

class GroupWork {
    static bool mycompare(pair<int, int> x, pair<int, int> y) {
	return x.second < y.second;
    }
public:
    long long bestGroup(vector<int> p, vector<int> s) {
	int N=p.size();
	vector<pair<int, int>> ps;
	for(int i=0; i<N; ++i) {
	    ps.push_back(make_pair(p[i], s[i]));
	}
	sort(ps.begin(), ps.end(), mycompare);
	debug(ps);

	llint ret=-1;
	llint popu=0;
	for(int i=N-1; i>=0; --i) {
	    pair<int, int> psi = ps[i];
	    popu+=psi.first;
	    llint run=psi.second * popu;
	    if(run>ret) ret=run;
	}
	
	return ret;
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
	{ { {1,2,1}, {3,5,9} }, {15LL} },
	{ { {2,2,2,2}, {5,1,1,5} }, {20LL} },
	{ { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, {31,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} }, {31LL} },
	{ { {1000000000,1000000000,1000000000}, {1000,999,998} }, {2994000000000LL} },
	// Your custom test goes here:
	//{ { {}, {}}, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    vector<int> p0;vector<int> p1;

    long long run(GroupWork* x) {
	return x->bestGroup(p0,p1);
    }
    void print() { Tester::printArgs(p0,p1); }
};
    
int main() {
    return Tester::runTests<GroupWork>(
				       getTestCases<input, Tester::output<long long>>(), disabledTest, 
				       500, 1484642351, CASE_TIME_OUT, Tester::COMPACT_REPORT
				       );
}
// CUT end
