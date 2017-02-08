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

class LostParentheses {
public:
    vector<string> mysplit(string s, char c) {
        vector<string> ret;
        int i=0;
        while(i<s.size()) {
            int j=s.find(c, i);
            if(j==-1) {
                ret.push_back(s.substr(i));
                break;
            } else {
                ret.push_back(s.substr(i, j-i));
            }
            i=j+1;
        }
        sort(s.begin(), s.end());
        return ret;
    }
    
    long mystl(string s) {
        stringstream ss;
        ss<<s;
        long ret;
        ss>>ret;
        return ret;
    }

    int minResult(string e) {
	vector<string> vs = mysplit(e, '-');

	vector<long> vl;
	
	for(int i=0; i<vs.size(); ++i) {
	    vector<string> vs2 = mysplit(vs[i], '+');
	    long partSum = 0;
	    for(int j=0; j<vs2.size(); ++j) {
		partSum += mystl(vs2[j]);
	    }
	    vl.push_back(partSum);
	}

	long ret = vl[0];
	for(int i=1; i<vl.size(); ++i) {
	    ret = ret - vl[i];
	}
	return (int) ret;
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
    { { "55-50+40" }, {-35} },
    { { "10+20+30+40" }, {100} },
    { { "00009-00009" }, {0} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        string p0;

        int run(LostParentheses* x) {
            return x->minResult(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<LostParentheses>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1485963604, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
