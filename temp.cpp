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

int maximalSum(vector<int> data) {
    vector<int> p, n, special;
    for (int I=0; I<data.size(); ++I) {
        int dI = data[I];
        if(dI>1) p.push_back(dI);
        else if(dI<-1) n.push_back(dI);
        else special.push_back(dI);
    }
    sort(p.begin(), p.end());
    sort(n.begin(), n.end());
    debug(n, p, special);
        
    int ret = 0;

    int i = p.size() - 1;
    while (i>0) {
        ret = ret + p[i]*p[i-1];
        i = i-2;
    }
    if (i == 0) special.push_back(p[i]);
        
    int j = n.size() - 1;
    while (j>0) {
        ret = ret + n[j]*n[j-1];
        j = j-2;
    }
    if (j == 0) special.push_back(n[j]);

    sort(special.begin(), special.end());   
        
    debug(n, p, special);
        
    int k = 1;
    while ((k < special.size()) && (special[k] < 0)) {
        ret = ret + special[k] * special[k-1];
        k = k+2;
    }
        
    if(special[k]==0) {
        ++k;
    } else {
        --k;
    }
        
    while (k<special.size()) {
        ret = ret + special[k];
        ++k;
    }
        
    return ret;
}

int main() {
    long n = 2e9;
    long ret=1;
    for(long i=n; i>0; --i)
	ret = ret*i;
    cout << ret << endl;
    
    return 0;
}
