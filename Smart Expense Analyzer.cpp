#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Expense
{
private:
    string category;
    float amount;
    int month;
    int week;
    int date;

public:
    void setExpense(string c, float a, int m, int w, int d)
    {
        category = c;
        amount = a;
        month = m;
        week = w;
        date = d;
    }

    string getCategory() { return category; }
    float getAmount() { return amount; }
    int getMonth() { return month; }
    int getWeek() { return week; }
    int getDate() { return date; }
};

class Analyzer
{
private:
    Expense e[100];
    int count;
    int mode;
    string userName;
    string fileName;
    float budget;

public:
    Analyzer()
    {
        count = 0;
        mode = 1;
        budget = 0;
    }

    void setUserName(string n)
    {
        userName = n;
        fileName = userName + ".txt";

        ofstream file(fileName.c_str(), ios::app);
        file.close();
    }

    string getMonthName(int m)
    {
        switch (m)
        {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "Invalid";
        }
    }

    void setMode()
    {
        cout << "Select Mode:\n";
        cout << "1. Monthly Analyzer\n";
        cout << "2. Weekly Analyzer\n";
        cout << "3. Everyday Analyzer\n";
        cout << "Enter choice: ";
        cin >> mode;
    }

    void addExpense()
    {
        char choice;
        float amount;
        int time = 0, catChoice, date;
        string category;

        if (mode == 1)
        {
            cout << "\nEnter Month (1-12): ";
            cin >> time;

            if (time < 1 || time > 12)
            {
                cout << "Invalid Month\n";
                return;
            }
        }
        else if (mode == 2)
        {
            cout << "\nEnter Week (1-4): ";
            cin >> time;

            if (time < 1 || time > 4)
            {
                cout << "Invalid Week\n";
                return;
            }
        }

        if (budget == 0)
        {
            cout << "Enter Budget: ";
            cin >> budget;
        }

        do
        {
            cout << "Enter Date: ";
            cin >> date;

            cout << "\nSelect Category:\n";
            cout << "1. Food\n";
            cout << "2. Travel\n";
            cout << "3. Shopping\n";
            cout << "4. Other\n";
            cout << "Enter choice: ";
            cin >> catChoice;

            switch (catChoice)
            {
            case 1: category = "Food"; break;
            case 2: category = "Travel"; break;
            case 3: category = "Shopping"; break;
            default: category = "Other";
            }

            cout << "Enter Amount: ";
            cin >> amount;

            if (mode == 1)
                e[count].setExpense(category, amount, time, 0, date);
            else if (mode == 2)
                e[count].setExpense(category, amount, 0, time, date);
            else
                e[count].setExpense(category, amount, 0, time, date);

            ofstream file(fileName.c_str(), ios::app);

            if (file.is_open())
            {
                file << "Date: " << date << " ";

                if (mode == 1)
                    file << getMonthName(time) << " ";
                else if (mode == 2)
                    file << "Week " << time << " ";
                else
                    file << "Daily ";

                file << "| Category: " << category;
                file << " | Amount: Rs." << amount << endl;

                file.close();
            }

            count++;

            cout << "Expense Added Successfully\n";
            cout << "Add More? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');

        showTotalStatus();
    }

    void showTotalStatus()
    {
        float total = 0;

        for (int i = 0; i < count; i++)
            total += e[i].getAmount();

        cout << "\nTotal Spending = Rs." << total << endl;
        cout << "Budget = Rs." << budget << endl;

        if (total > budget)
            cout << "Status: OVER BUDGET\n";
        else
            cout << "Status: WITHIN BUDGET\n";
    }

    void viewExpenses()
    {
        cout << "\n----- EXPENSE LIST -----\n";

        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << ". Date: " << e[i].getDate() << " ";

            if (mode == 1)
                cout << getMonthName(e[i].getMonth());
            else if (mode == 2)
                cout << "Week " << e[i].getWeek();
            else
                cout << "Daily";

            cout << " | " << e[i].getCategory();
            cout << " | Rs." << e[i].getAmount() << endl;
        }
    }

    void compareData()
    {
        int choice;

        cout << "\n1. Time-wise Comparison\n";
        cout << "2. Category-wise Comparison\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (mode == 1)
            {
                float monthTotal[13] = {0};
                int maxMonth = 1;

                for (int i = 0; i < count; i++)
                    monthTotal[e[i].getMonth()] += e[i].getAmount();

                for (int i = 1; i <= 12; i++)
                {
                    if (monthTotal[i] > 0)
                        cout << getMonthName(i) << " = Rs." << monthTotal[i] << endl;

                    if (monthTotal[i] > monthTotal[maxMonth])
                        maxMonth = i;
                }

                cout << "Highest Month: " << getMonthName(maxMonth)
                     << " = Rs." << monthTotal[maxMonth] << endl;
            }
            else if (mode == 2)
            {
                float weekTotal[5] = {0};
                int maxWeek = 1;

                for (int i = 0; i < count; i++)
                    weekTotal[e[i].getWeek()] += e[i].getAmount();

                for (int i = 1; i <= 4; i++)
                {
                    if (weekTotal[i] > 0)
                        cout << "Week " << i << " = Rs." << weekTotal[i] << endl;

                    if (weekTotal[i] > weekTotal[maxWeek])
                        maxWeek = i;
                }

                cout << "Highest Week: Week " << maxWeek
                     << " = Rs." << weekTotal[maxWeek] << endl;
            }
            else
            {
                cout << "Daily mode uses total budget tracking.\n";
                showTotalStatus();
            }
        }
        else if (choice == 2)
        {
            float food = 0, travel = 0, shopping = 0, other = 0;

            for (int i = 0; i < count; i++)
            {
                string c = e[i].getCategory();
                float a = e[i].getAmount();

                if (c == "Food")
                    food += a;
                else if (c == "Travel")
                    travel += a;
                else if (c == "Shopping")
                    shopping += a;
                else
                    other += a;
            }

            cout << "Food = Rs." << food << endl;
            cout << "Travel = Rs." << travel << endl;
            cout << "Shopping = Rs." << shopping << endl;
            cout << "Other = Rs." << other << endl;
        }
    }
};

int main()
{
    Analyzer a;
    int choice;
    string name;

    cout << "Enter your name: ";
    cin >> name;

    a.setUserName(name);

    cout << "\nWelcome " << name << " to Smart Expense Analyzer\n";

    a.setMode();

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Compare Data\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: a.addExpense(); break;
        case 2: a.viewExpenses(); break;
        case 3: a.compareData(); break;
        case 4: cout << "Thank you for using Smart Expense Analyzer\n"; break;
        default: cout << "Invalid Choice\n";
        }

    } while (choice != 4);

    return 0;
}
