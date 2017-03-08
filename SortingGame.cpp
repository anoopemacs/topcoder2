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

class SortingGame {
    string myswap(string s, int start, int k) {
	if(start+k > s.length() || start < 0) {
	    cout << "length out of bounds0";
	    return "error0";
	}
	string prefix = string(s.begin(), s.begin() + start);
	string middle = string(s.begin()+start, s.begin()+start+k);
	string suffix = string(s.begin()+start+k, s.end());
	////	debug(prefix, middle, suffix);
	reverse(middle.begin(), middle.end());
	
	return prefix+middle+suffix;
    }
    
    int aux(string b, int k) {
	string bs = b; sort(bs.begin(), bs.end()); // bs = b sorted
	//debug(b);
	queue<string> Q;
	queue<int> countq;
	Q.push(b);
	countq.push(0);

	set<string> doneset;

	while(!Q.empty()) {
	    int freq = countq.front(); countq.pop();
	    string s = Q.front(); Q.pop();
	    if(s==bs) {
		return freq;
	    }
	    doneset.insert(s);
            //debug(s, freq);
	    
	    for(int start=0; start+k<=b.length(); ++start) {
		string b1 = myswap(s, start, k);
		if(doneset.count(b1)==0) {
		    Q.push(b1);
		    countq.push(freq+1);
	            doneset.insert(b1);              
		}
	    }
	}
	
	//never reached:
	return -1;
    }
public:
    
    int fewestMoves(vector<int> board, int k) {
	string b = "";
	for(int i=0; i<board.size(); ++i) b = b + (char)(board[i] + '0');
	//debug(b);

	return aux(b,k);
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
    { { {1,2,3}, 3 }, {0} },
    { { {3,2,1}, 3 }, {1} },
    { { {5,4,3,2,1}, 2 }, {10} },
    { { {3,2,4,1,5}, 4 }, {-1} },
    { { {7,2,1,6,8,4,3,5}, 4 }, {7} },
    { {{8, 7, 6, 5, 4, 3, 2, 1}, 2}, {28}},
    // Your custom test goes here:
    //{ { {}, }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;int p1;

        int run(SortingGame* x) {
            return x->fewestMoves(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<SortingGame>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1488951821, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
