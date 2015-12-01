/*A time series of a stock's highest price during a trading day (at the New York Stock Exchange), is provided to you. In each test case, the day's highest prices is missing for certain days. By analyzing the data, try to identify the missing price for those particular days.*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>
using namespace std;
int main() {
    int n, temp[300],j=0;
    string price[300];
    double ret;
    ret=0;
    string date;
    string time_p;
    size_t found;
    double price_avg=0;
    double price_sum=0;
    double avg=0;
    double std=0;
    double sum=0;
    double test[300];
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>date>>time_p>>price[i];  
		
		temp[i]=0;
		found = price[i].find("M");
		if (found!=std::string::npos){
			temp[i]=1;
			test[i]=0;
		}
		else 
		{test[i]=stod(price[i]);
		} 
	}
    
	for (int i=1;i<n;i++){
		
		
		if ((temp[i]==0) && (temp[i-1]==0)){
			ret=(stod(price[i])-stod(price[i-1]))/stod(price[i-1]);
			
			//cout<<ret[i];
		}
        
		else if((temp[i]==0) && (temp[i-1]==1)){
			
			j=i-1;   
            while((j>0) && (temp[j]==1)){ 
				j--;
			}
			if (temp[j]==0){
				//cout<<"Hello"<<endl;
				ret=(stod(price[i])-stod(price[j]))/(stod(price[j]))/(double)(i-j);  }
			
			else
				ret=0; 
		}    
		
		sum+=ret;
	}                   
    
    //cout<<sum<<endl;
    avg = sum/(n-20);
    //cout<<avg;
	for (int i=0;i<n;i++){
        if (temp[i]==0){
            //cout<<"Anees"<<endl;
			price_sum+=stod(price[i]);
        }
	}
	price_avg = price_sum/(n-20);
    
	if (temp[0]==1){
		test[0]=price_avg;       
		cout<<test[0]<<endl;
	}
    
	
	
	for (int i=1;i<n;i++){
		
		if (temp[i]==1){
			test[i]=test[i-1]*(1+avg);
            cout<<test[i]<<endl;
			// cout<<"AA"<<endl;
		}      //cout<<temp[i]<<endl;
	}
	
	return 0;
}                    
