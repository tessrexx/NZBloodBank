// NZ Blood Bank - Aotearoa Blood
// Program allows users register as a donor or recipient & access a range of functions
// Also allows admin to view & update information

//C++ Libraries 
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

const int SIZE = 31;

//Structure containing information required to register a new donor
struct Donor_Details //Includes Registration Details
{
    char record_number;
    char first_name[SIZE];
    char last_name[SIZE];
    char date_of_birth[14];
    char gender[SIZE];
    char nationality[SIZE];
    char ethnicity[SIZE];
    char health_conditions[SIZE];
    char blood_group[SIZE];
    char contact_number[14];
    char email_address[SIZE];
    char address_line1[SIZE];
    char address_line2[SIZE];
    char last_donation[14];
    char clinic_location[SIZE];
    char booking_day[14];
    char booking_time[14];

    char username[SIZE];
    char password[SIZE];
};

// Structure for Booking Days
struct weekDays
{
    int week;
    char monday1[25], monday2[25], monday3[25], monday4[25], monday5[25], monday6[25], monday7[25];
    char tuesday1[25], tuesday2[25], tuesday3[25], tuesday4[25], tuesday5[25], tuesday6[25], tuesday7[25];
    char wednesday1[25], wednesday2[25], wednesday3[25], wednesday4[25], wednesday5[25], wednesday6[25], wednesday7[25];
    char thursday1[25], thursday2[25], thursday3[25], thursday4[25], thursday5[25], thursday6[25], thursday7[25];
    char friday1[25], friday2[25], friday3[25], friday4[25], friday5[25], friday6[25], friday7[25];
};

//Structure containing information required to register a new recipient
struct Recipient_Details
{
    char name[SIZE];
    char contact_number[14];
    char email_address[SIZE];
    char address_line1[SIZE];
    char address_line2[SIZE];
    char registration_status[14];

    char username[SIZE];
    char password[SIZE];
};


// Main Menu Functions
void main_menu();

// Donor Functions
void donor_registration();
void donor_login();
bool search_donor_file(char name[], char pass[]);
void donor_menu();
void book_donation();
void view_information();
void update_information();

// Recipient Functions
void recipient_login();
bool search_recipient_file(char name[], char pass[]);
void recipient_registration();
void recipient_menu();
void full_name();
void blood_group();
void location();

// Admin Functions
void admin_login();
void admin_menu();
void search_donor();
void search_recipient();
void update_blood();
void donor_report();
void blood_report();
void location_report();
void recipient_report();

// Visual Functions
void line();
void border_line();

// Main Function
int main()
{
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    cout << "  Welcome to Aotearoa Blood, where we make blood donation easy." << endl;
    cout << "  Use the menu below to navigate through our system." << endl;
    line();
    main_menu();

    return 0;
}

//Function to Display Introduction & Menu  ***COMPLETED***
void main_menu()
{
    int option;

    do
    {
        cout << endl << "  \tMAIN MENU" << endl;
        cout << "--------------------------------" << endl << endl;
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
        //cout << endl;
        switch (option)
        {

        case 1: // About & Contact Us
        {
            system("cls"); // clears screen
            border_line();
            cout << endl << ("\x1B[35m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            cout << "  Aotearoa Blood was founded in 1998 under the New Zealand Public Health and Disability Act 2000" << endl;
            cout << "  and is an appointed entity under section 63 of the Human Tissue Act 2008," << endl;
            cout << "  with primary responsibility for blood and controlled human substances in New Zealand." << endl;
            cout << "  Prior to this, a variety of regional blood services operated out of hospitals." << endl << endl;

            cout << endl << "  CONTACT US " << endl;
            cout << "  Phone: 0800 000 000" << endl;
            cout << "  Email: aotearoa@blood.co.nz" << endl << endl;
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
            recipient_registration();
            break;
        }
        case 6: // Admin
        {
            admin_login();
            break;
        }
        case 7:
        {
            cout << "Program Exited..." << endl << endl;
            exit(0);
        }
        default:
        {
            cout << "Invalid selection. Please try again.";
            break;
        }

        }
    } while (option < 8);
}

//Function to obtain New Donor Registration info  ***COMPLETED***
void donor_registration()
{
    // Variables needed to write the file
    fstream info;
    Donor_Details record;

    system("cls"); //Clears console screen

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    cout << "  \tDONOR REGISTRATION" << endl;
    cout << "--------------------------------" << endl << endl;

    // Open file
    info.open("Donor.dat", ios::out | ios::app | ios::binary);

    if (!info)
    {
        //Error message for non-existent file
        cout << "Error in opening the file... " << endl;
        line();
    }
    // User input & writing in data file
    else
    {
        cout << endl << "  Record No: ";
        cin >> record.record_number;
        cin.ignore();
        cout << "  First Name: ";
        cin.getline(record.first_name, SIZE);

        cout << "  Last Name: ";
        cin.getline(record.last_name, SIZE);

        cout << "  Date of Birth: ";
        cin.getline(record.date_of_birth, 14);

        cout << "  Gender: ";
        cin.getline(record.gender, SIZE);

        cout << "  Nationality: ";
        cin.getline(record.nationality, SIZE);

        cout << "  Ethnicity: ";
        cin.getline(record.ethnicity, SIZE);

        cout << endl << "  Health Conditions" << endl;
        cout << "  > Heart" << endl;
        cout << "  > ADHD" << endl;
        cout << "  > Diabetic" << endl;
        cout << "  > Cancer" << endl;
        cout << "  > Chickenpox" << endl;
        cout << "  > Asthma" << endl;
        cout << "  > Arthritis" << endl;
        cout << "  > etc..." << endl;

        cout << endl << "  Known Health Condition/s: ";
        cin.getline(record.health_conditions, SIZE);

        cout << endl << "  Blood Group (AB+, AB-, A+, A-, B+, B-, O+, O-): ";
        cin.getline(record.blood_group, SIZE);

        cout << "  Contact Number: ";
        cin.getline(record.contact_number, 14);

        cout << "  Email Address: ";
        cin.getline(record.email_address, SIZE);

        cout << "  Street Address: ";
        cin.getline(record.address_line1, SIZE);

        cout << "  Suburb/City: ";
        cin.getline(record.address_line2, SIZE);

        cout << "  Date of Last Donation (If applicable): ";
        cin.getline(record.last_donation, 14);

        cout << endl << "  Available Clinic Locations" << endl;
        cout << "  > Whangarei" << endl;
        cout << "  > Auckland" << endl;
        cout << "  > Gisborne" << endl;
        cout << "  > Wellington" << endl;
        cout << "  > Greymouth" << endl;
        cout << "  > Whangarei" << endl;
        cout << "  > Christchuch" << endl;
        cout << "  > Timaru" << endl;
        cout << "  > Dunedin" << endl;

        cout << endl << "  Clinic Location: ";
        cin.getline(record.clinic_location, SIZE);

        // User chooses their udername & password for future use 
        cout << endl << endl << "  Username: ";
        cin.getline(record.username, SIZE);

        cout << "  Password: ";
        cin.getline(record.password, SIZE);

        info.write(reinterpret_cast<char*>(&record), sizeof(record));
        // Close the file
        info.close();
    }
    cout << endl << "Thank you for registering! Please select Option 2 in the Main Menu to Login." << endl;
    line();
}

//Existing Donor Login  ***COMPLETED***
void donor_login()
{
    fstream info;
    Donor_Details record;
    bool flag = false;
    char name[SIZE];
    char pass[SIZE];
    int attempt = 0;

    system("cls"); //Clears console screen

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    cout << endl << "  \tDONOR LOGIN" << endl;
    cout << "--------------------------------" << endl << endl;

    // Open the file for reading
    info.open("Donor.dat", ios::in | ios::binary);

    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        for (attempt = 0; attempt < 3; attempt++)
        {
            //User Input
            cout << "Enter Username: ";
            cin.getline(name, SIZE);
            cout << "Enter Password: ";
            cin.getline(pass, SIZE);

            if (search_donor_file(name, pass))
            {
                system("cls");
                cout << "\t\t\t\t\t\t\t\t\tWelcome back " << name << "!";
                donor_menu();
                flag = true;
                break;
            }
            if (flag == false)
            {
                cout << endl << "Incorrect Username or Password. Please try again." << endl << endl;
            }
        }
        if (attempt > 2)
        {
            cout << endl << "Limit reached. Program Exited..." << endl << endl;
            exit(0);
        }
    }
    //Close File
    info.close();
}

//Function to check login against donor data file ***COMPLETED***
bool search_donor_file(char name[], char pass[])
{
    bool flag = false;
    fstream info;
    Donor_Details record;
    info.open("Donor.dat", ios::in | ios::binary);

    info.read(reinterpret_cast<char*>(&record), sizeof(record));
    while (!info.eof())
    {
        if ((strcmp(name, record.username) == 0) && (strcmp(pass, record.password) == 0))
        {
            flag = true;
            break;
        }
        info.read(reinterpret_cast<char*>(&record), sizeof(record));
    }

    info.close();
    return flag;
}

//Function to display Donor Menu  ***COMPLETED***
void donor_menu()
{
    int option;

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    do
    {
        //Donor Menu Display
        cout << endl << "  \tDONOR MENU" << endl;
        cout << "--------------------------------" << endl << endl;
        cout << " 1. Procedure to Donate Blood" << endl;
        cout << " 2. Benefits of Blood Donation" << endl;
        cout << " 3. Book Donation Appointment" << endl;
        cout << " 4. Manage/Update Information" << endl;
        cout << " 5. Exit" << endl;

        cout << endl << " Enter your option: "; //User Option Input
        cin >> option;
        cin.ignore(); //Clears input buffer
        cout << endl;

        switch (option)
        {
        case 1: // Procedure to Donate Blood
        {
            system("cls"); //Clears console screen
            border_line();
            cout << endl << ("\x1B[35m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            cout << endl << " PROCEDURE TO DONATE BLOOD" << endl;
            line();

            cout << " 1) Check-in at reception with your ID & complete a provided questionnaire." << endl;
            cout << "    Once you have completed your questionnaire, you will have a confidential interview with a NZBS" << endl;
            cout << "    nurse or donor technician. They will also check your haemoglobin level using a finger prick test." << endl;
            cout << "    This is a great opportunity for you to discuss the donation process and ask any questions you may have." << endl << endl;
            cout << " 2) Once the forms are completed, you will be seated and your arm will be cleaned at the" << endl;
            cout << "    venepuncture site (on the inside of the elbow) and a sterile, single-use needle will be inserted." << endl;
            cout << "    There may be a moment of discomfort as the needle goes in." << endl << endl;
            cout << " 3) A blood donation can take up to 60 minutes (includes registration, donation and recovery)." << endl;
            cout << "    The blood is collected in a sterile bag, and time on the bed can take about 5 to 10 minutes." << endl;
            cout << "    A unit of blood (around 470 ml) will be collected. The needle is then removed and a bandage is applied." << endl << endl;
            cout << " 4) After donating blood, you will be asked to rest on the chair for around 5 to 10 minutes. When " << endl;
            cout << "    you're ready, you will be invited to have refreshments in the recovery area. We like to keep an" << endl;
            cout << "    eye on you for another 10-15 minutes to make sure that you feel OK before leaving." << endl << endl;
            line();
            break;
        }
        case 2: // Benefits of Blood Donation
        {
            system("cls"); //Clears console screen
            border_line();
            cout << endl << ("\x1B[35m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            cout << endl << " BENEFITS OF BLOOD DONATION" << endl;
            line();

            cout << " - One blood donation can save up to 3 lives." << endl;
            cout << " - Join an extraordinary group of lifesavers." << endl;
            cout << " - Donating regularly ensures that a safe and plentiful supply " << endl;
            cout << "   of blood is available wheneverand wherever it is needed. " << endl;
            cout << " - Pay it forward. One day whanau, friends or even you may need it." << endl;
            cout << " - Less than 3% of people in New Zealand are blood donors." << endl;
            line();
            break;
        }
        case 3: // Book Donation Appointment
        {
            book_donation();
            line();
            break;
        }
        case 4: // Manage/Update Information
        {
            view_information();
            break;
        }
        case 5:
        {
            cout << "Exited Program..." << endl;
            exit(0);
        }
        default:
        {
            cout << "Invalid selection. Please try again." << endl;
            line();
            break;
        }
        }
    } while (option < 6);
}

//Function for donors to book donation  ***IN PROGRESS***
void book_donation()
{
    Donor_Details record;
    fstream info;
    long long int recordNumber;

    weekDays weekday = { 0, "9:00 am", "10:00am", "11:00am", "12:00pm", "2:00pm", "3:00pm", "4:00pm", // Monday
        "9:00 am", "10:00am", "11:00am", "12:00pm", "2:00pm", "3:00pm", "4:00pm", // Tuesday
        "9:00 am", "10:00am", "11:00am", "12:00pm", "2:00pm", "3:00pm", "4:00pm", // Wednesday
        "9:00 am", "10:00am", "11:00am", "12:00pm", "2:00pm", "3:00pm", "4:00pm", // Thursday
        "9:00 am", "10:00am", "11:00am", "12:00pm", "2:00pm", "3:00pm", "4:00pm" }; // Friday

    system("cls");
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();


    cout << endl << " Thank you for considering donating, your kindness helps others." << endl;
    cout << " Below are our current time slots avaliable. We are open on week days, 9:00am till 4:00pm." << endl;
    line();

    // Open file
    info.open("Donor.dat", ios::out | ios::app | ios::binary);
    if (!info)
    {
        //Error message for non-existent file
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        cout << endl << " Enter your Record Number: ";
        cin >> recordNumber;
        cin.ignore();

        cout << endl << "  _____________________________________________________________________________________________ ";
        cout << endl << " |" << "\t\t\t\t\t\t\t\t\t\t\t       " << "|";
        cout << endl << " |" << "\t\t\t\t  UPDATED TIME SLOTS AVAILABLE\t\t\t\t       " << "|";
        cout << endl << " |" << "\t\t\t\t\t\t\t\t\t\t\t       " << "|";

        border_line();
        cout << " |   MONDAY   |  " << weekday.monday1 << "  |  " << weekday.monday2 << "  |  " << weekday.monday3 << "  |  " << weekday.monday4 << "  |  " << weekday.monday5 << "  |  " << weekday.monday6 << "  |  " << weekday.monday7 << "  |";
        border_line();
        cout << " |  TUESDAY   |  " << weekday.tuesday1 << "  |  " << weekday.tuesday2 << "  |  " << weekday.tuesday3 << "  |  " << weekday.tuesday4 << "  |  " << weekday.tuesday5 << "  |  " << weekday.tuesday6 << "  |  " << weekday.tuesday7 << "  |";
        border_line();
        cout << " |  WEDNESDAY |  " << weekday.wednesday1 << "  |  " << weekday.wednesday2 << "  |  " << weekday.wednesday3 << "  |  " << weekday.wednesday4 << "  |  " << weekday.wednesday5 << "  |  " << weekday.wednesday6 << "  |  " << weekday.wednesday7 << "  |";
        border_line();
        cout << " |  THURSDAY  |  " << weekday.thursday1 << "  |  " << weekday.thursday2 << "  |  " << weekday.thursday3 << "  |  " << weekday.thursday4 << "  |  " << weekday.thursday5 << "  |  " << weekday.thursday6 << "  |  " << weekday.thursday7 << "  |";
        border_line();
        cout << " |   FRIDAY   |  " << weekday.friday1 << "  |  " << weekday.friday2 << "  |  " << weekday.friday3 << "  |  " << weekday.friday4 << "  |  " << weekday.friday5 << "  |  " << weekday.friday6 << "  |  " << weekday.friday7 << "  |";
        border_line();

        cout << endl << endl << " Enter the preferred day? ";
        cin.getline(record.booking_day, 14);

        cout << endl << " Enter the preferred time? ";
        cin.getline(record.booking_time, 14);

        // MONDAY -------------------------------------------
        if (record.booking_day == "monday")
        {
            if (record.booking_time == "9:00am")
            {
                strcpy_s(weekday.monday1, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "10:00am")
            {
                strcpy_s(weekday.monday2, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "11:00am")
            {
                strcpy_s(weekday.monday3, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "12:00pm")
            {
                strcpy_s(weekday.monday4, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "2:00pm")
            {
                strcpy_s(weekday.monday5, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "3:00pm")
            {
                strcpy_s(weekday.monday6, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "4:00pm")
            {
                strcpy_s(weekday.monday7, ("\x1B[31m Booked\033[0m"));
            }
        }

        // TUESDAY -------------------------------------------
        if (record.booking_day == "tuesday")
        {
            if (record.booking_time == "9:00am")
            {
                strcpy_s(weekday.tuesday1, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "10:00am")
            {
                strcpy_s(weekday.tuesday2, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "11:00am")
            {
                strcpy_s(weekday.tuesday3, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "12:00pm")
            {
                strcpy_s(weekday.tuesday4, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "2:00pm")
            {
                strcpy_s(weekday.tuesday5, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "3:00pm")
            {
                strcpy_s(weekday.tuesday6, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "4:00pm")
            {
                strcpy_s(weekday.tuesday7, ("\x1B[31m Booked\033[0m"));
            }
        }

        // WEDNESDAY --------------------------------------
        if (record.booking_day == "wednesday")
        {
            if (record.booking_time == "9:00am")
            {
                strcpy_s(weekday.wednesday1, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "10:00am")
            {
                strcpy_s(weekday.wednesday2, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "11:00am")
            {
                strcpy_s(weekday.wednesday3, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "12:00pm")
            {
                strcpy_s(weekday.wednesday4, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "2:00pm")
            {
                strcpy_s(weekday.wednesday5, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "3:00pm")
            {
                strcpy_s(weekday.wednesday6, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "4:00pm")
            {
                strcpy_s(weekday.wednesday7, ("\x1B[31m Booked\033[0m"));
            }
        }

        // THURSDAY -------------------------------------
        if (record.booking_day == "thursday")
        {
            if (record.booking_time == "9:00am")
            {
                strcpy_s(weekday.thursday1, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "10:00am")
            {
                strcpy_s(weekday.thursday2, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "11:00am")
            {
                strcpy_s(weekday.thursday3, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "12:00pm")
            {
                strcpy_s(weekday.thursday4, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "2:00pm")
            {
                strcpy_s(weekday.thursday5, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "3:00pm")
            {
                strcpy_s(weekday.thursday6, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "4:00pm")
            {
                strcpy_s(weekday.thursday7, ("\x1B[31m Booked\033[0m"));
            }
        }

        // FRIDAY -----------------------------------------------
        if (record.booking_day == "friday")
        {
            if (record.booking_time == "9:00am")
            {
                strcpy_s(weekday.friday1, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "10:00am")
            {
                strcpy_s(weekday.friday2, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "11:00am")
            {
                strcpy_s(weekday.friday3, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "12:00pm")
            {
                strcpy_s(weekday.friday4, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "2:00pm")
            {
                strcpy_s(weekday.friday5, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "3:00pm")
            {
                strcpy_s(weekday.friday6, ("\x1B[31m Booked\033[0m"));
            }
            else if (record.booking_time == "4:00pm")
            {
                strcpy_s(weekday.friday7, ("\x1B[31m Booked\033[0m"));
            }
        }

        cout << endl << endl << " Your booking has been confirmed!";
        cout << endl << " Your appointment to donate blood is on " << record.booking_day << " at " << record.booking_time;

        /*cout << endl << "  _____________________________________________________________________________________________ ";
        cout << endl << " |" << "\t\t\t\t\t\t\t\t\t\t\t       " << "|";
        cout << endl << " |" << "\t\t\t\t  UPDATED TIME SLOTS AVAILABLE\t\t\t\t       " << "|";
        cout << endl << " |" << "\t\t\t\t\t\t\t\t\t\t\t       " << "|";

        border_line();
        cout << " |   MONDAY   |  " << weekday.monday1 << "  |  " << weekday.monday2 << "  |  " << weekday.monday3 << "  |  " << weekday.monday4 << "  |  " << weekday.monday5 << "  |  " << weekday.monday6 << "  |  " << weekday.monday7 << "  |";
        border_line();
        cout << " |  TUESDAY   |  " << weekday.tuesday1 << "  |  " << weekday.tuesday2 << "  |  " << weekday.tuesday3 << "  |  " << weekday.tuesday4 << "  |  " << weekday.tuesday5 << "  |  " << weekday.tuesday6 << "  |  " << weekday.tuesday7 << "  |";
        border_line();
        cout << " |  WEDNESDAY |  " << weekday.wednesday1 << "  |  " << weekday.wednesday2 << "  |  " << weekday.wednesday3 << "  |  " << weekday.wednesday4 << "  |  " << weekday.wednesday5 << "  |  " << weekday.wednesday6 << "  |  " << weekday.wednesday7 << "  |";
        border_line();
        cout << " |  THURSDAY  |  " << weekday.thursday1 << "  |  " << weekday.thursday2 << "  |  " << weekday.thursday3 << "  |  " << weekday.thursday4 << "  |  " << weekday.thursday5 << "  |  " << weekday.thursday6 << "  |  " << weekday.thursday7 << "  |";
        border_line();
        cout << " |   FRIDAY   |  " << weekday.friday1 << "  |  " << weekday.friday2 << "  |  " << weekday.friday3 << "  |  " << weekday.friday4 << "  |  " << weekday.friday5 << "  |  " << weekday.friday6 << "  |  " << weekday.friday7 << "  |";
        border_line();*/
    }

    // Move to the right place in file and write the record
    info.write(reinterpret_cast<char*>(&record), sizeof(record));
    // Close File
    info.close();
}

//Function for donors to view their information  ***COMPLETED***
void view_information()
{
    Donor_Details record;
    fstream info;
    int option;
    int recordNumber;

    system("cls"); //Clears console screen
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    do
    {
        //Info Menu Display
        cout << endl << " \tMANAGE INFORMATION" << endl;
        cout << "--------------------------------" << endl << endl;
        cout << " 1. View Information" << endl;
        cout << " 2. Update Information" << endl;
        cout << " 3. Back to Main Menu" << endl;

        cout << endl << " Enter your option: "; //User Option Input
        cin >> option;
        cin.ignore(); //Clears input buffer
        cout << endl;

        switch (option)
        {
        case 1: // Procedure to Donate Blood
        {
            system("cls"); //Clears console screen
            border_line();
            cout << endl << ("\x1B[35m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();

            cout << endl << " \tVIEW INFORMATION" << endl;
            cout << "--------------------------------" << endl << endl;

            // Open the file for reading
            info.open("Donor.dat", ios::in | ios::binary);
            //Error Message
            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                cout << "Enter your Record Number: ";
                cin >> recordNumber;

                info.seekp(recordNumber * sizeof(record));
                info.read(reinterpret_cast<char*>(&record), sizeof(record));

                cout << endl << "  First Name:            " << record.first_name;
                cout << endl << "  Last Name:             " << record.last_name;
                cout << endl << "  Date of Birth:         " << record.date_of_birth;
                cout << endl << "  Gender:                " << record.gender;
                cout << endl << "  Nationality:           " << record.nationality;
                cout << endl << "  Ethnicity:             " << record.ethnicity;
                cout << endl << "  Health Conditions:     " << record.health_conditions;
                cout << endl << "  Blood Group:           " << record.blood_group;
                cout << endl << "  Contact Number:        " << record.contact_number;
                cout << endl << "  Email Address:         " << record.email_address;
                cout << endl << "  Street Address:        " << record.address_line1;
                cout << endl << "  Suburb/City:           " << record.address_line2;
                cout << endl << "  Date of Last Donation: " << record.last_donation;
                cout << endl << "  Clinic Location:       " << record.clinic_location << endl;
                cout << "----------------------------------" << endl;

                info.read(reinterpret_cast<char*>(&record), sizeof(record));
            }
            //Close File
            info.close();
            break;
        }
        case 2: // Manage/Update Information
        {
            update_information();
            break;
        }
        case 3:
        {
            system("cls");
            donor_menu();
            break;
        }
        default:
        {
            cout << "Invalid selection. Please try again." << endl;
            line();
            break;
        }
        }
    } while (option < 3);
}

//Function for donors to update their information  ***COMPLETED***
void update_information()
{
    Donor_Details record;
    fstream info;
    int option;
    long long int recordNumber;

    system("cls"); //Clears console screen
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    do
    {
        //  Update Info Menu 
        cout << endl << " UPDATE INFORMATION" << endl;
        cout << "--------------------------------" << endl << endl;
        cout << " 1. Contact Number" << endl;
        cout << " 2. Email Address" << endl;
        cout << " 3. Physical Address" << endl;
        cout << " 4. Health Conditions" << endl;
        cout << " 5. Donation Appointment" << endl;
        cout << " 6. Back to Donor Menu" << endl;

        cout << endl << " Enter the option you'd like to update: "; //User Option Input
        cin >> option;
        cin.ignore(); //Clears input buffer
        cout << endl;

        switch (option)
        {
        case 1: // Contact Number
        {
            system("cls"); //Clears console screen
            border_line();
            cout << endl << ("\x1B[35m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();

            cout << endl << "UPDATE CONTACT NUMBER" << endl;
            cout << "--------------------------------" << endl << endl;

            info.open("Donor.dat", ios::in | ios::out | ios::binary);

            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                cout << "Enter your Record Number: ";
                cin >> recordNumber;
                cin.ignore();

                info.seekg(recordNumber * sizeof(record), ios::beg);
                info.read(reinterpret_cast<char*>(&record), sizeof(record));

                cout << endl << "  Record Number:         " << record.record_number;
                cout << endl << "  First Name:            " << record.first_name;
                cout << endl << "  Last Name:             " << record.last_name;
                cout << endl << "  Date of Birth:         " << record.date_of_birth;
                cout << endl << "  Gender:                " << record.gender;
                cout << endl << "  Nationality:           " << record.nationality;
                cout << endl << "  Ethnicity:             " << record.ethnicity;
                cout << endl << "  Health Conditions:     " << record.health_conditions;
                cout << endl << "  Blood Group:           " << record.blood_group;
                cout << endl << "  Contact Number:        " << record.contact_number;
                cout << endl << "  Email Address:         " << record.email_address;
                cout << endl << "  Street Address:        " << record.address_line1;
                cout << endl << "  Suburb/City:           " << record.address_line2;
                cout << endl << "  Date of Last Donation: " << record.last_donation;
                cout << endl << "  Clinic Location:       " << record.clinic_location << endl;
                cout << "----------------------------------" << endl;

                //Get new data from user and edit in-memory record
                cout << endl << "Enter the new data: " << endl << endl;

                cout << "  Contact Number: ";
                cin.getline(record.contact_number, 14);

                // Move to the right place in file and write the record
                info.seekp(recordNumber * sizeof(record), ios::beg);
                info.write(reinterpret_cast<char*>(&record), sizeof(record));
            }

            cout << endl << "Your contact number has now been updated!" << endl;
            // Close the file
            info.close();
            line();
            break;
        }
        case 2: // Email Address
        {
            system("cls"); //Clears console screen
            cout << endl << ("\x1B[35m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            line();

            cout << endl << "UPDATE EMAIL ADDRESS" << endl;
            cout << "--------------------------------" << endl << endl;

            info.open("Donor.dat", ios::in | ios::out | ios::binary);

            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                cout << "Enter your Record Number: ";
                cin >> recordNumber;
                cin.ignore();

                info.seekg(recordNumber * sizeof(record), ios::beg);
                info.read(reinterpret_cast<char*>(&record), sizeof(record));

                cout << endl << "  Record Number:         " << record.record_number;
                cout << endl << "  First Name:            " << record.first_name;
                cout << endl << "  Last Name:             " << record.last_name;
                cout << endl << "  Date of Birth:         " << record.date_of_birth;
                cout << endl << "  Gender:                " << record.gender;
                cout << endl << "  Nationality:           " << record.nationality;
                cout << endl << "  Ethnicity:             " << record.ethnicity;
                cout << endl << "  Health Conditions:     " << record.health_conditions;
                cout << endl << "  Blood Group:           " << record.blood_group;
                cout << endl << "  Contact Number:        " << record.contact_number;
                cout << endl << "  Email Address:         " << record.email_address;
                cout << endl << "  Street Address:        " << record.address_line1;
                cout << endl << "  Suburb/City:           " << record.address_line2;
                cout << endl << "  Date of Last Donation: " << record.last_donation;
                cout << endl << "  Clinic Location:       " << record.clinic_location << endl;
                cout << "----------------------------------" << endl;

                //Get new data from user and edit in-memory record
                cout << endl << "Enter the new data: " << endl << endl;

                cout << "  Email Address: ";
                cin.getline(record.email_address, SIZE);

                // Move to the right place in file and write the record
                info.seekp(recordNumber * sizeof(record), ios::beg);
                info.write(reinterpret_cast<char*>(&record), sizeof(record));
            }

            cout << endl << "Your email address has now been updated!" << endl;
            // Close the file
            info.close();
            line();

            break;
        }
        case 3: // Physical Address
        {
            system("cls"); //Clears console screen
            cout << endl << ("\x1B[35m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            line();

            cout << endl << "UPDATE STREET ADDRESS" << endl;
            cout << "--------------------------------" << endl << endl;

            info.open("Donor.dat", ios::in | ios::out | ios::binary);

            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                cout << "Enter your Record Number: ";
                cin >> recordNumber;
                cin.ignore();

                info.seekg(recordNumber * sizeof(record), ios::beg);
                info.read(reinterpret_cast<char*>(&record), sizeof(record));

                cout << endl << "  Record Number:         " << record.record_number;
                cout << endl << "  First Name:            " << record.first_name;
                cout << endl << "  Last Name:             " << record.last_name;
                cout << endl << "  Date of Birth:         " << record.date_of_birth;
                cout << endl << "  Gender:                " << record.gender;
                cout << endl << "  Nationality:           " << record.nationality;
                cout << endl << "  Ethnicity:             " << record.ethnicity;
                cout << endl << "  Health Conditions:     " << record.health_conditions;
                cout << endl << "  Blood Group:           " << record.blood_group;
                cout << endl << "  Contact Number:        " << record.contact_number;
                cout << endl << "  Email Address:         " << record.email_address;
                cout << endl << "  Street Address:        " << record.address_line1;
                cout << endl << "  Suburb/City:           " << record.address_line2;
                cout << endl << "  Date of Last Donation: " << record.last_donation;
                cout << endl << "  Clinic Location:       " << record.clinic_location << endl;
                cout << "----------------------------------" << endl;

                //Get new data from user and edit in-memory record
                cout << endl << "Enter the new data: " << endl << endl;


                cout << "  Street Address: ";
                cin.getline(record.address_line1, SIZE);
                cout << "  Suburb/City: ";
                cin.getline(record.address_line2, SIZE);

                // Move to the right place in file and write the record
                info.seekp(recordNumber * sizeof(record), ios::beg);
                info.write(reinterpret_cast<char*>(&record), sizeof(record));
            }

            cout << endl << "Your address has now been updated!" << endl;

            // Close the file
            info.close();
            line();
            break;
        }
        case 4: // Health Conditions
        {
            system("cls"); //Clears console screen
            cout << endl << ("\x1B[35m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            line();

            cout << endl << "UPDATE HEALTH CONDITIONS" << endl;
            cout << "--------------------------------" << endl << endl;

            info.open("Donor.dat", ios::in | ios::out | ios::binary);

            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                cout << "Enter your Record Number: ";
                cin >> recordNumber;
                cin.ignore();

                info.seekg(recordNumber * sizeof(record), ios::beg);
                info.read(reinterpret_cast<char*>(&record), sizeof(record));

                cout << endl << "  Record Number:         " << record.record_number;
                cout << endl << "  First Name:            " << record.first_name;
                cout << endl << "  Last Name:             " << record.last_name;
                cout << endl << "  Date of Birth:         " << record.date_of_birth;
                cout << endl << "  Gender:                " << record.gender;
                cout << endl << "  Nationality:           " << record.nationality;
                cout << endl << "  Ethnicity:             " << record.ethnicity;
                cout << endl << "  Health Conditions:     " << record.health_conditions;
                cout << endl << "  Blood Group:           " << record.blood_group;
                cout << endl << "  Contact Number:        " << record.contact_number;
                cout << endl << "  Email Address:         " << record.email_address;
                cout << endl << "  Street Address:        " << record.address_line1;
                cout << endl << "  Suburb/City:           " << record.address_line2;
                cout << endl << "  Date of Last Donation: " << record.last_donation;
                cout << endl << "  Clinic Location:       " << record.clinic_location << endl;
                cout << "----------------------------------" << endl;

                //Get new data from user and edit in-memory record
                cout << endl << "Enter the new data: " << endl << endl;

                cout << "  Health Conditions: ";
                cin.getline(record.health_conditions, SIZE);

                // Move to the right place in file and write the record
                info.seekp(recordNumber * sizeof(record), ios::beg);
                info.write(reinterpret_cast<char*>(&record), sizeof(record));
            }

            cout << endl << "Your health conditions have now been updated!" << endl << endl;
            // Close the file
            info.close();
            line();
            break;
        }
        case 5: // Donation Appointment
        {
            system("cls");
            break;
        }
        case 6: // Display Main Menu
        {
            system("cls");
            donor_menu();
            break;
        }
        default:
        {
            cout << "Invalid selection. Please try again." << endl;
            line();
            break;
        }
        }
    } while (option < 7);

}

//Function to obtain New Recipient Registration Info  ***COMPLETED***
void recipient_registration()
{
    // Variables needed to write the file
    fstream info;
    Recipient_Details record;

    system("cls"); //Clears console screen

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    cout << endl << "    RECIPIENT REGISTRATION" << endl;
    cout << "--------------------------------" << endl << endl;

    // Open file
    info.open("Recipient.dat", ios::out | ios::app | ios::binary);

    if (!info)
    {
        //Error message for non-existent file
        cout << "Error opening file.";
    }
    // User input & writing in data file
    else
    {
        cout << "  First Name: ";
        cin.getline(record.name, SIZE);

        cout << "  Contact Number: ";
        cin.getline(record.contact_number, 14);

        cout << "  Email Address: ";
        cin.getline(record.email_address, SIZE);

        cout << "  Street Address: ";
        cin.getline(record.address_line1, SIZE);

        cout << "  Suburb/City: ";
        cin.getline(record.address_line2, SIZE);

        cout << "  Registration Status: ";
        cin.getline(record.registration_status, SIZE);

        // User chooses their udername & password for future use 
        cout << endl << endl << "  Username: ";
        cin.getline(record.username, SIZE);

        cout << "  Password: ";
        cin.getline(record.password, SIZE);

        info.write(reinterpret_cast<char*>(&record), sizeof(record));
        // Close the file
        info.close();
    }
    cout << endl << "Thank you for registering! Please select Option 4 in the Main Menu to Login." << endl;
    line();
}

//Existing Recipient Login  ***COMPLETED***
void recipient_login()
{
    Recipient_Details record;
    fstream info;
    bool flag = false;
    char name[SIZE];
    char pass[SIZE];
    int attempt = 0;

    system("cls"); //Clears console screen

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    cout << endl << "  \tRECIPIENT LOGIN" << endl;
    cout << "--------------------------------" << endl << endl;

    // Open the file for reading
    info.open("Recipient.dat", ios::in | ios::binary);

    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        for (attempt = 0; attempt < 3; attempt++)
        {
            //User Input
            cout << "Enter Username: ";
            cin.getline(name, SIZE);
            cout << "Enter Password: ";
            cin.getline(pass, SIZE);

            if (search_recipient_file(name, pass))
            {
                system("cls");
                cout << "\t\t\t\t\t\t\t\t\tWelcome back " << name << "!";
                recipient_menu();
                flag = true;
                break;
            }
            if (flag == false)
            {
                cout << endl << "Incorrect Username or Password. Please try again." << endl << endl;
            }
        }
        if (attempt > 2)
        {
            cout << endl << "Limit reached. Program Exited..." << endl << endl;
            exit(0);
        }
    }
    //Close File
    info.close();
}

//Function to check login against recipient data file ***COMPLETED***
bool search_recipient_file(char name[], char pass[])
{
    bool flag = false;
    fstream info;
    Recipient_Details record;
    info.open("Recipient.dat", ios::in | ios::binary);

    info.read(reinterpret_cast<char*>(&record), sizeof(record));
    while (!info.eof())
    {
        if ((strcmp(name, record.username) == 0) && (strcmp(pass, record.password) == 0))
        {
            flag = true;
            break;
        }
        info.read(reinterpret_cast<char*>(&record), sizeof(record));
    }

    info.close();
    return flag;
}

//Function to display Recipient Menu  ***COMPLETED***
void recipient_menu()
{
    int option;

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    while (1)
    {
        //Main Menu Display
        cout << endl << "  \tRECIPIENT MENU" << endl;
        cout << "--------------------------------" << endl << endl;
        cout << " Access Donor Information via: " << endl;
        cout << "  1. Full Name" << endl;
        cout << "  2. Blood Group" << endl;
        cout << "  3. Location" << endl;
        cout << "  4. Exit..." << endl;

        cout << endl << " Enter your option: "; //User Option Input
        cin >> option;
        cin.ignore(); //Clears input buffer

        cout << endl << endl;

        switch (option)
        {
        case 1: // Full Name
        {
            full_name();
            break;
        }
        case 2: // Blood Group
        {
            blood_group();
            break;
        }
        case 3: // Location
        {
            location();
            break;
        }
        case 4:
        {
            cout << "Program Exited..." << endl << endl;
            exit(0);
        }
        default:
        {
            cout << "Invalid selection. Please try again." << endl;
            line();
            break;
        }

        }
    }
}

//Function to search by Donor's full name & display ***COMPLETED***
void full_name()
{
    Donor_Details record;
    fstream info;
    bool flag = false;
    char firstName[SIZE];
    char lastName[SIZE];

    system("cls"); //Clears console screen

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    // Open the file for reading
    info.open("Donor.dat", ios::in | ios::binary);
    //Error Message
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        //User Input
        cout << endl << "Search by Donor's Full Name" << endl << endl;

        cout << " Enter First Name: ";
        cin.getline(firstName, SIZE);

        cout << " Enter Last Name: ";
        cin.getline(lastName, SIZE);

        cout << endl << "Retrieving matching records..." << endl << endl;
        cout << endl << " ----------------------------------" << endl;

        // Read & search for matching data
        info.read(reinterpret_cast<char*>(&record), sizeof(record));

        while (!info.eof())
        {
            if ((strcmp(firstName, record.first_name) == 0) && (strcmp(lastName, record.last_name) == 0))
            {
                cout << endl << " Record Number:         " << record.record_number;
                cout << endl << " First Name:            " << record.first_name;
                cout << endl << " Last Name:             " << record.last_name;
                cout << endl << " Date of Birth:         " << record.date_of_birth;
                cout << endl << " Gender:                " << record.gender;
                cout << endl << " Nationality:           " << record.nationality;
                cout << endl << " Ethnicity:             " << record.ethnicity;
                cout << endl << " Health Conditions:     " << record.health_conditions;
                cout << endl << " Blood Group:           " << record.blood_group;
                cout << endl << " Contact Number:        " << record.contact_number;
                cout << endl << " Email Address:         " << record.email_address;
                cout << endl << " Street Address:        " << record.address_line1;
                cout << endl << " Suburb/City:           " << record.address_line2;
                cout << endl << " Date of Last Donation: " << record.last_donation;
                cout << endl << " Clinic Location:       " << record.clinic_location << endl;
                cout << endl << " ----------------------------------" << endl;
                flag = true;
            }
            info.read(reinterpret_cast<char*>(&record), sizeof(record));
        }

        if (flag == true)
        {
            //Displayed message to confirm all relevent data has been shown
            cout << endl << "That's all the information in the file matching the name provided." << endl;
            line();
        }
        else
        {
            //Displayed message when searched name is not in file
            cout << endl << firstName << " " << lastName << " cannot be found in our records. Please try again." << endl;
            line();
        }

    }
    //Close File
    info.close();
}

//Function to search by Donor blood type & display ***COMPLETED***
void blood_group()
{
    Donor_Details record;
    fstream info;
    bool flag = false;
    char bloodGroup[14];

    system("cls"); //Clears console screen

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    // Open the file for reading
    info.open("Donor.dat", ios::in | ios::binary);
    //Error Message
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        //User Input
        cout << endl << "Search by Blood Group" << endl << endl;

        cout << " Enter Blood Type: ";
        cin.getline(bloodGroup, 14);

        cout << endl << "Retrieving matching records..." << endl;
        cout << endl << " ----------------------------------" << endl;

        // Read & search for matching data
        info.read(reinterpret_cast<char*>(&record), sizeof(record));

        while (!info.eof())
        {
            if (strcmp(bloodGroup, record.blood_group) == 0)
            {
                cout << endl << " Record Number:         " << record.record_number;
                cout << endl << " First Name:            " << record.first_name;
                cout << endl << " Last Name:             " << record.last_name;
                cout << endl << " Date of Birth:         " << record.date_of_birth;
                cout << endl << " Gender:                " << record.gender;
                cout << endl << " Nationality:           " << record.nationality;
                cout << endl << " Ethnicity:             " << record.ethnicity;
                cout << endl << " Health Conditions:     " << record.health_conditions;
                cout << endl << " Blood Group:           " << record.blood_group;
                cout << endl << " Contact Number:        " << record.contact_number;
                cout << endl << " Email Address:         " << record.email_address;
                cout << endl << " Street Address:        " << record.address_line1;
                cout << endl << " Suburb/City:           " << record.address_line2;
                cout << endl << " Date of Last Donation: " << record.last_donation;
                cout << endl << " Clinic Location:       " << record.clinic_location << endl;
                cout << endl << " ----------------------------------" << endl;
                flag = true;
            }
            info.read(reinterpret_cast<char*>(&record), sizeof(record));
        }

        if (flag == true)
        {
            //Displayed message to confirm all relevent data has been shown
            cout << endl << "That's all the information in the file matching the Blood Type provided." << endl;
            line();
        }
        else
        {
            //Displayed message when searched name is not in file
            cout << endl << bloodGroup << " cannot be found in our records. Please try again." << endl;
            line();
        }
    }


    //Close File
    info.close();
}

//Function to search by Donor loaction & display ***COMPLETED***
void location()
{
    Donor_Details record;
    fstream info;
    bool flag = false;
    char location[51];

    system("cls"); //Clears console screen

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    // Open the file for reading
    info.open("Donor.dat", ios::in | ios::binary);
    //Error Message
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        //User Input
        cout << endl << "Search by Location" << endl << endl;

        cout << " Enter Clinic Location: ";
        cin.getline(location, 14);

        cout << endl << "Retrieving matching records..." << endl;
        cout << endl << " ----------------------------------" << endl;

        // Read & search for matching data
        info.read(reinterpret_cast<char*>(&record), sizeof(record));

        while (!info.eof())
        {
            if (strcmp(location, record.clinic_location) == 0)
            {
                cout << endl << " Record Number:         " << record.record_number;
                cout << endl << " First Name:            " << record.first_name;
                cout << endl << " Last Name:             " << record.last_name;
                cout << endl << " Date of Birth:         " << record.date_of_birth;
                cout << endl << " Gender:                " << record.gender;
                cout << endl << " Nationality:           " << record.nationality;
                cout << endl << " Ethnicity:             " << record.ethnicity;
                cout << endl << " Health Conditions:     " << record.health_conditions;
                cout << endl << " Blood Group:           " << record.blood_group;
                cout << endl << " Contact Number:        " << record.contact_number;
                cout << endl << " Email Address:         " << record.email_address;
                cout << endl << " Street Address:        " << record.address_line1;
                cout << endl << " Suburb/City:           " << record.address_line2;
                cout << endl << " Date of Last Donation: " << record.last_donation;
                cout << endl << " Clinic Location:       " << record.clinic_location << endl;
                cout << endl << " --------------------------------- " << endl;
                flag = true;
            }
            info.read(reinterpret_cast<char*>(&record), sizeof(record));
        }

        if (flag == true)
        {
            //Displayed message to confirm all relevent data has been shown
            cout << endl << "That's all the information in the file matching the location provided." << endl;
            line();
        }
        else
        {
            //Displayed message when searched name is not in file
            cout << endl << location << " cannot be found in our records. Please try again." << endl;
            line();
        }
    }
    //Close File
    info.close();
}

//Function for Admin Login (fixed username & password)  ***COMPLETED***
void admin_login()
{
    string username("Admin");
    string password("Password");
    string user;
    string pass;
    bool flag = false;

    int attempt = 0;

    system("cls"); //Clears console screen

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    cout << endl << " \tADMIN LOGIN" << endl;
    cout << "--------------------------------" << endl << endl;

    while (attempt < 3)
    {
        cout << " Enter Username: ";
        cin >> user;
        cout << " Enter Password: ";
        cin >> pass;

        if ((user == username) && (pass == password))
        {
            system("cls"); //Clears console screen
            cout << "\t\t\t\t\t\t\t\t\tWelcome back " << user << "!";
            flag = true;
            admin_menu();
        }
        else if (flag == false)
        {
            cout << endl << "Incorrect Username or Password. Please try again." << endl;
            line();
            attempt++;
        }
        while (attempt > 2)
        {
            cout << "Limit reached. Program Exited..." << endl << endl;
            exit(0);
        }
    }

    line();
}

//Function to display Admin Menu  ***COMPLETED***
void admin_menu()
{
    int option;

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    do
    {
        //Main Menu Display
        cout << endl << "  \tADMIN MENU" << endl;
        cout << "--------------------------------" << endl << endl;
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
            search_recipient();
            break;
        }
        case 2: // View Donor Information
        {
            search_donor();
            break;
        }
        case 3: // Update Donor's Blood Report
        {
            update_blood();
            break;
        }
        case 4: // Donors Report
        {
            donor_report();
            break;
        }
        case 5: // Blood Group Report
        {
            blood_report();
            break;
        }
        case 6: // Location Report
        {
            location_report();
            break;
        }
        case 7: // Recipient Report
        {
            recipient_report();
            break;
        }
        case 8:
        {
            cout << "Program Exited..." << endl << endl;
            exit(0);
        }
        default: cout << "Invalid selection. Please try again." << endl;
            line();
        }
    } while (option < 8);
}

//Function for Admin to search and view Recipient Information ***COMPLETED***
void search_recipient()
{
    fstream info;
    Recipient_Details record;
    bool flag = false;
    char name[SIZE];

    system("cls"); //Clears console screen

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    // Open the file for reading
    info.open("Recipient.dat", ios::in | ios::binary);
    //Error Message
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        //User Input
        cout << endl << "Search by Recipient's Name" << endl << endl;

        cout << " Enter Name: ";
        cin.getline(name, SIZE);


        cout << endl << "Retrieving matching records..." << endl;
        cout << endl << " ----------------------------------" << endl;

        // Read & search for matching data
        info.read(reinterpret_cast<char*>(&record), sizeof(record));

        while (!info.eof())
        {
            if ((strcmp(name, record.name) == 0))
            {
                cout << endl << " Name:                  " << record.name;
                cout << endl << " Contact Number:        " << record.contact_number;
                cout << endl << " Email Address:         " << record.email_address;
                cout << endl << " Street Address:        " << record.address_line1;
                cout << endl << " Suburb/City:           " << record.address_line2;
                cout << endl << " Registration Status:   " << record.registration_status << endl;
                cout << endl << " ----------------------------------" << endl;
                flag = true;
            }
            info.read(reinterpret_cast<char*>(&record), sizeof(record));
        }

        if (flag == true)
        {
            //Displayed message to confirm all relevent data has been shown
            cout << endl << "That's all the information in the file matching the name provided." << endl;
            line();
        }
        else
        {
            //Displayed message when searched name is not in file
            cout << endl << name << " cannot be found in our records. Please try again." << endl;
            line();
        }

    }
    //Close File
    info.close();
}

//Function for Admin to search and view Donor Information ***COMPLETED***
void search_donor()
{
    Donor_Details record;
    fstream info;
    bool flag = false;
    char firstName[SIZE];
    char lastName[SIZE];

    system("cls"); //Clears console screen

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    // Open the file for reading
    info.open("Donor.dat", ios::in | ios::binary);
    //Error Message
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        //User Input
        cout << endl << "Search by Donor's Full Name" << endl << endl;

        cout << " Enter First Name: ";
        cin.getline(firstName, SIZE);

        cout << " Enter Last Name: ";
        cin.getline(lastName, SIZE);

        cout << endl << "Retrieving matching records..." << endl;
        cout << endl << " ----------------------------------" << endl;

        // Read & search for matching data
        info.read(reinterpret_cast<char*>(&record), sizeof(record));

        while (!info.eof())
        {
            if ((strcmp(firstName, record.first_name) == 0) && (strcmp(lastName, record.last_name) == 0))
            {
                cout << endl << "  Record Number:         " << record.record_number;
                cout << endl << "  First Name:            " << record.first_name;
                cout << endl << "  Last Name:             " << record.last_name;
                cout << endl << "  Date of Birth:         " << record.date_of_birth;
                cout << endl << "  Gender:                " << record.gender;
                cout << endl << "  Nationality:           " << record.nationality;
                cout << endl << "  Ethnicity:             " << record.ethnicity;
                cout << endl << "  Health Conditions:     " << record.health_conditions;
                cout << endl << "  Blood Group:           " << record.blood_group;
                cout << endl << "  Contact Number:        " << record.contact_number;
                cout << endl << "  Email Address:         " << record.email_address;
                cout << endl << "  Street Address:        " << record.address_line1;
                cout << endl << "  Suburb/City:           " << record.address_line2;
                cout << endl << "  Date of Last Donation: " << record.last_donation;
                cout << endl << "  Clinic Location:       " << record.clinic_location << endl;
                cout << endl << " ----------------------------------" << endl;
                flag = true;
            }
            info.read(reinterpret_cast<char*>(&record), sizeof(record));
        }

        if (flag == true)
        {
            //Displayed message to confirm all relevent data has been shown
            cout << endl << "That's all the information in the file matching the name provided." << endl;
            line();
        }
        else
        {
            //Displayed message when searched name is not in file
            cout << endl << firstName << " " << lastName << " cannot be found in our records. Please try again." << endl;
            line();
        }

    }
    //Close File
    info.close();
}

//Function for Admin to update Donor's Blood Type ***COMPLETED***
void update_blood()
{
    Donor_Details record;
    fstream info;
    long long int recordNumber;

    system("cls"); //Clears console screen
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    line();

    cout << endl << "  \tUPDATE INFORMATION" << endl;
    cout << "--------------------------------" << endl << endl;

    info.open("Donor.dat", ios::in | ios::out | ios::binary);

    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        cout << "Enter your Record Number: ";
        cin >> recordNumber;
        cin.ignore();

        info.seekg(recordNumber * sizeof(record), ios::beg);
        info.read(reinterpret_cast<char*>(&record), sizeof(record));

        cout << endl << "  Record Number:         " << record.record_number;
        cout << endl << "  First Name:            " << record.first_name;
        cout << endl << "  Last Name:             " << record.last_name;
        cout << endl << "  Date of Birth:         " << record.date_of_birth;
        cout << endl << "  Gender:                " << record.gender;
        cout << endl << "  Nationality:           " << record.nationality;
        cout << endl << "  Ethnicity:             " << record.ethnicity;
        cout << endl << "  Health Conditions:     " << record.health_conditions;
        cout << endl << "  Blood Group:           " << record.blood_group;
        cout << endl << "  Contact Number:        " << record.contact_number;
        cout << endl << "  Email Address:         " << record.email_address;
        cout << endl << "  Street Address:        " << record.address_line1;
        cout << endl << "  Suburb/City:           " << record.address_line2;
        cout << endl << "  Date of Last Donation: " << record.last_donation;
        cout << endl << "  Clinic Location:       " << record.clinic_location << endl;
        cout << "----------------------------------" << endl;

        //Get new data from user and edit in-memory record
        cout << endl << "Enter the new data: " << endl << endl;

        cout << "  Blood Group: ";
        cin.getline(record.blood_group, SIZE);

        // Move to the right place in file and write the record
        info.seekp(recordNumber * sizeof(record), ios::beg);
        info.write(reinterpret_cast<char*>(&record), sizeof(record));
    }
    // Close the file
    info.close();
    line();
}

//Function for Admin to view complete Donor Report ***COMPLETED***
void donor_report()
{
    Donor_Details record;
    fstream info;

    system("cls"); //Clears console screen

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    cout << endl << "  \tDONOR LIST" << endl;
    cout << "--------------------------------" << endl;

    // Open the file for reading
    info.open("Donor.dat", ios::in | ios::binary);
    //Error Message
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        // Display All Records
        info.read(reinterpret_cast<char*>(&record), sizeof(record));

        while (!info.eof())
        {
            cout << endl << " Record Number:         " << record.record_number;
            cout << endl << " First Name:            " << record.first_name;
            cout << endl << " Last Name:             " << record.last_name;
            cout << endl << " Date of Birth:         " << record.date_of_birth;
            cout << endl << " Gender:                " << record.gender;
            cout << endl << " Nationality:           " << record.nationality;
            cout << endl << " Ethnicity:             " << record.ethnicity;
            cout << endl << " Health Conditions:     " << record.health_conditions;
            cout << endl << " Blood Group:           " << record.blood_group;
            cout << endl << " Contact Number:        " << record.contact_number;
            cout << endl << " Email Address:         " << record.email_address;
            cout << endl << " Street Address:        " << record.address_line1;
            cout << endl << " Suburb/City:           " << record.address_line2;
            cout << endl << " Date of Last Donation: " << record.last_donation;
            cout << endl << " Clinic Location:       " << record.clinic_location << endl << endl;
            cout << "----------------------------------" << endl;

            //Read one structure at time & display
            info.read(reinterpret_cast<char*>(&record), sizeof(record));
        }
    }
    //Close File
    info.close();

    cout << endl << "All records on file retrieved..." << endl;

    line();
}

//Function for Admin to search and view Blood Report ***COMPLETED***
void blood_report()
{
    Donor_Details record;
    fstream info;
    int option;
    bool flag = false;
    char bloodGroup[14];

    system("cls"); //Clears console screen

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    do
    {
        cout << "\tBLOOD GROUP" << endl;
        cout << "--------------------------------" << endl;
        cout << endl << " 1. Search Blood Type";
        cout << endl << " 2. View All Blood Types";
        cout << endl << " 3. Back to Admin Menu";

        cout << endl << endl << " Enter your option: "; //User Option Input
        cin >> option;
        cin.ignore(); //Clears input buffer

        cout << endl << endl;

        switch (option)
        {
        case 1:
        {
            system("cls"); //Clears console screen

            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();

            // Open the file for reading
            info.open("Donor.dat", ios::in | ios::binary);
            //Error Message
            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                //User Input
                cout << endl << "Search by Blood Group" << endl << endl;

                cout << " Enter Blood Type: ";
                cin.getline(bloodGroup, 14);

                cout << endl << "Retrieving matching records..." << endl;
                cout << endl << " ----------------------------------" << endl;

                // Read & search for matching data
                info.read(reinterpret_cast<char*>(&record), sizeof(record));

                while (!info.eof())
                {
                    if (strcmp(bloodGroup, record.blood_group) == 0)
                    {
                        cout << endl << " Record Number:         " << record.record_number;
                        cout << endl << " First Name:            " << record.first_name;
                        cout << endl << " Last Name:             " << record.last_name;
                        cout << endl << " Date of Birth:         " << record.date_of_birth;
                        cout << endl << " Gender:                " << record.gender;
                        cout << endl << " Nationality:           " << record.nationality;
                        cout << endl << " Ethnicity:             " << record.ethnicity;
                        cout << endl << " Health Conditions:     " << record.health_conditions;
                        cout << endl << " Blood Group:           " << record.blood_group;
                        cout << endl << " Contact Number:        " << record.contact_number;
                        cout << endl << " Email Address:         " << record.email_address;
                        cout << endl << " Street Address:        " << record.address_line1;
                        cout << endl << " Suburb/City:           " << record.address_line2;
                        cout << endl << " Date of Last Donation: " << record.last_donation;
                        cout << endl << " Clinic Location:       " << record.clinic_location << endl;
                        cout << endl << " ----------------------------------" << endl;
                        flag = true;
                    }
                    info.read(reinterpret_cast<char*>(&record), sizeof(record));
                }

                if (flag == true)
                {
                    //Displayed message to confirm all relevent data has been shown
                    cout << endl << "That's all the information in the file matching the Blood Type provided." << endl;
                    line();
                }
                else
                {
                    //Displayed message when searched name is not in file
                    cout << endl << bloodGroup << " cannot be found in our records. Please try again." << endl;
                    line();
                }
            }
            info.close();
            break;
        }
        case 2:
        {
            system("cls"); //Clears console screen

            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();

            cout << "\tBLOOD GROUP REPORT" << endl;
            cout << "--------------------------------" << endl;

            // Open the file for reading
            info.open("Donor.dat", ios::in | ios::binary);
            //Error Message
            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                cout << endl << " Record:" << "\tFull Name:" << "\t\tContact Number:" << "\t\tBlood Group:";
                cout << endl << " *******" << "\t**********" << "\t\t***************" << "\t\t************" << endl;

                // Display All Records
                info.read(reinterpret_cast<char*>(&record), sizeof(record));

                while (!info.eof())
                {
                    cout << endl << " " << record.record_number << "\t\t" << record.first_name << " " << record.last_name << "\t\t" << record.contact_number << "\t\t" << record.blood_group;
                    cout << endl << endl;

                    //Read one structure at time & display
                    info.read(reinterpret_cast<char*>(&record), sizeof(record));
                }
            }
            //Close File
            info.close();

            cout << endl << "All records on file retrieved..." << endl;

            line();
            break;
        }
        case 3:
        {
            system("cls");
            // Re-Displaying header as it won't appear breaking out of this menu otherwise
            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            break;
        }
        default:
        {
            cout << "Invalid selection. Please try again." << endl;
            line();
        }
        }
    } while (option < 3);
}

//Function for Admin to search and view Location Report ***COMPLETED***
void location_report()
{
    Donor_Details record;
    fstream info;
    int option;
    bool flag = false;
    char location[SIZE];

    system("cls"); //Clears console screen

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    do
    {
        cout << "\tLOCATION" << endl;
        cout << "--------------------------------" << endl;
        cout << endl << " 1. Search Location";
        cout << endl << " 2. View All Locations";
        cout << endl << " 3. Back to Admin Menu";

        cout << endl << endl << " Enter your option: "; //User Option Input
        cin >> option;
        cin.ignore(); //Clears input buffer

        cout << endl << endl;

        switch (option)
        {
        case 1:
        {
            system("cls"); //Clears console screen

            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();

            // Open the file for reading
            info.open("Donor.dat", ios::in | ios::binary);
            //Error Message
            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                //User Input
                cout << endl << "Search by Location" << endl << endl;

                cout << " Enter Clinic Location: ";
                cin.getline(location, 14);

                cout << endl << "Retrieving matching records..." << endl;
                cout << endl << " ----------------------------------" << endl;

                // Read & search for matching data
                info.read(reinterpret_cast<char*>(&record), sizeof(record));

                while (!info.eof())
                {
                    if (strcmp(location, record.clinic_location) == 0)
                    {
                        cout << endl << " Record Number:         " << record.record_number;
                        cout << endl << " First Name:            " << record.first_name;
                        cout << endl << " Last Name:             " << record.last_name;
                        cout << endl << " Date of Birth:         " << record.date_of_birth;
                        cout << endl << " Gender:                " << record.gender;
                        cout << endl << " Nationality:           " << record.nationality;
                        cout << endl << " Ethnicity:             " << record.ethnicity;
                        cout << endl << " Health Conditions:     " << record.health_conditions;
                        cout << endl << " Blood Group:           " << record.blood_group;
                        cout << endl << " Contact Number:        " << record.contact_number;
                        cout << endl << " Email Address:         " << record.email_address;
                        cout << endl << " Street Address:        " << record.address_line1;
                        cout << endl << " Suburb/City:           " << record.address_line2;
                        cout << endl << " Date of Last Donation: " << record.last_donation;
                        cout << endl << " Clinic Location:       " << record.clinic_location << endl;
                        cout << endl << " --------------------------------- " << endl;
                        flag = true;
                    }
                    info.read(reinterpret_cast<char*>(&record), sizeof(record));
                }

                if (flag == true)
                {
                    //Displayed message to confirm all relevent data has been shown
                    cout << endl << "That's all the information in the file matching the location provided." << endl;
                    line();
                }
                else
                {
                    //Displayed message when searched name is not in file
                    cout << endl << location << " cannot be found in our records. Please try again." << endl;
                    line();
                }
            }
            //Close File
            info.close();
            break;
        }
        case 2:
        {
            system("cls"); //Clears console screen

            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();

            cout << endl << "\tLOCATION REPORT" << endl;
            cout << "--------------------------------" << endl;

            // Open the file for reading
            info.open("Donor.dat", ios::in | ios::binary);
            //Error Message
            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                cout << endl << " Record:" << "\tFull Name:" << "\t\tContact Number:" << "\t\tLocation:";
                cout << endl << " *******" << "\t**********" << "\t\t***************" << "\t\t*********" << endl;

                // Display All Records
                info.read(reinterpret_cast<char*>(&record), sizeof(record));

                while (!info.eof())
                {
                    cout << endl << " " << record.record_number << "\t\t" << record.first_name << " " << record.last_name << "\t\t" << record.contact_number << "\t\t" << record.clinic_location;
                    cout << endl << endl;

                    //Read one structure at time & display
                    info.read(reinterpret_cast<char*>(&record), sizeof(record));
                }
            }
            //Close File
            info.close();

            cout << endl << "All records on file retrieved..." << endl;

            line();
            break;
        }
        case 3:
        {
            system("cls");
            // Re-Displaying header as it won't appear breaking out of this menu otherwise
            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            break;
        }
        default:
        {
            cout << "Invalid selection. Please try again." << endl;
            line();
        }
        }
    } while (option < 3);
}

//Function for Admin to view complete Recipient Report ***COMPLETED***
void recipient_report()
{
    Recipient_Details record;
    fstream info;

    system("cls"); //Clears console screen

    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    cout << endl << "  \tRECIPIENT LIST" << endl;
    cout << "--------------------------------" << endl;

    // Open the file for reading
    info.open("Recipient.dat", ios::in | ios::binary);
    //Error Message
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        // Display All Records
        info.read(reinterpret_cast<char*>(&record), sizeof(record));

        while (!info.eof())
        {
            cout << endl << " Name:                  " << record.name;
            cout << endl << " Contact Number:        " << record.contact_number;
            cout << endl << " Email Address:         " << record.email_address;
            cout << endl << " Street Address:        " << record.address_line1;
            cout << endl << " Suburb/City:           " << record.address_line2;
            cout << endl << " Registration Status:   " << record.registration_status << endl;
            cout << endl << " ----------------------------------" << endl;

            //Read one structure at time & display
            info.read(reinterpret_cast<char*>(&record), sizeof(record));
        }
    }
    //Close File
    info.close();

    cout << endl << "All records on file retrieved..." << endl;

    line();
}

//Function to display ---------- ***COMPLETED***
void line()
{
    cout << endl;
    for (int i = 0; i < 97; i++)
    {
        cout << "-";
    }
    cout << endl;
}

//Function to display x----------x ***COMPLETED***
void border_line()
{
    cout << endl << "+";
    for (int i = 0; i < 95; i++)
    {
        cout << "-";
    }
    cout << "+" << endl;
}
