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

map<string, int> t2s_global, p_global;

class Paintball {
public:
    vector<string> mysplit(string s, char c = ' ') {
        vector<string> ret;
        int i=0;
        while(i<s.size()) {
            int j=s.find(c, i);
            if(j==-1) {
                ret.push_back(s.substr(i));
                break;
            } else {
                ret.push_back(s.substr(i, j-i));
            }
            i=j+1;
        }
        //    sort(s.begin(), s.end());
        return ret;
    }
    
    static bool mysort(string s1, string s2) {
	return t2s_global[s1] > t2s_global[s2];
    }
    
    string myits(int i) {
        stringstream ss;
        ss<<i;
        string ret;
        ss>>ret;
        return ret;
    }
    
    static bool mysort2(string p1, string p2) {
	return p_global[p1] > p_global[p2];
    }
    
    vector<string> getLeaderboard(vector<string> players, vector<string> messages) {
	map<string, vector<string>> t;
	map<string, int> p;
	map<string, string> p2t; //p2t[player] = histeam
	vector<string> allteams;
	for(int i=0; i<players.size(); ++i) {
	    vector<string> ith = mysplit(players[i]);
	    allteams.push_back(ith[1]);
	}
	sort(allteams.begin(), allteams.end());
	
	vector<string>::iterator iter = unique(allteams.begin(), allteams.end());
	
	for(vector<string>::iterator i=allteams.begin(); i<iter; ++i) {
	    string teamName = *i;
	    vector<string> teamMembers;
	    for(int j=0; j<players.size(); ++j) {
	        vector<string> jth = mysplit(players[j]);
		if(jth[1] == teamName) {
		    teamMembers.push_back(jth[0]);
		}
            }
	    sort(teamMembers.begin(), teamMembers.end());
	    t[teamName] = teamMembers;
	}
	///////////////
	vector<string> allplayers;
	for(int i=0; i<players.size(); ++i) {
            vector<string> ith = mysplit(players[i]);
            allplayers.push_back(ith[0]);
	    p2t[ith[0]] = ith[1];
        }
	for(int i=0; i<allplayers.size(); ++i) {
	    p[allplayers[i]] = 0;
	}

	map<string, int> t2s;//team2score
	for(vector<string>::iterator i=allteams.begin(); i<iter; ++i) {
	    string teamName = *i;
	    t2s[teamName] = 0;
	}
	
	for(int i=0; i<messages.size(); ++i) {
	    vector<string> vsm = mysplit(messages[i]);
	    string team1 = p2t[vsm[0]];
	    string team2 = p2t[vsm[2]];
	    
	    if(vsm[0]==vsm[2]) {//self
		--p[vsm[0]];
		--t2s[team1];
	    } else if (p2t[vsm[0]] == p2t[vsm[2]]) {//same team
		--p[vsm[0]];
		--t2s[team1];
	    } else { // diff teams
		--p[vsm[2]];
		++p[vsm[0]];
		--t2s[team2];
		++t2s[team1];
	    }
	}
	debug(p);
	p_global = p;
	debug(t2s);
	t2s_global = t2s;
	stable_sort(allteams.begin(), iter, mysort);

	vector<string> allt = vector<string>(allteams.begin(), iter);
	vector<string> ret;

	for(int i=0; i<allt.size(); ++i) {
	    string tname = allt[i];
	    string tscore = myits(t2s[tname]);
	    ret.push_back(tname + " " + tscore);
	    vector<string> members = t[tname];
	    stable_sort(members.begin(), members.end(), mysort2);
	    
	    for(int j=0; j<members.size(); ++j) {
		string pname = members[j];
		string pscore = myits(p[pname]);
		ret.push_back("  " + pname + " " + pscore);
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
    { { {"A RED","B BLUE"}, {"A SPLATTERED B"} }, { {"RED 1","  A 1","BLUE -1","  B -1"} } },
    { { {"LISA RED","BART RED","HOMER BLUE","MARGE BLUE","MAGGIE GREEN"}, {"MAGGIE SPLATTERED HOMER","MAGGIE SPLATTERED MARGE"} }, { {"GREEN 2","  MAGGIE 2","RED 0","  BART 0","  LISA 0","BLUE -2","  HOMER -1","  MARGE -1"} } },
    { { {"TODD STRIKEFORCE","BART OMEGA","DATA STRIKEFORCE","MILHOUSE OMEGA","NELSON DISCOVERYCHANNEL","MARTIN DISCOVERYCHANNEL"}, {"BART SPLATTERED MARTIN","TODD SPLATTERED MARTIN"} }, { {"OMEGA 1","  BART 1","  MILHOUSE 0","STRIKEFORCE 1","  TODD 1","  DATA 0","DISCOVERYCHANNEL -2","  NELSON 0","  MARTIN -2"} } },
    { { {"DR COHO","ST COHO","PE COHO"}, {"DR SPLATTERED ST","ST SPLATTERED PE"} }, { {"COHO -2","  PE 0","  DR -1","  ST -1"} } },
    { { {"A B","AA AA","AAA AAA"}, {"A SPLATTERED AAA","A SPLATTERED AAA","A SPLATTERED AAA","AA SPLATTERED AAA","AA SPLATTERED AAA"} }, { {"B 3","  A 3","AA 2","  AA 2","AAA -5","  AAA -5"} } },
    // Your custom test goes here:
    //{ { {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;vector<string> p1;

        vector<string> run(Paintball* x) {
            return x->getLeaderboard(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<Paintball>(
            getTestCases<input, Tester::output<vector<string>>>(), disabledTest, 
            600, 1486905058, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
