#include<bits/stdc++.h>
using namespace std;

vector<int> LPS(string pat)
 {
   int n = pat.size();
   vector<int> lps(n, 0);
   int j =0;
   int i =1;
   while(i <n){
     if(pat[i] == pat[j])
       {
       j++;
       lps[i] = j;
       i++;
       }
       else
        {
         if(j !=0) j = lps[j-1];
         else  i++;
     }
     }
     return lps;
  }

vector<int> KMP(string s,string pat)
{
     int n = s.length();
     vector<int> lps = LPS(pat);
     vector<int>res;

     int i=0,j=0;
     while(i <n)
     {
       if(s[i] == pat[j])
         {
         i++;
         j++;
         }
         else
          {
           if(j !=0) j = lps[j-1];
           else
             i++;
           }
         if(j == pat.size())
          {
           res.push_back(i-j);
             j= lps[j-1];
          }
       }
       return res;
  }
int main()
{
  string s,pat;
  cout<<"Enter your string"<<endl;
  cin>>s;
  cout<<"Enter your pattern"<<endl;
  cin>>pat;
  auto res = KMP(s,pat);
  for(auto i : res)
    cout<<i<<" ";
  return 0;
  }