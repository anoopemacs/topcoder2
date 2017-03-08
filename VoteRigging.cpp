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

int mymax(int a, int b) {
    return max(a, b);
}

class VoteRigging {
    int winner(vector<int> votes) {
	if(votes.size()==1) return votes[0];
	int ret = INT_MIN;
	for(int i=1; i<votes.size(); ++i) {
	    ret = max(ret, votes[i]);
	}
	return ret;
    }
 public:
    int minimumVotes(vector<int> votes) {
	if(votes.size()==1) return 0;
	int ret = 0;
	
	while(votes[0] <= winner(votes)) {
	    int i=1;
	    while((votes[i] != winner(votes)) && (i<votes.size())) ++i;
	    
	    debug(winner(votes), i, votes[i]);
	    votes[i] = winner(votes) - 1;
	    votes[0] = votes[0] + 1;
	    ++ret;
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
    { { {5,7,7} }, {2} },
    { { {10,10,10,10} }, {1} },
    { { {1} }, {0} },
    { { {5,10,7,3,8} }, {4} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;

        int run(VoteRigging* x) {
            return x->minimumVotes(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<VoteRigging>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1488732483, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
