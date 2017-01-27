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

class InboxCleanup {
public:
    int solve_page(string m) {
	int c1=0;
	for(int i=0; i<m.length(); ++i) {
	    if(m[i]=='D') ++c1;
	}
	if(c1==0) return 0; // no 'D' in string
	++c1;
	
	int c2=0;
	++c2;
	for(int i=0; i<m.length(); ++i) {
	    if(m[i]=='.') ++c2;
	}
	++c2;
	
	return min(c1, c2);
    }
    
    int fewestClicks(string messages, int low, int high) {
	int ret=INT_MAX;
	
	int N = messages.length();
	for(int p=low; p<=high; ++p) {
	    int run=0;
	    
	    int q=N/p;
	    int r=N%p;
	    int next_page_clicks=0;
	    next_page_clicks+=(q-1);
	    if(r!=0) ++next_page_clicks;
	    
	    run+=next_page_clicks;
	    
	    for(int i=0; i<q; ++i) {
		string mi=messages.substr(p*i, p);
	        
		if(p==10) {debug("run at p=10", run, q, solve_page(mi)); }
                
		run+=solve_page(mi);
	    }
	    
	    if(r!=0) {
		string mr=messages.substr(p*q, r);
		run+=solve_page(mr);
	    }
	    ret=min(ret, run);
	    
	    if(p==10) {debug("run at p=10", run, q); }
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
	{ { "..........", 5, 10 }, {0} },
	{ { ".D.D.DD.D.", 5, 5 }, {8} },
	{ { "...D..DDDDDD...D.DD..", 3, 10 }, {12} },
	{ { "D.D..D..DD.DDDD.D.DDD.DDDD..", 3, 11 }, {17} },
	{ { "DDD.........................", 1, 3 }, {11} },
	// Your custom test goes here:
	//{ { , , }, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    string p0;int p1;int p2;

    int run(InboxCleanup* x) {
	return x->fewestClicks(p0,p1,p2);
    }
    void print() { Tester::printArgs(p0,p1,p2); }
};
    
int main() {
    return Tester::runTests<InboxCleanup>(
					  getTestCases<input, Tester::output<int>>(), disabledTest, 
					  500, 1484551909, CASE_TIME_OUT, Tester::COMPACT_REPORT
					  );
}
// CUT end
