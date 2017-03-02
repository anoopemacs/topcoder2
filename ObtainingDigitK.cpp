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

class ObtainingDigitK {
public:
    
    int myhas(string s, int k) {
	return find(s.begin(), s.end(), (char)('0'+k)) != s.end();
    }
    
    int minNumberToAdd(string n, int k) {
	int N = n.size();
	if(myhas(n, k))
	    return 0;

	int l = n[N-1] - '0';

	int b = N-2;
        while(n[b]=='9')
            --b;
	int non9;

	if(b<0) non9 = 0;
        else  non9 = n[b]-'0';

	if(non9+1 != k)
	    return (k-l+20)%10;
	else {
	    return min((k-l+20)%10, 10-l);    
	}
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
    { { "153", 7 }, {4} },
    { { "158", 7 }, {9} },
    { { "7853192", 2 }, {0} },
    { { "99999999999999999999999999999999999999999999999", 0 }, {1} },
    { { "2999", 3 }, {1} },
    { { "24997", 5 }, {3} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        string p0;int p1;

        int run(ObtainingDigitK* x) {
            return x->minNumberToAdd(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<ObtainingDigitK>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1487714053, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
