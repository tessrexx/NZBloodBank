// NZ BLOOD BANK - NOTES.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Chosen name is "AOTEAROA BLOOD"
// Testing Functions/Structures/General Shit
// Notes only

//C++ Libraries we may need
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//Structure containing information required to register a new donor
struct New_Donor
{
    char first_name[10];
    char last_name[20];
    int date_of_birth;
    char gender; // List M/F/O ??
    char nationality[20];
    char ethnicity[20];
    char health_conditions[20];
    char blood_group = NULL;
    double contact_number;
    char email_address[30];
    char physical_address[75];
    int last_donation = 00 / 00 / 00;
};

//Structure containing information required to register a new recipient
struct New_Recipient
{
    char name[20];
    char email_address[30];
    char physical_address[75];
    double contact_number;
    int registration_status; // <----- Recipients validation status (valid registration to access blood) = Unsure what this is but listed in brief
};

//Functions (some will require pointers at some point)
void introduction_menu();
void donor_login();
void donor_registration();
void donor_menu();
void book_donation();
void update_information();
void recipient_login();
void recipient_registration();
void recipient_menu();
void admin_login();
void admin_menu();
void line();

int main()
{
    introduction_menu();

    return 0;
}

//Function to Display Introduction & Menu
void introduction_menu()
{
    int option;

    cout << endl << "\tAOTEAROA BLOOD";
    line();

    do
    {
        //Main Menu Display
        cout << " Main Menu";
        line();
        cout << " 1. Information & Contact Us" << endl;
        cout << " 2. Existing Donor" << endl;
        cout << " 3. New Donor" << endl;
        cout << " 4. Existing Recipient" << endl;
        cout << " 5. New Recipient" << endl;
        cout << " 6. Admin" << endl;
        cout << " 7. Exit..." << endl;

        cout << endl << " Enter your option: "; //User Option Input
        cin >> option;
        cin.ignore(); //Clears input buffer
        cout << endl;

        switch (option)
        {

        case 1: // Information & Contact Us
        {
            system("cls"); //Clears console screen
            cout << endl << "\tAOTEAROA BLOOD";

            line();
            cout << " About Aotearoa Blood";
            line();
            cout << " Aotearoa Blood was founded in 1998 under the New Zealand Public Health and Disability Act 2000" << endl;
            cout << " and is an appointed entity under section 63 of the Human Tissue Act 2008," << endl;
            cout << " with primary responsibility for blood and controlled human substances in New Zealand." << endl;
            cout << " Prior to this, a variety of regional blood services operated out of hospitals." << endl;

            line();
            cout << " Contact us: ";
            line();
            cout << " Phone: 0800 000 000" << endl;
            cout << " Email: aotearoa@blood.co.nz" << endl;
            line();
            break;
        }
        case 2: // Existing Donor
        {
            donor_login();
            break;
        }
        case 3: // New Donor
        {
            donor_registration();
            break;
        }
        case 4: // Existing Recipient
        {
            recipient_login();
            break;
        }
        case 5: // New Recipient
        {
            admin_login();
            break;
        }
        case 6: // Admin
        {
            admin_login();
            break;
        }
        default: exit(0); //Exit Console
        }
    } while (option < 7);
}

//Existing donor login (MAY COMBINE WITH DONOR MENU)
void donor_login()
{
    system("cls"); //Clears console screen
    cout << endl << "\tAOTEAROA BLOOD";
    line();

    cout << " Donor Login" << endl << endl;
    cout << " Username: ";
    /* cin >> ************* <--- Will need to insert something to check records */
    cout << endl;
    cout << " Password: ";
    /* cin >> ************* <--- Will need to insert something to check records */
    cout << endl;

    /* if (username || password != file)
      {
       Username or Password incorrect.
       Please try again.
       attempt++ (to count attempts)
      }
      else
      {
       donor_menu();
      }
    */

    line();
}

//New donor registration 
void donor_registration()
{

}

//Function to display Donor Menu (MAY COMBINE WITH DONOR lOGIN)
void donor_menu()
{
    system("cls"); //Clears console screen
    cout << "\tAOTEAROA BLOOD";
    line();

    cout << "Welcome " << endl; /*insert name attached to login*/
    line();

    int option;

    do
    {
        //Main Menu Display
        cout << " Donor Menu";
        line();
        cout << " 1. Procedure to Donate Blood" << endl;
        cout << " 2. Benefits of Blood Donation" << endl;
        cout << " 3. Book Donation Appointment" << endl;
        cout << " 4. Manage/Update Information" << endl;
        cout << " 5. Exit..." << endl;

        cout << endl << " Enter your option: "; //User Option Input
        cin >> option;
        cin.ignore(); //Clears input buffer
        cout << endl;

        switch (option)
        {

        case 1: // Procedure to Donate Blood
        {
            system("cls"); //Clears console screen
            cout << endl << "\tAOTEAROA BLOOD";
            line();
            cout << " Procedure to Donate Blood";
            line();

            cout << " 1) Check-in at reception with your ID & complete a provided questionnaire." << endl;
            cout << "    Once you have completed your questionnaire, you will have a confidential interview with a NZBS nurse or" << endl;
            cout << "    donor technician. They will also check your haemoglobin level using a finger prick test." << endl;
            cout << "    This is a great opportunity for you to discuss the donation process and ask any questions you may have." << endl << endl;
            cout << " 2) Once the forms are completed, you will be seated and your arm will be cleaned at the" << endl;
            cout << "    venepuncture site (on the inside of the elbow) and a sterile, single-use needle will be inserted." << endl;
            cout << "    There may be a moment of discomfort as the needle goes in." << endl << endl;
            cout << " 3) A blood donation can take up to 60 minutes (includes registration, donation and recovery)." << endl;
            cout << "    The blood is collected in a sterile bag, and time on the bed can take about 5 to 10 minutes." << endl;
            cout << "    A unit of blood (around 470 ml) will be collected. The needle is then removed and a bandage is applied." << endl << endl;
            cout << " 4) After donating blood, you will be asked to rest on the chair for around 5 to 10 minutes. When you're ready, " << endl;
            cout << "    you will be invited to have refreshments in the recovery area. We like to keep an eye on you for another" << endl;
            cout << "    10-15 minutes to make sure that you feel OK before leaving." << endl;
            break;
        }
        case 2: // Benefits of Blood Donation
        {
            system("cls"); //Clears console screen
            cout << "\tAOTEAROA BLOOD";
            line();
            cout << " Benefits of Blood Donation";
            line();

            cout << " • One blood donation can save up to 3 lives." << endl;
            cout << " • Join an extraordinary group of lifesavers." << endl;
            cout << " • Donating regularly ensures that a safe and plentiful supply " << endl;
            cout << "   of blood is available wheneverand wherever it is needed. " << endl;
            cout << " • Pay it forward. One day whanau, friends or even you may need it." << endl;
            cout << " • Less than 3% of people in New Zealand are blood donors." << endl;
            break;
        }
        case 3: // Book Donation Appointment
        {
            book_donation();
            break;
        }
        case 4: // Manage/Update Information
        {
            update_information();
            break;
        }
        default: exit(0); //Exit Console
        }
    } while (option < 5);
}

//Function for donors to book donation
void book_donation()
{

}

//Function for donors to update their information
void update_information()
{
    system("cls"); //Clears console screen

    int option;

    cout << endl << "\tAOTEAROA BLOOD";
    line();

    do
    {
        //Main Menu Display
        cout << " Manage/Update Information";
        line();
        cout << " 1. Contact Information" << endl;
        cout << " 2. Email Address" << endl;
        cout << " 3. Physical Address" << endl;
        cout << " 4. Health Conditions" << endl;
        cout << " 5. Donation Appointment" << endl;
        cout << " 6. Exit..." << endl;

        cout << endl << " Enter your option: "; //User Option Input
        cin >> option;
        cin.ignore(); //Clears input buffer
        cout << endl;

        switch (option)
        {

        case 1: // Contact Information
        {
            /* More info needed here */
            break;
        }
        case 2: // Email Address
        {
            /* More info needed here */
            break;
        }
        case 3: // Physical Address
        {
            /* More info needed here */
            break;
        }
        case 4: // Health Conditions
        {
            /* More info needed here */
            break;
        }
        case 5: // Donation Appointment
        {
            /* More info needed here */
            break;
        }
        default: exit(0); //Exit Console
        }
    } while (option < 6);
}

//Existing recipient login (MAY COMBINE WITH RECIPIENT MENU)
void recipient_login()
{
    system("cls"); //Clears console screen
    cout << endl << "\tAOTEAROA BLOOD";
    line();

    cout << " Recipient Login" << endl << endl;
    cout << " Username: ";
    /* cin >> ************* <--- Will need to insert something to check records */
    cout << endl;
    cout << " Password: ";
    /* cin >> ************* <--- Will need to insert something to check records */
    cout << endl;

    /* if (username || password != file)
     {
      Username or Password incorrect.
      Please try again.
      attempt++ (to count attempts)
     }
     else
     {
      recipient_menu();
     }
    */

    line();
}

//New recipient registration
void recipient_registration()
{

}

//Function to display Recipient Menu (MAY COMBINE WITH RECIPIENT LOGIN)
void recipient_menu()
{
    system("cls"); //Clears console screen
    cout << endl << "\tAOTEAROA BLOOD";
    line();

    cout << "Welcome " << endl; /*insert name attached to login*/
    line();

    int option;

    do
    {
        //Main Menu Display
        cout << " Recipient Menu";
        line();
        cout << " Access Donor Information via: " << endl;
        cout << " 1. Full Name" << endl;
        cout << " 2. Blood Group" << endl;
        cout << " 3. Location" << endl;
        cout << " 4. Exit..." << endl;

        cout << endl << " Enter your option: "; //User Option Input
        cin >> option;
        cin.ignore(); //Clears input buffer
        cout << endl;

        switch (option)
        {

        case 1: // Full Name
        {
            /* More info needed here */
            break;
        }
        case 2: // Blood Group
        {
            /* More info needed here */
            break;
        }
        case 3: // Location
        {
            /* More info needed here */
            break;
        }
        default: exit(0); //Exit Console
        }
    } while (option < 4);
}


//Fixed admin login (MAY COMBINE WITH ADMIN MENU)
void admin_login()
{
    system("cls"); //Clears console screen
    cout << "\tAOTEAROA BLOOD";
    line();

    cout << " Admin Login" << endl << endl;
    cout << " Username: ";
    /* cin >> ************* <--- Will need to insert something to check records */
    cout << endl;
    cout << " Password: ";
    /* cin >> ************* <--- Will need to insert something to check records */
    cout << endl;

    /* if (username || password != file)
     {
      Username or Password incorrect.
      Please try again.
      attempt++ (to count attempts)
     }
     else
     {
      admin_menu();
     }
    */

    line();
}

//Function to display Admin Menu (MAY COMBINE WITH ADMIN LOGIN)
void admin_menu()
{
    system("cls"); //Clears console screen
    cout << endl << "\tAOTEAROA BLOOD";
    line();

    cout << "Welcome " << endl; /*insert name attached to login*/
    line();

    int option;

    do
    {
        //Main Menu Display
        cout << " Admin Menu";
        line();
        cout << " 1. View Recipient Information" << endl;
        cout << " 2. View Donor Information" << endl;
        cout << " 3. Update Donor's Blood Report" << endl;
        cout << " 4. Donors Report" << endl;
        cout << " 5. Blood Group Report" << endl;
        cout << " 6. Location Report" << endl;
        cout << " 7. Recipient Report" << endl;
        cout << " 8. Exit..." << endl;

        cout << endl << " Enter your option: "; //User Option Input
        cin >> option;
        cin.ignore(); //Clears input buffer
        cout << endl;

        switch (option)
        {

        case 1: // View Recipient Information
        {
            /* More info needed here */
            break;
        }
        case 2: // View Donor Information
        {
            /* More info needed here */
            break;
        }
        case 3: // Update Donor's Blood Report
        {
            /* More info needed here */
            break;
        }
        case 4: // Donors Report
        {
            /* More info needed here */
            break;
        }
        case 5: // Blood Group Report
        {
            /* More info needed here */
            break;
        }
        case 6: // Location Report
        {
            /* More info needed here */
            break;
        }
        case 7: // Recipient Report
        {
            /* More info needed here */
            break;
        }
        default: exit(0); //Exit Console
        }
    } while (option < 8);
}

//Function to display ----------
void line()
{
    cout << endl;
    for (int i = 0; i < 40; i++)
    {
        cout << "-";
    }
    cout << endl;
}