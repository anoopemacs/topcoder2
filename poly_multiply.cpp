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

void myprint(vector<int> v) {
    //print algebraic expression
    for(int i=v.size()-1; i>=1; --i) {
	cout << v[i] << " x^" << i << " + ";
    }
    cout << v[0] << endl;
}

void myprint(vector<int> v1, vector<int> v2, vector<int> ans) {
    myprint(v1);
    cout << " multiply " << endl;
    myprint(v2);
    cout << " equals " << endl;
    myprint(ans);
    cout << "___________________________________________________________________________________________________" << endl;    
}

vector<int> f2(vector<int> v1, vector<int> v2) {
    vector<int> ret;
    //ax+b * cx+d
    int b=v1[0], a=v1[1], d=v2[0], c=v2[1];
    ret.push_back(b*d);    
    ret.push_back(a*d+b*c);
    ret.push_back(a*c);
    return ret;
}

vector<int> mysum(vector<int> v1, vector<int> v2, vector<int> v3, vector<int> v4) {
    int max1 = max((int)v1.size(), (int)v2.size());
    int max2 = max((int)v3.size(), (int)v4.size());
    int N = max(max1, max2);

    vector<int> ret(N, 0);
    for(int i=0; i<N; ++i) {
	if(i<v1.size()) ret[i] += v1[i];
	if(i<v2.size()) ret[i] += v2[i];
	if(i<v3.size()) ret[i] += v3[i];
	if(i<v4.size()) ret[i] += v4[i];
    }
    return ret; 
}

vector<int> f(vector<int> v1, vector<int> v2, int shift=0) {
    vector<int> before_shift = vector<int>((int) v1.size() + v2.size() - 1 , 0);
	
    if(v1.size() == 1) {
        for(int i=0; i<before_shift.size(); ++i) {
            before_shift[i] = v2[i] * v1[0];
        }
    } else if(v2.size() == 1) {
        for(int i=0; i<before_shift.size(); ++i) {
            before_shift[i] = v1[i] * v2[0];
        }
    } else if(v1.size()==2 && v2.size()==2) {
	before_shift = f2(v1,v2);
    } else {

	vector<int> a = vector<int>(v1.begin()+1, v1.end());
	vector<int> b = vector<int>(v1.begin(), v1.begin()+1);
	vector<int> c = vector<int>(v2.begin()+1, v2.end());
	vector<int> d = vector<int>(v2.begin(), v2.begin()+1);

	vector<int> m1 = f(a, c, 2);    
	vector<int> m2 = f(a, d, 1);    
	vector<int> m3 = f(b, c, 1);
	vector<int> m4 = f(b, d, 0);    
	
	//	myprint(a,c,m1);
	
	before_shift = mysum(m1,m2,m3,m4);
    }

    vector<int> ret;
    for(int i=0; i<shift; ++i) ret.push_back(0);
    for(int i=0; i<before_shift.size(); ++i) ret.push_back(before_shift[i]);
    
    return ret;
    
}

int main() {
    //v[i] is coefficient of x^i
    vector<int> v1 = {7,35,0,0,0,7,0,0,9};
    vector<int> v2 = {7,3,4,0,0,31,0,3,0,0,7};
    myprint(v1, v2, f(v1,v2));
    
    return 0;
}
