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

class BirthNumbersValidator {
public:
    long mysti(string s) {
        stringstream ss;
        ss<<s;
        long ret;
        ss>>ret;
        return ret;
    }
    
    bool leapp(string s) {
	//input = 2digit string
	int si = mysti(s);
	if(si <= 6)
	    s = "20"+s;
	else
	    s = "19"+s;

	int year = mysti(s);
	if((year%400 == 0) || ((year%4==0)&&(year%100!=0)))
	    return true;
	else
	    return false;
    }

    vector<string> validate(vector<string> test) {
	int N = test.size();
	vector<string> ret(N);
	
	for(int i=0; i<N; ++i) {
	    ret[i] = "YES";
	    string bn = test[i];
	    
	    vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	    if (leapp(bn.substr(0, 2))) {
		days_in_month[1] = 29;
	    }
	    debug(days_in_month);

	    int month = mysti(bn.substr(2, 2));
	    int day = mysti(bn.substr(4, 2));
	    long whole0 = mysti(bn);
	    
	    if (whole0 % 11 != 0) {
		ret[i] = "NO";
		continue;
	    }
	    if (month>=51 && month<=62) month-=50;
	    if (!(month>=1 && month<=12)) {
		ret[i] = "NO";
		continue;
	    }

	    int dim = days_in_month[month-1];
	    if (!(day>0 && day<=dim)) {
		ret[i] = "NO";
		continue;
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
    { { {"8104121234"} }, { {"YES"} } },
    { { {"8154121239"} }, { {"YES"} } },
    { { {"8134120005"} }, { {"NO"} } },
    { { {"8102310007","8104121235"} }, { {"NO","NO"} } },
    { { {"0411131237"} }, { {"YES"} } },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;

        vector<string> run(BirthNumbersValidator* x) {
            return x->validate(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<BirthNumbersValidator>(
            getTestCases<input, Tester::output<vector<string>>>(), disabledTest, 
            500, 1485688716, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
