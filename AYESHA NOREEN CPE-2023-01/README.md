
<div align="center">
  <h1>TerBot - A Robust Terminal Chat System</h1>
  <a class="header-badge" target="_blank" href="https://www.linkedin.com/in/khatoonintech/">
  <img src="https://img.shields.io/badge/style--5eba00.svg?label=LinkedIn&logo=linkedin&style=social">
  </a>
  

<sub>Author:
<a href="https://www.linkedin.com/in/Khatoonintech/" target="_blank">Ayesha Noreen</a><br>
<small> <i>#KhatoonInTech CE' 27 @BZU |Agentic AI & Automation Engr @ DevRolin | ByteWise Certified ML/DL Engineer|GSoC Contributor | SWEfellow: Confiniti. ,HeadStarterAI</i> </small>
</sub>
<br>
<br>
<br>

 ![portal ](../main/images/portal.png)

</div>

---
# 💬 TERBOT - Terminal-Based Chatbot System

A lightweight C++ terminal-based chatbot system that simulates basic multi-user chat functionalities with admin controls, message backups, and chat history. The system allows admins to manage users, enter chat rooms, and store or retrieve message logs in CSV format.

---

## 📑 Table of Contents

* [🧰 Features](#-features)
* [📁 Project Structure](#-project-structure)
* [💻 Requirements](#-requirements)
* [🚀 How to Run Locally](#-how-to-run-locally)
* [📦 How to Clone This Repository](#-how-to-clone-this-repository)
* [🔍 Class and Function Breakdown](#-class-and-function-breakdown)

  * [User Class](#user-class)
  * [Admin Class](#admin-class)
  * [Message Class](#message-class)
  * [BackUp Class](#backup-class)
  * [Helper Functions](#helper-functions)
* [📓 Backup File Format](#-backup-file-format)
* [🧑‍💻 Author](#-author)

---

## 🧰 Features

* 👨‍💼 Admin login and dashboard
* 👥 Add, View, Edit, and Delete users
* 💬 Simulate a chatroom between users
* 🕓 Timestamped message logs
* 📄 CSV-based message backups
* 🗑️ Edit or delete records from the backup
* 🖥️ Terminal-only user interface

---

## 📁 Project Structure

```
chatbot/
├── chatbot.cpp       # Main source code
├── backup.csv        # Backup file (auto-generated)
└── README.md         # Project documentation
```

---

## 💻 Requirements

* C++ Compiler (e.g., `g++`, `clang++`)
* Command-line terminal (Windows CMD, PowerShell, Terminal, etc.)
* No third-party libraries required

---

## 🚀 How to Run Locally

1. **Clone the Repository:**

```bash
git clone https://github.com/your-username/terbot-chatbot.git
cd terbot-chatbot
```

2. **Compile the Code:**

```bash
g++ chatbot.cpp -o chatbot
```

3. **Run the Executable:**

```bash
./chatbot       # Linux / macOS
chatbot.exe     # Windows
```

---

## 📦 How to Clone This Repository

```bash
git clone https://github.com/your-username/terbot-chatbot.git
```

> Replace `your-username` with your actual GitHub username if you upload the project there.

---

## 🔍 Class and Function Breakdown

### 📦 User Class

Handles creation, display, editing, and deletion of users.

* **Attributes:**

  * `user_id`: Unique user identifier.
  * `user_name`: Name of the user.

* **Methods:**

  * `addUsers(...)`: Add one or more users.
  * `viewUsers(...)`: List all current users.
  * `deleteUser(...)`: Remove a user by ID.
  * `editUser(...)`: Edit a user’s name.

---

### 👮 Admin Class (inherits from User)

Handles authentication and permission dashboard.

* **Attributes:**

  * `Admin_ID = 911`
  * `Admin_Name = "bruski"`

* **Methods:**

  * `login(...)`: Authenticates admin using hardcoded credentials.
  * `AdminPermissions(...)`: Displays dashboard options.

---

### 📨 Message Class

Handles chat message creation and formatting.

* **Attributes:**

  * `sender_id`, `sender_name`, `content`, `timestamp`

* **Methods:**

  * `getFormattedMessage()`: Returns timestamped formatted message.
  * `newChat(...)`: Prints chat history from the message queue.

---

### 💾 BackUp Class

Handles CSV file interactions for storing, viewing, editing, and deleting messages.

* **Static Attributes:**

  * `File`, `file`: File streams
  * `line`: Temp line string for reading

* **Methods:**

  * `showBackup(...)`: Parses and displays the CSV chat history.
  * `storeBackup(...)`: Appends a new message to the backup.
  * `deleteBackup(...)`: Removes all records of a specific user.
  * `editBackup(...)`: Updates a user's name in the backup.

---

### 🔧 Helper Functions

* `header(sectionTitle)`: Displays a formatted section header.
* `footer()`: Displays a footer with developer info.
* `ChatRoomLoop(...)`: Main interaction loop where users send messages.

---

## 📓 Backup File Format

```csv
USER_IDs,USER_NAMES,MESSAGES,TIMESTAMPS
1001,John,Hello, how are you?,Wed May 15 14:12:43 2025
1002,Emily,I'm doing great!,Wed May 15 14:14:12 2025
```

> Automatically created in `backup.csv`. Edited and managed by the `BackUp` class.

---
## 🧑‍💻 Author

Made with 💙 by **Ayesha Noreen**
Computer Engineering, CPE-23--01
Project Name: **TERBOT**

**Tip**: If you wish to expand the system, consider:

* Adding chat functionality between users.
* Password protection for admin login.
* Encrypting the backup file or switching to a database.

---


## License

This project is licensed under the [MIT License](LICENSE).


---

<div align="center">
<h3>For any query/help ,please contact our developer:</h3>  
Developer : <a href="https://www.linkedin.com/in/Khatoonintech/" target="_blank">Ayesha Noreen</a><br>
   <small> ByteWise Certified ML/DL Engineer|GSoC Contributor | SWEfellow: Confiniti. ,HeadStarterAI </small>
<br> <a href="https://www.github.com/Khatoonintech/" target="_blank"> Don't forget to ⭐ our repo </a><br>


</div>

