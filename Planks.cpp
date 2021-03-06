#include <bits/stdc++.h>
#define debug(args...) // Just strip off all debug tokens
#define dump(x) // Just strip off all dump tokens
using namespace std;
typedef long long int64;

// CUT begin
#undef dump
#define dump(x) cerr << #x << " = " << (x) << endl;
#undef debug
#define debug(args...) {dbg,args;cout<<endl;}
struct debugger{template<typename T> debugger& operator ,(const T& v){cout<<v<<" ";return *this;}}dbg;
template <typename T1,typename T2> inline ostream& operator<<(ostream& os,const pair<T1,T2>& p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>inline ostream&operator<<(ostream& os,const vector<T>& v){string delim="[";for(unsigned int i=0;i < v.size();i++){os<<delim<<v[i];delim=", ";}return os<<"]";}
template<typename T>inline ostream&operator<<(ostream& os,const set<T>& v){string delim="[";for (typename set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
template<typename T1,typename T2>inline ostream&operator<<(ostream& os,const map<T1,T2>& v){string delim="[";for (typename map<T1,T2>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
// CUT end

int myMax(int a, int b) {
    if(a>b) return a;
    return b;
}

class Planks {    
public:
    
    int makeSimilar(vector<int> lengths, int costPerCut, int woodValue) {
	int ret = 0;    
	int maxLength = accumulate(lengths.begin(), lengths.end(), 0, myMax);
	
	for(int L=1; L<=maxLength; ++L) {
	    int moneyAtL = 0;
	    for(int i=0; i<lengths.size(); ++i) {
                int l = lengths[i];                 

                if(L==lengths[i]) {
		    moneyAtL += l*woodValue;
                } else if (L<lengths[i]) {
		    
		    if(woodValue*L - costPerCut > 0) {
			moneyAtL += (l/L)*(woodValue*L - costPerCut);

			if(l%L == 0) moneyAtL += costPerCut; //reimburse last cut                   
                    }
		    
                }
            }
	    ret = max(ret, moneyAtL);
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
    { { {26,103,59}, 1, 10 }, {1770} },
    { { {26,103,59}, 10, 10 }, {1680} },
    { { {26,103,59}, 100, 10 }, {1230} },
    { { {5281,5297,5303,5309,5323,5333,5347,5351,5381,5387}, 5, 20 }, {1057260} },
    { { {31,73,127,179,181,191,283,353,359,1019}, 25, 10 }, {25145} },
    { { {200,200,200,400}, 1000, 1 }, {600} },
    // Your custom test goes here:
    //{ { {}, , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;int p1;int p2;

        int run(Planks* x) {
            return x->makeSimilar(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };
    
    int main() {
        return Tester::runTests<Planks>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1488356951, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
