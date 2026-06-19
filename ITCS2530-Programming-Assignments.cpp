// Week 05 Programming Assignment: Changing the console color and adding user-defined functions
// 6/18/26
// ITCS 2530 Prof. Koss
// Aisha Ehsan

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

//use a namespace so don't have to keep retyping std into the code
using namespace std;

//organizing the code into functions for week 05
void setPinkColor();
void displayBanner();
void collectInput(string& favoriteProject, string& favoriteYarnColor,
    int& hoursPerWeek, double& yarnCostPerSkein, int& hookSize);
int calculateMonthlyHours(int hoursPerWeek);
double calculateMonthlyYarnBudget(double yarnCostPerSkein);
string createMessage(int hoursPerWeek, double yarnCostPerSkein, int hookSize);
void saveReport(string favoriteProject, string favoriteYarnColor,
    int hoursPerWeek, int monthlyHours, double yarnCostPerSkein,
    double monthlyYarnBudget, int hookSize, string myMessage);
void displayMenu();

//main function
int main()
{
    //declaring variables (for user input)
    string favoriteProject;
    string favoriteYarnColor;
    int hoursPerWeek;
    double yarnCostPerSkein;
    int hookSize;
    int choice;
    string myMessage;

    setPinkColor();

    displayBanner();

    collectInput(favoriteProject, favoriteYarnColor, hoursPerWeek,
        yarnCostPerSkein, hookSize);

    // calculate monthly crochet hours and also the price of each week's skein to determine the budget
    int monthlyHours = calculateMonthlyHours(hoursPerWeek);
    double monthlyYarnBudget = calculateMonthlyYarnBudget(yarnCostPerSkein);

    myMessage = createMessage(hoursPerWeek, yarnCostPerSkein, hookSize);

    saveReport(favoriteProject, favoriteYarnColor, hoursPerWeek,
        monthlyHours, yarnCostPerSkein, monthlyYarnBudget, hookSize, myMessage);
    
    do //do-while loop includes the switch statement which has 5 cases as options for the user to choose from
    {
        displayMenu();

        cout << "Enter choice: ";
        cin >> choice;

        // Week 03 switch statement
        switch (choice)
        {
        case 1: //gives the user project ideas they can crochet
            cout << "\n===== PROJECT IDEAS =====" << endl;

            cout << "\nEasy Projects:" << endl;
            cout << "<3 Heart" << endl;
            cout << "<3 Simple Flower" << endl;
            cout << "<3 Headband" << endl;

            cout << "\nIntermediate Projects:" << endl;
            cout << "<3 Beanie" << endl;
            cout << "<3 Tote Bag" << endl;
            cout << "<3 Baby Blanket" << endl;

            cout << "\nAdvanced Projects:" << endl;
            cout << "<3 Amigurumi Animal" << endl;
            cout << "<3 Sweater" << endl;
            cout << "<3 Pants" << endl;
            break;

        case 2: // will print a summary based on the questions the user was initially prompted to answer
            cout << endl;
            cout << "========== YOUR CROCHET SUMMARY ==========" << endl;

            cout << left;
            cout << setw(25) << "Favorite Project:" << favoriteProject << endl;
            cout << setw(25) << "Favorite Yarn Color:" << favoriteYarnColor << endl;
            cout << setw(25) << "Hours Per Week:" << hoursPerWeek << endl;
            cout << setw(25) << "Monthly Hours:" << monthlyHours << endl;
            cout << setw(25) << "Cost Per Skein:" << "$"
                << fixed << setprecision(2) << yarnCostPerSkein << endl;
            cout << setw(25) << "Monthly Yarn Budget:" << "$"
                << monthlyYarnBudget << endl;
            cout << setw(25) << "Hook Size:" << hookSize << endl;
            cout << setw(25) << "My Message:" << myMessage << endl;
            break;

        case 3: //will print a message from me to the user
            cout << "\n========== MY CROCHET MESSAGE ==========" << endl;
            cout << myMessage << endl;
            break;

        case 4: //use a for loop to ask the user how many projects they crocheted and what they crocheted in the month
        {
            int numProjects; //how many times the loop will run
            string projectName; //stores each input temporarily

            cout << "\nHow many crochet projects have you completed this month? ";
            cin >> numProjects;
            cin.ignore();

            for (int i = 1; i <= numProjects; i++) //i is the counter that tracks the current loop number
            {
                cout << "Enter project #" << i << ": ";
                getline(cin, projectName);

                cout << "Project #" << i << ": " << projectName << endl;
            }
            break;
        }
        case 5: //this option allows the user to quit my program
            cout << "Thanks for using my Crochet Program!" << endl;
            break;
                
        default: //included so it doesn't seem like the program randomly ended
            cout << "\nSorry! That menu option is invalid." << endl;
            break;
        }
    } while (choice != 5);

    return 0;    
}

//changing the console text to pink
void setPinkColor()
{
    cout << "\033[95m";
}

void displayBanner()
{        
    //welcome banner at the beginning
    cout << "========================================" << endl;
    cout << "      WELCOME TO MY CROCHET PROGRAM      " << endl;
    cout << "========================================" << endl;
    cout << endl;
}
//this function asks the user questions and fills in the original project, color, hours, cost, and hook size variables (pass by reference)
void collectInput(string& favoriteProject, string& favoriteYarnColor,
    int& hoursPerWeek, double& yarnCostPerSkein, int& hookSize)
{
    //use getline to get the full line including whitespace
    cout << "What is your favorite thing to crochet? ";
    getline(cin, favoriteProject);

    cout << "What is your favorite yarn color? ";
    getline(cin, favoriteYarnColor);

    cout << "How many hours do you crochet each week? ";
    cin >> hoursPerWeek;

    // Input validation using a while loop so the input is correct
    while (hoursPerWeek < 0)
    {
        cout << "Invalid input. Weekly hours cannot be negative.\n";
        cout << "Enter hours again: ";
        cin >> hoursPerWeek;
    }

    cout << "What is the average cost of one skein of yarn? $";
    cin >> yarnCostPerSkein;

    // input validation since the price can't be negative
    if (yarnCostPerSkein < 0)
    {
        cout << "Invalid input. Cost cannot be negative." << endl;
        yarnCostPerSkein = 0;
    }
    //ask the user what size crochet hook they use for the switch
    cout << "What crochet hook size do you usually use (2-8)? ";
    cin >> hookSize;

    if (hookSize < 2 || hookSize > 8)
    {
        cout << "Invalid hook size. Setting hook size to 4." << endl;
        hookSize = 4;
    }
}
int calculateMonthlyHours(int hoursPerWeek)
{
    return hoursPerWeek * 4;
}

double calculateMonthlyYarnBudget(double yarnCostPerSkein)
{
    return yarnCostPerSkein * 4;
}
//function to determine my message to the user based on their input
string createMessage(int hoursPerWeek, double yarnCostPerSkein, int hookSize)
{
    string myMessage;
    // First Compound if/else using 'and' about hours and cost 
    if (hoursPerWeek >= 5 && yarnCostPerSkein <= 10)
    {
        myMessage = "You are a dedicated crocheter who stays within budget!";
    }
    else if (hoursPerWeek < 5 && yarnCostPerSkein > 10)
    {
        myMessage = "You crochet occasionally and enjoy premium yarn.";
    }
    else
    {
        myMessage = "You have a balanced crochet routine.";
    }

    // My second Compound if/else for the third menu option about hook size
    if (hookSize >= 2 && hookSize <= 4)
    {
        myMessage += " Smaller hooks are great for detailed projects.";
    }
    else if (hookSize >= 5 && hookSize <= 8)
    {
        myMessage += " Larger hooks are great for faster, chunkier projects.";
    }
    return myMessage;
} 
//this function receives all the crochet information so it can save it to report.txt (it gets copies of the values from main)
void saveReport(string favoriteProject, string favoriteYarnColor,
    int hoursPerWeek, int monthlyHours, double yarnCostPerSkein,
    double monthlyYarnBudget, int hookSize, string myMessage)
{
    // Open an output file and close it at the end
    ofstream reportFile("report.txt");

    // Save report to file
    reportFile << "========== YOUR CROCHET SUMMARY ==========" << endl;

    reportFile << left;
    reportFile << setw(25) << "Favorite Project:" << favoriteProject << endl;
    reportFile << setw(25) << "Favorite Yarn Color:" << favoriteYarnColor << endl;
    reportFile << setw(25) << "Hours Per Week:" << hoursPerWeek << endl;
    reportFile << setw(25) << "Monthly Hours:" << monthlyHours << endl;
    reportFile << setw(25) << "Cost Per Skein:" << "$" << fixed
        << setprecision(2) << yarnCostPerSkein << endl;
    reportFile << setw(25) << "Monthly Yarn Budget:" << "$"
        << monthlyYarnBudget << endl;
    reportFile << setw(25) << "Hook Size:" << hookSize << endl;
    reportFile << setw(25) << "My Message:" << myMessage << endl;
    reportFile.close();
}

void displayMenu()
{
        cout << "\n========== CROCHET MENU ==========" << endl;
        cout << "1. Choose a new project based on the difficulty level." << endl;
        cout << "2. View Crochet Summary based on the questions above." << endl;
        cout << "3. View My Crochet Message" << endl;
        cout << "4. See What You've Crocheted This Month." << endl;
        cout << "5. Quit Program." << endl;
}