#include <iostream>
#include <sstream>
#include <string>
using namespace std;

main(){
    string affan = "2024-01-10";
    string item[3];
    int i = 0;
    stringstream ss(affan);
    while (getline(ss,item[i],'-'))
    {
        i++;
    }
    
    for (int i = 0; i < 3; i++)
    {
        cout << item[i] << endl;
    }
    
    
}