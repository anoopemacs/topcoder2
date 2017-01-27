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

vector<vector<string>> sus;

class PositiveID {
    vector<string> mysplit(string s) {
	vector<string> ret;
	int i=0;
	while(i<s.size()) {
	    int j=s.find(',', i);
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
    
    vector<string> remove_duplicates(vector<string> v) {
	vector<string> ret;
	for(int i=0; i<v.size(); ++i) {
	    string vi=v[i];
	    if(find(ret.begin(), ret.end(), vi) == ret.end())
		ret.push_back(vi);
	}
	return ret;
    }
    
    int mylcs(vector<string> a, vector<string> b) {
	vector<string> allprops=a;
	copy(b.begin(), b.end(), back_inserter(a));
	allprops = remove_duplicates(allprops);
	int ret=0;
	for(int i=0; i<allprops.size(); ++i) {
	    vector<string>::iterator ia, ib;
	    ia=find(a.begin(), a.end(), allprops[i]);
	    ib=find(b.begin(), b.end(), allprops[i]);
	    if(ia!=a.end() && ib!=b.end()) ++ret;
	}
	return ret;
    }
    
public:
    int maximumFacts(vector<string> suspects) {
	int N=suspects.size();
	if(N==1) return 0;
	for(int i=0; i<N; ++i)
	    sus.push_back(mysplit(suspects[i]));
	
	int ret=0;
	//debug(sus);
	for(int i=0; i<N; ++i) {
	    vector<string> a=sus[i];
	    for(int j=i+1; j<N; ++j) {
		vector<string> b=sus[j];
		ret=max(ret, mylcs(a,b));
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
	{ { {"blond,tall,skinny","short,skinny,blond,tattooed","scarred,bald"} }, {2} },
	{ { {"gigantic,fluorescent,loud,male"} }, {0} },
	{ { {"medium,average,nondescript","medium,average,nondescript"} }, {3} },
	{ { {"big,tall,loud,happy,male,scarred,tattooed,dirty","short,male,beard,quiet,happy,tanned,handsome","female,pretty,blond,quiet","somnambulistic","happy,tiny,stout,male,tanned,beard,blond"} }, {4} },
	{ { {"aa,ab,ac,ad,ae,af,ag,ah,ai,aj,ak,al,am,an,ao,ap,aq", "ba,bb,bc,bd,be,bf,bg,bh,bi,bj,bk,bl,bm,bn,bo,bp,bq", "ca,cb,cc,cd,ce,cf,cg,ch,ci,cj,ck,cl,cm,cn,co,cp,cq", "da,db,dc,dd,de,df,dg,dh,di,dj,dk,dl,dm,dn,do,dp,dq", "ea,eb,ec,ed,ee,ef,eg,eh,ei,ej,ek,el,em,en,eo,ep,eq", "fa,fb,fc,fd,fe,ff,fg,fh,fi,fj,fk,fl,fm,fn,fo,fp,fq", "ga,gb,gc,gd,ge,gf,gg,gh,gi,gj,gk,gl,gm,gn,go,gp,gq", "ha,hb,hc,hd,he,hf,hg,hh,hi,hj,hk,hl,hm,hn,ho,hp,hq", "ia,ib,ic,id,ie,if,ig,ih,ii,ij,ik,il,im,in,io,ip,iq", "ja,jb,jc,jd,je,jf,jg,jh,ji,jj,jk,jl,jm,jn,jo,jp,jq", "ka,kb,kc,kd,ke,kf,kg,kh,ki,kj,kk,kl,km,kn,ko,kp,kq", "la,lb,lc,ld,le,lf,lg,lh,li,lj,lk,ll,lm,ln,lo,lp,lq", "ma,mb,mc,md,me,mf,mg,mh,mi,mj,mk,ml,mm,mn,mo,mp,mq", "na,nb,nc,nd,ne,nf,ng,nh,ni,nj,nk,nl,nm,nn,no,np,nq", "oa,ob,oc,od,oe,of,og,oh,oi,oj,ok,ol,om,on,oo,op,oq", "pa,pb,pc,pd,pe,pf,pg,ph,pi,pj,pk,pl,pm,pn,po,pp,pq", "qa,qb,qc,qd,qe,qf,qg,qh,qi,qj,qk,ql,qm,qn,qo,qp,qq", "ra,rb,rc,rd,re,rf,rg,rh,ri,rj,rk,rl,rm,rn,ro,rp,rq", "sa,sb,sc,sd,se,sf,sg,sh,si,sj,sk,sl,sm,sn,so,sp,sq", "ta,tb,tc,td,te,tf,tg,th,ti,tj,tk,tl,tm,tn,to,tp,tq", "ua,ub,uc,ud,ue,uf,ug,uh,ui,uj,uk,ul,um,un,uo,up,uq", "va,vb,vc,vd,ve,vf,vg,vh,vi,vj,vk,vl,vm,vn,vo,vp,vq", "wa,wb,wc,wd,we,wf,wg,wh,wi,wj,wk,wl,wm,wn,wo,wp,wq", "xa,xb,xc,xd,xe,xf,xg,xh,xi,xj,xk,xl,xm,xn,xo,xp,xq", "ya,yb,yc,yd,ye,yf,yg,yh,yi,yj,yk,yl,ym,yn,yo,yp,yq", "za,zb,zc,zd,ze,zf,zg,zh,zi,zj,zk,zl,zm,zn,zo,zp,zq"} }, {0} },
	// Your custom test goes here:
	//{ { {}}, {} },
    };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
    vector<string> p0;

    int run(PositiveID* x) {
	return x->maximumFacts(p0);
    }
    void print() { Tester::printArgs(p0); }
};
    
int main() {
    return Tester::runTests<PositiveID>(
					getTestCases<input, Tester::output<int>>(), disabledTest, 
					500, 1484652851, CASE_TIME_OUT, Tester::COMPACT_REPORT
					);
}
// CUT end
