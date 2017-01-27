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

int mem[11]; //[1,9]

class PalindromicNumbers {
public:
    bool palindromic(int n) {
	stringstream ss;
	ss<<n;
	string s;
	ss>>s;
	string s2=s;
	reverse(s2.begin(), s2.end());
	if(s==s2) return true;
	return false;
    }
    
    int digits(int n) {
	int r=n;
	int num_of_digits=0;
	while(r!=0) {
	    r/=10;
	    ++num_of_digits;
	}
	return num_of_digits;
    }
    
    int myreverse(int n) {//reverse an int
	stringstream ss;
	ss<<n;
	string s;
	ss>>s;
	reverse(s.begin(), s.end());
	
	stringstream ss2;
	ss2<<s;
	int ret;
	ss2>>ret;
	return ret;
    }
    
    int aux(int l, int u) {//digits(l)==digits(u)
	if(l==u) {
	    if(palindromic(l)) return 1;
	    else return 0;
	}
	
	int digs=digits(l);
	//num is fxf, range of fx=? [f,F]
	int e=digs/2;
	int f=l/pow(10, e);
	int F=u/pow(10, e);
	
	int ret=0;
	if(F>f) ret=ret+ (F-f-1);
	
	//l=AB, u=CD
	int divisor=pow(10, digs/2);
	int A=l/divisor;
	if(digs%2!=0) A=A/10;
	int B=l%divisor;
	
	int C=u/divisor;
	if(digs%2!=0) C=C/10;
	int D=u%divisor;
	
	if(B<=myreverse(A))
	    ++ret;
	if(D>=myreverse(C))
	    ++ret;
	
	//repeat case:
	int ab=f*pow(10, e) + myreverse(A);
	int cd=F*pow(10, e) + myreverse(C);
	if(ab==cd) --ret;
	
	return ret;
    }
    
    int countPalNums(int lower, int upper) {
	int dl=digits(lower);
	int du=digits(upper);
	if(dl==du)
	    return aux(lower, upper);
	//1+2+3
	int L=pow(10, dl)-1;
	int U=pow(10, du-1);
	
	int ret=0;
	//1&3 [lower, L] & [U, upper]
	debug(aux(lower,L));
	ret+=aux(lower,L);      
	debug(aux(U, upper));
	ret+=aux(U, upper);
	
	debug(lower, L, U, upper);
	
	//2:(L,U)
	int dL=digits(L);
	int dU=digits(U);
	
	debug("1:", aux(lower,L));
	
	for(int d=dL+1; d<=dU-1; ++d) {
	    debug("3: ", aux( pow(10, d-1), pow(10, d)-1 ));
	    ret+=aux( pow(10, d-1), pow(10, d)-1 );
	}
	
	debug("2:", aux(U, upper));
	
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
	{ { 8, 25 }, {4} },
	{ { 111, 222 }, {12} },
	{ { 88966989, 88977987 }, {0} },
	{ { 999999990, 1000000000 }, {1} },
	// Your custom test goes here:
	//{ { , }, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    int p0;int p1;

    int run(PalindromicNumbers* x) {
	return x->countPalNums(p0,p1);
    }
    void print() { Tester::printArgs(p0,p1); }
};

int main() {
    return Tester::runTests<PalindromicNumbers>(
						getTestCases<input, Tester::output<int>>(), disabledTest,
						500, 1484560344, CASE_TIME_OUT, Tester::COMPACT_REPORT
						);
}
// CUT end
