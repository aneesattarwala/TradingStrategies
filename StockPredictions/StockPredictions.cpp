/*Algorithms that can correctly predict stock prices can help generate millions of dollars. In this one-player game, you try to predict the rise and fall of the stock price of various stocks and buy or sell the stocks accordingly.
 
 You start with $100. Each turn you will be given the stock prices of current day and previous 4 days. You must then choose to BUY or SELL the stocks. Your program will be run with input for 1 day at a time.*/

// Simple MA strategy. Sell if MA is below the current price by 10% and buy vice versa.
// Parameters need to be tuned with more data.
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void printTransactions(double m, int k, int d, vector <string> name, vector <int> owned, vector < vector <double> > prices) 
{
    int flag=0;  
    double purchase=0;
	vector<double> avg;
	double _avg=0.0;
	vector<vector<double>>::iterator it_r;
	vector<double>::iterator it_c;          
	vector<vector<double>>::iterator price;
	vector<string>::iterator it_name;
	vector<int>::iterator own;
	double pct;
	int txn=0;
	vector <double> sells;
	vector <double>:: iterator it;
    vector <double> buys;
    vector <double> holds;
    vector <double> pct_chg;
    int buys_p=0;
    int sells_p=0;
    double spent=0;
    vector<double> sold;
    vector<string>sold_name;
	vector <double>:: iterator b;
	vector <double>:: iterator s;
    vector <double>:: iterator sf;
    vector <double>:: iterator bf;
	vector <double>:: iterator bb_f;
    vector <double> lastprice;
    map<double,string> m_price;
    map<double,double> m_pct;
    map<double,double> :: reverse_iterator itm;
    map<double,double> :: iterator its;
	map<string,int> :: iterator itst;
	double total_sale=0;
    map <string,int> purchase_set;
    map <string,int> sold_set;
	if(d>1)
    {flag=1;}
    for (it_r=prices.begin();it_r!=prices.end();++it_r){
        for (it_c =(*it_r).begin();it_c!=(*it_r).end()-1;++it_c){
            _avg+=(*it_c);
        }
		avg.push_back(_avg/4);    
		_avg=0;
	}
	for (int i=0;i<k;++i){         
		pct = (prices[i][4]-avg[i])/avg[i];
		lastprice.push_back(prices[i][4]);
		m_pct.insert(pair<double,double>(prices[i][4],pct));   
		m_price.insert(pair<double,string>(prices[i][4],name[i]));  
	}
	int b_p1;
	for (itm=m_pct.rbegin();itm!=m_pct.rend();++itm){  
		bb_f=find(lastprice.begin(),lastprice.end(),itm->first); 
		b_p1 = distance(lastprice.begin(),bb_f);
		if (flag==1){
			if ( (itm->second>.10) && owned[b_p1]>0 ){
				sells_p=owned[b_p1];
				txn++;
				sold_set.insert(pair<string,int>(name[b_p1],owned[b_p1]));
				// owned[b_p1]=0;
			} 
		}
		if(flag==0){
			if ( owned[b_p1]>0){
				sells_p=owned[b_p1];
				txn++;
				sold_set.insert(pair<string,int>(name[b_p1],owned[b_p1]));
			}   
		}
		total_sale+=sells_p*prices[b_p1][4];
	}
    vector<double>purchase_price;
    vector<int>purchase_no;
    double compare=0;
    if(flag==1){  
		for (its=m_pct.begin();its!=m_pct.end();++its){  
            compare = m-spent;
            buys_p=0;
            if(compare > its->first && its->second<-.1){
				buys_p++;
				spent+=its->first;
				compare = m-spent;
				//cout<<itm->first<<" "<<itm->second<<" "<<compare<<" "<<spent<<endl;
				purchase=its->first;}
			if(buys_p>0){
				bb_f=find(lastprice.begin(),lastprice.end(),purchase); 
				b_p1 = distance(lastprice.begin(),bb_f);   
				purchase_set.insert(pair<string,int>(name[b_p1],buys_p));
				owned[b_p1]+=buys_p; 
				txn++;}
		}
	}
	cout<<txn<<endl;  
    for (itst=sold_set.begin();itst!=sold_set.end();++itst){  
        cout<<itst->first<<" SELL "<<itst->second<<endl;}
    for (itst=purchase_set.begin();itst!=purchase_set.end();++itst){  
        cout<<itst->first<<" BUY "<<itst->second<<endl;}
    //cout<<spent<<" "<<(m-spent)<<" "<<total_sale<<" "<<(m-spent)+total_sale<<endl;
	
}

int main(void) {
    double _m;
    cin >> _m;
    
    int _k;
    cin >> _k;
    
    int _d;
    cin >> _d;
    
    vector<string> _name;
    vector<int> _owned;
    vector < vector <double> > _prices;
    
    string _name_item;
    int _owned_item;
    double _prices_item_item;
    
    for(int _i=0; _i<_k; _i++) {
        cin >> _name_item;
        _name.push_back(_name_item);
        
        cin >> _owned_item;
        _owned.push_back(_owned_item);
		
        vector <double> _prices_item;
        for(int _j = 0; _j<5; _j++) {
            cin >> _prices_item_item;
            _prices_item.push_back(_prices_item_item);
        }
        _prices.push_back(_prices_item);  
        
        
    }
    
    printTransactions(_m, _k, _d, _name, _owned, _prices);
    
    return 0;
}