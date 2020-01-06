#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;

struct wo{ 
    string word;
    /* Number appear */
    int occurences;
    bool operator<(const wo &other) const{
        return occurences < other.occurences;
    }
};
/* Convert to upper words */
string capitalize(string s){
    string ns;
    for(char c:s){
        ns.push_back(::toupper(c));
    }
     return ns;
}
/* Start */
int main(){

    /* Txt read and data insert */
    fstream fin;
    fin.open("1984.txt",ios::in);
    string word;
    map<string,int> dictionary;
    while(fin >> word){
        word= capitalize(word);
        if (dictionary.find(word)==dictionary.end()) //doesen't found on dictionary
        {   
            dictionary[word]=1;
        }
        else
        {
            dictionary[word]++;
        } 
    }
    fin.close();

    vector<wo>items;
    for (auto kv:dictionary){
    wo item;
    item.word=kv.first;
    item.occurences=kv.second;
    items.push_back(item);
    }
    /* Data sort */
    sort(items.begin(),items.end());

    /* Results */
    for(auto item:items){
        cout << item.word  << " " << item.occurences << " "  << endl;
    }
    system("pause");
}