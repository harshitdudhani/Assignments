#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    long long n;
    cin>>n;
    long long a[n];
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long b[n];
    for(long long i=0;i<n;i++)
    {
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    for(long long i=1;i<n-1;i++)
    {
        long long q=a[i-1]+b[i-1];
        long long r=a[i]+b[i];
        if(q==r)
        {
            long long temp = b[i];
            b[i]=b[i+1];
            b[i+1]=temp;
        }
    }
    long long c[n];
    for(long long i=0;i<n;i++)
    {
        c[i]=a[i]+b[i];   
    }
    set<long long> distinctElements;
    for (long long i = 0; i < n; ++i) {
        distinctElements.insert(c[i]);
        
    }
    if(distinctElements.size()>=3)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
int main()
{
    long long t; cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}