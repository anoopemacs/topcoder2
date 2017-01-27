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

class PrefixFreeSets {
public:
    static bool compare(string s1, string s2) {
	return (s1.length() < s2.length());
    }
    
    int maxElements(vector<string> words) {
	sort(words.begin(), words.end(), compare);
	stable_sort(words.begin(), words.end(), compare);
	debug(words);
	int N = words.size();
	int ret = 0;
	
	for(int i=0; i<N; ++i) {
	    string wi=words[i];
	    ++ret;
	    
	    for(int j=i+1; j<N; ++j) {
		string wj=words[j];
		if(wj.find(wi) == 0) {
		    --ret;
		    break;
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
	{ { {"hello","hi","h","run","rerun","running"} }, {4} },
	{ { {"a","b","cba","cbc","cbb","ccc"} }, {6} },
	{ { {"a","ab","abc","abcd","abcde","abcdef"} }, {1} },
	{ { {"topcoder","topcoder","topcoding"} }, {2} },
	// Your custom test goes here:
	//{ { {}}, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    vector<string> p0;

    int run(PrefixFreeSets* x) {
	return x->maxElements(p0);
    }
    void print() { Tester::printArgs(p0); }
};
    
int main() {
    return Tester::runTests<PrefixFreeSets>(
					    getTestCases<input, Tester::output<int>>(), disabledTest, 
					    500, 1484504490, CASE_TIME_OUT, Tester::COMPACT_REPORT
					    );
}
// CUT end
