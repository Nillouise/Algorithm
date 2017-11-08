#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
map<string,int> s2id;
vector<string> id2s;
vector<int> depend[10000];//我依赖什么
vector<int> depend2[10000];//哪些依赖于我
int status[10000];
vector<int> installed;
int ID(const string& s)
{
    if(s2id.count(s)>0)
    {
        return s2id[s];
    }
    s2id[s]=id2s.size();
    id2s.push_back(s);
    return s2id[s];
}

int install(int id,int toplevel)
{
    if(status[id]==0)
    {
        for(auto a:depend[id])
        {
            install(a,0);
        }
//        if(toplevel)
//        {
//            status[id]=1;
//        }else{
//            status[id]=2;
//        }//这里用？：代替
        cout << "   Installing " << id2s[id] << endl;
        status[id]=toplevel?1:2;
        installed.push_back(id);
    }else if(status[id]==2&&toplevel)
    {
        //status[id]=1;//书上没有这个操作//去掉这个操作也不能ac//这句加不加都能ac
    }else
    {
    }
    return 0;
}

int remove(int id,int toplevel)
{
    //居然是这句错了，为啥呀？难不成status[id]还能为0？//测试结果确实能为0。。
    //if(toplevel==0&&status[id]==1)return 0;
    if(toplevel||status[id]==2)
    {
        for(auto a:depend2[id])
        {
            if(status[a]!=0)
                return 0;
        }

        //installed.erase(id);//这是错的，erase接收的是迭代器iterator
        //remove会把符合条件的所有元素都移动到队尾，并返回指向这个队尾的指针。
        installed.erase(remove(installed.begin(),installed.end(),id),installed.end());
        //仔细体会这句语句吧。
        cout << "   Removing " << id2s[id] << endl;
        status[id]=0;
        for(auto a:depend[id])
        {
            remove(a,0);
        }
    }
    return 1;
}


int main()
{
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);

	string s;
	while(getline(cin,s))
    {
        cout<<s<<endl;
        stringstream ss(s);//感觉这个stringstream本身就有点奇怪bug，好像ss<<s中s有空格的话会导致输不进去。
        string cmd;
        ss>>cmd;
        if(cmd=="DEPEND")
        {
            string it1,it2;
            ss>>it1;
            while(ss>>it2)
            {
                depend[ID(it1)].push_back(ID(it2));
   //             depend[ID(it2)].push_back(ID(it1));//一开始就想到是输入这里写错了，可以居然也没有一眼发现
                depend2[ID(it2)].push_back(ID(it1));
            }
        }else if(cmd=="INSTALL")
        {
            //
//            for(int i=0;i<4;i++)
//            {
//                for(auto a:depend[i])cout<<a<<" ";
//                cout<<endl;
//            }

            string it;
            ss>>it;
            if(status[ID(it)])
                cout<<"   "<<it<<" is already installed.\n";
            else
                install(ID(it),1);
        }else if(cmd=="REMOVE")
        {
            string it;
            ss>>it;
            if(status[ID(it)]==0)
            {
                cout<<"   "<<it<<" is not installed.\n";
                continue;
            }
            int flag=0;
            for(auto a:depend2[ID(it)])
            {
                if(status[a]){flag=1;break;}
            }
            if(flag)
            {
                cout<<"   "<<it<<" is still needed.\n";
            }else
            {
                remove(ID(it),1);
            }

        }else if(cmd=="LIST")
        {
            for(auto a:installed)
            {
                cout<<"   "<<id2s[a]<<endl;
            }
        }else if(cmd=="END")
        {
            break;
        }
    }
    return 0;
}
