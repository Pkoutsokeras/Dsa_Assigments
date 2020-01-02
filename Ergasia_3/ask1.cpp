#include <iostream>
#include <vector>
#include <list>
#include <ctime>
using namespace std;
string zeros = "0000000000";

struct block{
    size_t id;
    string timestamp;
    string data;
    size_t nouce;
    size_t previous_hash;
};

size_t hash_combined(block &a_block){
    string c=to_string(a_block.id) + a_block.timestamp + a_block.data +to_string(a_block.nouce) + to_string(a_block.previous_hash);
    hash<string>h;
    return h(c);
}

void print_block(block &a_block){
    cout << "ID" << a_block.id;
    cout << "TS" << a_block.timestamp;
}

void find_nouce(block &a_block,int difficulty){
    size_t hr =hash_combined(a_block);
    while(true){
         string hrs = to_string(hr);
            if(hrs.compare (hrs.size()-difficulty,difficulty,zeros,0,difficulty)==0)
            break;
            a_block.nouce++;
            hr= hash_combined(a_block);
    }
}
bool check_valid_blockchain(list <block> &chain){
    
}

int main(){
    list<block> blockhain;
    int difficulty=7;
    vector<string> texts = {"Alice pays 5 euros to Bob","Bob Pays 5 euros to Carl","Carl pays 10 euros to David","David pays 2 euro to Alice","Alice pays 2 euros to Bob","Bob pays 5 euros to David","Carl pays 5 euros to Alice"};
    time_t now=time(0);
    struct tm *timeinto=localtime(&now);
    char buffer[80];
    strftime(buffer,80,"%F %T",timeinto);
    block genesis = {0,buffer,"GENESIS block",0,0};
    find_nouce(genesis,difficulty);
    block previous_block = genesis;

    for(int i=0; i<7; i++){
        block a_block;
        a_block.id= i+1;
        now = time(0);
        timeinto = localtime(&now);
        strftime(buffer,80,"%F %T",timeinto);
        a_block.timestamp = buffer;
        a_block.data = texts[i];
        a_block.nouce=0;
        a_block.previous_hash=hash_combined(previous_block);
        find_nouce(a_block,difficulty);
        blockhain.push_back(a_block);
        previous_block(a_block);
        print_block(a_block);
    }
    system("PAUSE");
}