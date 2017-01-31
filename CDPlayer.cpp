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

class CDPlayer {
public:
    vector<string> mysplit(string s, int n, int b) {
	//n = size of each part, b = begin
	vector<string> ret;
	if(b!=0) {
	    ret.push_back(s.substr(0, b));
	}

	while(b < s.size()) {
	    string part = s.substr(b, n);
	    ret.push_back(part);
	    b = b+n;
	}
	return ret;
    }
    
    bool mycheck(vector<string> vs) {
	//each of s in vs is unique
	int N = vs.size();
	for(int i=0; i<N; ++i) {
	    string s = vs[i];
	    sort(s.begin(), s.end());
	    string::iterator iter = unique(s.begin(), s.end());
	    if(iter != s.end())
		return false;
	}
	return true;
    }
    
    int isRandom(vector<string> sl, int n) {
	int N = sl.size();
	string S;
	int len=0;
	for(int i=0; i<N; ++i) {
	    S+=sl[i];
	    len=len+sl[i].size();
	}

	

        for(int j=0; j<n; ++j) { // j - is the start index

	    vector<string> vs = mysplit(S, n, j);

	    //check vs for each is unique
	    bool checkAtj = mycheck(vs);

	    if(checkAtj == true) {
		debug(vs, j);
		return j;
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
    { { {"BBAC"}, 3 }, {1} },
    { { {"BACAB","BCA"}, 3 }, {2} },
    { { {"AAACBACBACBACBACBACBACB"}, 3 }, {-1} },
    { { {"ABCDEABDECBAECDEDACB"}, 5 }, {0} },
    { { {"ABCABCABCABCABCABCABC","ABCABCABCABCABCABCABC"}, 22 }, {-1} },
    { { {"AAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAA"}, 1 }, {0} },
    { { {"ADEF"}, 12 }, {0} },
    // Your custom test goes here:
    //{ { {}, }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;int p1;

        int run(CDPlayer* x) {
            return x->isRandom(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<CDPlayer>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1485864123, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
