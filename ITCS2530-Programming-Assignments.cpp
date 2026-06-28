// Week 06 Programming Assignment: Collaborating on Crochet Upgrades
// 6/27/26
// ITCS 2530 Prof. Koss
// Rahima - Upgrading Aisha's Repository

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h> // Added for robust native Windows console color styling

using namespace std;

// ============================================================================
// WEEK 06 REQUIREMENT: SIMPLE ENUM 
// ============================================================================
enum CrochetLevel { EASY, MEDIUM, HARD };

// GLOBAL CONSTANTS (Eliminates Magic Numbers)
const int COLOR_PINK = 13;     // Light magenta/pink in Windows API
const int COLOR_DEFAULT = 7;    // Normal white text
const int COLOR_WARNING = 12;    // Red error text

const int MENU_MIN = 1;
const int MENU_MAX = 5;
const int MENU_EXIT = 5;
const int MAX_PROJECTS = 10;   // Array upper boundary limit

// REFACTORED FUNCTION PROTOTYPES
void setPinkColor();
void setWarningColor();
void displayBanner();
void collectInput(string& favoriteProject, string& favoriteYarnColor,
    int& hoursPerWeek, double& yarnCostPerSkein, int& hookSize);
int calculateMonthlyHours(int hoursPerWeek);
double calculateMonthlyYarnBudget(double yarnCostPerSkein);
string createMessage(int hoursPerWeek, double yarnCostPerSkein, int hookSize);

// NEW FUNCTIONS IMPLEMENTING WEEK 06 ARRAYS & ENUMS
void determineLevel(CrochetLevel& lvl, int hoursPerWeek, int hookSize);
void saveReport(string favoriteProject, string favoriteYarnColor,
    int hoursPerWeek, int monthlyHours, double yarnCostPerSkein,
    double monthlyYarnBudget, int hookSize, string myMessage, CrochetLevel lvl);
void displayMenu();

// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main()
{
    // Aisha's original variables
    string favoriteProject;
    string favoriteYarnColor;
    int hoursPerWeek = 0;
    double yarnCostPerSkein = 0.0;
    int hookSize = 4;
    int choice = 0;
    string myMessage;

    // WEEK 06 REQUIREMENT: Arrays matching her exact naming style
    string myProjectsList[MAX_PROJECTS];
    int projectCount = 0;

    CrochetLevel myLevel = EASY;

    setPinkColor();
    displayBanner();

    collectInput(favoriteProject, favoriteYarnColor, hoursPerWeek, yarnCostPerSkein, hookSize);

    int monthlyHours = calculateMonthlyHours(hoursPerWeek);
    double monthlyYarnBudget = calculateMonthlyYarnBudget(yarnCostPerSkein);
    myMessage = createMessage(hoursPerWeek, yarnCostPerSkein, hookSize);

    // Simple Enum evaluation based on her inputs
    determineLevel(myLevel, hoursPerWeek, hookSize);

    saveReport(favoriteProject, favoriteYarnColor, hoursPerWeek,
        monthlyHours, yarnCostPerSkein, monthlyYarnBudget, hookSize, myMessage, myLevel);

    do
    {
        setPinkColor();
        displayMenu();

        cout << "Enter choice: ";
        cin >> choice;

        // Repaired stream state error capture check
        while (cin.fail() || choice < MENU_MIN || choice > MENU_MAX) {
            setWarningColor();
            cout << "Invalid choice! Enter a numeric value between 1 and 5: ";
            cin.clear();
            cin.ignore(1000, '\n');
            setPinkColor();
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            cout << "\n===== PROJECT IDEAS =====" << endl;
            cout << "\nEasy Projects:\n<3 Heart\n<3 Simple Flower\n<3 Headband" << endl;
            cout << "\nIntermediate Projects:\n<3 Beanie\n<3 Tote Bag\n<3 Baby Blanket" << endl;
            cout << "\nAdvanced Projects:\n<3 Amigurumi Animal\n<3 Sweater\n<3 Pants" << endl;
            break;

        case 2:
            cout << endl;
            cout << "========== YOUR CROCHET SUMMARY ==========" << endl;
            cout << left;
            cout << setw(25) << "Favorite Project:" << favoriteProject << endl;
            cout << setw(25) << "Favorite Yarn Color:" << favoriteYarnColor << endl;
            cout << setw(25) << "Hours Per Week:" << hoursPerWeek << endl;
            cout << setw(25) << "Monthly Hours:" << monthlyHours << endl;
            cout << setw(25) << "Cost Per Skein:" << "$" << fixed << setprecision(2) << yarnCostPerSkein << endl;
            cout << setw(25) << "Monthly Yarn Budget:" << "$" << monthlyYarnBudget << endl;
            cout << setw(25) << "Hook Size:" << hookSize << "mm" << endl;

            // WEEK 06 REQUIREMENT: Using Enum within a decision tree
            cout << setw(25) << "Estimated Skill Level:";
            if (myLevel == EASY) cout << "Beginner Track" << endl;
            else if (myLevel == MEDIUM) cout << "Intermediate Track" << endl;
            else cout << "Advanced Track" << endl;

            cout << setw(25) << "My Message:" << myMessage << endl;
            break;

        case 3:
            cout << "\n========== MY CROCHET MESSAGE ==========" << endl;
            cout << myMessage << endl;
            break;

        case 4:
        {
            // WEEK 06 REQUIREMENT: Array manipulation matching her Case 4 style
            cout << "\nHow many crochet projects have you completed this month? (Max " << MAX_PROJECTS << "): ";
            cin >> projectCount;

            while (cin.fail() || projectCount < 0 || projectCount > MAX_PROJECTS) {
                setWarningColor();
                cout << "Invalid count. Enter a value between 0 and " << MAX_PROJECTS << ": ";
                cin.clear();
                cin.ignore(1000, '\n');
                setPinkColor();
                cin >> projectCount;
            }
            cin.ignore();

            for (int i = 0; i < projectCount; i++)
            {
                cout << "Enter name for project #" << (i + 1) << ": ";
                getline(cin, myProjectsList[i]);
            }

            cout << "\n--- Current Monthly Inventory Records ---" << endl;
            for (int i = 0; i < projectCount; i++) {
                cout << "Project [" << i << "]: " << myProjectsList[i] << endl;
            }
            break;
        }
        case 5:
            cout << "Thanks for using my Crochet Program!" << endl;
            break;
        }
    } while (choice != MENU_EXIT);

    // Clean reset back to normal before closing
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, COLOR_DEFAULT);
    return 0;
}

// ============================================================================
// SYSTEM UTILITIES AND LOGIC MODULES
// ============================================================================

void setPinkColor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, COLOR_PINK);
}

void setWarningColor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, COLOR_WARNING);
}

void displayBanner()
{
    cout << "========================================" << endl;
    cout << "      WELCOME TO MY CROCHET PROGRAM      " << endl;
    cout << "========================================" << endl;
    cout << endl;
}

void collectInput(string& favoriteProject, string& favoriteYarnColor,
    int& hoursPerWeek, double& yarnCostPerSkein, int& hookSize)
{
    cout << "What is your favorite thing to crochet? ";
    getline(cin, favoriteProject);

    cout << "What is your favorite yarn color? ";
    getline(cin, favoriteYarnColor);

    cout << "How many hours do you crochet each week? ";
    cin >> hoursPerWeek;
    while (cin.fail() || hoursPerWeek < 0) {
        setWarningColor();
        cout << "Invalid input. Enter positive numeric hours: ";
        cin.clear();
        cin.ignore(1000, '\n');
        setPinkColor();
        cin >> hoursPerWeek;
    }

    cout << "What is the average cost of one skein of yarn? $";
    cin >> yarnCostPerSkein;
    while (cin.fail() || yarnCostPerSkein < 0.0) {
        setWarningColor();
        cout << "Invalid input. Enter a positive numeric price: $";
        cin.clear();
        cin.ignore(1000, '\n');
        setPinkColor();
        cin >> yarnCostPerSkein;
    }

    cout << "What crochet hook size do you usually use (2-8)? ";
    cin >> hookSize;
    while (cin.fail() || hookSize < 2 || hookSize > 8) {
        setWarningColor();
        cout << "Invalid hook size. Enter an integer between 2 and 8: ";
        cin.clear();
        cin.ignore(1000, '\n');
        setPinkColor();
        cin >> hookSize;
    }
}

int calculateMonthlyHours(int hoursPerWeek) { return hoursPerWeek * 4; }
double calculateMonthlyYarnBudget(double yarnCostPerSkein) { return yarnCostPerSkein * 4; }

string createMessage(int hoursPerWeek, double yarnCostPerSkein, int hookSize)
{
    string myMessage;
    if (hoursPerWeek >= 5 && yarnCostPerSkein <= 10.0) {
        myMessage = "You are a dedicated crocheter who stays within budget!";
    }
    else if (hoursPerWeek < 5 && yarnCostPerSkein > 10.0) {
        myMessage = "You crochet occasionally and enjoy premium yarn.";
    }
    else {
        myMessage = "You have a balanced crochet routine.";
    }

    if (hookSize >= 2 && hookSize <= 4) {
        myMessage += " Smaller hooks are great for detailed projects.";
    }
    else if (hookSize >= 5 && hookSize <= 8) {
        myMessage += " Larger hooks are great for faster, chunkier projects.";
    }
    return myMessage;
}

// ENUM STATE ASSIGNMENT CRITERIA
void determineLevel(CrochetLevel& lvl, int hoursPerWeek, int hookSize) {
    if (hoursPerWeek >= 10 && hookSize <= 3) {
        lvl = HARD;
    }
    else if (hoursPerWeek >= 5) {
        lvl = MEDIUM;
    }
    else {
        lvl = EASY;
    }
}

void saveReport(string favoriteProject, string favoriteYarnColor,
    int hoursPerWeek, int monthlyHours, double yarnCostPerSkein,
    double monthlyYarnBudget, int hookSize, string myMessage, CrochetLevel lvl)
{
    ofstream reportFile("report.txt");
    if (!reportFile.is_open()) return;

    reportFile << "========== YOUR CROCHET SUMMARY ==========" << endl;
    reportFile << left;
    reportFile << setw(25) << "Favorite Project:" << favoriteProject << endl;
    reportFile << setw(25) << "Favorite Yarn Color:" << favoriteYarnColor << endl;
    reportFile << setw(25) << "Hours Per Week:" << hoursPerWeek << endl;
    reportFile << setw(25) << "Monthly Hours:" << monthlyHours << endl;
    reportFile << setw(25) << "Cost Per Skein:" << "$" << fixed << setprecision(2) << yarnCostPerSkein << endl;
    reportFile << setw(25) << "Monthly Yarn Budget:" << "$" << monthlyYarnBudget << endl;
    reportFile << setw(25) << "Hook Size:" << hookSize << "mm" << endl;

    reportFile << setw(25) << "Project Level Assessment:";
    if (lvl == EASY) reportFile << "Easy" << endl;
    else if (lvl == MEDIUM) reportFile << "Medium" << endl;
    else reportFile << "Hard" << endl;

    reportFile << setw(25) << "My Message:" << myMessage << endl;
    reportFile.close();
}

void displayMenu()
{
    cout << "\n========== CROCHET MENU ==========" << endl;
    cout << "1. Choose a new project based on the difficulty level." << endl;
    cout << "2. View Crochet Summary based on the questions above." << endl;
    cout << "3. View My Crochet Message" << endl;
    cout << "4. See What You've Crocheted This Month (Upgraded Array Log)." << endl;
    cout << "5. Quit Program." << endl;
}