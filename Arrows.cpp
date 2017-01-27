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

class Arrows {
public:
    int longestArrow(string s) {
	string::iterator f1, f2;
	f1 = find(s.begin(), s.end(), '<');
	f2 = find(s.begin(), s.end(), '>');
	if(f1==s.end() && f2==s.end()) return -1;

	int ret=1;
	for(string::iterator r=s.begin(); r<s.end(); ++r) {
	    char c=*r;
	    if(c=='<' && (r+1)!=s.end()) {
		int run=1;
		char cn=*(r+1);
		string::iterator iter;
		if(cn=='=' || cn=='-') {
		    for(iter=r+1; ((*iter)==cn && iter<s.end()); ++iter)
			++run;
		    ret=max(ret,run);
		}
	    }
	    if(c=='>' && (r-1)>=s.begin()) {
		int run=1;
                char cp=*(r-1);
                string::iterator iter;
                if(cp=='=' || cp=='-') {
                    for(iter=r-1; ((*iter)==cp && iter>=s.begin()); --iter)
                        ++run;
                    ret=max(ret,run);
                }
	    }
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
	{ { "<--->--==>" }, {4} },
	{ { "<<<<<<<<<<" }, {1} },
	{ { "----==-" }, {-1} },
	{ { "<----=====>" }, {6} },
	// Your custom test goes here:
	//{ { }, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    string p0;

    int run(Arrows* x) {
	return x->longestArrow(p0);
    }
    void print() { Tester::printArgs(p0); }
};
    
int main() {
    return Tester::runTests<Arrows>(
				    getTestCases<input, Tester::output<int>>(), disabledTest, 
				    450, 1484679241, CASE_TIME_OUT, Tester::COMPACT_REPORT
				    );
}
// CUT end
