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


int myval(string s) {
    int N = s.size();
    sort(s.begin(), s.end());
    string::iterator iter = unique(s.begin(), s.end());
    return N * (int) (iter - s.begin());
}
    
int myval(vector<string> vs) {
    int ret = 0;
    for(int i=0; i<vs.size(); ++i) {
        ret += myval(vs[i]);
    }
    return ret;
}
    

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {-1, 1, 1, -1, 2, -2, 2, -2};

bool valid(int x, int y, int N, int M) {
    if(x <= 0 || y <= 0 || x > N || y > M)
        return false;
    return true;
}

int bfs(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {

    int N = p3.first;
    int M = p3.second;
    queue<pair<pair<int, int>, int> > Que;
    map<pair<int, int>, bool> Vis;

    Que.push(make_pair(p1, 0));

    while(!Que.empty()) {

        pair<pair<int, int>, int> temp = Que.front();
        Que.pop();

        if(temp.first.first == p2.first && temp.first.second == p2.second)
            return temp.second;
        int x = temp.first.first;
        int y = temp.first.second;
        int dis = temp.second + 1;


        if(Vis.count(make_pair(x, y)))
            continue;
        Vis[make_pair(x, y)] = true;

        for(int i = 0; i < 8; ++i) {
        
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if(valid(x1, y1, N, M))
                Que.push(make_pair(make_pair(x1, y1), dis));
        }
        
    }
        
    return -1;
}
        
int solve(int N, int M, int x1, int y1, int x2, int y2) {
        
    pair<int, int> p1;
    p1.first = x1;
    p1.second = y1;
        
    pair<int, int> p2;
    p2.first = x2;
    p2.second = y2;
        
    pair<int, int> p3;
    p3.first = N;
    p3.second = M;
        
    int ans = bfs(p1, p2, p3);
    return ans;
}

    
int knight_dist(int x1, int y1, int x2, int y2, int Nr, int Nc) {
        
    queue<int> Q;
    Q.push(x1);
    Q.push(y1);
    Q.push(0);
        
    int solved[10][10];
    memset(solved, 0, sizeof(solved));
        
    while(!Q.empty()) {
	int xq = Q.front(); Q.pop();
	int yq = Q.front(); Q.pop();
	int distq = Q.front(); Q.pop();
	
	//cout << endl;   
	//debug("x1,y1,distq", xq,yq,distq);
	
	if(xq==x2 && yq==y2)
	    return distq;
	solved[xq][yq] = 1;     
    
        for(int i=0; i<8; ++i) {
	    int x3 = xq+dx[i];
	    int y3 = yq+dy[i];
	    
	    if(x3>=0 && x3<Nr && y3>=0 && y3<Nc && solved[x3][y3] == 0) {
	        //debug(x3,y3,"*******", "i=", i, "d[]", dx[i], dy[i]);
		
		Q.push(x3);
		Q.push(y3);
		Q.push(distq+1);
		//debug("x3,y3,distq_plus_one", xq,yq,distq+1);
	    }
	}
    }
    return 10000;
}

int main() {
    vector<int> dx = {1,1,2,2,-1,-1,-2,-2};
    vector<int> dy = {2,-2,1,-1,2,-2,1,-1};
    //debug(dx);
    //debug(dy);
    
    //    cout << knight_dist(0,0,9,9,10,10) << endl;
    //cout << knight_dist(0,0,0,4,1,5) << endl;
    cout << knight_dist(0,0,0,4,2,5) << endl;
    
    return 0;
}
