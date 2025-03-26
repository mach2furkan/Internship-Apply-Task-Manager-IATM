#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <ctime>

using namespace std;

// Structure to represent a Subtask
struct Subtask {
    string title;
    bool completed;
};

// Structure to represent a Task
struct Task {
    string title;
    string description;
    string priority; // High, Medium, Low, or Custom
    string category; // Work, Personal, Study, Career
    string status;   // Not Started, In Progress, Completed
    string deadline; // YYYY-MM-DD format
    vector<Subtask> subtasks; // Subtasks for the task
    string assignedTo;       // User(s) assigned to the task
    string notes;            // Additional notes for the task
    time_t createdAt;        // Timestamp when the task was created
};

void addTask(vector<Task> &vector);

void viewTasksWithColor(vector<Task> &vector);

void searchTaskByTitle(vector<Task> &vector);

void filterTasksByCategory(vector<Task> &vector);

void editTask(vector<Task> &vector);

void deleteTask(vector<Task> &vector);

void sortTasks(vector<Task> &vector);

void saveTasksToFile(vector<Task> &vector, string basicString);

void loadTasksFromFile(vector<Task> &vector, string basicString);

void userStatisticsDashboard(vector<Task> &vector);

void exportTasksToCSV(vector<Task> &vector);

void markTaskStatus(vector<Task> &vector);

string switchUser();

void taskReminders(vector<Task> &vector);

void bulkActions(vector<Task> &vector);

void searchTaskByDeadline(vector<Task> &vector);

void archiveCompletedTasks(vector<Task> &vector, ::vector <Task> &vector1);

void viewAllTasks(vector<Task> &vector);

// Function to display the menu options
void displayMenu() {
    cout << "\n=== Task Manager Pro ===\n";
    cout << "1. Add Task\n";
    cout << "2. View All Tasks\n";
    cout << "3. Search Task by Title\n";
    cout << "4. Filter Tasks by Category\n";
    cout << "5. Edit Task Details\n";
    cout << "6. Delete Task\n";
    cout << "7. Sort Tasks\n";
    cout << "8. Save Tasks to File\n";
    cout << "9. Load Tasks from File\n";
    cout << "10. View Statistics Dashboard\n";
    cout << "11. Export Data to CSV\n";
    cout << "12. Mark Task as Completed/In Progress\n";
    cout << "13. Switch User\n";
    cout << "14. Task Reminders\n";
    cout << "15. Bulk Actions (Delete/Complete)\n";
    cout << "16. Search Task by Deadline\n";
    cout << "17. Archive Completed Tasks\n";
    cout << "18. View Task Duration\n";           // New Feature
    cout << "19. Add/Edit Subtasks\n";            // New Feature
    cout << "20. Collaborate on Tasks\n";         // New Feature
    cout << "21. Define Custom Priority Levels\n"; // New Feature
    cout << "22. Add/Edit Task Notes\n";          // New Feature
    cout << "23. View Task Progress Bar\n";       // New Feature
    cout << "24. Export Tasks to JSON\n";         // New Feature
    cout << "25. View User Activity Log\n";       // New Feature
    cout << "26. Exit\n";
    cout << "=========================\n";
}

// New Feature: Task Duration Tracking
void viewTaskDuration(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    time_t now = time(0);
    cout << "\nTask Durations:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        const Task& task = tasks[i];
        double duration = difftime(now, task.createdAt) / (60 * 60 * 24); // Days difference
        cout << "\nTask #" << i + 1 << ": " << task.title << "\n";
        cout << "Duration: " << static_cast<int>(duration) << " days\n";
    }
}

// New Feature: Add/Edit Subtasks
void addEditSubtasks(Task& task) {
    cout << "\nSubtasks for Task: " << task.title << "\n";
    cout << "1. Add Subtask\n";
    cout << "2. Mark Subtask as Completed\n";
    cout << "3. View Subtasks\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Subtask newSubtask;
        cout << "\nEnter Subtask Title: ";
        getline(cin >> ws, newSubtask.title);
        newSubtask.completed = false;
        task.subtasks.push_back(newSubtask);
        cout << "\nSubtask added successfully!\n";
    } else if (choice == 2) {
        if (task.subtasks.empty()) {
            cout << "\nNo subtasks available.\n";
            return;
        }

        cout << "\nSubtasks:\n";
        for (size_t i = 0; i < task.subtasks.size(); ++i) {
            cout << i + 1 << ". " << task.subtasks[i].title << " (" << (task.subtasks[i].completed ? "Completed" : "Not Completed") << ")\n";
        }

        int index;
        cout << "\nEnter the number of the subtask to mark as completed: ";
        cin >> index;

        if (index >= 1 && index <= static_cast<int>(task.subtasks.size())) {
            task.subtasks[index - 1].completed = true;
            cout << "\nSubtask marked as completed!\n";
        } else {
            cout << "\nInvalid subtask number.\n";
        }
    } else if (choice == 3) {
        if (task.subtasks.empty()) {
            cout << "\nNo subtasks available.\n";
            return;
        }

        cout << "\nSubtasks:\n";
        for (size_t i = 0; i < task.subtasks.size(); ++i) {
            cout << i + 1 << ". " << task.subtasks[i].title << " (" << (task.subtasks[i].completed ? "Completed" : "Not Completed") << ")\n";
        }
    } else {
        cout << "\nInvalid choice.\n";
    }
}

// New Feature: Collaborate on Tasks
void collaborateOnTasks(Task& task) {
    cout << "\nEnter the username(s) to assign this task to (comma-separated): ";
    getline(cin >> ws, task.assignedTo);
    cout << "\nTask assigned to: " << task.assignedTo << "\n";
}

// New Feature: Define Custom Priority Levels
void defineCustomPriorityLevels(vector<string>& customPriorities) {
    cout << "\nEnter custom priority levels (comma-separated): ";
    string input;
    getline(cin >> ws, input);

    stringstream ss(input);
    string token;
    while (getline(ss, token, ',')) {
        customPriorities.push_back(token);
    }

    cout << "\nCustom priority levels defined: ";
    for (const string& priority : customPriorities) {
        cout << priority << " ";
    }
    cout << "\n";
}

// New Feature: Add/Edit Task Notes
void addEditTaskNotes(Task& task) {
    cout << "\nCurrent Notes: " << task.notes << "\n";
    cout << "Enter new notes: ";
    getline(cin >> ws, task.notes);
    cout << "\nNotes updated successfully!\n";
}

// New Feature: View Task Progress Bar
void viewTaskProgressBar(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    cout << "\nTask Progress Bars:\n";
    for (const Task& task : tasks) {
        int totalSubtasks = task.subtasks.size();
        int completedSubtasks = 0;

        for (const Subtask& subtask : task.subtasks) {
            if (subtask.completed) {
                completedSubtasks++;
            }
        }

        double progress = totalSubtasks > 0 ? (static_cast<double>(completedSubtasks) / totalSubtasks) * 100 : 0;
        cout << "\nTask: " << task.title << "\n";
        cout << "[";
        for (int i = 0; i < 10; ++i) {
            if (i < static_cast<int>(progress / 10)) {
                cout << "=";
            } else {
                cout << " ";
            }
        }
        cout << "] " << static_cast<int>(progress) << "%\n";
    }
}

// New Feature: Export Tasks to JSON
void exportTasksToJSON(const vector<Task>& tasks) {
    ofstream file("tasks.json");
    if (!file.is_open()) {
        cout << "\nError: Unable to open JSON file for exporting.\n";
        return;
    }

    file << "{\n  \"tasks\": [\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        const Task& task = tasks[i];
        file << "    {\n";
        file << "      \"title\": \"" << task.title << "\",\n";
        file << "      \"description\": \"" << task.description << "\",\n";
        file << "      \"priority\": \"" << task.priority << "\",\n";
        file << "      \"category\": \"" << task.category << "\",\n";
        file << "      \"status\": \"" << task.status << "\",\n";
        file << "      \"deadline\": \"" << task.deadline << "\"\n";
        file << "    }" << (i < tasks.size() - 1 ? "," : "") << "\n";
    }
    file << "  ]\n}\n";

    file.close();
    cout << "\nTasks exported to JSON successfully!\n";
}

// New Feature: User Activity Log
void logUserActivity(map<string, vector<string>>& activityLog, const string& currentUser, const string& action) {
    activityLog[currentUser].push_back(action);
    cout << "\nAction logged: " << action << "\n";
}

void viewUserActivityLog(const map<string, vector<string>>& activityLog, const string& currentUser) {
    if (activityLog.find(currentUser) == activityLog.end() || activityLog.at(currentUser).empty()) {
        cout << "\nNo activity log available for user: " << currentUser << "\n";
        return;
    }

    cout << "\n=== Activity Log for User: " << currentUser << " ===\n";
    for (const string& action : activityLog.at(currentUser)) {
        cout << "- " << action << "\n";
    }
    cout << "=====================================\n";
}

// Main function
int main() {
    map<string, vector<Task>> userTasks;         // Map of username -> tasks
    map<string, vector<Task>> userArchivedTasks; // Map of username -> archived tasks
    map<string, vector<string>> activityLog;     // Map of username -> activity log
    string currentUser = "default";              // Default user
    int choice;

    vector<string> customPriorities = {"High", "Medium", "Low"}; // Default priorities

    cout << "Welcome to Task Manager Pro!\n";

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(userTasks[currentUser]);
                logUserActivity(activityLog, currentUser, "Added a new task.");
                break;
            case 2:
                viewTasksWithColor(userTasks[currentUser]); // Updated with color coding
                break;
            case 3:
                searchTaskByTitle(userTasks[currentUser]);
                break;
            case 4:
                filterTasksByCategory(userTasks[currentUser]);
                break;
            case 5:
                editTask(userTasks[currentUser]);
                logUserActivity(activityLog, currentUser, "Edited a task.");
                break;
            case 6:
                deleteTask(userTasks[currentUser]);
                logUserActivity(activityLog, currentUser, "Deleted a task.");
                break;
            case 7:
                sortTasks(userTasks[currentUser]);
                break;
            case 8:
                saveTasksToFile(userTasks[currentUser], currentUser);
                logUserActivity(activityLog, currentUser, "Saved tasks to file.");
                break;
            case 9:
                loadTasksFromFile(userTasks[currentUser], currentUser);
                logUserActivity(activityLog, currentUser, "Loaded tasks from file.");
                break;
            case 10:
                userStatisticsDashboard(userTasks[currentUser]); // Updated dashboard
                break;
            case 11:
                exportTasksToCSV(userTasks[currentUser]);
                logUserActivity(activityLog, currentUser, "Exported tasks to CSV.");
                break;
            case 12:
                markTaskStatus(userTasks[currentUser]);
                logUserActivity(activityLog, currentUser, "Marked a task as completed/in progress.");
                break;
            case 13:
                currentUser = switchUser();
                logUserActivity(activityLog, currentUser, "Switched user.");
                break;
            case 14:
                taskReminders(userTasks[currentUser]); // New Feature
                break;
            case 15:
                bulkActions(userTasks[currentUser]); // New Feature
                logUserActivity(activityLog, currentUser, "Performed bulk actions.");
                break;
            case 16:
                searchTaskByDeadline(userTasks[currentUser]); // New Feature
                break;
            case 17:
                archiveCompletedTasks(userTasks[currentUser], userArchivedTasks[currentUser]); // New Feature
                logUserActivity(activityLog, currentUser, "Archived completed tasks.");
                break;
            case 18:
                viewTaskDuration(userTasks[currentUser]); // New Feature
                break;
            case 19:
                if (userTasks[currentUser].empty()) {
                    cout << "\nNo tasks available to add/edit subtasks.\n";
                } else {
                    viewAllTasks(userTasks[currentUser]);
                    int index;
                    cout << "\nEnter the number of the task to add/edit subtasks: ";
                    cin >> index;

                    if (index >= 1 && index <= static_cast<int>(userTasks[currentUser].size())) {
                        addEditSubtasks(userTasks[currentUser][index - 1]); // New Feature
                        logUserActivity(activityLog, currentUser, "Added/edited subtasks.");
                    } else {
                        cout << "\nInvalid task number.\n";
                    }
                }
                break;
            case 20:
                if (userTasks[currentUser].empty()) {
                    cout << "\nNo tasks available to collaborate on.\n";
                } else {
                    viewAllTasks(userTasks[currentUser]);
                    int index;
                    cout << "\nEnter the number of the task to collaborate on: ";
                    cin >> index;

                    if (index >= 1 && index <= static_cast<int>(userTasks[currentUser].size())) {
                        collaborateOnTasks(userTasks[currentUser][index - 1]); // New Feature
                        logUserActivity(activityLog, currentUser, "Collaborated on a task.");
                    } else {
                        cout << "\nInvalid task number.\n";
                    }
                }
                break;
            case 21:
                defineCustomPriorityLevels(customPriorities); // New Feature
                logUserActivity(activityLog, currentUser, "Defined custom priority levels.");
                break;
            case 22:
                if (userTasks[currentUser].empty()) {
                    cout << "\nNo tasks available to add/edit notes.\n";
                } else {
                    viewAllTasks(userTasks[currentUser]);
                    int index;
                    cout << "\nEnter the number of the task to add/edit notes: ";
                    cin >> index;

                    if (index >= 1 && index <= static_cast<int>(userTasks[currentUser].size())) {
                        addEditTaskNotes(userTasks[currentUser][index - 1]); // New Feature
                        logUserActivity(activityLog, currentUser, "Added/edited task notes.");
                    } else {
                        cout << "\nInvalid task number.\n";
                    }
                }
                break;
            case 23:
                viewTaskProgressBar(userTasks[currentUser]); // New Feature
                break;
            case 24:
                exportTasksToJSON(userTasks[currentUser]); // New Feature
                logUserActivity(activityLog, currentUser, "Exported tasks to JSON.");
                break;
            case 25:
                viewUserActivityLog(activityLog, currentUser); // New Feature
                break;
            case 26:
                cout << "\nThank you for using Task Manager Pro!\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 26);

    return 0;
}

void viewAllTasks(vector<Task> &vector) {

}

void archiveCompletedTasks(vector<Task> &vector, ::vector <Task> &vector1) {

}

void searchTaskByDeadline(vector<Task> &vector) {

}

void bulkActions(vector<Task> &vector) {

}

void taskReminders(vector<Task> &vector) {

}

string switchUser() {
    return std::string();
}

void markTaskStatus(vector<Task> &vector) {

}

void exportTasksToCSV(vector<Task> &vector) {

}

void userStatisticsDashboard(vector<Task> &vector) {

}

void loadTasksFromFile(vector<Task> &vector, string basicString) {

}

void saveTasksToFile(vector<Task> &vector, string basicString) {

}

void sortTasks(vector<Task> &vector) {

}

void deleteTask(vector<Task> &vector) {

}

void editTask(vector<Task> &vector) {

}

void filterTasksByCategory(vector<Task> &vector) {

}

void searchTaskByTitle(vector<Task> &vector) {

}

void viewTasksWithColor(vector<Task> &vector) {

}

void addTask(vector<Task> &vector) {

}
