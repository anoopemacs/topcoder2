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

class PalindromeDecoding {
    string myinsert(string s, int before, string cut) {
	string ret=s.substr(0, before);
	ret=ret+cut;
	ret=ret+s.substr(before, s.size()-before);
	return ret;
    }
public:
    string decode(string code, vector<int> position, vector<int> length) {
	int N=position.size();
	for(int i=0; i<N; ++i) {
	    string cut=code.substr(position[i], length[i]);
	    reverse(cut.begin(), cut.end());
	    code=myinsert(code, position[i]+length[i], cut);
	}
	return code;
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
	{ { "ab", {0}, {2} }, {"abba"} },
	{ { "Misip", {2,3,1,7}, {1,1,2,2} }, {"Mississippi"} },
	{ { "XY", {0,0,0,0}, {2,4,8,16} }, {"XYYXXYYXXYYXXYYXXYYXXYYXXYYXXYYX"} },
	{ { "TC206", {1,2,5}, {1,1,1} }, {"TCCC2006"} },
	{ { "nodecoding", {}, {} }, {"nodecoding"} },
	// Your custom test goes here:
	//{ { , {}, {}}, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    string p0;vector<int> p1;vector<int> p2;

    string run(PalindromeDecoding* x) {
	return x->decode(p0,p1,p2);
    }
    void print() { Tester::printArgs(p0,p1,p2); }
};
    
int main() {
    return Tester::runTests<PalindromeDecoding>(
						getTestCases<input, Tester::output<string>>(), disabledTest, 
						500, 1484649291, CASE_TIME_OUT, Tester::COMPACT_REPORT
						);
}
// CUT end
