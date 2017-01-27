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

class StandInLine {
public:
    vector<int> my_insert(vector<int> v, int pos, int q) {
	if(pos==v.size()) {
	    v.push_back(q);
	    return v;
	}
	
	vector<int> ret;
	for(int i=0; i<v.size(); ++i) {
	    if(i==pos) ret.push_back(q);
	    ret.push_back(v[i]);
	}
	return ret;
    }
    
    vector<int> reconstruct(vector<int> left) {
	int N = left.size(); // N is also the tallest soldier
	
	vector<int> ret;
	for (int h=N; h>=1; --h) {
	    ret = my_insert(ret, left[h-1], h);
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
	{ { {2,1,1,0} }, { {4,2,1,3} } },
	{ { {0,0,0,0,0} }, { {1,2,3,4,5} } },
	{ { {5,4,3,2,1,0} }, { {6,5,4,3,2,1} } },
	{ { {6,1,1,1,2,0,0} }, { {6,2,3,4,7,5,1} } },
	// Your custom test goes here:
	//{ { {}}, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    vector<int> p0;

    vector<int> run(StandInLine* x) {
	return x->reconstruct(p0);
    }
    void print() { Tester::printArgs(p0); }
};
    
int main() {
    return Tester::runTests<StandInLine>(
					 getTestCases<input, Tester::output<vector<int>>>(), disabledTest, 
					 500, 1484549047, CASE_TIME_OUT, Tester::COMPACT_REPORT
					 );
}
// CUT end
