#include <iostream>
#include <string>
 #include "clData.h" 

using namespace std;

 

 
int ReadNumber(string Message) {
    int Number = 0;
    cout << Message;
    cin >> Number;
 
    while (cin.fail()) {
        cin.clear();
        cout << "Invalid Number, Please Enter a valid one: ";
        cin >> Number;
    }
    return Number;
}

// دالة لقراءة تاريخ كامل من المستخدم
clData ReadFullDate() {
    int Day = ReadNumber("Please Enter Day: ");
    int Month = ReadNumber("Please Enter Month: ");
    int Year = ReadNumber("Please Enter Year: ");
    return clData(Day, Month, Year);
}

// --- Sub-Menu for Date Arithmetic ---

void ShowArithmeticSubMenu(clData& date) {
    while (true) {
        system("cls");
        cout << "========================================\n";
        cout << "      Date Arithmetic Operations\n";
        cout << "      Current Date: " << date << "\n";
        cout << "========================================\n";
        cout << "[1] Add Days.\n";
        cout << "[2] Add Weeks.\n";
        cout << "[3] Add Months.\n";
        cout << "[4] Add Years.\n";
        cout << "[5] Add Decades.\n";
        cout << "[6] Add Centuries.\n";
        cout << "[7] Add Millennia.\n";
        cout << "----------------------------------------\n";
        cout << "[8] Subtract Days.\n";
        cout << "[9] Subtract Weeks.\n";
        cout << "[10] Subtract Months.\n";
        cout << "[11] Subtract Years.\n";
        cout << "[12] Subtract Decades.\n";
        cout << "----------------------------------------\n";
        cout << "[0] Return to Main Menu.\n";
        cout << "========================================\n";

        int choice = ReadNumber("Your Choice? ");
        int amount;

        switch (choice) {
        case 1: amount = ReadNumber("Enter number of days to add: "); date.increse_Day_N(amount); break;
        case 2: amount = ReadNumber("Enter number of weeks to add: "); date.increses_one_Week_N(amount); break;
        case 3: amount = ReadNumber("Enter number of months to add: "); date.increse_one_Monthe_N(amount); break;
        case 4: amount = ReadNumber("Enter number of years to add: "); date.increse_one_Year_N(amount); break;
        case 5: amount = ReadNumber("Enter number of decades to add: "); date.increse_Decide_N(amount); break;
        case 6: amount = ReadNumber("Enter number of centuries to add: "); date.increse_Century_N(amount); break;
        case 7: amount = ReadNumber("Enter number of millennia to add: "); date.increse_Millennium_N(amount); break;
        case 8: amount = ReadNumber("Enter number of days to subtract: "); date.Decreses_Day_N(amount); break;
        case 9: amount = ReadNumber("Enter number of weeks to subtract: "); date.Decres_Week_N(amount); break;
        case 10: amount = ReadNumber("Enter number of months to subtract: "); date.DecreseMonthe_N(amount); break;
        case 11: amount = ReadNumber("Enter number of years to subtract: "); date.Decrese_Year_N(amount); break;
        case 12: amount = ReadNumber("Enter number of decades to subtract: "); date.Decrseas_Decide_N(amount); break;
        case 0: return;
        default: cout << "Invalid Choice. Please try again.\n"; system("pause");
        }
    }
}


 

void ShowMainMenu() {
    system("cls");
    cout << "========================================\n";
    cout << "      Main Menu - Date Calculator\n";
    cout << "========================================\n";
    cout << "[1]  Print Year Calendar.\n";
    cout << "[2]  Print Month Calendar.\n";
    cout << "[3]  Check Date Properties.\n";
    cout << "[4]  Add / Subtract Time from a Date.\n";
    cout << "[5]  Calculate Difference Between Two Dates.\n";
    cout << "[6]  Compare Two Dates.\n";
    cout << "[7]  Check if a Date is within a Period.\n";
    cout << "[8]  Check if Two Periods Overlap.\n";
    cout << "[9]  Convert Number to Text.\n";
    cout << "[0]  Exit.\n";
    cout << "========================================\n";
}

// --- Main Program ---

int main() {
    clData date1, date2, date3, date4; // Create date objects to work with

    while (true) {
        ShowMainMenu();
        int choice = ReadNumber("Your Choice? ");

        switch (choice) {
        case 1: {
            int year = ReadNumber("Enter a year to display its calendar: ");
            date1.Print_Clender_of_Year(year);
            break;
        }
        case 2: {
            int year = ReadNumber("Enter a year: ");
            int month = ReadNumber("Enter a month: ");
            date1.Print_Clenader_Monthe(month, year);
            break;
        }
        case 3: {
            cout << "Enter a date to check its properties:\n";
            date1 = ReadFullDate();
            cout << "\nDate: " << date1 << endl;
            cout << "Is it the last day of the month? " << (date1.Is_Last_Day_Monthe(date1) ? "Yes" : "No") << endl;
            cout << "Is it the last month of the year? " << (date1.Is_Last_Monthe_Yesr(date1.GetMonth()) ? "Yes" : "No") << endl;
            cout << "Is it a weekend? " << (date1.Is_Weekend(date1) ? "Yes" : "No") << endl;
            cout << "Is it a business day? " << (date1.Is_Busnese_Day(date1) ? "Yes" : "No") << endl;
            cout << "\n--- Days until end of period ---\n";
            date1.Print_The_Day_Monthe_Yers_End(date1);
            break;
        }
        case 4: {
            cout << "Enter the starting date:\n";
            date1 = ReadFullDate();
            ShowArithmeticSubMenu(date1);
            break;
        }
        case 5: {
            cout << "Enter the first date:\n";
            date1 = ReadFullDate();
            cout << "Enter the second date:\n";
            date2 = ReadFullDate();
            date1.Print_Double_Day_Deffrence(date1, date2);
            break;
        }
        case 6: {
            cout << "Enter the first date:\n";
            date1 = ReadFullDate();
            cout << "Enter the second date:\n";
            date2 = ReadFullDate();
            if (date1 == date2) cout << "Result: Dates are Equal.\n";
            if (date1 < date2) cout << "Result: Date 1 is Before Date 2.\n";
            if (date1 > date2) cout << "Result: Date 1 is After Date 2.\n";
            break;
        }
        case 7: {
            cout << "Enter the period start date:\n";
            date1 = ReadFullDate();
            cout << "Enter the period end date:\n";
            date2 = ReadFullDate();
            cout << "Enter the date to check:\n";
            date3 = ReadFullDate();
            date1.Print_Is_Day1_after_Day2(date1, date2, date3);
            break;
        }
        case 8: {
            cout << "Enter Period 1 Start Date:\n";
            date1 = ReadFullDate();
            cout << "Enter Period 1 End Date:\n";
            date2 = ReadFullDate();
            cout << "Enter Period 2 Start Date:\n";
            date3 = ReadFullDate();
            cout << "Enter Period 2 End Date:\n";
            date4 = ReadFullDate();
            date1.Print_Is_Format(date1, date2, date3, date4);
            break;
        }
        case 9: {
            int num = ReadNumber("Enter a number to convert to text: ");
            cout << "Text: " << date1.Number_To_Text(num) << endl;
            break;
        }
        case 0: {
            cout << "Exiting program. Goodbye!\n";
            return 0;
        }
        default: {
            cout << "Invalid Choice. Please try again.\n";
        }
        }
        cout << "\n";
        system("pause"); 
    }

    return 0;
}

