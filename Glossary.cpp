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

string myupper(string s) {
    int N = s.size();
    string ret;
    for(int i=0; i<N; ++i) {
        ret = ret + (char)toupper(s[i]);
    }
    return ret;
}

bool mycompare(string s1, string s2) {
    return myupper(s1) < myupper(s2);
}

class Glossary {
public:
    vector<string> buildGlossary(vector<string> items) {
	int N = items.size();
	
	map<char, vector<string>> dic;
	
	for(char c='A'; c<='Z'; ++c) {
	    vector<string> vs;
	    for(int i=0; i<N; ++i) {
		if((char)toupper(items[i][0]) == c) {
		    vs.push_back(items[i]);
		}
	    }
	    if(vs.size()>=1) dic[c] = vs;
	}

	string availables;
	for(map<char, vector<string>>::iterator iter=dic.begin(); iter!=dic.end(); ++iter) {
	    char c = iter->first;
	    availables += c;
	    sort((iter->second).begin(), (iter->second).end(), mycompare);
	}
	//debug(dic);
	//debug(availables);
	sort(availables.begin(), availables.end());
	//debug(availables);

	int first_col_length=0, second_col_length=0;
	for(int i=0; i<availables.size(); ++i) {
	    char c = availables[i];
	    if(c <= 'M') {
		first_col_length += 2;
		first_col_length += dic[c].size();
	    }
	    else {
		second_col_length += 2;
		second_col_length += dic[c].size();
	    }
	}
	debug(first_col_length, second_col_length);
	
	vector<string> ret;
	
	for(int k=0; k<availables.size(); ++k) {
	    char c = availables[k];
	    if(c>'M') break;
	    
	    ret.push_back(c+string(18, ' ')+string(2, ' '));
	    ret.push_back(string(19, '-') + string(2, ' '));
	    
	    vector<string> vsm = dic[c];

	    for(int i=0; i<vsm.size(); ++i) {
		string si = vsm[i];
		string topush = string(2, ' ');
		topush = topush + si;
		topush = topush + string(21 - topush.size(), ' ');
		
		ret.push_back(topush);
	    }
	    
	}

	ret.resize(max(first_col_length, second_col_length));
	
	for(int i=0; i<ret.size(); ++i) {
	    while(ret[i].size()<21)
		ret[i]+=' ';
	}
	
	int I=0;
	while(availables[I]<='M') ++I;

        for(int i=I, m=0; i<availables.size(); ++i) {
	    char c = availables[i];
	    
            ret[m] = ret[m] +  c + string(18, ' ');
	    ++m;
	    
	    ret[m] = ret[m] +  string(19, '-');
            ++m;
            
	    vector<string> vsm = dic[c];
            
	    for(int k=0; k<vsm.size(); ++k, ++m) {
		string sk = vsm[k];
		ret[m] = ret[m] + string(2, ' ') + sk + string(17- sk.size(), ' ');
	    }
        }

	for(int i=0; i<ret.size(); ++i) {
	    while(ret[i].size()<40)
                ret[i]+=' ';
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
	{ { {"Canada","France","Germany","Italy","Japan","Russia","United Kingdom","United States"} }, { {"C                    R                  ","-------------------  -------------------","  Canada               Russia           ","F                    U                  ","-------------------  -------------------","  France               United Kingdom   ","G                      United States    ","-------------------                     ","  Germany                               ","I                                       ","-------------------                     ","  Italy                                 ","J                                       ","-------------------                     ","  Japan                                 "} } },
	{ { {"alpha","beta","gamma","delta","omega"} }, { {"A                    O                  ","-------------------  -------------------","  alpha                omega            ","B                                       ","-------------------                     ","  beta                                  ","D                                       ","-------------------                     ","  delta                                 ","G                                       ","-------------------                     ","  gamma                                 "} } },
	{ { {"AVL tree","backtracking","array","balanced tree","binary search"} }, { {"A                                       ","-------------------                     ","  array                                 ","  AVL tree                              ","B                                       ","-------------------                     ","  backtracking                          ","  balanced tree                         ","  binary search                         "} } },
	{ { {"XXXXXXXXXXXXXXXXX","YYYYYYYYYYYYYYYYY","ZZZZZZZZZZZZZZZZZ"} }, { {"                     X                  ","                     -------------------","                       XXXXXXXXXXXXXXXXX","                     Y                  ","                     -------------------","                       YYYYYYYYYYYYYYYYY","                     Z                  ","                     -------------------","                       ZZZZZZZZZZZZZZZZZ"} } },
	{ { {"Asteria","Astraeus","Atlas","Clymene","Coeus","Crius","Cronus","Dione","Epimetheus","Helios","Hyperion","Iapetus","Leto","Mnemosyne","Oceanus","Ophion","Phoebe","Prometheus","Rhea","Tethys","Theia","Themis"} }, { {"A                    O                  ","-------------------  -------------------","  Asteria              Oceanus          ","  Astraeus             Ophion           ","  Atlas              P                  ","C                    -------------------","-------------------    Phoebe           ","  Clymene              Prometheus       ","  Coeus              R                  ","  Crius              -------------------","  Cronus               Rhea             ","D                    T                  ","-------------------  -------------------","  Dione                Tethys           ","E                      Theia            ","-------------------    Themis           ","  Epimetheus                            ","H                                       ","-------------------                     ","  Helios                                ","  Hyperion                              ","I                                       ","-------------------                     ","  Iapetus                               ","L                                       ","-------------------                     ","  Leto                                  ","M                                       ","-------------------                     ","  Mnemosyne                             "} } },
	{ {{"Cancan", "Altos", "ComFortless", "busied", "battlegrounds", "crumbs", "Acreages", "AirworthIness", "Anoraks", "calligraphy", "Carburetor", "beauty", "Airlines", "animatedly", "buskers", "Confessing", "Barricades", "anklets", "Compartmentalize", "bitty", "camisole", "accomplish", "connoted", "avalanches", "bricklayer", "brogue", "Clairvoyant", "bunkhouSe", "comprehends", "belch", "blockade", "consortia", "Bridegrooms", "beat", "conduits", "cuckoLded", "Cloudiest", "amend", "craggy", "compressing", "amBush", "Assemblywoman", "Appraising", "Austere", "Credulousness", "coppers", "bloating", "chatterBox", "Brawled", "appoiNtees"}},
	  {{"A                                       ", "-------------------                     ", "  accomplish                            ", "  Acreages                              ", "  Airlines                              ", "  AirworthIness                         ", "  Altos                                 ", "  amBush                                ", "  amend                                 ", "  animatedly                            ", "  anklets                               ", "  Anoraks                               ", "  appoiNtees                            ", "  Appraising                            ", "  Assemblywoman                         ", "  Austere                               ", "  avalanches                            ", "B                                       ", "-------------------                     ", "  Barricades                            ", "  battlegrounds                         ", "  beat                                  ", "  beauty                                ", "  belch                                 ", "  bitty                                 ", "  bloating                              ", "  blockade                              ", "  Brawled                               ", "  bricklayer                            ", "  Bridegrooms                           ", "  brogue                                ", "  bunkhouSe                             ", "  busied                                ", "  buskers                               ", "C                                       ", "-------------------                     ", "  calligraphy                           ", "  camisole                              ", "  Cancan                                ", "  Carburetor                            ", "  chatterBox                            ", "  Clairvoyant                           ", "  Cloudiest                             ", "  ComFortless                           ", "  Compartmentalize                      ", "  comprehends                           ", "  compressing                           ", "  conduits                              ", "  Confessing                            ", "  connoted                              ", "  consortia                             ", "  coppers                               ", "  craggy                                ", "  Credulousness                         ", "  crumbs                                ", "  cuckoLded                             "}} }, 
	// Your custom test goes here:
	//{ { {}}, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    vector<string> p0;

    vector<string> run(Glossary* x) {
	return x->buildGlossary(p0);
    }
    void print() { Tester::printArgs(p0); }
};
    
int main() {
    return Tester::runTests<Glossary>(
				      getTestCases<input, Tester::output<vector<string>>>(), disabledTest, 
				      500, 1486029183, CASE_TIME_OUT, Tester::COMPACT_REPORT
				      );
}
// CUT end
