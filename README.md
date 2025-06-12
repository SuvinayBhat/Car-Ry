# 🚗 CAR-RY: Car Rental Management System in C++ & SQLite

Welcome to **CAR-RY**, a lightweight car rental record management system built in **C++** using **SQLite**. This console-based application lets you store, view, update, and delete customer records — including their name, age, rented car, and rental amount.

This project is ideal for learning purposes or small-scale offline applications, using a simple and clean terminal UI.

---

## 🎯 Features

- View all customer entries  
- Add a new customer record  
- Delete a specific record by ID  
- Update any field (first name, last name, age, car name, amount)  
- Delete all entries  
- Simple ASCII-art exit animation ✨

---

## 📁 Folder Structure

/your-project-folder
│
├── main.cpp ← Main application logic
├── sqlite3.c ← SQLite source file (add to project)
├── CARS.db ← The SQLite database file (auto-created)

---

## 🛠️ Setup Instructions (Visual Studio)

### ✅ Step 1: Add SQLite Source File

1. Right-click on **Source Files** in Solution Explorer  
2. Click **Add → Existing Item**  
3. Select `sqlite3.c` and add it to the project

---

### 📦 Step 2: Install SQLite NuGet Package

To simplify SQLite integration, install the NuGet package:  
**`sqlite3_c_plus_plus` by Dawlin**

#### Installation steps:
1. Right-click on your project in **Solution Explorer**  
2. Click **Manage NuGet Packages**  
3. Go to the **Browse** tab  
4. Search for `sqlite3_c_plus_plus`  
5. Select the package by Dawlin and click **Install**

This helps manage SQLite dependencies and setup smoothly.

---

## 💻 How to Run

1. Open the project in Visual Studio  
2. Make sure `main.cpp` is set as the startup file  
3. Press **Ctrl + F5** or click **Local Windows Debugger**

You’ll see a menu like this:

Welcome To CAR-RY!!
What would you like to do?

See All Entries

Add An Entry

Delete An Entry

Update Data

Delete ALL ENTRIES

EXIT PROGRAM

Use the number keys to interact with the system.

---

## 🔄 Resetting Records

To clear all rental records at once, choose option `5` from the main menu.

---

## 📌 Notes

- The `CARS.db` file is automatically created in the same folder on first run.
- You can safely delete the database file to reset everything.
- Ensure your compiler supports C++17 or later for best compatibility.

---
