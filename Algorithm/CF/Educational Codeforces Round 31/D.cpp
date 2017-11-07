//这题用了涉及到的思考技术：从后往前推，以及加入一个不影响结果但影响处理过程的变量（这点应该很重要，所有的两个孩子树都可以变成3个）。
//而且还有个问题是哈夫曼树的路径和颜色的联系。
//Let's consider the process backwards: we will store the number of balls of each color in a multiset and then "merge" some of them.
//If n is odd, then we can always pick three groups of balls with minimal sizes and replace them by one group (adding the size of this group to the penalty). Repeat until you have only one group.
//If n is even, then we need to add an auxiliary group of size 0. Then n becomes odd, so we can use the above algorithm to solve this case.
//Why does it work? This algorithm is exactly the same as the algorithm of building a Huffman code with the alphabet of size 3. And it can easily be seen that these problems are similar: by separating a group of balls into three groups, we add a new character to the codes of the colours present in that group, and our goal is to obtain a prefix code.
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
vector<int> vec;




int main()
{
    freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);

    cin>>n;
    vec.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    if(n%2==0)
    {
        vec.push_back(0);
    }

        //这里保存的是中间结果，中间结果也是会溢出的
    //priority_queue<int,vector<int>,greater<int> > Q;//greater就是从小到大排把
    priority_queue<LL,vector<LL>,greater<LL> >Q;
    for(auto a:vec)
    {
        Q.push(a);
    }
    LL penal=0;
    while(Q.size()>=3)
    {
        //这里保存的是中间结果，中间结果也是会溢出的
        LL a=Q.top();Q.pop();
        LL b=Q.top();Q.pop();
        LL c=Q.top();Q.pop();
//        penal+=1LL+a+b+c;//这里会溢出//卧槽居然写成这个屌样
        penal+=1LL*a+1LL*b+1LL*c;
        Q.push(1LL*a+1LL*b+1LL*c);
    }
    cout<<penal<<endl;
    return 0;
}
