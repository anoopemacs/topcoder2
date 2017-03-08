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

class InstantRunoffVoting {
 public:
    int winner(vector<string> voters) {
	int ret = -1;
	int Nr = voters.size();
	int Nc = voters[0].length();
	
	vector<int> notEliminated(Nc, 1);

	for(int round=0; round<Nc; ++round) {
	    vector<int> votes(Nc, 0);
	    for(int r=0; r<Nr; ++r) {
		for(int c=0; c<Nc; ++c) {
		    if(notEliminated[(int) (voters[r][c] - '0')] == 1) {
			votes[(int) (voters[r][c] - '0')]++;
			break;
		    }
		}
	    }

	    int maxVotes = INT_MIN;
	    int minVotes = INT_MAX;
	    for(int i=0; i<votes.size(); ++i) {
		if(votes[i]<minVotes && notEliminated[i]==1) minVotes = votes[i];
		if(votes[i]>maxVotes && notEliminated[i]==1) maxVotes = votes[i];
	    }

	    //winner check:
	    if(maxVotes >= (int) (accumulate(votes.begin(), votes.end(), 0))/2+1) {
		vector<int> maxVoteIndices;
		for(int i=0; i<votes.size(); ++i) {
		    if(votes[i]==maxVotes) {
			maxVoteIndices.push_back(i);
		    }
		}
		debug("maxVoteIndices", maxVoteIndices);
		if(maxVoteIndices.size() == 1) return maxVoteIndices[0];
	    }

	    debug("minVotes:", minVotes);
	    //elimination:
	    for(int i=0; i<votes.size(); ++i) {
		if(votes[i]==minVotes) {
		    notEliminated[i] = 0;
		}
	    }

	    if(count(notEliminated.begin(), notEliminated.end(), 1) == 1)
		return (int)(find(notEliminated.begin(), notEliminated.end(), 1) - notEliminated.begin());

	    debug(votes, notEliminated);
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
    { { {"01","10","01","01","10"} }, {0} },
    { { {"120","102","210","021","012"} }, {1} },
    { { {"10","01"} }, {-1} },
    { { {"3120","3012","1032","3120","2031","2103","1230","1230"} }, {-1} },
    { { {"24103","30412","32014","21043","30412","32401","14203","04123","30241","02413","13042","01432","01342","32401","24301","12430","41023","02413","42310","12043"} }, {1} },
    { { {"0649853172","2146875039","2671548309","5897216403","4719823056","7945213860","9021538647","9286145307","9176403528","3709486152"} }, {9} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;

        int run(InstantRunoffVoting* x) {
            return x->winner(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<InstantRunoffVoting>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1488797132, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
