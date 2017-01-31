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

class CardStraights {
public:
    int longestStraight(vector<int> cards) {
	sort(cards.begin(), cards.end());
	int i=0;
	while(cards[i]==0 && i<cards.size()) ++i;
	int jokers = i;
	//	debug(jokers);
	//debug(cards);
	
	vector<int>::iterator iter = unique(cards.begin(), cards.end());
	vector<int> cards_unique = vector<int>(cards.begin(), iter);

	vector<int>::iterator iter2 = remove(cards_unique.begin(), cards_unique.end(), 0);
	vector<int> cards_nozero = vector<int>(cards_unique.begin(), iter2);
	debug(cards_nozero);
	//cout << "***************************************************************************************************" << endl;
	
	
	int ret=jokers;
	
	for(int j=0; j<cards_nozero.size(); ++j) {// j is the start index of chain
	    
	    int jrun = jokers;
	    int run = 1;
	    
	    int k=j;
	    while(jrun>=0 && (k+1)<cards_nozero.size() && (cards_nozero[k+1]-cards_nozero[k]-1)<=jrun) {
		run = run + (cards_nozero[k+1]-cards_nozero[k]);
		jrun = jrun - (cards_nozero[k+1]-cards_nozero[k]-1);
		++k;
	    }
	    run = run+jrun;
	    jrun = jrun-jrun;
	    
	    //	    debug(vector<int>(cards_nozero.begin()+j, cards_nozero.begin()+k+1), " ====> ", run);
	    ret = max(ret, run);                    
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
    { { {0,6,5,10,3,0,11} }, {5} },
    { { {100,100,100,101,100,99,97,103} }, {3} },
    { { {0,0,0,1,2,6,8,1000} }, {6} },
    { { {1,9,5,7,3,4,0,0,0,10} }, {10} },
    { { {0, 0, 0, 0, 0, 0, 0, 0, 0} }, {9} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;

        int run(CardStraights* x) {
            return x->longestStraight(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<CardStraights>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1485751947, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
