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

class ProblemsToSolve {
public:
    int minNumber(vector<int> p, int v) {
	int N=p.size();
	if(N==1) return 1;
	
	int mn=0, mx=0;//min, max, variety=mv indices
	int mv=0;
	int i=1;
	for(; i<N; ++i) {
	    if(p[i]>p[mx]) mx=i;
	    if(p[i]<p[mn]) mn=i;
	    mv=p[mx]-p[mn];
	    if(mv>=v) break;
	}
	if(i==N) return N;

	int l=min(mx,mn);
	int r=max(mx,mn);
	debug("l&r:", l, r);
	
	int k=r;
	vector<int> ls; //all possible l values
	for(;k>=0;--k) {
	    int diff=abs(p[r]-p[k]);
	    if(diff>=v) ls.push_back(k);
	}

	debug("ls: ", ls);
	
	int ret=INT_MAX;
	for(int j=0; j<ls.size(); ++j) {
	
	    int L=ls[j];
	    int R=r;
	    
	    int ret_run=1;      //solve problem at r
	
	    while(R-2 >= L) {
		R=R-2;
		debug("#", R-2);
		++ret_run;
	    }
	    if(R != L) {
		R=R-1;
		debug("#", R-1);
        	++ret_run;
	    }
	    debug("assert R=L, R&L:", R, L);
	
	    while(L-2 >= 0) {
		L=L-2;
		debug("#", L-2);
        	++ret_run;
	    }
	    if(L != 0) {
		L=L-1;
		debug("#", L-1);
        	++ret_run;
	    }
	    debug("assert L=0", L);
	    ret = min(ret, ret_run);

	    //   cout << "###################################################################################################"<<endl;
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
    { { {1,2,3}, 2 }, {2} },
    { { {1,2,3,4,5}, 4 }, {3} },
    { { {10,1,12,101}, 100 }, {3} },
    { { {10,1}, 9 }, {2} },
    { { {6,2,6,2,6,3,3,3,7}, 4 }, {2} },
    {{{9, 11, 2, 7, 3, 1, 15, 2, 15, 14, 15, 4, 13, 7, 3, 12, 17, 7, 4, 3}, 11}, {4}},
    // Your custom test goes here:
    //{ { {}, }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;int p1;

        int run(ProblemsToSolve* x) {
            return x->minNumber(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<ProblemsToSolve>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1485788460, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
