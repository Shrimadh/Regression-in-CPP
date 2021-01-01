#include<bits/stdc++.h> 
using namespace std;   

bool custom_sort(double a, double b) 
{
    double  a1=abs(a-0);
    double  b1=abs(b-0);
    return a1<b1;
}

int main()
{

double x[] = {1, 2, 4, 3, 5};    
double y[] = {1, 3, 3, 2, 5};    
vector<double>error;             
double err;
double b0 = 0;                   
double b1 = 0;                  
double alpha = 0.01;      
int epoch = 1;

for (int i = 0; i < 20; i ++) {   
    int idx = i % 5;
    if(idx == 0)
    {
        cout<<"\nEpoch Number: "<< epoch++ <<endl;
    }          
    double p = b0 + b1 * x[idx];  
    err = p - y[idx];              
    b0 = b0 - alpha * err;        
    b1 = b1 - alpha * err * x[idx];
    cout<<"B0="<<b0<<" "<<"\tB1="<<b1<<" "<<"\tloss="<<err<<endl;
    error.push_back(err);
}
sort(error.begin(),error.end(),custom_sort);

cout<<"\nFinal Values are: "<<"B0="<<b0<<"    "<<"B1="<<b1<<"    "<<"Loss="<<error[0]<<endl;

cout<<"\nEnter a test x value: ";
double test;
cin>>test;

double pred=b0+b1*test;
cout<<endl;
cout<<"The value predicted by the model= "<<pred<<"\n";
}