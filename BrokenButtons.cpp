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

class BrokenButtons {
public:
    string myits(int i) {
        stringstream ss;
        ss<<i;
        string ret;
        ss>>ret;
        return ret;
    }

    bool validp(int n, vector<int> broken) {
        if(n<0) return false;
	
	switch(n) {
        case 98:
        case 99:
        case 100:
        case 101:
        case 102:
        case 103:
            return true;
        }

	string s = myits(n);
	for(int i=0; i<broken.size(); ++i) {
	    char button = '0'+broken[i];
	    if(s.find(button, 0) != -1)
		return false;
	}
	return true;
    }
    
    int minPresses(int page, vector<int> broken) {
	switch(page) {
	case 98:
	case 99:
	case 100:
	case 101:
	case 102:
	case 103:
	    return abs(100-page);
	}

	if(validp(page, broken))
	    return myits(page).size();

	int l = page, r = page;
	while(!(validp(l, broken)) && l>=0) --l;
	while(!(validp(r, broken)) && r<=1000000) ++r;
	debug(l, r);

	int diff = abs(100-page);
	int ret = INT_MAX;
	
	if(validp(l, broken) && validp(r, broken)) {
	    ret = min(minPresses(l, broken) + (page-l), minPresses(r, broken) + (r-page));
	} else if(validp(l, broken) && !validp(r, broken)) {
	    ret = minPresses(l, broken) + (page-l);
	} else if(!validp(l, broken) && validp(r, broken)) {
	    ret = minPresses(r, broken) + (r-page);    
	}   
	
	return min(diff, ret);
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
    { { 5457, {6,7,8} }, {6} },
    { { 100, {1,0,5} }, {0} },
    { { 14124, {} }, {5} },
    { { 1, {1,2,3,4,5,6,7,8,9} }, {2} },
    { { 80000, {8,9} }, {2228} },
    { {498992, {1, 2, 3, 5, 6, 7, 8, 9}}, {54554}},
    { {500000, {0, 1, 2, 3, 4, 5, 6, 8, 9}}, {277783}},
    { {1, {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}}, {99}},
    // Your custom test goes here:
    //{ { , {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;vector<int> p1;

        int run(BrokenButtons* x) {
            return x->minPresses(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<BrokenButtons>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1486312008, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
