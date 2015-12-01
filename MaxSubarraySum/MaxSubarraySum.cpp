#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
/* Program to compute maximum subarray sum 
using namespace std;
int max(int a1[],int n)
{
    int temp=a1[0];
    for (int m=0;m<n;++m)
	{
		if (temp<a1[m])  
			temp=a1[m];
    }
    return temp;
}
int main() {
    int t,n,l=0,m=0;
    int a[100000];
	cin>>t;
	for (int k=0;k<t;++k){
		cin>>n;
		l=0;
		for (int j=0;j<n;++j){
			cin>>a[j];
			if(a[j]<0)
				l++;
		}
		
		
		int sum=0,maxsum=0;
		int nonsum=0;
		for (int i=0;i<n;++i)
		{
			if(l==n)
            {maxsum = max(a,n);
				nonsum= max(a,n);}
			else if (n==1)
			{
				maxsum = a[i];
				nonsum= a[i];
			}
			else 
			{
				if (sum+a[i]>0)
				{
					sum+=a[i];
					
					if (a[i]>0)
						nonsum+=a[i];
					if (sum>=maxsum)
					{
						maxsum=sum;
					}
					
				}
				else if(sum+a[i]<=0)
					sum=0;			
				
			}
			
		}  cout<<maxsum<<" "<<nonsum<<" "<<endl; 
	}  return 0;
}