//这题用了涉及到的思考技术：从后往前推，以及加入一个不影响结果但影响处理过程的变量（这点应该很重要，所有的两个孩子树都可以变成3个）。
//而且还有个问题是哈夫曼树的路径和颜色的联系。
//Let's consider the process backwards: we will store the number of balls of each color in a multiset and then "merge" some of them.
//If n is odd, then we can always pick three groups of balls with minimal sizes and replace them by one group (adding the size of this group to the penalty). Repeat until you have only one group.
//If n is even, then we need to add an auxiliary group of size 0. Then n becomes odd, so we can use the above algorithm to solve this case.
//Why does it work? This algorithm is exactly the same as the algorithm of building a Huffman code with the alphabet of size 3. And it can easily be seen that these problems are similar: by separating a group of balls into three groups, we add a new character to the codes of the colours present in that group, and our goal is to obtain a prefix code.

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    priority_queue<LL,vector<LL>,greater<LL> > pq;
    for (int i = 0; i < n; i++) 
    {
        LL a;
        cin>>a;
        pq.push(a);
    }
    if(pq.size()%2==0)pq.push(0);
    LL penal = 0;
    while(pq.size()>=3)
    {
        int a = pq.top();pq.pop();
        int b = pq.top();pq.pop();
        int c = pq.top();pq.pop();
        pq.push(a+b+c);
        penal +=a+b+c;
    }
    cout<<penal<<endl;

    return 0;
}
