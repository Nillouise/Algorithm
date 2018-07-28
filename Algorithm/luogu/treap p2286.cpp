#include<bits/stdc++.h>
using namespace std;
typedef long long LL;



int main(int argc, char const *argv[]) 
{
    int n;
    cin>>n;
    set<int> pet,cus;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int c,v;
        cin>>c>>v;
        if(c==0)
        {
            if(cus.size()>0){
                auto it = cus.lower_bound(v);
                if(it!=cus.begin()){
                    auto it2 = it;
                    it2--;
                    if(abs(*it2-v)<=abs(*it-v)){
                        it = it2;
                    }
                }
                cus.erase(it);
                ans += abs(*it-v);
                ans %= 1000000;
            }else{
                pet.insert(v);
            }
        }else if(c==1)
        {
            if(pet.size()>0){
                auto it = pet.lower_bound(v);
                if(it!=pet.begin()){
                    auto it2 = it;
                    it2--;
                    if(abs(*it2-v)<=abs(*it-v)){
                        it=it2;
                    }
                }
                pet.erase(it);
                ans +=abs(*it-v);
                ans %= 1000000;
            }else{
                cus.insert(v);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}