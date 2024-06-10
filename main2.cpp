#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// Declaracion de funciones
void Add(string date, string event);
void DelEvent(string date, string event);
void DelDate(string date);
void Find(string date);
void Print();

// Declaracion de mapa
map<string, vector<string>> db;

int main(){
    int n;
    cin >> n;

    string command, date, description;

    while (cin >> command) {
        if (command == "Add") {
            cin >> date >> description;
            Add(date, description);
        } else if (command == "Del") {
            cin >> date >> description;
            if (description.empty())
                DelDate(date);
            else
                DelEvent(date, description);
        } else if (command == "Find") {
            cin >> date;
            Find(date);
        } else if (command == "Print") {
            Print();
        } else {
            cout << "Unknown command: " << command << endl;
            return 1; // Terminar con error
        }
    }

    return 0;
}

void Add(string date, string event){
    db[date].push_back(event);   
}

void DelEvent(string date, string event){
    auto& events = db[date];
    events.erase(remove(events.begin(), events.end(), event), events.end());
    cout << "Deleted successfully" << endl;
}

void DelDate(string date){
    int eventsDeleted = db.erase(date);
    cout << "Deleted " << eventsDeleted << " events" << endl;
}

void Find(string date){
    if(db.count(date) == 0){
        cout << "Event not found" << endl;
    }
    else{
        vector<string>& events = db[date];
        sort(events.begin(), events.end());
        for(const string& event : events){
            cout << event << endl;
        }
    }
}

void Print(){
    for(auto& pair : db){
        const string& date = pair.first;
        vector<string>& events = pair.second;
        for(const string& event : events){
            cout << date << " " << event << endl;
        }
    }
}
