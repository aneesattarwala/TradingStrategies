/*Your algorithms have become so good at predicting the market that you now know what the share price of Wooden Orange Toothpicks Inc. (WOT) will be for the next N days.

 Each day, you can either buy one share of WOT, sell any number of shares of WOT that you own, or not make any transaction at all. What is the maximum profit you can obtain with an optimum trading strategy?*/

// Buy until you hit global max. Sell at global max. Start buying again as you go below next local maxima, continue through local minima and sell at local maxima.
//Continue this strategy till all local maxima are  covered.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int max(int A[],int l,int b, int e);

int main() {
	
    long long int n_share=0;
    long long int profit=0;
    long long int purchase=0;
    int i,n,t, price;
    int S[50001],temp;
    cin>>t;
	while (t>0){
        cin>>n;
        for (int i=0;i<n;i++)
		{
            cin>>price;
            S[i]=price;
        }
		// S[n+1]=0;
        i=0;
        
        while(i<n)
        {
            temp = max(S,n,i,n);    
            while (S[i]<temp)    
            {
                purchase+=S[i];
                n_share++;
                i++;
            }
            profit += n_share*(S[i]) - purchase;
            n_share= 0;
            purchase=0;
            i++;
        }
        cout<<profit;
        profit=0;
        cout<<endl;
        t--;
	}
    return 0;
}
int max(int A[],int l, int b, int e)
{
    int max=A[b];
    for (int i=b+1;i<e;i++){
        if (A[i]>max)
            max=A[i];
    }
    return max;
}