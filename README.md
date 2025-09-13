# 📋 Smart Task Manager (C++)

A command-line Task Manager built in C++ that helps users manage their daily tasks with features like add, list, delete, complete, and save to file.

This project applies Low-Level Design (LLD), OOP principles, and file handling to solve a real-world problem in a beginner-friendly yet scalable way.


---

🚀 Features

➕ Add Task with title, description, priority, and deadline

📋 List Tasks with status (Pending / Completed)

✅ Mark Task as Completed

🗑️ Delete Task by ID

💾 Save Tasks to a file (tasks.txt)

📂 Load Tasks automatically when the program starts

🔐 Unique ID system to manage tasks



---

🏗️ Project Structure

Task Class → Represents an individual task (title, description, priority, deadline, status)

TaskManager Class → Manages all tasks (add, list, delete, update, save, load)

File Handling → Tasks are stored in tasks.txt for persistence

Main Program → Provides menu-driven interface



---

⚙️ How to Run

1. Compile

g++ task_manager.cpp -o task_manager

2. Run

./task_manager

3. Example Usage

===== Smart Task Manager =====
1. Add Task
2. List Tasks
3. Mark Task Completed
4. Delete Task
5. Save & Exit
Choose an option: 1

Enter Title: Finish Resume
Enter Description: Tailor resume for Google apprenticeship
Enter Priority (High/Medium/Low): High
Enter Deadline (2025-09-15): 
✅ Task added successfully!

===== Smart Task Manager =====
2
📋 Task List:
1. Finish Resume [High Priority] - Due: 2025-09-15 - Status: Pending


---

📂 File Example (tasks.txt)

1|Finish Resume|Tailor resume for Google apprenticeship|High|2025-09-15|0

Format → id|title|description|priority|deadline|status

Status → 0 = Pending, 1 = Completed



---

🧑‍💻 Skills Demonstrated

C++ OOP → Classes, Encapsulation, Methods

LLD Principles → Separation of concerns, modular design

File Handling → Persistent storage with text files

Problem Solving → Task management as a real-world use case

Clean Coding → Readable, maintainable design



---

🌟 Future Enhancements

🔍 Search tasks by keyword or priority

🕒 Sort tasks by deadline or priority

🔔 Notifications or reminders using system clock

🖥️ GUI version using Qt or ncurses

🌐 REST API version in Python/Flask (cross-language extension)



---

📜 License

This project is open-source and free to use for learning purposes.


---

👉 On your resume, write it like this:
Smart Task Manager (C++) – Built a CLI-based task manager applying LLD, OOP principles, and file persistence to solve real-world productivity problems.


---
