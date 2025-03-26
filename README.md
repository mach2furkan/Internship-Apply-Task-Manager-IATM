# Internship-Apply-Task-Manager-IATM

# 🚀 Task Manager Pro: The Ultimate Task Management System 🚀

Welcome to **Task Manager Pro**, the most advanced, feature-rich task management system designed to revolutionize how you organize, track, and collaborate on tasks. This project is a showcase of modern C++ programming techniques, object-oriented design, and real-world application development. Whether you're managing personal tasks or leading a team, this system has everything you need to stay productive and efficient.

---

## 🌟 Features Overview

### **Core Features**
1. **Add Task**: Add tasks with details like title, description, priority, category, deadline, and more.
2. **View All Tasks**: Display a list of all tasks in the system.
3. **Search Task by Title**: Search for tasks by their title (supports partial matches).
4. **Filter Tasks by Category**: Filter tasks based on predefined categories (e.g., Work, Personal, Study).

---

### **Advanced Features** ✨
5. **Edit Task Details**: Update any field of an existing task (title, description, priority, etc.).
6. **Delete Task**: Remove a task from the system.
7. **Sort Tasks**: Sort tasks by priority, deadline, or creation date.
8. **Save Tasks to File**: Persist all task data to a file (`tasks.txt`) for future use.
9. **Load Tasks from File**: Load previously saved task data from a file into the system.
10. **Statistics Dashboard**: Gain insights into your task management:
    - Total number of tasks.
    - Number of completed vs. incomplete tasks.
    - Most common task category.

---

### **Pro Features (Unique Enhancements)** 🔥
11. **Task Reminders**: Get notified about upcoming deadlines.
12. **Priority-Based Color Coding**: Display tasks in red, yellow, or green based on their priority.
13. **Bulk Actions**: Delete or mark multiple tasks as completed in one go.
14. **Task Search by Deadline**: Filter tasks with deadlines within a specific range.
15. **Task Archiving**: Archive completed tasks to a separate list for better organization.
16. **User-Specific Statistics Dashboard**: Detailed insights for each user, such as task completion rate.
17. **Task Duration Tracking**: Track how long a task has been open (in days).
18. **Subtasks Support**: Add subtasks to a main task and track their completion status.
19. **Task Collaboration**: Assign tasks to multiple users for teamwork.
20. **Custom Priority Levels**: Define your own priority levels (e.g., Urgent, Important, Optional).
21. **Task Notes**: Add notes to tasks for additional context or updates.
22. **Progress Bar Visualization**: Display a visual progress bar for each task based on its status.
23. **Export to JSON**: Export tasks to a JSON file for structured data sharing.
24. **User Activity Log**: Maintain a log of user actions (e.g., task added, edited, deleted).

---

## 🛠️ How It Works

### **Menu Options**
The system provides an interactive menu that lets you perform various operations:

```
=== Task Manager Pro ===
1. Add Task
2. View All Tasks
3. Search Task by Title
4. Filter Tasks by Category
5. Edit Task Details
6. Delete Task
7. Sort Tasks
8. Save Tasks to File
9. Load Tasks from File
10. View Statistics Dashboard
11. Export Data to CSV
12. Mark Task as Completed/In Progress
13. Switch User
14. Task Reminders
15. Bulk Actions (Delete/Complete)
16. Search Task by Deadline
17. Archive Completed Tasks
18. View Task Duration
19. Add/Edit Subtasks
20. Collaborate on Tasks
21. Define Custom Priority Levels
22. Add/Edit Task Notes
23. View Task Progress Bar
24. Export Tasks to JSON
25. View User Activity Log
26. Exit
========================
```

Simply select the desired option by entering the corresponding number, and let the system do the rest!

---

## 🎯 Example Workflow

1. **Add Tasks**:
   - Add multiple tasks with their details (e.g., title, description, priority, category, deadline).
   - Example:
     ```
     Title: Complete Internship Application
     Description: Submit application for XYZ company
     Priority: High
     Category: Career
     Deadline: 2023-12-01
     ```

2. **View All Tasks**:
   - Display a list of all tasks currently in the system.

3. **Search by Title**:
   - Search for "Application" to find all tasks with "Application" in their title.

4. **Filter by Category**:
   - Filter tasks under the "Career" category.

5. **Edit Task Details**:
   - Update a task's priority or deadline.

6. **Delete a Task**:
   - Remove a task from the system if it is no longer relevant.

7. **Sort by Priority**:
   - Sort tasks in descending order of priority.

8. **Save to File**:
   - Save all task data to `tasks.txt` for persistence.

9. **Load from File**:
   - Load previously saved data from `tasks.txt`.

10. **View Statistics Dashboard**:
    - Get insights into your task management:
      ```
      Total Tasks: 5
      Completed Tasks: 2
      Incomplete Tasks: 3
      Most Common Category: Career
      ```

11. **Export Data to CSV**:
    - Export task data to a CSV file for further analysis.

12. **Track Progress**:
    - Mark a task as "In Progress" or "Completed."

13. **Receive Deadline Alerts**:
    - Get notified about tasks with upcoming deadlines.

14. **Switch Users**:
    - Log in as a different user to manage their tasks.

---

## 🧰 Technologies Used

- **Programming Language**: Modern C++ (C++17/C++20)
- **Data Structures**: Vectors, Maps, Structs
- **File Handling**: Input/Output Streams (`ifstream`, `ofstream`)
- **Sorting Algorithms**: Standard Library Sorting (`std::sort`)
- **String Manipulation**: Partial matching with `std::string::find`
- **JSON Export**: Custom logic to write data into JSON format
- **CLI Enhancements**: ANSI escape codes for colors and animations

---

## 📝 Code Structure

The project is organized into modular components for clarity and maintainability:

1. **`main.cpp`**: Entry point of the program. Handles user interaction and menu navigation.
2. **`TaskManager.h` / `TaskManager.cpp`**: Core functionality for managing tasks (add, edit, delete, sort, etc.).
3. **`FileHandler.h` / `FileHandler.cpp`**: Handles saving and loading data to/from files.
4. **`Utils.h` / `Utils.cpp`**: Utility functions for string manipulation, input validation, and animations.
5. **`UserManager.h` / `UserManager.cpp`**: Manages multi-user support (login, logout, user-specific data).

---

## 📊 Why This Project Stands Out

### **Professional Design**
- Modular code structure ensures readability and maintainability.
- Object-oriented principles are applied effectively.

### **Interactive Features**
- The system provides a user-friendly interface with clear instructions and feedback.

### **Real-World Relevance**
- Simulates a practical use case for task management, making it highly relatable for companies and recruiters.

### **Persistence and Scalability**
- Data persistence via file handling ensures that task information is not lost between sessions.
- Multi-user support allows scalability for larger organizations.

### **Advanced Functionality**
- Task prioritization, deadline alerts, and progress tracking make this system stand out from basic CRUD applications.

---

## 🧪 Future Enhancements

While this version is robust and feature-rich, here are some ideas for future improvements:
1. **Database Integration**: Replace file handling with a database (e.g., SQLite) for better scalability.
2. **Web Interface**: Develop a web-based frontend using frameworks like Flask or Django.
3. **Authentication**: Add secure login functionality with password hashing.
4. **Notifications**: Send email or desktop notifications for upcoming deadlines.
5. **Collaboration Features**: Allow multiple users to collaborate on shared tasks.
6. **Cross-Platform GUI**: Build a graphical user interface (GUI) using Qt or wxWidgets.

---

## 🙌 Acknowledgments

This project was created to demonstrate proficiency in C++ programming and software design. Special thanks to:
- **Stack Overflow** for debugging tips.
- **C++ Standard Library Documentation** for inspiration.
- **You**, the user, for taking the time to explore this project!

---

## 📜 License

This project is open-source and free to use under the **MIT License**. Feel free to modify, distribute, or enhance it as needed.

---

## 💡 Final Thoughts

The **Task Manager Pro** is more than just a program—it's a testament to your skills and creativity. Use it to impress potential employers, showcase your technical expertise, and stand out during your internship interview.

Happy coding, and good luck with your internship journey! 🚀

