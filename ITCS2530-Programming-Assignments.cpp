// Week 04 Programming Assignment: Adding while, for, and do-while loops to the code
// 6/10/26
// ITCS 2530 Prof. Koss
// Aisha Ehsan

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

//use a namespace so don't have to keep retyping std into the code
using namespace std;

//everything goes in main for c++
int main()
{
    //variables to store the user input
    string favoriteProject;
    string favoriteYarnColor;
    int hoursPerWeek;
    double yarnCostPerSkein;
    //some new variables
    int hookSize;
    int choice;
    string myMessage;

    //welcome banner at the beginning
    cout << "========================================" << endl;
    cout << "      WELCOME TO MY CROCHET PROGRAM      " << endl;
    cout << "========================================" << endl;
    cout << endl;

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

    // One more input validation for the price since price can't be negative
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

    // calculate monthly crochet hours and also the price of each week's skein to determine the budget
    int monthlyHours = hoursPerWeek * 4;
    double monthlyYarnBudget = yarnCostPerSkein * 4;

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

    // Open an output file here and close it at the end
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

    do
    {
        // Week 03 menu
        cout << "\n========== CROCHET MENU ==========" << endl;
        cout << "1. Choose a new project based on the difficulty level." << endl;
        cout << "2. View Crochet Summary based on the questions above." << endl;
        cout << "3. View My Crochet Message" << endl;
        cout << "4. See What You've Crocheted This Month." << endl;
        cout << "5. Quit Program." << endl;
        cout << "Enter choice: ";
        cin >> choice;


        // Week 03 switch statement
        switch (choice)
        {
        case 1:
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

        case 2:
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

        case 3:
            cout << "\n========== MY CROCHET MESSAGE ==========" << endl;
            cout << myMessage << endl;
            break;

        case 4:
        {
            //use a for loop to ask the user how many projects they crocheted and what they crocheted in the month
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
        case 5:
            cout << "Thanks for using my Crochet Program!" << endl;
            break;
            //kept default so it doesn't seem like the program randomly ended    
        default:
            cout << "\nSorry! That menu option is invalid." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}