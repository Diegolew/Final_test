#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

//Declaracion de funciones
void Add(string date, string event);
void DelEvent(string date, string event);
void DelDate(string date);
void Find(string date);
void Print();

//Declaracion de mapa
map<string, vector<string>> db;

int main(){
int n;
cin >> n;

for(int i = 0; i < n; i++){
    string command;
    cin >> command;

    if(command == "Add"){
        string date, event;
        cin >> date >> event;
        Add(date, event);
    }
    else if(command == "DelEvent"){
        string date, event;
        cin >> date >> event;
        DelEvent(date, event);
    }
    else if(command == "DelDate"){
        string date;
        cin >> date;
        DelDate(date);
    }
    else if(command == "Find"){
        string date;
        cin >> date;
        Find(date);
    }
    else if(command == "Print"){
        Print();
    }
}
    return 0;
}

void Add(string date, string event){
    db[date].push_back(event);   
}

void DelEvent(string date, string event){
    for(int i = 0; i < db[date].size(); i++){
        if(db[date][i] == event){
            db[date].erase(db[date].begin() + i);
        }
    }
}
