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

double x1[] = {2.7810836, 1.465489372, 3.396561688, 1.38807019, 3.06407232,7.627531214,5.332441248,6.922596716,8.675418651 ,7.673756466};                          
double x2[] = {2.550537003,2.362125076,4.400293529,1.850220317,3.005305973,2.759262235,2.088626775,1.77106367,-0.2420686549,3.508563011};
double y[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
 
vector<double>error; 
double err;    
double b0 = 0; 
double b1 = 0; 
double b2=  0; 
double alpha = 0.01; 
double  e = 2.71828;
int epoch = 1;

for (int i = 0; i < 40; i++) { 
    int idx = i % 10; 
    if(idx == 0)
    {
        cout<<"\nEpoch Number = "<<epoch++<<endl;
    }
    double p = -(b0 + b1 * x1[idx]+ b2* x2[idx]);
    double pred  = 1/(1+ pow(e,p)); 
    err = y[idx]-pred;  
    b0 = b0 - alpha * err*pred *(1-pred)* 1.0;  
    b1 = b1 + alpha * err * pred*(1-pred) *x1[idx];
    b2 = b2 + alpha * err * pred*(1-pred) * x2[idx];
    cout<<"B0="<<b0<<" "<<"\tB1="<<b1<<" "<<"\tB2="<<b2<<"\tLoss="<<err<<endl;
    error.push_back(err);
    }

sort(error.begin(),error.end(),custom_sort);
cout<<"\nFinal Values are: "<<"B0="<<b0<<" "<<"  B1="<<b1<<" "<<"  B2="<<b2<<"  Loss="<<error[0]<<endl;
  
double test1,test2;
cout<<"\nEnter the values of the two features X1 and X2 = ";
cin>>test1>>test2;
double pred=b0+b1*test1+b2*test2; 
cout<<"\nThe value predicted by the model = "<<pred<<endl;
if(pred>0.5)
pred=1;
else
pred=0;
cout<<"\nThe class predicted by the model = "<<pred<<"\n"<<endl;
}