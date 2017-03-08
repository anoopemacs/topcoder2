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

class CountExpressions {
 public:
    int calcExpressions(int X, int Y, int VAL) {
	int64 x=X, y=Y, val=VAL;
	vector<string> vs;
	
	string num = "xy";
	vector<int> ns;
	ns.push_back(x);
	ns.push_back(y);
	
	string ops = "+-*";

	for(int i=0; i<2; ++i) {
	    for(int j=0; j<3; ++j) {
		for(int k=0; k<2; ++k) {
		    for(int l=0; l<3; ++l) {
			for(int m=0; m<2; ++m) {
			    for(int n=0; n<3; ++n) {
				for(int o=0; o<2; ++o) {
				    string exp = "";
				    exp = exp+num[i];
				    exp = exp+ops[j];
				    exp = exp+num[k];
				    exp = exp+ops[l];
				    exp = exp+num[m];
				    exp = exp+ops[n];
				    exp = exp+num[o];
				    vs.push_back(exp);
				}
			    }
			}
		    }
		}
	    }
	}
	//debug(vs);
	//make vs unique
	sort(vs.begin(), vs.end());
	vector<string>::iterator uEnd = unique(vs.begin(),vs.end());
	
	int ret = 0;
	for(vector<string>::iterator iter = vs.begin(); iter != uEnd; ++iter) {
	    string ex = *iter;
	    
	    if((count(ex.begin(), ex.end(), 'x') == 2) &&
	       (count(ex.begin(), ex.end(), 'y') == 2)) {

		int64 a,b,c,d;
        	int64 fir, sec, thr; //fir = (a op1 b), sec = (fir op2 c), thr = (sec op3 d)
		a=b=c=d=1; fir=sec=thr=1;
		
		a = (ex[0]=='x')? x : y;
		b = (ex[2]=='x')? x : y;
		c = (ex[4]=='x')? x : y;
		d = (ex[6]=='x')? x : y;

		if(ex[1]=='+') fir = a+b;
		else if(ex[1]=='-') fir = a-b;
		else if(ex[1]=='*') fir = a*b;
		
		if(ex[3]=='+') sec = fir+c;
                else if(ex[3]=='-') sec = fir-c;
                else if(ex[3]=='*') sec = fir*c;

		if(ex[5]=='+') thr = sec+d;
                else if(ex[5]=='-') thr = sec-d;
                else if(ex[5]=='*') thr = sec*d;
                
		if(thr==val) ++ret;
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
    { { 7, 8, 16 }, {9} },
    { { 3, 5, 7 }, {5} },
    { { 99, 100, 98010000 }, {6} },
    { { -99, 42, -1764 }, {2} },
    { { 100, -100, -100000000 }, {0} },
    { { 1, 2, 5 }, {17} },
    // Your custom test goes here:
    //{ { , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
	int p0;int p1;int p2;

	int run(CountExpressions* x) {
	    return x->calcExpressions(p0,p1,p2);
	}
	void print() { Tester::printArgs(p0,p1,p2); }
    };

    int main() {
	return Tester::runTests<CountExpressions>(
	    getTestCases<input, Tester::output<int>>(), disabledTest,
	    500, 1488968672, CASE_TIME_OUT, Tester::COMPACT_REPORT
	);
    }
// CUT end
