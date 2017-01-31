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

class CreatePairs {
 public:
    int maximalSum(vector<int> data) {
	vector<int> small, medium, large;
	for (int i=0; i<data.size(); ++i) {
	    if(data[i] > 1) large.push_back(data[i]);
	    else if (data[i] == 1) medium.push_back(data[i]);
	    else if (data[i] < 1) small.push_back(data[i]);
	}
	int ret = 0;
	for(int i=0; i<medium.size(); ++i)
	    ret = ret + medium[i];
	
	sort(small.begin(), small.end());
	sort(large.rbegin(), large.rend());

	for(int i=0; i<small.size(); i=i+2) {
	    if((i+1) < small.size())
		ret = ret + small[i]*small[i+1];
	    else
		ret = ret + small[i];
	}

	for(int i=0; i<large.size(); i=i+2) {
            if((i+1) < large.size())
                ret = ret + large[i]*large[i+1];
            else
                ret = ret + large[i];
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
    { { {0,1,2,4,3,5} }, {27} },
    { { {-1,1,2,3} }, {6} },
    { { {-1} }, {-1} },
    { { {-1,0,1} }, {1} },
    { { {1,1} }, {2} },
    { { {2,2} }, {4} },
    { {{-1, -1, -1}}, {0} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;

        int run(CreatePairs* x) {
            return x->maximalSum(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<CreatePairs>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1485677213, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
