#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#define n 248
using namespace std;
int main(){

    int i=0;
    int j;
    string countries[n]; 
    string abbr[n]; //initials of the countries
    long long pop[n][57]; //population
    string line; 
    string word;
    fstream fin; 
    int years[57];
    long long diff[n][57];
    int max[n];
    fin.open("population-figures-easy.csv",ios::in);
    getline(fin,line);

    while(getline(fin,line)){
        stringstream ss(line);
        int k=0;
        while (getline(ss,word,','))    
        {

            if(k==0){
                countries[i]=word;
            }

            else if(k==1){
                abbr[i]=word;
            }

            else{
                if (word==""){
                    pop[i][k-2]=0;
                }

                else
                {
                    pop[i][k-2]=stoll(word);
                }
            }

            k++;
        }

        i++;
    }
    fin.close();

    for (i=0; i<57; i++){
        years[i]=1960+i; //adds the years for the cout
    }

    for(i=0; i<n; i++){
        for(j=1; j<57; j++){
            diff[i][j]=pop[i][j]-pop[i][j-1];
        }
        max[i] = diff[i][0];
        for(j=1; j<57; j++){
            if(diff[i][j]>max[i]){
                max[i]=diff[i][j];
            }
        }
    }
    for(i=0; i<n; i++){
        cout<< "Country: " << countries[i] << " Difference  Population : " << max[i] << "\n";
    }
    
    system("PAUSE");
}
