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

class IQTest {
    string myits(int i) {
	stringstream ss;
	ss<<i;
	string ret;
	ss>>ret;
	return ret;
    }
    bool mycheck(vector<int> pre, int a, int b) {
	bool ret=true;
	for(int i=3; i<pre.size(); ++i) {
	    if((a*pre[i-1]+b) != pre[i]) ret=false;
	}
	return ret;
    }
public:
    string nextNumber(vector<int> previous) {
	int N=previous.size();
	if(N==1) return "AMBIGUITY";
	
	//all equal
	int p=previous[0];
	int count=0;
	for(int i=0; i<N; ++i) {
	    if(previous[i]==p) ++count;
	}
	if(count == N) return myits(p);
	
	if(N==2) return "AMBIGUITY";
	
	//now N>=3, ret="BUG" or myits(integer)
	int q=previous[1];
	int r=previous[2];
	//first 3 elts are p, q, r
	if((p-q)==0) return "BUG";
	double a=(double)(q-r)/(double)(p-q);
	double b=q-a*p;
	if((a!=(int)a) || (b!=(int)b)) return "BUG";
	debug(a, (int)a, b, (int)b);
	if(mycheck(previous, a, b)) return myits(a*previous[N-1]+b);
	return "BUG";
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
	{ { {1,2,3,4,5} }, {"6"} },
	{ { {3,6,12,24,48} }, {"96"} },
	{ { {1,4,13,40} }, {"121"} },
	{ { {0} }, {"AMBIGUITY"} },
	{ { {-1,2} }, {"AMBIGUITY"} },
	{ { {57,57} }, {"57"} },
	{ { {16,-8,4,-2} }, {"BUG"} },
	{ { {6,5,4,3,1} }, {"BUG"} },
	{ { {-12,12,-36,60} }, {"-132"} },
	{ {{-8, 1, -8}}, {"1"}},
	{ {{-100, -98, 99}}, {"BUG"}},
	// Your custom test goes here:
	//{ { {}}, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    vector<int> p0;

    string run(IQTest* x) {
	return x->nextNumber(p0);
    }
    void print() { Tester::printArgs(p0); }
};
    
int main() {
    return Tester::runTests<IQTest>(
				    getTestCases<input, Tester::output<string>>(), disabledTest, 
				    500, 1484660976, CASE_TIME_OUT, Tester::COMPACT_REPORT
				    );
}
// CUT end
