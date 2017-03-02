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

int myop(int a, int b) {
    return max(a, b);
}

class DrawingMarbles {
public:
    double sameColor(vector<int> colors, int n) {
	int N = colors.size();
	int L = accumulate(colors.begin(), colors.end(), INT_MIN, myop);
	debug(L);
	if(n>L) return 0;

	double sum = accumulate(colors.begin(), colors.end(), 0.0);
	double ret = 0;
	
	for(int i=0; i<N; ++i) {
	    if(n<=colors[i]) {
		double probi = 1;
		
		for(int j=0; j<n; ++j) {
		    probi *= (colors[i]-j)/(sum-j);
                }
		
		ret = ret + probi;
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
    { { {13}, 8 }, {1.0} },
    { { {5,7}, 1 }, {1.0} },
    { { {5,6,7}, 2 }, {0.3006535947712418} },
    { { {12,2,34,13,17}, 4 }, {0.035028830818304504} },

    { {{16, 10, 11, 20, 6, 12, 17, 2, 15, 15, 17, 8, 14, 19, 1, 1, 4, 5, 13, 9, 14, 2, 17, 4, 3, 20, 4, 11, 13, 19, 2, 8, 20, 5, 20, 6, 16, 16, 19, 2, 10, 15, 9, 4, 14, 1, 16, 9, 17, 8}, 3}, {6.451180614601044E-4}},
    

    // Your custom test goes here:
    //{ { {}, }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;int p1;

        double run(DrawingMarbles* x) {
            return x->sameColor(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<DrawingMarbles>(
            getTestCases<input, Tester::output<double>>(), disabledTest, 
            500, 1487722337, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
