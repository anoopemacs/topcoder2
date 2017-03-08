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

class TwoStringMasks {
public:
    string shortestCommon(string s1, string s2) {
	if(s1=="*") {
            string::iterator iter = remove(s2.begin(),s2.end(), '*');
            return string(s2.begin(), iter);
        }
	
	if(s2=="*") {
	    string::iterator iter = remove(s1.begin(),s1.end(), '*');
	    return string(s1.begin(), iter);
	}
	
	string::iterator it1 = find(s1.begin(), s1.end(), '*');
	string::iterator it2 = find(s2.begin(), s2.end(), '*');
	
	if(it1-s1.begin() > it2-s2.begin()) {
	    string temp = s1; s1=s2; s2=temp;
	}
        //now s1's '*' occurs first

        //update iterators
	it1 = find(s1.begin(), s1.end(), '*');
        it2 = find(s2.begin(), s2.end(), '*');
	
	int len_prefix = it1-s1.begin();
	//	debug(len_prefix, *it1);
        
	string prefix1 = s1.substr(0, len_prefix);
	string prefix2 = s2.substr(0, len_prefix);
	//	debug(prefix1, prefix2);
	
	if(prefix1 != prefix2) return "impossible";

	s1 = string(it1, s1.end());
	s2 = string(s2.begin()+len_prefix, s2.end());
	//	debug(s1, s2);

	// ***************************************************************************************************
	
	//backside:
	string sr1 = string(s1.rbegin(), s1.rend()), sr2 = string(s2.rbegin(), s2.rend());
	string::iterator irt1 = find(sr1.begin(), sr1.end(), '*');
        string::iterator irt2 = find(sr2.begin(), sr2.end(), '*');
        
        if(irt1-sr1.begin() > irt2-sr2.begin()) {
            string temp = sr1; sr1=sr2; sr2=temp;
        }
        //now sr1's '*' occurs first

        //update irterators
        irt1 = find(sr1.begin(), sr1.end(), '*');
        irt2 = find(sr2.begin(), sr2.end(), '*');
        
        int len_suffix = irt1-sr1.begin();
	//        debug(len_suffix, *irt1);
        
        string suffix1 = sr1.substr(0, len_suffix);
        string suffix2 = sr2.substr(0, len_suffix);
	//        debug(suffix1, suffix2);
        
        if(suffix1 != suffix2) return "impossible";

        sr1 = string(irt1, sr1.end());
        sr2 = string(sr2.begin()+len_suffix, sr2.end());
        //debug("***************************************************************************************************");
	//debug(sr1, sr2);

	string a=string(sr2.rbegin(), sr2.rend());
	string b=string(sr1.rbegin(), sr1.rend());
	if(a[0]!='*') {
	    string temp=a; a=b; b=temp;
	}
	
	debug(a,b);
	//a has '*' at beginning, b has '*' at end
	
	
	//solving:
	int df = a.length() - b.length();
	if(df<0) df = df*(-1);

	//note: ans_max_length = 49+49 = 98

	//'*' replacement length belongs to [0, 49]
	for(int l1=0; l1<=49; ++l1) {
	    int l2 = (a.length()<b.length())? l1-df : l1+df;
	    if(l2<0) continue;

            string A = string(a.begin(), find(a.begin(), a.end(), '*')) + string(l1, '*') + string(find(a.begin(),a.end(),'*')+1, a.end());
	    //string A = string(l1, '*') + string(a.begin()+1, a.end());
            //string B = string(b.begin(), b.end()-1) + string(l2, '*');
	    string B = string(b.begin(), find(b.begin(), b.end(), '*')) + string(l2, '*') + string(find(b.begin(),b.end(),'*')+1, b.end());
	    debug("assert equal:", A.length(), B.length());
	    //debug(a, b, A,B);
	    debug(A,B);

	    int A_replace_count = 0;
	    int B_replace_count = 0;
	    
	    for(int i=0; i<A.length(); ++i) {
		if(A[i]=='*' && B[i]=='*') {
		    A[i] = '$';
		    B[i] = '$';
		}
		if(A[i]=='*') {
		    A[i]=B[i];
		    ++A_replace_count;
		}
		if(B[i]=='*') {
		    B[i]=A[i];
		    ++B_replace_count;
		}
	    }
	    debug("replace counts A,B", A_replace_count, B_replace_count);
	    
	    if(A==B) {
		reverse(suffix1.begin(), suffix1.end());
		debug("summing step:", prefix1, A, suffix1);
		return prefix1 + A + suffix1;	
	    } 
	    
	}
	
	// never reached
	return "never_reached";
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
        { { "A*", "*B" }, {"AB"} },   
	{ { "TOPC*DER", "T*PCODER" }, {"TOPCODER"} },
	{ { "HELLO*", "HI*" }, {"impossible"} },
	{ { "GOOD*LUCK", "*" }, {"GOODLUCK"} },
	{ { "*SAMPLETEST", "THIRDSAMPLE*" }, {"THIRDSAMPLETEST"} },
	{ { "*TOP", "*CODER" }, {"impossible"} },
	{ { "*", "A*" }, {"A"} },
	{ { "*A", "B*" }, {"BA"} },
	{ { "LASTCASE*", "*LASTCASE" }, {"LASTCASE"} },
	{ {"THISISATESTTHATCHECKSAVERYWEIRDSPECIFIC*SITUTATION", "THISIS*ON"}, {"THISISATESTTHATCHECKSAVERYWEIRDSPECIFICSITUTATION"}},
	// Your custom test goes here:
	//{ { , }, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    string p0;string p1;

    string run(TwoStringMasks* x) {
	return x->shortestCommon(p0,p1);
    }
    void print() { Tester::printArgs(p0,p1); }
};
    
int main() {
    return Tester::runTests<TwoStringMasks>(
					    getTestCases<input, Tester::output<string>>(), disabledTest, 
					    500, 1488773490, CASE_TIME_OUT, Tester::COMPACT_REPORT
					    );
}
// CUT end
