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

vector<vector<int>> h;  
int N;

class RGBStreet2 {
    //brute force 3*pow(2*19) possibilities
    vector<int> myparse(string s) {
	vector<int> ret;
	int r,g,b;
	sscanf(s.c_str(), "%d%d%d", &r, &g, &b);
	ret.push_back(r);
	ret.push_back(g);
	ret.push_back(b);
	return ret;
    }
    
    int aux(int pre, int start) {
	// pre=previous color, start=start index of house
	if(start>=N) return 0;
	
	vector<int> hs = h[start];
	int ret=INT_MAX;
	for(int i=0; i<=2; ++i) {
	    if(i==pre) continue;
	    ret=min(ret, hs[i]+aux(i, start+1));
	}
	return ret;
    }
    
public:
    int estimateCost(vector<string> houses) {
	int ret=INT_MAX;
	N=houses.size(); // number of houses
	for(int i=0; i<N; ++i)
	    h.push_back(myparse(houses[i]));
	debug(h);
	
	//3cases
	int ans1=h[0][0]+aux(0, 1);
	int ans2=h[0][1]+aux(1, 1);
	int ans3=h[0][2]+aux(2, 1);
	
	ret=min(ans1, ans2);
	ret=min(ret, ans3);
	
	return ret;
    }
};

int dp[21][3];
int oo=20*1000+1;

class RGBStreet {
    //dynamic programming solution
    vector<int> myparse(string s) {
        vector<int> ret;
        int r,g,b;
        sscanf(s.c_str(), "%d%d%d", &r, &g, &b);
        ret.push_back(r);
        ret.push_back(g);
        ret.push_back(b);
        return ret;
    }
    
public:
    int estimateCost(vector<string> houses) {
        int ret=INT_MAX;
        N=houses.size(); // number of houses
        for(int i=0; i<N; ++i)
            h.push_back(myparse(houses[i]));
        debug(h);
	memset(dp, 0, sizeof(dp));
	dp[20][0]=0; dp[20][1]=0; dp[20][2]=0;
	
	for(int i=N-1; i>=0; --i) { //hnum
	    for(int c=0; c<=2; ++c) { //present color
		int cCost = h[i][c];
		
		int mini=INT_MAX;
                for(int j=0; j<=2; ++j) { //next color
		    if(j==c) continue;
		    mini = min(mini, cCost + dp[i+1][j]);
		}
		dp[i][c] = mini;
            }
	}
	ret = min(dp[0][0], dp[0][1]);
	ret = min(ret, dp[0][2]);
	
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
	{ { {"1 100 100","100 1 100","100 100 1"} }, {3} },
	{ { {"1 100 100","100 100 100","1 100 100"} }, {102} },
	{ { {"26 40 83","49 60 57","13 89 99"} }, {96} },
	{ { {"30 19 5","64 77 64","15 19 97","4 71 57","90 86 84","93 32 91"} }, {208} },
	{ { {"71 39 44","32 83 55","51 37 63","89 29 100","83 58 11","65 13 15","47 25 29","60 66 19"} }, {253} },
	// Your custom test goes here:
	//{ { {}}, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    vector<string> p0;

    int run(RGBStreet* x) {
	return x->estimateCost(p0);
    }
    void print() { Tester::printArgs(p0); }
};
    
int main() {
    return Tester::runTests<RGBStreet>(
				       getTestCases<input, Tester::output<int>>(), disabledTest, 
				       500, 1484650150, CASE_TIME_OUT, Tester::COMPACT_REPORT
				       );
}
// CUT end
