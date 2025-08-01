#include<bits/stdc++.h>
using namespace std;
typedef long long gh;
gh n,m;
gh a[10000000];
map<gh,gh>dem;
gh b[10000000];
int main()
{
    cin>>n>>m;
    for(gh i=1;i<=n;i++)
    {
        cin>>a[i];
        dem[__gcd(a[i],m)]++;
    }
    // cout<<"\n";
    gh tong=0,o=0;
    for(gh i=1;i*i<=m;i++)
    {
        if(m%i==0)
        {
            b[++o]=i;
            if(i*i!=m)
                b[++o]=m/i;
        }
    }
    // for(gh i=1;i<=o;i++)
    //     cout<<b[i]<<" ";
    for(gh i=1;i<=o;i++)
    {
        for(gh j=i;j<=o;j++)
        {
            if(((b[i]%m)*(b[j]%m))%m==0)
            {
                if(i==j)
                    tong+=dem[b[i]]*(dem[b[i]]+1)/2;
                else
                    tong+=dem[b[i]]*dem[b[j]];
            }
        }
    }
    cout<<tong;
}
