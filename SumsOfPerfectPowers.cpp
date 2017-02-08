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

class SumsOfPerfectPowers {
public:
    
    int howMany(int L, int U) {
	if(L==0 && U==0) return 1;
	
        int ret=0;
	vector<int> ppvec;
	ppvec.push_back(0);
	ppvec.push_back(1);
	
        for(int b=2; b<=2500; ++b) { //b=base
            long runb=b;
            while(runb<=U) {
                runb *= b;
                if(runb<=U) ppvec.push_back(runb);
            }
        }
	
	sort(ppvec.begin(), ppvec.end());
	vector<int>::iterator iter = unique(ppvec.begin(), ppvec.end());
	ppvec.resize(distance(ppvec.begin(), iter));
        //debug(ppvec);

	vector<int> valids;
	for(int i=0; i<ppvec.size(); ++i) {
	    for(int j=0; j<ppvec.size(); ++j) {
		valids.push_back(ppvec[i]+ppvec[j]);
	    }
	}
	
        sort(valids.begin(), valids.end());
        vector<int>::iterator iter2 = unique(valids.begin(), valids.end());
        valids.resize(distance(valids.begin(), iter2));
        debug(valids);
	for(int i=0; i<valids.size(); ++i) {
	    if(valids[i]>=L && valids[i]<=U) ++ret;
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
	{ { 0, 4 }, {4} },
	/*
	{ { 0, 1 }, {2} },
	{ { 5, 6 }, {1} },
	{ { 25, 30 }, {5} },
	{ { 103, 103 }, {0} },
	{ { 1, 100000 }, {33604} },
	{ {5000000, 5000000}, {1} },
	*/
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;

        int run(SumsOfPerfectPowers* x) {
            return x->howMany(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<SumsOfPerfectPowers>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1485972233, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end


/*
  class SumsOfPerfectPowers_brute_force {
  public:
  bool pp(long n) {
  //is a perfect power
  if(n==0 || n==1) return true;
	
  for(long b=2; b<=2500; ++b) { //b=base
  long runb=b;
  while(runb<n) {
  runb *= b;
  if(runb==n) return true;
  }
  }
	
  return false;
  }
    
  int howMany(int L, int U) {
  int ret=0;
	
  for(long n=L; n<=U; ++n) {
  //  debug("n = ", n, " ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	    
  bool nbool = false;
  //split n into a+b
  for(long a=0; a<=n/2; ++a) {
  long b = n-a;
  //	debug(a, b);
		
  if(pp(a) && pp(b)) {
  nbool = true;
  break;
  }
  }
  if(nbool == true) ++ret;
  }
	
  return ret;
  }
  };
*/
