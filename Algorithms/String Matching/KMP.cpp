#include<bits/stdc++.h>
using namespace std;

int main()
{
    string txt,pat;
    cout<<"Enter text string : ";
    cin>>txt;

    cout<<"Enter pattern string : ";
    cin>>pat;

    vector<int> ans;

    int n=txt.size(),m=pat.size();

    int prefix[m],q=0,len=0,curr=1;

    prefix[0]=0;

    while(curr<m)
    {
        if(pat[curr]==pat[len])
        {
            len++;
            prefix[curr]=len;
            curr++;
        }
        else if(len!=0)
        {
            len=prefix[len-1];
        }
        else
        {
            prefix[curr]=0;
            curr++;
        }
    }

    for(int i=0;i<n;i++)
    {
        while(q>0 && pat[q]!=txt[i])
            q=prefix[q-1];
        
        if(pat[q]==txt[i])
            q++;
        
        if(q==m)
        {
            ans.push_back(i-m+1);
            q=prefix[q-1];
        }
    }

    if(ans.size()==0)
        cout<<"\nNo pattern found";

    for(auto x:ans)
        cout<<"\nPattern found at index : "<<x;

    return 0;
}