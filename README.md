# Smart Expense Analyzer 💰📊

Smart Expense Analyzer is a **C++ console-based project** designed to help users track and analyze their daily expenses in a simple and organized way. It allows users to record spending, compare expenses, and monitor budgets using different analysis modes.

---

## 🚀 Features

### 🔹 User Profile
- User enters their name at startup.
- Personal expense data is saved in a text file using the username.

### 🔹 Three Analysis Modes
Choose how you want to track your expenses:

1. **Monthly Analyzer**
   - Add expenses month-wise.
   - Compare spending between months.

2. **Weekly Analyzer**
   - Add expenses week-wise.
   - Compare spending between weeks.

3. **Everyday Analyzer**
   - Record daily expenses.
   - Track overall budget status.

### 🔹 Expense Categories
Users can add expenses under categories such as:

- Food 🍔  
- Travel 🚗  
- Shopping 🛍️  
- Other 📌  

### 🔹 Budget Tracking
- Set your budget once.
- Instantly shows:
  - **Within Budget**
  - **Over Budget**

### 🔹 Data Comparison
Compare expenses based on:

- **Time-wise Comparison**
  - Highest spending month/week

- **Category-wise Comparison**
  - Food total
  - Travel total
  - Shopping total
  - Other total

### 🔹 File Handling
- Saves all expenses into a `.txt` file.
- Each user gets separate data storage.

---

## 🛠️ Technologies Used

- **C++**
- **Object-Oriented Programming (OOP)**
- **File Handling**
- **Arrays**
- **Functions**
- **Switch Case**
- **Loops**

---

## 📂 Project Structure

- `Expense Class`
  - Stores category, amount, date, month, week

- `Analyzer Class`
  - Handles:
    - Adding expenses
    - Viewing expenses
    - Comparing data
    - Budget tracking

---

## ▶️ How to Run

1. Open the project in any C++ compiler (CodeBlocks / Dev C++ / VS Code / Turbo C++)  
2. Compile the program  
3. Run the executable file  
4. Enter your name and start managing expenses  

---

## 📌 Sample Menu

```text
1. Add Expense
2. View Expenses
3. Compare Data
4. Exit
