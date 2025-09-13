#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
using namespace std;

// ================== Task Class ==================
class Task {
private:
    int id;
    string title;
    string description;
    string priority;   // High, Medium, Low
    string deadline;   // Simple date as string (e.g., 2025-09-20)
    bool completed;

public:
    // Constructor
    Task(int _id, string _title, string _description, string _priority, string _deadline) {
        id = _id;
        title = _title;
        description = _description;
        priority = _priority;
        deadline = _deadline;
        completed = false;
    }

    // Getters
    int getId() const { return id; }
    string getTitle() const { return title; }
    string getPriority() const { return priority; }
    string getDeadline() const { return deadline; }
    bool isCompleted() const { return completed; }

    // Methods
    void markCompleted() { completed = true; }

    void editTask(string _title, string _description, string _priority, string _deadline) {
        title = _title;
        description = _description;
        priority = _priority;
        deadline = _deadline;
    }

    void displayTask() const {
        cout << id << ". " << title
             << " [" << priority << " Priority] "
             << " - Due: " << deadline
             << " - Status: " << (completed ? "Completed" : "Pending")
             << endl;
    }

    // Save to file
    string serialize() const {
        return to_string(id) + "|" + title + "|" + description + "|" + priority + "|" + deadline + "|" + (completed ? "1" : "0");
    }

    // Load from file
    static Task deserialize(const string& line) {
        vector<string> parts;
        string temp = "";
        for (char ch : line) {
            if (ch == '|') {
                parts.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }
        parts.push_back(temp);

        Task t(stoi(parts[0]), parts[1], parts[2], parts[3], parts[4]);
        if (parts[5] == "1") t.markCompleted();
        return t;
    }
};

// ================== Task Manager ==================
class TaskManager {
private:
    vector<Task> tasks;
    int nextId;

public:
    TaskManager() : nextId(1) {}

    void addTask(string title, string description, string priority, string deadline) {
        Task newTask(nextId++, title, description, priority, deadline);
        tasks.push_back(newTask);
        cout << "✅ Task added successfully!\n";
    }

    void listTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }
        cout << "\n📋 Task List:\n";
        for (const auto& task : tasks) {
            task.displayTask();
        }
    }

    void deleteTask(int id) {
        auto it = remove_if(tasks.begin(), tasks.end(), [id](Task& t) { return t.getId() == id; });
        if (it != tasks.end()) {
            tasks.erase(it, tasks.end());
            cout << "🗑️ Task deleted successfully.\n";
        } else {
            cout << "⚠️ Task not found.\n";
        }
    }

    void markTaskCompleted(int id) {
        for (auto& task : tasks) {
            if (task.getId() == id) {
                task.markCompleted();
                cout << "✅ Task marked as completed.\n";
                return;
            }
        }
        cout << "⚠️ Task not found.\n";
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        for (const auto& task : tasks) {
            file << task.serialize() << "\n";
        }
        file.close();
        cout << "💾 Tasks saved to file.\n";
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) return;

        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                Task t = Task::deserialize(line);
                tasks.push_back(t);
                nextId = max(nextId, t.getId() + 1);
            }
        }
        file.close();
        cout << "📂 Tasks loaded from file.\n";
    }
};

// ================== Main Program ==================
int main() {
    TaskManager manager;
    manager.loadFromFile("tasks.txt");

    int choice;
    do {
        cout << "\n===== Smart Task Manager =====\n";
        cout << "1. Add Task\n";
        cout << "2. List Tasks\n";
        cout << "3. Mark Task Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Save & Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string title, desc, priority, deadline;
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Description: ";
            getline(cin, desc);
            cout << "Enter Priority (High/Medium/Low): ";
            getline(cin, priority);
            cout << "Enter Deadline (YYYY-MM-DD): ";
            getline(cin, deadline);

            manager.addTask(title, desc, priority, deadline);
        }
        else if (choice == 2) {
            manager.listTasks();
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Task ID to mark completed: ";
            cin >> id;
            manager.markTaskCompleted(id);
        }
        else if (choice == 4) {
            int id;
            cout << "Enter Task ID to delete: ";
            cin >> id;
            manager.deleteTask(id);
        }
        else if (choice == 5) {
            manager.saveToFile("tasks.txt");
            cout << "👋 Exiting... Goodbye!\n";
        }
        else {
            cout << "⚠️ Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
