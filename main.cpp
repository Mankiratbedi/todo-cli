#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

   
    if (argc < 2) {
        cout << "Usage: todo <command> [arguments]" << endl;
        cout << "Type 'todo help' for a list of commands." << endl;
        return 1; 
    }

    string command = argv[1];

    if (command == "list") {
        ifstream file("todo.txt");
        string line;
        int taskNumber = 1;

        if (!file.is_open()) {
            cout << "No tasks yet. Why not add one?" << endl;
            return 0;
        }

        while (getline(file, line)) {
            cout << taskNumber++ << ". " << line << endl;
        }
        file.close();

    } else if (command == "help") {
        cout << "Available commands:\n";
        cout << "  add \"<task>\"   - Add a new task\n";
        cout << "  list             - List all tasks\n";
        cout << "  done <number>    - Mark a task as done\n";
    
    } else {
        cout << "Unknown command: " << command << endl;
    }

    return 0;
}