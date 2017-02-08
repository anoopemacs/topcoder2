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

class WhiteHats {
public:
    bool validp(vector<char> p, vector<int> wc) {
	int w = count(p.begin(), p.end(), 'w');
	
	for(int i=0; i<p.size(); ++i) {
	    if(p[i]=='w' && wc[i]!=w-1) return false;
	    if(p[i]=='b' && wc[i]!=w) return false;
        }
	return true;
    }
    
    void myaux(char s, vector<int> wc, int si, vector<char>& vc) {
	if(si==wc.size()-1) {
	    vc.push_back(s);
	    return;   
	}
	
	if(s=='b') {
	    vc.push_back('b');
	    if(wc[si]==wc[si+1])
		myaux('b', wc, si+1, vc);
	    else
		myaux('w', wc, si+1, vc);
	} else {
	    vc.push_back('w');
	    if(wc[si]==wc[si+1])
		myaux('w', wc, si+1, vc);
	    else
		myaux('b', wc, si+1, vc);
	}
    }
    
    int whiteNumber(vector<int> count) {
	vector<int> wc = count;
	int N = count.size();
	vector<int> bc;
	for(int i=0; i<N; ++i)
	    bc.push_back(N-1-wc[i]);
	
	vector<char> vc1;
	myaux('b', wc, 0, vc1);
	vector<char> vc2;
	myaux('w', wc, 0, vc2);
	debug(vc1, vc2);
	
	if(validp(vc1, wc)) {
	    int ret=0;
	    for(int i=0; i<vc1.size(); ++i)
		if(vc1[i]=='w') ++ret;
	    return ret;
	}
	if(validp(vc2, wc)) {
	    int ret=0;
            for(int i=0; i<vc2.size(); ++i)
                if(vc2[i]=='w') ++ret;
            return ret;
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
    { { {2,1,1} }, {2} },
    { { {2,2,2} }, {3} },
    { { {0,0} }, {0} },
    { { {1,1,1,2} }, {-1} },
    { { {10,10} }, {-1} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;

        int run(WhiteHats* x) {
            return x->whiteNumber(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<WhiteHats>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1486363311, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
