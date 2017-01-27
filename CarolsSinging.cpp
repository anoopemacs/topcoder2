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

int Np;
int Ns;
vector<string> l;

int ans=INT_MAX;

class CarolsSinging {
public:
    int myprocess(string s) {
	int p=0;
	int didsing[30];
	memset(didsing, 0, sizeof(didsing));
	//debug(Ns, s.size());
	
	for(int i=0; i<Ns; ++i) {
	    if(s[i]!='0') {
		for(int j=0; j<Np; ++j) {
		    if(l[j][i]=='Y' && didsing[j]==0) {
			didsing[j]=1;
			++p;
		    } 
		}
	    }
	}
	int ct = count(s.begin(), s.end(), '1');
	//if(ct==6 && p==Np-1) debug(s, p, Np);
	
	if(p>=Np) {
	    //cout << s << endl;
	    //debug(count(s.begin(), s.end(), '1'));
	    return count(s.begin(), s.end(), '1');
	}
	return INT_MAX;
    }
    
    int myaux(int b, string s) {
	
        if(b>=Ns) {
	    //	    cout << "\"" << s << "\"" << ",";
	    int run = myprocess(s);
	    ans = min (ans, run);
            return ans;
        }
        s[b]='0';
        int ret1=myaux(b+1, s);
	
        s[b]='1';
        int ret2=myaux(b+1, s);
	
        return min(ret1, ret2);
    }
    
    int choose(vector<string> lyrics) {
	Np=lyrics.size(); //num of persons
	Ns=lyrics[0].length(); //num of songs
	l=lyrics;
	string base="0000000000";
	
	return myaux(0, base.substr(0, Ns));
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
	{ { {"YN","NY"} }, {2} },
	{ { {"YN","YY","YN"} }, {1} },
	{ { {"YNN","YNY","YNY","NYY","NYY","NYN"} }, {2} },
	{ { {"YNNYYY","YYNYYY","YNNYYN","NYYNNN","YYYNNN","YYYNNY","NYYYYY","NYNYYY","NNNNYY","YYYYYY","YNNNNN","YYYYNY","YYNNNN","NNYYYN","NNNNYY","YYYNNN","NYNNYN","YNNYYN","YYNNNY","NYYNNY","NNYYYN","YNYYYN","NNNYNY","YYYYNN","YYNYNN","NYYNYY","YYNYYN"} }, {4} },
	{ {{"YNNYNNNNNN", "NNNNNYNYNN", "NNNNYNNNYN", "NNYNNNYNNN", "NNNNNYNNNY", "NNYNNNNNNY", "NNNNNNNYYN", "NNYNNNNNYN", "NNNNNNNNYY", "NNNYNNNYNN", "YNNNNNNNNN", "NNYNNNNNNY", "NNNYNNNNNY", "NNNYYNNNNN", "NNNNNNYNNY", "YNYNNNNNNN", "NYNNYNNNNN", "NNNNNYNNNY", "NNNNNNNNYY", "YNNNNNNNYN", "NNNNNYYNNN"}}, {6}},
	// Your custom test goes here:
	//{ { {}}, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    vector<string> p0;

    int run(CarolsSinging* x) {
	return x->choose(p0);
    }
    void print() { Tester::printArgs(p0); }
};
    
int main() {
    return Tester::runTests<CarolsSinging>(
					   getTestCases<input, Tester::output<int>>(), disabledTest, 
					   500, 1484716167, CASE_TIME_OUT, Tester::COMPACT_REPORT
					   );
}
// CUT end
