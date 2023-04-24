#include <stdio.h>
#define INF 1000000

int ned[100000],d[100000],nn[100000],ind[100001],q[100000],ed[400000],u[200000],v[200000];

int main() {
  int n,m,s,t,i,j,nt,k,now,next;
  double ex,mex,y;
  scanf("%d %d %d %d", &n, &m, &s, &t);
  s--; t--;
  for(i=0;i<n;i++) {ned[i]=0; d[i]=INF; nn[i]=0; }
  for(i=0;i<m;i++) {
    scanf("%d %d", &u[i], &v[i]);
    u[i]--; v[i]--;
    ned[u[i]]++;
    ned[v[i]]++;
  }
  ind[0]=0;
  for(i=0;i<n;i++) { 
    ind[i+1]=ind[i]+ned[i];
    ned[i]=0;
  }
  for(i=0;i<m;i++) {
    ed[ind[u[i]]+ned[u[i]]++]=v[i];
    ed[ind[v[i]]+ned[v[i]]++]=u[i];
  }
  q[0]=t;
  d[t]=0;
  now=0;
  next=1;
  while(now<next) {
    k=q[now];
    nn[d[k]]++;
    for(i=0;i<ned[k];i++) {
      j=ed[ind[k]+i];
      if(d[j]==INF) {
	d[j]=d[k]+1;
	q[next++]=j;
      }
    }
    now++;
  }
  y=n;
  nt=0;
  mex=d[s];
  for(k=0;nn[k]!=0;k++) {
    y+=nn[k]*k;
    nt+=nn[k];
    ex=y/(double)nt;
    if(ex<mex) mex=ex;
  }
  printf("%.6f\n", mex);
}
    
