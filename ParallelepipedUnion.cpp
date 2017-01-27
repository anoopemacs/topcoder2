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

class ParallelepipedUnion {
public:
    static bool myspace(char c) {
	return isspace(c);
    }
    static bool notspace(char c) {
	return !isspace(c);
    }
    int st_int(string s) { //string to int
	stringstream ss;
        ss<<s;
        int ret;
        ss>>ret;
	return ret;
    }
    
    vector<int> my_parse(string s) {
	vector<int> ret;
	
	int i=0, j=0;
	
	while(i!=s.size()) {
	    while(myspace(s[i]) && i!=s.size()) ++i;
	    j=i;
	    while(notspace(s[j]) && j!=s.size()) ++j;
	    
	    if(i!=j) {
		int temp = st_int(s.substr(i, j-i));
		ret.push_back(temp);
	    }
	    i=j;
	}
	
	return ret;
    }
    
    int v(vector<int> p) { //simple volume
	return (p[3]-p[0])*(p[4]-p[1])*(p[5]-p[2]);
    }
    
    int overlap(int x1, int x2, int x3, int x4) {
	int ret = min(x2, x4) - max(x1, x3);
	if (ret<0) return 0;
	return ret;
    }
    
    int getVolume(vector<string> ps) {
	vector<int> f = my_parse(ps[0]);
	vector<int> s = my_parse(ps[1]);
	debug("first=", f, "second=", s);
	int v1=v(f);
	int v2=v(s);
	debug("v1=", v(f), "v2=", v(s));
	
	int overlapx = overlap(f[0], f[3], s[0], s[3]);
	int overlapy = overlap(f[1], f[4], s[1], s[4]);
	int overlapz = overlap(f[2], f[5], s[2], s[5]);
	int overlapVol = overlapx * overlapy * overlapz;
	    
	return v1+v2-overlapVol;
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
	{ { {"1 1 1 4 4 2","3 2 1 5 3 3"} }, {12} },
	{ { {"1 1 1 2 2 2","3 3 3 4 4 4"} }, {2} },
	{ { {"1 10 20 5 15 23","2 12 22 3 14 23"} }, {60} },
	{ { {"28 31 21 67 60 81","60 1 21 67 50 81"} }, {80460} },
	{ { {"34 3 50 37 6 53","36 1 51 38 4 55"} }, {49} },
	// Your custom test goes here:
	//{ { {}}, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    vector<string> p0;

    int run(ParallelepipedUnion* x) {
	return x->getVolume(p0);
    }
    void print() { Tester::printArgs(p0); }
};
    
int main() {
    return Tester::runTests<ParallelepipedUnion>(
						 getTestCases<input, Tester::output<int>>(), disabledTest, 
						 500, 1484493673, CASE_TIME_OUT, Tester::COMPACT_REPORT
						 );
}
// CUT end
