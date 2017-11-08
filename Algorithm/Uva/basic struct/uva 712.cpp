#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
//    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);

	int n;
	int T=0;
	while(cin>>n,n!=0)
    {
        //if(T!=0)cout<<"end"<<endl;//题目输出突然变成在所有样例后加空行
        T++;
        vector<int> order(n);
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            order[i]=s[1]-'0'-1;
        }
        string bot;//bottom
        cin>>bot;
        int qs;
        cin>>qs;
        cout<<"S-Tree #"<<T<<":"<<endl;
        for(int i=0;i<qs;i++)
        {
            string q;
            cin>>q;
            int index = 1;
            for(int i=0;i<order.size();i++)
            {
                if(q[order[i]]=='0')
                {
                    index*=2;
                }else{
                    index=index*2+1;
                }
            }
            index = index-(1<<n);
            cout<<bot[index];
        }
        cout<<endl<<endl;
    }




    return 0;
}
