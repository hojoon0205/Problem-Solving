#include <bits/stdc++.h>

using namespace std;


#define seti pair<int,int>
#define ci(t) cin>>t
#define co(t) cout<<t
#define fa(i,a,b) for(int i=a;i<b;++i)
#define LL long long
#define setl pair<LL,LL>

const int max_v=(1<<20) + 7;

template <typename U ,typename T> void ckmax(U &a,T b){if(a<b) a=b;};
template <typename U ,typename T> void ckmin(U &a,T b){if(a>b) a=b;};

int dead[max_v];
int win[max_v];
int cnt[max_v];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; ci(n);

    vector<seti> ve((1<<n)-2);
    vector<int> vi(1<<n); iota(vi.begin(),vi.end(),1);
    for(auto & x : ve) ci(x.first >> x.second);

    for(auto & x : ve) ++win[x.first],++cnt[x.first],++cnt[x.second];

    for(int dep = 1<<n;;dep>>=1)
    {
        if(ve.size() == 0)
        {            
            vector<seti> ans;
            assert(vi.size() ==2);
            ans.push_back({vi[0],vi[1]}); ans.push_back({vi[1],vi[0]}); sort(ans.begin(),ans.end());

            for(auto & x : ans) co(x.first <<" "<< x.second<<"\n");
            exit(0);
        }

        int nop = -1;                
        vector<int> nvi;
        vector<int> vz;

        for(auto & x : vi) 
        {
            if(win[x] == 0) 
            {
                if(cnt[x]==1) vz.push_back(x);
                else if(cnt[x] == 0) nop=x;                
            }
            else
            {
                nvi.push_back(x);
            }
        }
             
        if(~nop)
        {            
            vector<seti> ans;

            if((int)vz.size() *2 == dep)
            {
                for(auto & x :vz) dead[x] = 1;

                vector<int> tmp((1<<n)+1,0);

                for(auto & x : ve)
                {
                    if(dead[x.second])
                    {
                        if(tmp[x.first])
                        {
                            ans.push_back({x.second,nop}); ans.push_back({tmp[x.first],nop});
                            
                            sort(ans.begin(),ans.end());
                            for(auto & x : ans) co(x.first <<" "<< x.second<<"\n");
                            
                            exit(0);

                        }
                        tmp[x.first] = x.second;
                    }
                }

            }
            else
            {
                vector<int> tmp((1<<n)+1,0);
                for(auto & x : vz) dead[x] = 1,tmp[x]=1;
                tmp[nop]=1;

                for(auto & x : ve)
                {
                    if(dead[x.second])
                    {
                        tmp[x.first] = 1;
                    }
                }

                int wop = -1;

                for(auto & x : vi) if(tmp[x]==0)
                {
                    wop = x;
                }

                ans.push_back({wop,nop});
            }
            
            sort(ans.begin(),ans.end());
            for(auto & x : ans) co(x.first <<" "<< x.second<<"\n");
            exit(0);            
        }
        else
        {
            for(auto & x : vz) dead[x] = 1;
            
            vector<seti> nve;

            for(auto x : ve)
            {
                
                if(dead[x.second])
                {                    
                    --cnt[x.first],--cnt[x.second];
                    --win[x.first];
                }
                else
                {
                    nve.push_back(x);
                }
            }
            
            ve= nve;
        }

        vi = nvi;
    }
    return 0;





}