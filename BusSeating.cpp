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

class BusSeating {
public:
    double dist(int x, int y) {
	if((x<=9 && y<=9) || (x>=10 && y>=10)) return abs(x-y);
	
	x=x%10;
	y=y%10;
	return sqrt(4+ pow(abs(x-y),2));
    }
    
    double dist3(int x, int y, int z) {
	return dist(x,y) + dist(y, z) + dist(z,x);
    }
    
    double getArrangement(string leftRow, string rightRow) {
	vector<int> bus;
	for(int i=0; i<leftRow.length(); ++i) {
	    if(leftRow[i]=='-') bus.push_back(0);
	    else bus.push_back(1);
	}
	for(int i=0; i<rightRow.length(); ++i) {
            if(rightRow[i]=='-') bus.push_back(0);
            else bus.push_back(1);
        }
	
	double ret=DBL_MAX;
	for(int i=0; i<=19; ++i) {
	    if(bus[i]==1) continue;
	    for(int j=i+1; j<=19; ++j) {
		if(bus[j]==1) continue;
		for(int k=j+1; k<=19; ++k) {
		    if(bus[k]==1) continue;
		    
		    ret=min(ret, dist3(i,j,k));
		}
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
	{ { "----------", "----------" }, {4.0} },
	{ { "XXX-X-XX-X", "-XXXX---XX" }, {4.0} },
	{ { "XXXXXXXXXX", "-XX-XX-X--" }, {6.0} },
	{ { "XXX-X-XX-X", "XXX-X-XX-X" }, {6.82842712474619} },
	// Your custom test goes here:
	//{ { , }, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    string p0;string p1;

    double run(BusSeating* x) {
	return x->getArrangement(p0,p1);
    }
    void print() { Tester::printArgs(p0,p1); }
};
    
int main() {
    return Tester::runTests<BusSeating>(
					getTestCases<input, Tester::output<double>>(), disabledTest, 
					500, 1484560480, CASE_TIME_OUT, Tester::COMPACT_REPORT
					);
}
// CUT end
