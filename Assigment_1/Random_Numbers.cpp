#include <iostream>
#include <ctime>
using namespace std;
void stats(int a[],int n,double &avg,int &min,int &max){
    int sum;
    int i;
    sum=min=max=a[0]; 
    for (i=0; i<n; i++){
        sum +=a[i];
        if (max<a[i]) //finds maximum value 
            max=a[i];
        if  (min>a[i]) //finds minimum value
            min = a[i]; 
    }
    avg=(double)sum/(double)n; //calculates average
}
int main(){
    int i,j,min,max;
    double avg;
    int a[100];
    srand(time(NULL));
    for(i=0; i<100; i++){
        j=rand()%1001; //gets random numbers to the array
        a[i]=j;   
    }
    stats(a,100,avg,min,max); //function call 
    cout<<"Average : "<<avg<<"\n"<<"Min : "<<min<<"\n"<<"Max : "<<max<<"\n";
      system("PAUSE");
}
