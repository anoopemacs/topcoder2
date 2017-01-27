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

string myits(int i) {
    stringstream ss;
    ss<<i;
    string ret;
    ss>>ret;
    return ret;
}

int mysti(string s) {
    stringstream ss;
    ss<<s;
    int ret;
    ss>>ret;
    return ret;
}

vector<string> mysplit(string s, char c) {
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
    sort(s.begin(), s.end());
    return ret;
}

int main() {
    bitset<32> bset1;
    cout << bset1 << endl;
    return 0;
}
