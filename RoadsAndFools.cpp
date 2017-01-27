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

class RoadsAndFools {
    bool mycheck(vector<int> ans) {
	for(int i=1; i<ans.size(); ++i) {
            if(ans[i]<=ans[i-1])
		return false;
        }
	return true;
    }
public:
    string myits(int s) {
	stringstream ss;
	ss<<s;
	string ret;
	ss>>ret;
	return ret;
    }
    
    string determineOrientation(int length, vector<int> frontSides) {
	int N=frontSides.size();
	vector<int> backSides;
	for(int i=0; i<N; ++i)
	    backSides.push_back(length-frontSides[i]);
	
	vector<int> greediest;
	
	int cmp=INT_MIN;
	for(int i=0; i<N; ++i) {
	    int small=min(frontSides[i], backSides[i]);
	    int large=max(frontSides[i], backSides[i]);
	    if(small > cmp) {
		greediest.push_back(small);
		cmp=small;
	    } else {
		greediest.push_back(large);
		cmp=large;
	    }
	}
	debug(greediest);
	if(!(mycheck(greediest))) return "NO SOLUTION";
	
	//hereon greediest is one possible solution
	string ret=myits(greediest[0]);
	for(int i=1; i<N; ++i)
	    ret=ret+" "+ myits(greediest[i]);
	
	//check for multiple sols:
	
	for(int j=0; j<N; ++j) {
	    vector<int> sol;
            int cmp2=INT_MIN;
	    
	    for(int i=0; i<N; ++i) {
		int small=min(frontSides[i], backSides[i]);             
                int large=max(frontSides[i], backSides[i]);             
		
        	//j-th we will pick large:
		if(i==j) {
		    if(small<=cmp2) {
			sol.push_back(INT_MIN);
			break;
		    }
		    sol.push_back(large);
		    cmp2=large;
		    continue;
		}
		
		if(small > cmp2) {
		    sol.push_back(small);
		    cmp2=small;
		} else {
		    sol.push_back(large);
		    cmp2=large;
		}
	    }
	    if(mycheck(sol) && (sol!=greediest)) return "MULTIPLE SOLUTIONS";
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
	{ { 5, {1,2,3} }, {"1 2 3"} },
	{ { 5, {5,2,0} }, {"MULTIPLE SOLUTIONS"} },
	{ { 5, {4,4} }, {"1 4"} },
	{ { 5, {4,4,4} }, {"NO SOLUTION"} },
	{ { 5, {3} }, {"MULTIPLE SOLUTIONS"} },
	{ { 10, {5} }, {"5"} },
	// Your custom test goes here:
	//{ { , {}}, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    int p0;vector<int> p1;

    string run(RoadsAndFools* x) {
	return x->determineOrientation(p0,p1);
    }
    void print() { Tester::printArgs(p0,p1); }
};
    
int main() {
    return Tester::runTests<RoadsAndFools>(
					   getTestCases<input, Tester::output<string>>(), disabledTest, 
					   500, 1484643350, CASE_TIME_OUT, Tester::COMPACT_REPORT
					   );
}
// CUT end
