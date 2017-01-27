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

int factorial[(int)1e7]; //10 power 7

class ExtraordinarilyLarge {
public:
    void precompute() {
	factorial[0]=1;
	factorial[1]=1;
	
	for(int i=2; i<1e9; ++i) {
	    factorial[i]=i*factorial[i-1];
	    if(factorial[i] > 1e9) {
		break; // enough
	    }
	}
	
    }
    
    int my_sti(string s) {
	stringstream ss;
	ss << s;
	int ret;
	ss >> ret;
	return ret;
    }
    
    
    int myparse(string s) {
	int n=0,f=0;
        for(int i=0; i<s.length(); ++i) {
            if(s[i]=='!') {
                n = my_sti (s.substr(0, i));
                f = s.length() - i;
                break;
            }
        }
        debug("n, f:", n, f);
	
	int S=n;
	for(int i=0; i<f; ++i) {
	    if(S>1e7) return INT_MAX;
	    S=factorial[S];
	    if(S==0) return INT_MAX;
	}
	return S;
    }
    
    string compare(string x, string y) {
	memset(factorial, 0, sizeof(factorial));
	precompute();
	int strip=0;
	while(x[x.size()-1] == '!' && y[y.size()-1] == '!') {
	    x=x.substr(0, x.size()-1);
	    y=y.substr(0, y.size()-1);
	    ++strip;
	}
	debug("after strip:", x, y);
	
	int X=0, Y=0;
	if(x[x.size()-1]!='!' && y[y.size()-1]=='!') {
	    X=my_sti(x);
	    Y=myparse(y);
	} else if (x[x.size()-1]=='!' && y[y.size()-1]!='!'){
	    X=myparse(x);
	    Y=my_sti(y);
	} else if (x[x.size()-1]!='!' && y[y.size()-1]!='!') {
	    X=my_sti(x);
	    Y=my_sti(y);
	}
	
	if(X==0 && strip!=0) X=1;
	if(Y==0 && strip!=0) Y=1;
	
	if(X<Y) return "x<y";
        if(X>Y) return "x>y";
        if(X==Y) return "x=y";
	return "error";
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
	{ { "0!", "1" }, {"x=y"} },
	{ { "9!", "999999999" }, {"x<y"} },
	{ { "9!!", "999999999" }, {"x>y"} },
	{ { "456!!!", "123!!!!!!" }, {"x<y"} },
	{ { "5!", "120" }, {"x=y"} },
	{ { "0!", "0!!!!!!!!" }, {"x=y"} },
	{ {"39916800!!!!!", "11!!!!!!"}, {"x=y"} },
	
	// Your custom test goes here:
	//{ { , }, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    string p0;string p1;

    string run(ExtraordinarilyLarge* x) {
	return x->compare(p0,p1);
    }
    void print() { Tester::printArgs(p0,p1); }
};
    
int main() {
    return Tester::runTests<ExtraordinarilyLarge>(
						  getTestCases<input, Tester::output<string>>(), disabledTest, 
						  500, 1484560505, CASE_TIME_OUT, Tester::COMPACT_REPORT
						  );
}
// CUT end
