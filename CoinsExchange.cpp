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

class CoinsExchange {
public:
    int countExchanges(int G1, int S1, int B1, int G2, int S2, int B2) {
	//8 cases

	if(G1<G2 && S1<S2 && B1<B2) return -1;
	if(G1>=G2 && S1>=S2 && B1>=B2) return 0;

	if(G1<G2 && S1>=S2 && B1>=B2) {
	    int greq = G2-G1;
            int srem = S1-S2;
	    int brem = B1-B2;

	    int sreq = greq*11;
	    if(sreq<=srem) return greq;

	    int breq = (sreq-srem)*11;
	    if(breq>brem) return -1;

	    return (sreq-srem) + greq;
	}

	if(G1<G2 && S1<S2 && B1>=B2) {
            int greq = G2-G1;
            int sreq = (S2-S1) + greq*11;
            int brem = B1-B2;
	    
	    int breq = sreq*11;
	    if(breq>brem) return -1;
	 
	    return sreq + greq;
        }
	
	if(G1<G2 && S1>=S2 && B1<B2) {
            int greq = G2-G1;
            int srem = S1-S2;
            int breq = B2-B1;
            
            int sreq = greq*11 + ceil(breq/9.0);
	    if(sreq>srem) return -1;
         
            return greq + (int) ceil(breq/9.0);
        }
	
	if(G1>=G2 && S1<S2 && B1<B2) {
            int grem = G1-G2;
            int breq = B2-B1;
	    int sreq = S2-S1 + (int)ceil(breq/9.0);         

            int greq = ceil(sreq/9.0);
            if(greq>grem) return -1;

            return greq + (int)ceil(breq/9.0);
        }
	
	if(G1>=G2 && S1<S2 && B1>=B2) {
            int grem = G1-G2;
            int sreq = S2-S1;
            int brem = B1-B2;

	    int smax = grem*9+brem/11;
	    if(smax<sreq) return -1;
	    
	    if(grem*9 >= sreq)
		return ceil(sreq/9.0);
	    else
		return grem + (sreq-grem*9);
        }

	if(G1>=G2 && S1>=S2 && B1<B2) {
            int grem = G1-G2;
            int srem = S1-S2;
            int breq = B2-B1;

            int bmax = grem*81+srem*9;
            if(bmax<breq) return -1;
            
            if(srem*9 >= breq)
                return (int)ceil(breq/9.0);
	    else {
		int sreq = (int)ceil(breq/9.0);
		return sreq + (int)ceil((sreq-srem)/9.0);
	    }
		
        }
	
	return -69;
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
    { { 1, 0, 0, 0, 0, 81 }, {10} },
    { { 1, 100, 12, 5, 53, 33 }, {7} },
    { { 1, 100, 12, 5, 63, 33 }, {-1} },
    { { 5, 10, 12, 3, 7, 9 }, {0} },
    // Your custom test goes here:
    //{ { , , , , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;int p2;int p3;int p4;int p5;

        int run(CoinsExchange* x) {
            return x->countExchanges(p0,p1,p2,p3,p4,p5);
        }
        void print() { Tester::printArgs(p0,p1,p2,p3,p4,p5); }
    };
    
    int main() {
        return Tester::runTests<CoinsExchange>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1486016945, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
