#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int D[2000];
int B[2000];
vector<int> G[2000];

int dfs(int x1,x2,int y1,int y2,int p)
{

    return 0;
}

vector<int> C[1000+5];
int cen=0;

int getcen(int x)
{

}

int dfs(int pos,int p)
{
    for(int i=pos+1;i<n;)
    {
        if(getcen(D[pos])!=getcen(D[i])-1)
        {
            return i;
        }else{
            G[D[pos]].push_back(D[i]);
            i = dfs(i,D[pos]);
        }
    }
    return pos+1;
}

int main()
{
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
        cin>>B[i];
    for(int i=0;i<n;i++)
        cin>>D[i];
    C[0].push_back(B[0]);
    cen++;
    for(int i=1;i<n;i++)
    {
        if(i!=1&&B[i]<B[i-1])cen++;
        C[cen].push_back(B[i]);
    }



	return 0;
}
