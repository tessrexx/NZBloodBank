// NZ Blood Bank - Aotearoa Blood
// Program allows users register as a donor or recipient & access a range of functions
// Also allows admin to view & update information
// Check ReadMe.txt for default Login Details

// C++ Libraries 
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

// Global constant for chars
const int SIZE = 31;

// Structure containing information required to register a new donor
struct Donor_Details
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

    char username[SIZE];
    char password[SIZE];
};

// Structure to hold donor booking days and times
struct Weekdays
{
    int week;
    char monday1[25], monday2[25], monday3[25], monday4[25], monday5[25], monday6[25], monday7[25], monday8[25];
    char tuesday1[25], tuesday2[25], tuesday3[25], tuesday4[25], tuesday5[25], tuesday6[25], tuesday7[25], tuesday8[25];
    char wednesday1[25], wednesday2[25], wednesday3[25], wednesday4[25], wednesday5[25], wednesday6[25], wednesday7[25], wednesday8[25];
    char thursday1[25], thursday2[25], thursday3[25], thursday4[25], thursday5[25], thursday6[25], thursday7[25], thursday8[25];
    char friday1[25], friday2[25], friday3[25], friday4[25], friday5[25], friday6[25], friday7[25], friday8[25];
};

// Global array to hold default/available timeslots for donor booking
Weekdays week = { 0, " 9:00", "10:00", "11:00", "12:00", " 1:00", " 2:00", " 3:00", " 4:00", // Monday
                     " 9:00", "10:00", "11:00", "12:00", " 1:00", " 2:00", " 3:00", " 4:00", // Tuesday
                     " 9:00", "10:00", "11:00", "12:00", " 1:00", " 2:00", " 3:00", " 4:00", // Wednesday
                     " 9:00", "10:00", "11:00", "12:00", " 1:00", " 2:00", " 3:00", " 4:00", // Thursday
                     " 9:00", "10:00", "11:00", "12:00", " 1:00", " 2:00", " 3:00", " 4:00" }; // Friday

// Structure to hold donor booking details
struct Bookings
{
    char record_number;
    char booking_day[14];
    char booking_time[14];
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

// Donor Functions
void donor_registration();
void donor_login();
bool search_donor_file(char name[], char pass[]);
void donor_menu();
void check_existing();
void book_donation();
void reschedule_appointment();
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
    // Function variable
    int option;

    // Display Title/Header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    // Display Info Blurb
    cout << endl << "  Welcome to Aotearoa Blood, where we make blood donation easy." << endl;
    cout << "  Use the menu below to navigate through our system." << endl;
    line();

    do
    {
        // User menu options
        cout << endl << "  \tMAIN MENU" << endl;
        cout << "--------------------------------" << endl << endl;
        cout << " 1. Information & Contact Us" << endl;
        cout << " 2. Existing Donor" << endl;
        cout << " 3. New Donor" << endl;
        cout << " 4. Existing Recipient" << endl;
        cout << " 5. New Recipient" << endl;
        cout << " 6. Admin" << endl;
        cout << " 7. Exit..." << endl;

        cout << endl << " Enter your option: "; // User input
        cin >> option;
        cin.ignore(); //Clears input buffer
        switch (option)
        {
        case 1: // About & Contact Us
        {
            system("cls"); // clears screen
            // Display title/header
            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            cout << endl << "\tINFORMATION" << endl;
            cout << "--------------------------------" << endl << endl;
            cout << "  Aotearoa Blood was founded in 1998 under the New Zealand Public Health and Disability Act 2000" << endl;
            cout << "  and is an appointed entity under section 63 of the Human Tissue Act 2008," << endl;
            cout << "  with primary responsibility for blood and controlled human substances in New Zealand." << endl;
            cout << "  Prior to this, a variety of regional blood services operated out of hospitals." << endl;
            line();
            // Contact details for the blood bank
            cout << endl << "\tCONTACT US " << endl;
            cout << "--------------------------------" << endl << endl;
            cout << "  Phone: 0800 000 000" << endl;
            cout << "  Email: aotearoa@blood.co.nz" << endl << endl;
            line();
            break;
        }

        case 2: // Existing donor login function
        {
            donor_login();
            break;
        }
        case 3: // New donor registration function
        {
            donor_registration();
            break;
        }
        case 4: // Existing recipient login function
        {
            recipient_login();
            break;
        }
        case 5: // New recipient registration function
        {
            recipient_registration();
            break;
        }
        case 6: // Admin login function
        {
            admin_login();
            break;
        }
        case 7: // Exit program
        {
            cout << endl << "Program Exited..." << endl << endl;
            exit(0);
        }
        default: // Incorrect input. Allows user to try a different input
        {
            cout << "Invalid selection. Please try again.";
            break;
        }

        }
    } while (option < 8);

    // Success code returned
    return 0;
} // End of main function

// Function to obtain new donor registration information 
void donor_registration()
{
    // Structure and file variables
    fstream info;
    Donor_Details record;

    system("cls"); // Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    // Display subtitle
    cout << "  \tDONOR REGISTRATION" << endl;
    cout << "--------------------------------" << endl << endl;

    // Open data file for writing
    info.open("Donor.dat", ios::out | ios::app | ios::binary);
    // Error message for non-existent file
    if (!info)
    {
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
        // List of example health conditions
        cout << endl << "  Health Conditions" << endl;
        cout << "  > Heart" << endl;
        cout << "  > ADHD" << endl;
        cout << "  > Diabetic" << endl;
        cout << "  > Cancer" << endl;
        cout << "  > Chickenpox" << endl;
        cout << "  > Asthma" << endl;
        cout << "  > Arthritis" << endl;
        cout << "  > Other" << endl;
        cout << endl << "  Known Health Condition/s: ";
        cin.getline(record.health_conditions, SIZE);
        cout << endl << "  Blood Group (AB+, AB-, A+, A-, B+, B-, O+, O-, Unknown): ";
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
        // List of clinic locations
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

        // User chooses their username & password for future use 
        cout << endl << endl << "  Username: ";
        cin.getline(record.username, SIZE);
        cout << "  Password: ";
        cin.getline(record.password, SIZE);

        // Writing user's input to data file
        info.write(reinterpret_cast<char*>(&record), sizeof(record));
        // Close data file
        info.close();
    }
    // Display registration confirmation
    cout << endl << "Thank you for registering! Please select Option 2 in the Main Menu to Login." << endl;
    line();
} // End of donor_registration function

// Function for existing donor to login 
void donor_login()
{
    // Function and file variables
    fstream info;
    bool flag = false;
    char name[SIZE];
    char pass[SIZE];
    int attempt = 0;

    system("cls"); // Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    // Display subtitle
    cout << endl << "  \tDONOR LOGIN" << endl;
    cout << "--------------------------------" << endl << endl;

    // Open the file for reading
    info.open("Donor.dat", ios::in | ios::binary);
    // Error message for non-existent file
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        // Loop for 3 login attempts
        for (attempt = 0; attempt < 3; attempt++)
        {
            // User Input
            cout << " Enter Username: ";
            cin.getline(name, SIZE);
            cout << " Enter Password: ";
            cin.getline(pass, SIZE);

            // Call search donor function to read file for matching the entered details
            if (search_donor_file(name, pass)) // Do following if check is correct
            {
                system("cls"); // Clears console screen
                cout << "\t\t\t\t\t\t\t\t\tWelcome back " << name << "!"; // Will wellcome and display entered username on next screen
                donor_menu(); // Call donor menu function
                flag = true;
                break;
            }
            if (flag == false) // Display message if incorrect details entered
            {
                cout << endl << "Incorrect Username or Password. Please try again." << endl << endl;
            }
        }
        if (attempt > 2) // Close program if incorrect details entered 3 times
        {
            cout << endl << "Limit reached. Program Exited..." << endl << endl;
            exit(0);
        }
    }
    //Close data file
    info.close();
} // End of donor_login function

// Function to check login against donor data file 
bool search_donor_file(char name[], char pass[])
{
    // Structure, function, and file variables
    bool flag = false;
    fstream info;
    Donor_Details record;

    // Open data file for reading
    info.open("Donor.dat", ios::in | ios::binary);
    info.read(reinterpret_cast<char*>(&record), sizeof(record));

    while (!info.eof())
    {
        // Check if entered username and password matches data file
        if ((strcmp(name, record.username) == 0) && (strcmp(pass, record.password) == 0))
        {
            flag = true;
            break;
        }
        info.read(reinterpret_cast<char*>(&record), sizeof(record));
    }

    // Close data file
    info.close();
    // Return true/false flag to donor login function
    return flag;
} // End of search_donor_file function 

//Function to display Donor Menu  
void donor_menu()
{
    // Function variable
    int option;
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    do
    {
        // Display subtitle and donor menu
        cout << endl << "  \tDONOR MENU" << endl;
        cout << "--------------------------------" << endl << endl;
        cout << " 1. Procedure to Donate Blood" << endl;
        cout << " 2. Benefits of Blood Donation" << endl;
        cout << " 3. Book Donation Appointment" << endl;
        cout << " 4. Manage/Update Information" << endl;
        cout << " 5. Logout" << endl;

        cout << endl << " Enter your option: "; //User Option Input
        cin >> option;
        cin.ignore(); //Clears input buffer
        cout << endl;

        switch (option)
        {
        case 1: // Procedure to Donate Blood
        {
            system("cls"); //Clears console screen
            // Display title/header
            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            // Display subtitle
            cout << endl << "   PROCEDURE TO DONATE BLOOD" << endl;
            cout << "--------------------------------" << endl << endl;
            // Donation Steps
            cout << " 1) Check in with your ID at reception and fill out the provided questionnaire. " << endl;
            cout << "    After you've finished your questionnaire, you'll meet with a Aotearoa Blood Nurse for a " << endl;
            cout << "    confidential interview. A finger prick test will be used to check your hemoglobin level." << endl;
            cout << "    This is an excellent time for you to ask any questions you may have about the donation procedure." << endl << endl;
            cout << " 2) After you've filled out the paperwork, you'll be seated and your arm will be sanitized at the " << endl;
            cout << "    venipuncture site (on the inside of the elbow) before a sterile, single-use needle is inserted." << endl;
            cout << "    As the needle is inserted, there may be some discomfort." << endl << endl;
            cout << " 3) Donating blood may take up to 60 minutes (includes registration, donation and recovery)." << endl;
            cout << "    The blood is taken in a sterile bag, and being on the bed for 5 to 10 minutes is typical." << endl;
            cout << "    A unit of blood (about 470 ml) will be taken. After that, the needle is removed and a bandage is" << endl;
            cout << "    placed on the wound." << endl << endl;
            cout << " 4) You will be requested to sit in the chair for 5 to 10 minutes after donating blood." << endl;
            cout << "    When you're ready, you'll be invited to the recuperation area for refreshments. Before departing," << endl;
            cout << "    we want to keep an eye on you for another 10-15 minutes to make sure you're comfortable." << endl;
            line();
            break;
        }
        case 2: // Benefits of Blood Donation
        {
            system("cls"); //Clears console screen
            // Display title/header
            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            // Display subtitle
            cout << endl << "  BENEFITS OF BLOOD DONATION" << endl;
            cout << "--------------------------------" << endl << endl;
            // Donation Benefits
            cout << " - One blood donation can save up to 3 lives." << endl;
            cout << " - Join an extraordinary group of lifesavers." << endl;
            cout << " - Donating regularly ensures that a safe and plentiful supply " << endl;
            cout << "   of blood is available whenever and wherever it is needed. " << endl;
            cout << " - Pay it forward. One day whanau, friends or even you may need it." << endl;
            cout << " - Less than 3% of people in New Zealand are blood donors." << endl;
            line();
            break;
        }
        case 3: // Book donation appointment function
        {
            book_donation();
            break;
        }
        case 4: // Manage and update personal information function
        {
            view_information();
            break;
        }
        case 5:  // Return to main menu 
        {
            system("cls"); // Clears console screen
            cout << "\t\t\t\t\t\t\t\t\t\tLogged out"; // Will display on Main Menu Screen
            main();
        }
        default: // Incorrect input. Allows user to try a different input
        {
            cout << "Invalid selection. Please try again." << endl;
            line();
            break;
        }
        }
    } while (option < 6);
} // End of donor_menu function

// Function to check existing time slots data file 
void check_existing()
{
    // File variable
    fstream slots;

    // User input & writing/reading in data file
    slots.open("TimeSlots.dat", ios::in | ios::binary);
    // If file is empty, the WeekDay array will be copied in
    if (slots)
    {
        slots.read(reinterpret_cast<char*>(&week), sizeof(week));
        while (!slots.eof())
        {
            slots.read(reinterpret_cast<char*>(&week), sizeof(week));
        }
    }
    // Close data file
    slots.close();
} // End of check_existing function 

//Function for donors to book donation  
void book_donation()
{
    // Structure and file variables
    fstream info;
    fstream timeSlot;
    Bookings booking;
    // Clears input buffer
    system("cls");
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    // Display donation blurb
    cout << endl << " Thank you for considering donating, your kindness helps others." << endl;
    cout << " Below are our current time slots avaliable. We are open Monday to Friday, 9:00am until 4:00pm." << endl;
    line();
    // Display subtitle
    cout << endl << "     BOOK BLOOD DONATION" << endl;
    cout << "--------------------------------" << endl;

    // Call function to store array if time slot file not created
    check_existing();

    // Open time slot file and booking file for writing
    timeSlot.open("TimeSlots.dat", ios::out | ios::app | ios::binary);
    info.open("Booking.dat", ios::out | ios::app | ios::binary);
    //Error message for non-existent file
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        // User input
        cout << endl << "Enter your Record Number: ";
        cin >> booking.record_number;
        cin.ignore();
        // Dipslay subtitle
        cout << endl << " _______________________________________________________________________________________________ ";
        cout << endl << "|" << "\t\t\t\t\t\t\t\t\t\t\t       " << " |";
        cout << endl << "|" << "\t\t\t\t       TIME SLOTS AVAILABLE\t\t\t\t       " << " |";
        cout << endl << "|" << "\t\t\t\t\t\t\t\t\t\t\t       " << " |";
        // Display available time slots
        border_line();
        cout << "|    MONDAY   |  " << week.monday1 << "  |  " << week.monday2 << "  |  " << week.monday3 << "  |  " << week.monday4 << "  |  " << week.monday5 << "  |  " << week.monday6 << "  |  " << week.monday7 << "  |  " << week.monday8 << "   |";
        border_line();
        cout << "|   TUESDAY   |  " << week.tuesday1 << "  |  " << week.tuesday2 << "  |  " << week.tuesday3 << "  |  " << week.tuesday4 << "  |  " << week.tuesday5 << "  |  " << week.tuesday6 << "  |  " << week.tuesday7 << "  |  " << week.tuesday8 << "   |";
        border_line();
        cout << "|   WEDNESDAY |  " << week.wednesday1 << "  |  " << week.wednesday2 << "  |  " << week.wednesday3 << "  |  " << week.wednesday4 << "  |  " << week.wednesday5 << "  |  " << week.wednesday6 << "  |  " << week.wednesday7 << "  |  " << week.wednesday8 << "   |";
        border_line();
        cout << "|   THURSDAY  |  " << week.thursday1 << "  |  " << week.thursday2 << "  |  " << week.thursday3 << "  |  " << week.thursday4 << "  |  " << week.thursday5 << "  |  " << week.thursday6 << "  |  " << week.thursday7 << "  |  " << week.thursday8 << "   |";
        border_line();
        cout << "|    FRIDAY   |  " << week.friday1 << "  |  " << week.friday2 << "  |  " << week.friday3 << "  |  " << week.friday4 << "  |  " << week.friday5 << "  |  " << week.friday6 << "  |  " << week.friday7 << "  |  " << week.friday8 << "   |";
        border_line();
        // User inputs day
        cout << endl << endl << " Enter the preferred day: ";
        cin.getline(booking.booking_day, 14);

        // Check if input day is valid
        while (strcmp(booking.booking_day, "Monday") != 0 && strcmp(booking.booking_day, "monday") != 0 && strcmp(booking.booking_day, "Tuesday") != 0 && strcmp(booking.booking_day, "tuesday") != 0 && strcmp(booking.booking_day, "Wednesday") != 0 && strcmp(booking.booking_day, "wednesday") != 0
            && strcmp(booking.booking_day, "Thursday") != 0 && strcmp(booking.booking_day, "thursday") != 0 && strcmp(booking.booking_day, "Friday") != 0 && strcmp(booking.booking_day, "friday") != 0)
        {
            cout << endl << "Open Days are Monday - Friday. Please try again.";
            cout << endl << endl << " Enter the preferred day: ";
            cin.getline(booking.booking_day, 14);
        }
        // User inputs time
        cout << " Enter the preferred time (i.e. 9:00 or 9): ";
        cin.getline(booking.booking_time, 14);

        // Check if input time is valid
        while (strcmp(booking.booking_time, "9:00") != 0 && strcmp(booking.booking_time, "9") != 0 && strcmp(booking.booking_time, "10:00") != 0 && strcmp(booking.booking_time, "10") != 0 && strcmp(booking.booking_time, "11:00") != 0 && strcmp(booking.booking_time, "11") != 0 && strcmp(booking.booking_time, "12:00") != 0
            && strcmp(booking.booking_time, "12") != 0 && strcmp(booking.booking_time, "1:00") != 0 && strcmp(booking.booking_time, "1") != 0 && strcmp(booking.booking_time, "2:00") != 0 && strcmp(booking.booking_time, "2") != 0 && strcmp(booking.booking_time, "3:00") != 0 && strcmp(booking.booking_time, "3") != 0 && strcmp(booking.booking_time, "4:00") != 0 && strcmp(booking.booking_time, "4") != 0)
        {
            cout << endl << "Booking Hours are 9:00am - 4:00pm. Please try again.";
            cout << endl << endl << " Enter the preferred time (i.e. 9:00 or 9): ";
            cin.getline(booking.booking_time, 14);
        }

        // Monday loop for selected timeslot to change to "Booked"
        if (strcmp(booking.booking_day, "Monday") == 0 || strcmp(booking.booking_day, "monday") == 0)
        {
            if (strcmp(booking.booking_time, "9:00") == 0 || strcmp(booking.booking_time, "9") == 0)
            {
                strcpy_s(week.monday1, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "10:00") == 0 || strcmp(booking.booking_time, "10") == 0)
            {
                strcpy_s(week.monday2, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "11:00") == 0 || strcmp(booking.booking_time, "11") == 0)
            {
                strcpy_s(week.monday3, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "12:00") == 0 || strcmp(booking.booking_time, "12") == 0)
            {
                strcpy_s(week.monday4, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "1:00") == 0 || strcmp(booking.booking_time, "1") == 0)
            {
                strcpy_s(week.monday5, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "2:00") == 0 || strcmp(booking.booking_time, "2") == 0)
            {
                strcpy_s(week.monday6, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "3:00") == 0 || strcmp(booking.booking_time, "3") == 0)
            {
                strcpy_s(week.monday7, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "4:00") == 0 || strcmp(booking.booking_time, "4") == 0)
            {
                strcpy_s(week.monday8, ("\x1B[31mBooked\033[0m"));
            }
            timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
        }

        // Tuesday loop for selected timeslot to change to "Booked"
        if (strcmp(booking.booking_day, "Tuesday") == 0 || strcmp(booking.booking_day, "tuesday") == 0)
        {
            if (strcmp(booking.booking_time, "9:00") == 0 || strcmp(booking.booking_time, "9") == 0)
            {
                strcpy_s(week.tuesday1, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "10:00") == 0 || strcmp(booking.booking_time, "10") == 0)
            {
                strcpy_s(week.tuesday2, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "11:00") == 0 || strcmp(booking.booking_time, "11") == 0)
            {
                strcpy_s(week.tuesday3, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "12:00") == 0 || strcmp(booking.booking_time, "12") == 0)
            {
                strcpy_s(week.tuesday4, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "1:00") == 0 || strcmp(booking.booking_time, "1") == 0)
            {
                strcpy_s(week.tuesday5, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "2:00") == 0 || strcmp(booking.booking_time, "2") == 0)
            {
                strcpy_s(week.tuesday6, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "3:00") == 0 || strcmp(booking.booking_time, "3") == 0)
            {
                strcpy_s(week.tuesday7, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "4:00") == 0 || strcmp(booking.booking_time, "4") == 0)
            {
                strcpy_s(week.tuesday8, ("\x1B[31mBooked\033[0m"));
            }
            timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
        }

        // Wednesday loop for selected timeslot to change to "Booked"
        if (strcmp(booking.booking_day, "Wednesday") == 0 || strcmp(booking.booking_day, "wednesday") == 0)
        {
            if (strcmp(booking.booking_time, "9:00") == 0 || strcmp(booking.booking_time, "9") == 0)
            {
                strcpy_s(week.wednesday1, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "10:00") == 0 || strcmp(booking.booking_time, "10") == 0)
            {
                strcpy_s(week.wednesday2, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "11:00") == 0 || strcmp(booking.booking_time, "11") == 0)
            {
                strcpy_s(week.wednesday3, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "12:00") == 0 || strcmp(booking.booking_time, "12") == 0)
            {
                strcpy_s(week.wednesday4, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "1:00") == 0 || strcmp(booking.booking_time, "1") == 0)
            {
                strcpy_s(week.wednesday5, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "2:00") == 0 || strcmp(booking.booking_time, "2") == 0)
            {
                strcpy_s(week.wednesday6, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "3:00") == 0 || strcmp(booking.booking_time, "3") == 0)
            {
                strcpy_s(week.wednesday7, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "4:00") == 0 || strcmp(booking.booking_time, "4") == 0)
            {
                strcpy_s(week.wednesday8, ("\x1B[31mBooked\033[0m"));
            }
            timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
        }

        // Thursday loop for selected timeslot to change to "Booked"
        if (strcmp(booking.booking_day, "Thursday") == 0 || strcmp(booking.booking_day, "thursday") == 0)
        {
            if (strcmp(booking.booking_time, "9:00") == 0 || strcmp(booking.booking_time, "9") == 0)
            {
                strcpy_s(week.thursday1, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "10:00") == 0 || strcmp(booking.booking_time, "10") == 0)
            {
                strcpy_s(week.thursday2, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "11:00") == 0 || strcmp(booking.booking_time, "11") == 0)
            {
                strcpy_s(week.thursday3, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "12:00") == 0 || strcmp(booking.booking_time, "12") == 0)
            {
                strcpy_s(week.thursday4, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "1:00") == 0 || strcmp(booking.booking_time, "1") == 0)
            {
                strcpy_s(week.thursday5, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "2:00") == 0 || strcmp(booking.booking_time, "2") == 0)
            {
                strcpy_s(week.thursday6, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "3:00") == 0 || strcmp(booking.booking_time, "3") == 0)
            {
                strcpy_s(week.thursday7, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "4:00") == 0 || strcmp(booking.booking_time, "4") == 0)
            {
                strcpy_s(week.thursday8, ("\x1B[31mBooked\033[0m"));
            }
            timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
        }

        // Friday loop for selected timeslot to change to "Booked"
        if (strcmp(booking.booking_day, "Friday") == 0 || strcmp(booking.booking_day, "friday") == 0)
        {
            if (strcmp(booking.booking_time, "9:00") == 0 || strcmp(booking.booking_time, "9") == 0)
            {
                strcpy_s(week.friday1, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "10:00") == 0 || strcmp(booking.booking_time, "10") == 0)
            {
                strcpy_s(week.friday2, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "11:00") == 0 || strcmp(booking.booking_time, "11") == 0)
            {
                strcpy_s(week.friday3, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "12:00") == 0 || strcmp(booking.booking_time, "12") == 0)
            {
                strcpy_s(week.friday4, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "1:00") == 0 || strcmp(booking.booking_time, "1") == 0)
            {
                strcpy_s(week.friday5, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "2:00") == 0 || strcmp(booking.booking_time, "2") == 0)
            {
                strcpy_s(week.friday6, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "3:00") == 0 || strcmp(booking.booking_time, "3") == 0)
            {
                strcpy_s(week.friday7, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "4:00") == 0 || strcmp(booking.booking_time, "4") == 0)
            {
                strcpy_s(week.friday8, ("\x1B[31mBooked\033[0m"));
            }
            timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
        }

        // Display booking confirmation 
        cout << endl << endl << " Your booking has been confirmed!";
        cout << endl << " Your appointment to donate blood is on " << booking.booking_day << " at " << booking.booking_time << endl;
    }

    // Display subtitle
    cout << endl << " _______________________________________________________________________________________________ ";
    cout << endl << "|" << "\t\t\t\t\t\t\t\t\t\t\t       " << " |";
    cout << endl << "|" << "\t\t\t\t  UPDATED TIME SLOTS AVAILABLE\t\t\t\t       " << " |";
    cout << endl << "|" << "\t\t\t\t\t\t\t\t\t\t\t       " << " |";
    // Display new available time slots
    border_line();
    cout << "|    MONDAY   |  " << week.monday1 << "  |  " << week.monday2 << "  |  " << week.monday3 << "  |  " << week.monday4 << "  |  " << week.monday5 << "  |  " << week.monday6 << "  |  " << week.monday7 << "  |  " << week.monday8 << "   |";
    border_line();
    cout << "|   TUESDAY   |  " << week.tuesday1 << "  |  " << week.tuesday2 << "  |  " << week.tuesday3 << "  |  " << week.tuesday4 << "  |  " << week.tuesday5 << "  |  " << week.tuesday6 << "  |  " << week.tuesday7 << "  |  " << week.tuesday8 << "   |";
    border_line();
    cout << "|   WEDNESDAY |  " << week.wednesday1 << "  |  " << week.wednesday2 << "  |  " << week.wednesday3 << "  |  " << week.wednesday4 << "  |  " << week.wednesday5 << "  |  " << week.wednesday6 << "  |  " << week.wednesday7 << "  |  " << week.wednesday8 << "   |";
    border_line();
    cout << "|   THURSDAY  |  " << week.thursday1 << "  |  " << week.thursday2 << "  |  " << week.thursday3 << "  |  " << week.thursday4 << "  |  " << week.thursday5 << "  |  " << week.thursday6 << "  |  " << week.thursday7 << "  |  " << week.thursday8 << "   |";
    border_line();
    cout << "|    FRIDAY   |  " << week.friday1 << "  |  " << week.friday2 << "  |  " << week.friday3 << "  |  " << week.friday4 << "  |  " << week.friday5 << "  |  " << week.friday6 << "  |  " << week.friday7 << "  |  " << week.friday8 << "   |";
    border_line();


    // Writing user's input to data files
    timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
    info.write(reinterpret_cast<char*>(&booking), sizeof(booking));

    // Close data files
    info.close();
    timeSlot.close();
} // End of book_donation function

// Function for donors to view their information
void view_information()
{
    // Structure, function, and file variables
    Donor_Details record;
    fstream info;
    int option;
    long long int recordNumber;

    system("cls"); //Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    do
    {
        // Display subtitle and information menu
        cout << endl << " \tMANAGE INFORMATION" << endl;
        cout << "--------------------------------" << endl << endl;
        cout << " 1. View Information" << endl;
        cout << " 2. Update Information" << endl;
        cout << " 3. Reschedule Appointment" << endl;
        cout << " 4. Back to Main Menu" << endl;

        cout << endl << " Enter your option: "; //User Option Input
        cin >> option;
        cin.ignore(); //Clears input buffer
        cout << endl;

        switch (option)
        {
        case 1: // View current donor details
        {
            system("cls"); //Clears console screen
            // Display title/header
            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            // Display subtitle
            cout << endl << " \tVIEW INFORMATION" << endl;
            cout << "--------------------------------" << endl << endl;

            // Open the data file for reading
            info.open("Donor.dat", ios::in | ios::binary);
            // Error message for non-existent file
            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                // User input
                cout << "Enter your Record Number: ";
                cin >> recordNumber;
                // Searching user's input in data file and displaying results
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
                cout << endl << "  Clinic Location:       " << record.clinic_location << endl << endl;

                cout << "----------------------------------" << endl;

                info.read(reinterpret_cast<char*>(&record), sizeof(record));
            }
            //Close data ile
            info.close();
            break;
        }
        case 2: // Update donor's information function
        {
            update_information();
            break;
        }
        case 3: // Reschedule existing donation appointment function             
        {
            reschedule_appointment();
            break;
        }
        case 4:
        {
            system("cls"); // Clears console screen
            donor_menu(); // Donor menu function
            break;
        }
        default: // Incorrect input. Allows user to try a different input
        {
            cout << "Invalid selection. Please try again." << endl;
            line();
            break;
        }
        }
    } while (option < 3);
} // End of view_information function

// Function for donors to update their information
void update_information()
{
    // Structure, function and file variables
    Donor_Details record;
    fstream info;
    int option;
    long long int recordNumber;

    system("cls"); //Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    do
    {
        //  Display subtitle and manage information menu 
        cout << endl << "\tUPDATE INFORMATION" << endl;
        cout << "--------------------------------" << endl << endl;
        cout << " 1. Contact Number" << endl;
        cout << " 2. Email Address" << endl;
        cout << " 3. Physical Address" << endl;
        cout << " 4. Health Conditions" << endl;
        cout << " 5. Back to Information Menu" << endl;

        cout << endl << " Enter the option you'd like to update: "; //User Option Input
        cin >> option;
        cin.ignore(); //Clears input buffer
        cout << endl;

        switch (option)
        {
        case 1: // Update contact number
        {
            system("cls"); //Clears console screen
            // Display title/header
            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            // Display subtitle
            cout << endl << "     UPDATE CONTACT NUMBER" << endl;
            cout << "--------------------------------" << endl << endl;
            // Open data file for writing
            info.open("Donor.dat", ios::in | ios::out | ios::binary);
            // Error message for non-existent file
            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                // User input
                cout << "Enter your Record Number: ";
                cin >> recordNumber;
                cin.ignore(); // Clears input buffer
                // Searching user's input in data file and displaying results
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
                cout << endl << "  Clinic Location:       " << record.clinic_location << endl << endl;
                cout << "----------------------------------" << endl;

                // Get new data from user and edit in-memory record
                cout << endl << "Enter the new data: " << endl << endl;
                cout << "  Contact Number: ";
                cin.getline(record.contact_number, 14);

                // Move to the right place in file and write the record
                info.seekp(recordNumber * sizeof(record), ios::beg);
                info.write(reinterpret_cast<char*>(&record), sizeof(record));
            }
            // Display confirmation of update
            cout << endl << "Your contact number has now been updated!" << endl;
            // Close data file
            info.close();
            line();
            break;
        }
        case 2: // Update email address
        {
            system("cls"); //Clears console screen
            // Display title/header
            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            // Display subtitle
            cout << endl << "     UPDATE EMAIL ADDRESS" << endl;
            cout << "--------------------------------" << endl << endl;
            // Open data file for writing
            info.open("Donor.dat", ios::in | ios::out | ios::binary);
            // Error message for non-existent file
            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                // User input
                cout << "Enter your Record Number: ";
                cin >> recordNumber;
                cin.ignore(); // Clears input buffer
                // Searching user's input in data file and displaying results
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
                cout << endl << "  Clinic Location:       " << record.clinic_location << endl << endl;
                cout << "----------------------------------" << endl;

                // Get new data from user and edit in-memory record
                cout << endl << "Enter the new data: " << endl << endl;

                cout << "  Email Address: ";
                cin.getline(record.email_address, SIZE);

                // Move to the right place in file and write the record
                info.seekp(recordNumber * sizeof(record), ios::beg);
                info.write(reinterpret_cast<char*>(&record), sizeof(record));
            }
            // Display confirmation of update
            cout << endl << "Your email address has now been updated!" << endl;
            // Close data file
            info.close();
            line();
            break;
        }
        case 3: // Update physical address
        {
            system("cls"); //Clears console screen
            // Display title/header
            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            // Display subtitle
            cout << endl << "     UPDATE STREET ADDRESS" << endl;
            cout << "--------------------------------" << endl << endl;
            // Open data file for writing
            info.open("Donor.dat", ios::in | ios::out | ios::binary);
            // Error message for non-existent file
            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                // User input
                cout << "Enter your Record Number: ";
                cin >> recordNumber;
                cin.ignore(); // Clears input buffer
                // Searching user's input in data file and displaying results
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
                cout << endl << "  Clinic Location:       " << record.clinic_location << endl << endl;
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
            // Display confirmation of update
            cout << endl << "Your address has now been updated!" << endl;

            // Close data file
            info.close();
            line();
            break;
        }
        case 4: // Update health conditions
        {
            system("cls"); //Clears console screen
            // Display title/header
            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            // Display subtitle
            cout << endl << "    UPDATE HEALTH CONDITIONS" << endl;
            cout << "--------------------------------" << endl << endl;
            // Open data file for writing
            info.open("Donor.dat", ios::in | ios::out | ios::binary);
            // Error message for non-existent file
            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                // User input
                cout << "Enter your Record Number: ";
                cin >> recordNumber;
                cin.ignore(); // Clears input buffer
                // Searching user's input in data file and displaying results
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
                cout << endl << "  Clinic Location:       " << record.clinic_location << endl << endl;
                cout << "----------------------------------" << endl;

                //Get new data from user and edit in-memory record
                cout << endl << "Enter the new data: " << endl << endl;
                cout << "  Health Conditions: ";
                cin.getline(record.health_conditions, SIZE);

                // Move to the right place in file and write the record
                info.seekp(recordNumber * sizeof(record), ios::beg);
                info.write(reinterpret_cast<char*>(&record), sizeof(record));
            }
            // Display confirmation of update
            cout << endl << "Your health conditions have now been updated!" << endl;
            // Close the file
            info.close();
            line();
            break;
        }
        case 5: // Display main menu
        {
            system("cls"); // Clears console screen
            view_information(); // Information menu function
            break;
        }
        default: // Incorrect input. Allows user to try a different input
        {
            cout << "Invalid selection. Please try again." << endl;
            line();
            break;
        }
        }
    } while (option < 6);
} // End of update_information function

// Function to reschedule donor appointmen
void reschedule_appointment()
{
    // Structure, function, and file variables
    Bookings booking;
    long long int recordNumber;
    fstream timeSlot;
    fstream reschedule;
    int input;

    system("cls"); //Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    // Call function to store array if time slot file not created
    check_existing();

    // Open time slot file and booking file for writing
    timeSlot.open("TimeSlots.dat", ios::out | ios::app | ios::binary);
    reschedule.open("Booking.dat", ios::in | ios::out | ios::binary);
    // Error message for non-existent file
    if (!reschedule)
    {
        cout << "Error opening file.";
    }
    else
    {
        // Display subtitle
        cout << endl << "    RESCHEDULE YOUR APPOINTMENT";
        cout << endl << "----------------------------------" << endl << endl;
        // User input
        cout << " Enter your Record Number: ";
        cin >> recordNumber;
        cin.ignore(); // Clears input buffer

        // Searching user's input in data file and displaying results
        reschedule.seekg(recordNumber * sizeof(booking), ios::beg);
        reschedule.read(reinterpret_cast<char*>(&booking), sizeof(booking));

        //Display the record first
        cout << endl << "Retrieving current appointment..." << endl;
        cout << endl << "----------------------------------" << endl;

        cout << endl << "  Day of Appointment:   " << booking.booking_day;
        cout << endl << "  Time of Appointment:  " << booking.booking_time << endl;
        cout << endl << "----------------------------------" << endl;

        // Monday loop for "Booked" timeslot to change to relevent time
        if (strcmp(booking.booking_day, "Monday") == 0 || strcmp(booking.booking_day, "monday") == 0)
        {
            if (strcmp(booking.booking_time, "9:00") == 0 || strcmp(booking.booking_time, "9") == 0)
            {
                strcpy_s(week.monday1, " 9:00");
            }
            else if (strcmp(booking.booking_time, "10:00") == 0 || strcmp(booking.booking_time, "10") == 0)
            {
                strcpy_s(week.monday2, "10:00");
            }
            else if (strcmp(booking.booking_time, "11:00") == 0 || strcmp(booking.booking_time, "11") == 0)
            {
                strcpy_s(week.monday3, "11:00");
            }
            else if (strcmp(booking.booking_time, "12:00") == 0 || strcmp(booking.booking_time, "12") == 0)
            {
                strcpy_s(week.monday4, "12:00");
            }
            else if (strcmp(booking.booking_time, "1:00") == 0 || strcmp(booking.booking_time, "1") == 0)
            {
                strcpy_s(week.monday5, " 1:00");
            }
            else if (strcmp(booking.booking_time, "2:00") == 0 || strcmp(booking.booking_time, "2") == 0)
            {
                strcpy_s(week.monday6, " 2:00");
            }
            else if (strcmp(booking.booking_time, "3:00") == 0 || strcmp(booking.booking_time, "3") == 0)
            {
                strcpy_s(week.monday7, " 3:00");
            }
            else if (strcmp(booking.booking_time, "4:00") == 0 || strcmp(booking.booking_time, "4") == 0)
            {
                strcpy_s(week.monday8, " 4:00");
            }
            timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
        }

        // Tuesday loop for "Booked" timeslot to change to relevent time
        if (strcmp(booking.booking_day, "Tuesday") == 0 || strcmp(booking.booking_day, "tuesday") == 0)
        {
            if (strcmp(booking.booking_time, "9:00") == 0 || strcmp(booking.booking_time, "9") == 0)
            {
                strcpy_s(week.tuesday1, " 9:00");
            }
            else if (strcmp(booking.booking_time, "10:00") == 0 || strcmp(booking.booking_time, "10") == 0)
            {
                strcpy_s(week.tuesday2, "10:00");
            }
            else if (strcmp(booking.booking_time, "11:00") == 0 || strcmp(booking.booking_time, "11") == 0)
            {
                strcpy_s(week.tuesday3, "11:00");
            }
            else if (strcmp(booking.booking_time, "12:00") == 0 || strcmp(booking.booking_time, "12") == 0)
            {
                strcpy_s(week.tuesday4, "12:00");
            }
            else if (strcmp(booking.booking_time, "1:00") == 0 || strcmp(booking.booking_time, "1") == 0)
            {
                strcpy_s(week.tuesday5, " 1:00");
            }
            else if (strcmp(booking.booking_time, "2:00") == 0 || strcmp(booking.booking_time, "2") == 0)
            {
                strcpy_s(week.tuesday6, " 2:00");
            }
            else if (strcmp(booking.booking_time, "3:00") == 0 || strcmp(booking.booking_time, "3") == 0)
            {
                strcpy_s(week.tuesday7, " 3:00");
            }
            else if (strcmp(booking.booking_time, "4:00") == 0 || strcmp(booking.booking_time, "4") == 0)
            {
                strcpy_s(week.tuesday8, " 4:00");
            }
            timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
        }

        // Wednesday loop for "Booked" timeslot to change to relevent time
        if (strcmp(booking.booking_day, "Wednesday") == 0 || strcmp(booking.booking_day, "wednesday") == 0)
        {
            if (strcmp(booking.booking_time, "9:00") == 0 || strcmp(booking.booking_time, "9") == 0)
            {
                strcpy_s(week.wednesday1, " 9:00");
            }
            else if (strcmp(booking.booking_time, "10:00") == 0 || strcmp(booking.booking_time, "10") == 0)
            {
                strcpy_s(week.wednesday2, "10:00");
            }
            else if (strcmp(booking.booking_time, "11:00") == 0 || strcmp(booking.booking_time, "11") == 0)
            {
                strcpy_s(week.wednesday3, "11:00");
            }
            else if (strcmp(booking.booking_time, "12:00") == 0 || strcmp(booking.booking_time, "12") == 0)
            {
                strcpy_s(week.wednesday4, "12:00");
            }
            else if (strcmp(booking.booking_time, "1:00") == 0 || strcmp(booking.booking_time, "1") == 0)
            {
                strcpy_s(week.wednesday5, " 1:00");
            }
            else if (strcmp(booking.booking_time, "2:00") == 0 || strcmp(booking.booking_time, "2") == 0)
            {
                strcpy_s(week.wednesday6, " 2:00");
            }
            else if (strcmp(booking.booking_time, "3:00") == 0 || strcmp(booking.booking_time, "3") == 0)
            {
                strcpy_s(week.wednesday7, " 3:00");
            }
            else if (strcmp(booking.booking_time, "4:00") == 0 || strcmp(booking.booking_time, "4") == 0)
            {
                strcpy_s(week.wednesday8, " 4:00");
            }
            timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
        }

        // Thursday loop for "Booked" timeslot to change to relevent time
        if (strcmp(booking.booking_day, "Thursday") == 0 || strcmp(booking.booking_day, "thursday") == 0)
        {
            if (strcmp(booking.booking_time, "9:00") == 0 || strcmp(booking.booking_time, "9") == 0)
            {
                strcpy_s(week.thursday1, " 9:00");
            }
            else if (strcmp(booking.booking_time, "10:00") == 0 || strcmp(booking.booking_time, "10") == 0)
            {
                strcpy_s(week.thursday2, "10:00");
            }
            else if (strcmp(booking.booking_time, "11:00") == 0 || strcmp(booking.booking_time, "11") == 0)
            {
                strcpy_s(week.thursday3, "11:00");
            }
            else if (strcmp(booking.booking_time, "12:00") == 0 || strcmp(booking.booking_time, "12") == 0)
            {
                strcpy_s(week.thursday4, "12:00");
            }
            else if (strcmp(booking.booking_time, "1:00") == 0 || strcmp(booking.booking_time, "1") == 0)
            {
                strcpy_s(week.thursday5, " 1:00");
            }
            else if (strcmp(booking.booking_time, "2:00") == 0 || strcmp(booking.booking_time, "2") == 0)
            {
                strcpy_s(week.thursday6, " 2:00");
            }
            else if (strcmp(booking.booking_time, "3:00") == 0 || strcmp(booking.booking_time, "3") == 0)
            {
                strcpy_s(week.thursday7, " 3:00");
            }
            else if (strcmp(booking.booking_time, "4:00") == 0 || strcmp(booking.booking_time, "4") == 0)
            {
                strcpy_s(week.thursday8, " 4:00");
            }
            timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
        }

        // Friday loop for "Booked" timeslot to change to relevent time
        if (strcmp(booking.booking_day, "Friday") == 0 || strcmp(booking.booking_day, "friday") == 0)
        {
            if (strcmp(booking.booking_time, "9:00") == 0 || strcmp(booking.booking_time, "9") == 0)
            {
                strcpy_s(week.friday1, " 9:00");
            }
            else if (strcmp(booking.booking_time, "10:00") == 0 || strcmp(booking.booking_time, "10") == 0)
            {
                strcpy_s(week.friday2, "10:00");
            }
            else if (strcmp(booking.booking_time, "11:00") == 0 || strcmp(booking.booking_time, "11") == 0)
            {
                strcpy_s(week.friday3, "11:00");
            }
            else if (strcmp(booking.booking_time, "12:00") == 0 || strcmp(booking.booking_time, "12") == 0)
            {
                strcpy_s(week.friday4, "12:00");
            }
            else if (strcmp(booking.booking_time, "1:00") == 0 || strcmp(booking.booking_time, "1") == 0)
            {
                strcpy_s(week.friday5, " 1:00");
            }
            else if (strcmp(booking.booking_time, "2:00") == 0 || strcmp(booking.booking_time, "2") == 0)
            {
                strcpy_s(week.friday6, " 2:00");
            }
            else if (strcmp(booking.booking_time, "3:00") == 0 || strcmp(booking.booking_time, "3") == 0)
            {
                strcpy_s(week.friday7, " 3:00");
            }
            else if (strcmp(booking.booking_time, "4:00") == 0 || strcmp(booking.booking_time, "4") == 0)
            {
                strcpy_s(week.friday8, " 4:00");
            }
            timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
        }

        // Get new data from user and edit in-memory record
        cout << endl << "Enter new booking details: " << endl << endl;
        cout << " Re-enter your Record Number: ";
        cin >> booking.record_number;
        cin.ignore(); // Clears input buffer

        // Dipslay subtitle
        cout << endl << " _______________________________________________________________________________________________ ";
        cout << endl << "|" << "\t\t\t\t\t\t\t\t\t\t\t       " << " |";
        cout << endl << "|" << "\t\t\t\t       TIME SLOTS AVAILABLE\t\t\t\t       " << " |";
        cout << endl << "|" << "\t\t\t\t\t\t\t\t\t\t\t       " << " |";
        // Display available time slots
        border_line();
        cout << "|    MONDAY   |  " << week.monday1 << "  |  " << week.monday2 << "  |  " << week.monday3 << "  |  " << week.monday4 << "  |  " << week.monday5 << "  |  " << week.monday6 << "  |  " << week.monday7 << "  |  " << week.monday8 << "   |";
        border_line();
        cout << "|   TUESDAY   |  " << week.tuesday1 << "  |  " << week.tuesday2 << "  |  " << week.tuesday3 << "  |  " << week.tuesday4 << "  |  " << week.tuesday5 << "  |  " << week.tuesday6 << "  |  " << week.tuesday7 << "  |  " << week.tuesday8 << "   |";
        border_line();
        cout << "|   WEDNESDAY |  " << week.wednesday1 << "  |  " << week.wednesday2 << "  |  " << week.wednesday3 << "  |  " << week.wednesday4 << "  |  " << week.wednesday5 << "  |  " << week.wednesday6 << "  |  " << week.wednesday7 << "  |  " << week.wednesday8 << "   |";
        border_line();
        cout << "|   THURSDAY  |  " << week.thursday1 << "  |  " << week.thursday2 << "  |  " << week.thursday3 << "  |  " << week.thursday4 << "  |  " << week.thursday5 << "  |  " << week.thursday6 << "  |  " << week.thursday7 << "  |  " << week.thursday8 << "   |";
        border_line();
        cout << "|    FRIDAY   |  " << week.friday1 << "  |  " << week.friday2 << "  |  " << week.friday3 << "  |  " << week.friday4 << "  |  " << week.friday5 << "  |  " << week.friday6 << "  |  " << week.friday7 << "  |  " << week.friday8 << "   |";
        border_line();
        // User inputs day
        cout << endl << endl << " Enter the preferred day: ";
        cin.getline(booking.booking_day, 14);

        // Check if input day is valid
        while (strcmp(booking.booking_day, "Monday") != 0 && strcmp(booking.booking_day, "monday") != 0 && strcmp(booking.booking_day, "Tuesday") != 0 && strcmp(booking.booking_day, "tuesday") != 0 && strcmp(booking.booking_day, "Wednesday") != 0 && strcmp(booking.booking_day, "wednesday") != 0
            && strcmp(booking.booking_day, "Thursday") != 0 && strcmp(booking.booking_day, "thursday") != 0 && strcmp(booking.booking_day, "Friday") != 0 && strcmp(booking.booking_day, "friday") != 0)
        {
            cout << endl << "Open Days are Monday - Friday. Please try again.";
            cout << endl << endl << " Enter the preferred day: ";
            cin.getline(booking.booking_day, 14);
        }

        // User inputs time
        cout << " Enter the preferred time (i.e. 9:00 or 9): ";
        cin.getline(booking.booking_time, 14);

        // Check if input time is valid
        while (strcmp(booking.booking_time, "9:00") != 0 && strcmp(booking.booking_time, "9") != 0 && strcmp(booking.booking_time, "10:00") != 0 && strcmp(booking.booking_time, "10") != 0 && strcmp(booking.booking_time, "11:00") != 0 && strcmp(booking.booking_time, "11") != 0 && strcmp(booking.booking_time, "12:00") != 0 && strcmp(booking.booking_time, "12") != 0
            && strcmp(booking.booking_time, "1:00") != 0 && strcmp(booking.booking_time, "1") != 0 && strcmp(booking.booking_time, "2:00") != 0 && strcmp(booking.booking_time, "2") != 0 && strcmp(booking.booking_time, "3:00") != 0 && strcmp(booking.booking_time, "3") != 0 && strcmp(booking.booking_time, "4:00") != 0 && strcmp(booking.booking_time, "4") != 0)
        {
            cout << endl << "Booking Hours are 9:00am - 4:00pm. Please try again.";
            cout << endl << endl << " Enter the preferred time (i.e. 9:00 or 9): ";
            cin.getline(booking.booking_time, 14);
        }


        // Monday loop for selected timeslot to change to "Booked"
        if (strcmp(booking.booking_day, "Monday") == 0 || strcmp(booking.booking_day, "monday") == 0)
        {
            if (strcmp(booking.booking_time, "9:00") == 0 || strcmp(booking.booking_time, "9") == 0)
            {
                strcpy_s(week.monday1, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "10:00") == 0 || strcmp(booking.booking_time, "10") == 0)
            {
                strcpy_s(week.monday2, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "11:00") == 0 || strcmp(booking.booking_time, "11") == 0)
            {
                strcpy_s(week.monday3, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "12:00") == 0 || strcmp(booking.booking_time, "12") == 0)
            {
                strcpy_s(week.monday4, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "1:00") == 0 || strcmp(booking.booking_time, "1") == 0)
            {
                strcpy_s(week.monday5, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "2:00") == 0 || strcmp(booking.booking_time, "2") == 0)
            {
                strcpy_s(week.monday6, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "3:00") == 0 || strcmp(booking.booking_time, "3") == 0)
            {
                strcpy_s(week.monday7, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "4:00") == 0 || strcmp(booking.booking_time, "4") == 0)
            {
                strcpy_s(week.monday8, ("\x1B[31mBooked\033[0m"));
            }
            timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
        }

        // Tuesday loop for selected timeslot to change to "Booked"
        if (strcmp(booking.booking_day, "Tuesday") == 0 || strcmp(booking.booking_day, "tuesday") == 0)
        {
            if (strcmp(booking.booking_time, "9:00") == 0 || strcmp(booking.booking_time, "9") == 0)
            {
                strcpy_s(week.tuesday1, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "10:00") == 0 || strcmp(booking.booking_time, "10") == 0)
            {
                strcpy_s(week.tuesday2, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "11:00") == 0 || strcmp(booking.booking_time, "11") == 0)
            {
                strcpy_s(week.tuesday3, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "12:00") == 0 || strcmp(booking.booking_time, "12") == 0)
            {
                strcpy_s(week.tuesday4, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "1:00") == 0 || strcmp(booking.booking_time, "1") == 0)
            {
                strcpy_s(week.tuesday5, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "2:00") == 0 || strcmp(booking.booking_time, "2") == 0)
            {
                strcpy_s(week.tuesday6, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "3:00") == 0 || strcmp(booking.booking_time, "3") == 0)
            {
                strcpy_s(week.tuesday7, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "4:00") == 0 || strcmp(booking.booking_time, "4") == 0)
            {
                strcpy_s(week.tuesday8, ("\x1B[31mBooked\033[0m"));
            }
            timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
        }

        // Wednesday loop for selected timeslot to change to "Booked"
        if (strcmp(booking.booking_day, "Wednesday") == 0 || strcmp(booking.booking_day, "wednesday") == 0)
        {
            if (strcmp(booking.booking_time, "9:00") == 0 || strcmp(booking.booking_time, "9") == 0)
            {
                strcpy_s(week.wednesday1, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "10:00") == 0 || strcmp(booking.booking_time, "10") == 0)
            {
                strcpy_s(week.wednesday2, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "11:00") == 0 || strcmp(booking.booking_time, "11") == 0)
            {
                strcpy_s(week.wednesday3, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "12:00") == 0 || strcmp(booking.booking_time, "12") == 0)
            {
                strcpy_s(week.wednesday4, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "1:00") == 0 || strcmp(booking.booking_time, "1") == 0)
            {
                strcpy_s(week.wednesday5, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "2:00") == 0 || strcmp(booking.booking_time, "2") == 0)
            {
                strcpy_s(week.wednesday6, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "3:00") == 0 || strcmp(booking.booking_time, "3") == 0)
            {
                strcpy_s(week.wednesday7, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "4:00") == 0 || strcmp(booking.booking_time, "4") == 0)
            {
                strcpy_s(week.wednesday8, ("\x1B[31mBooked\033[0m"));
            }
            timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
        }

        // Thursday loop for selected timeslot to change to "Booked"
        if (strcmp(booking.booking_day, "Thursday") == 0 || strcmp(booking.booking_day, "thursday") == 0)
        {
            if (strcmp(booking.booking_time, "9:00") == 0 || strcmp(booking.booking_time, "9") == 0)
            {
                strcpy_s(week.thursday1, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "10:00") == 0 || strcmp(booking.booking_time, "10") == 0)
            {
                strcpy_s(week.thursday2, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "11:00") == 0 || strcmp(booking.booking_time, "11") == 0)
            {
                strcpy_s(week.thursday3, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "12:00") == 0 || strcmp(booking.booking_time, "12") == 0)
            {
                strcpy_s(week.thursday4, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "1:00") == 0 || strcmp(booking.booking_time, "1") == 0)
            {
                strcpy_s(week.thursday5, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "2:00") == 0 || strcmp(booking.booking_time, "2") == 0)
            {
                strcpy_s(week.thursday6, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "3:00") == 0 || strcmp(booking.booking_time, "3") == 0)
            {
                strcpy_s(week.thursday7, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "4:00") == 0 || strcmp(booking.booking_time, "4") == 0)
            {
                strcpy_s(week.thursday8, ("\x1B[31mBooked\033[0m"));
            }
            timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
        }

        // Friday loop for selected timeslot to change to "Booked"
        if (strcmp(booking.booking_day, "Friday") == 0 || strcmp(booking.booking_day, "friday") == 0)
        {
            if (strcmp(booking.booking_time, "9:00") == 0 || strcmp(booking.booking_time, "9") == 0)
            {
                strcpy_s(week.friday1, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "10:00") == 0 || strcmp(booking.booking_time, "10") == 0)
            {
                strcpy_s(week.friday2, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "11:00") == 0 || strcmp(booking.booking_time, "11") == 0)
            {
                strcpy_s(week.friday3, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "12:00") == 0 || strcmp(booking.booking_time, "12") == 0)
            {
                strcpy_s(week.friday4, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "1:00") == 0 || strcmp(booking.booking_time, "1") == 0)
            {
                strcpy_s(week.friday5, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "2:00") == 0 || strcmp(booking.booking_time, "2") == 0)
            {
                strcpy_s(week.friday6, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "3:00") == 0 || strcmp(booking.booking_time, "3") == 0)
            {
                strcpy_s(week.friday7, ("\x1B[31mBooked\033[0m"));
            }
            else if (strcmp(booking.booking_time, "4:00") == 0 || strcmp(booking.booking_time, "4") == 0)
            {
                strcpy_s(week.friday8, ("\x1B[31mBooked\033[0m"));
            }
            timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
        }

        // Display booking confirmation
        cout << endl << endl << " Your booking has been confirmed!";
        cout << endl << " Your new appointment to donate blood is on " << booking.booking_day << " at " << booking.booking_time << endl;

        // Display subtitle
        cout << endl << " _______________________________________________________________________________________________ ";
        cout << endl << "|" << "\t\t\t\t\t\t\t\t\t\t\t       " << " |";
        cout << endl << "|" << "\t\t\t\t  UPDATED TIME SLOTS AVAILABLE\t\t\t\t       " << " |";
        cout << endl << "|" << "\t\t\t\t\t\t\t\t\t\t\t       " << " |";
        // Display new available time slots
        border_line();
        cout << "|    MONDAY   |  " << week.monday1 << "  |  " << week.monday2 << "  |  " << week.monday3 << "  |  " << week.monday4 << "  |  " << week.monday5 << "  |  " << week.monday6 << "  |  " << week.monday7 << "  |  " << week.monday8 << "   |";
        border_line();
        cout << "|   TUESDAY   |  " << week.tuesday1 << "  |  " << week.tuesday2 << "  |  " << week.tuesday3 << "  |  " << week.tuesday4 << "  |  " << week.tuesday5 << "  |  " << week.tuesday6 << "  |  " << week.tuesday7 << "  |  " << week.tuesday8 << "   |";
        border_line();
        cout << "|   WEDNESDAY |  " << week.wednesday1 << "  |  " << week.wednesday2 << "  |  " << week.wednesday3 << "  |  " << week.wednesday4 << "  |  " << week.wednesday5 << "  |  " << week.wednesday6 << "  |  " << week.wednesday7 << "  |  " << week.wednesday8 << "   |";
        border_line();
        cout << "|   THURSDAY  |  " << week.thursday1 << "  |  " << week.thursday2 << "  |  " << week.thursday3 << "  |  " << week.thursday4 << "  |  " << week.thursday5 << "  |  " << week.thursday6 << "  |  " << week.thursday7 << "  |  " << week.thursday8 << "   |";
        border_line();
        cout << "|    FRIDAY   |  " << week.friday1 << "  |  " << week.friday2 << "  |  " << week.friday3 << "  |  " << week.friday4 << "  |  " << week.friday5 << "  |  " << week.friday6 << "  |  " << week.friday7 << "  |  " << week.friday8 << "   |";
        border_line();

        // Move to the right place in file and write the record
        timeSlot.seekp(recordNumber * sizeof(week), ios::beg);
        timeSlot.write(reinterpret_cast<char*>(&week), sizeof(week));
        reschedule.seekp(recordNumber * sizeof(booking), ios::beg);
        reschedule.write(reinterpret_cast<char*>(&booking), sizeof(booking));
    }
    // Close data files
    reschedule.close();

    cout << endl << "Press 1 to return to the Manage Information Menu: ";
    cin >> input;
    if (input == 1)
    {
        view_information();
    }
    else
    {
        cout << endl << "Invalid key. Press 1 to return to the Manage Information Menu: ";
    }

} // End of reschedule_appointment function

// Function to obtain new recipient registration information
void recipient_registration()
{
    // Structure and file variables
    fstream info;
    Recipient_Details record;

    system("cls"); //Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    // Display subtitle
    cout << endl << "    RECIPIENT REGISTRATION" << endl;
    cout << "--------------------------------" << endl << endl;

    // Open data file for writing
    info.open("Recipient.dat", ios::out | ios::app | ios::binary);
    // Error message for non-existent file
    if (!info)
    {
        cout << "Error opening file.";
    }
    // User input & writing in data file
    else
    {
        cout << "  Company Name: ";
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

        // User chooses their username & password for future use 
        cout << endl << endl << "  Username: ";
        cin.getline(record.username, SIZE);
        cout << "  Password: ";
        cin.getline(record.password, SIZE);

        // Writing user's input to data file
        info.write(reinterpret_cast<char*>(&record), sizeof(record));
        // Close data file
        info.close();
    }
    // Display registration confirmation
    cout << endl << "Thank you for registering! Please select Option 4 in the Main Menu to Login." << endl;
    line();
} // End of recipient_registration function

// Function to obtain new recipient registration information
void recipient_login()
{
    // Function and file variables
    fstream info;
    bool flag = false;
    char name[SIZE];
    char pass[SIZE];
    int attempt = 0;

    system("cls"); //Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    // Display subtitle
    cout << endl << "  \tRECIPIENT LOGIN" << endl;
    cout << "--------------------------------" << endl << endl;

    // Open the file for reading
    info.open("Recipient.dat", ios::in | ios::binary);
    // Error message for non-existent file
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        // Loop for 3 login attempts
        for (attempt = 0; attempt < 3; attempt++)
        {
            // User Input
            cout << " Enter Username: ";
            cin.getline(name, SIZE);
            cout << " Enter Password: ";
            cin.getline(pass, SIZE);
            // Call search recipient function to read file for matching the entered details
            if (search_recipient_file(name, pass)) // Do following if check is correct
            {
                system("cls"); // Clears console screen
                cout << "\t\t\t\t\t\t\t\t\tWelcome back " << name << "!"; // Will wellcome and display entered username on next screen
                recipient_menu(); // Call recipient menu function
                flag = true;
                break;
            }
            if (flag == false) // Display message if incorrect details entered
            {
                cout << endl << "Incorrect Username or Password. Please try again." << endl << endl;
            }
        }
        if (attempt > 2) // Close program if incorrect details entered 3 times
        {
            cout << endl << "Limit reached. Program Exited..." << endl << endl;
            exit(0);
        }
    }
    // Close data file
    info.close();
} // End of recipient_login function

// Function to check login against recipient data file
bool search_recipient_file(char name[], char pass[])
{
    // Structure, function, and file variables
    bool flag = false;
    fstream info;
    Recipient_Details record;

    // Open data file for reading
    info.open("Recipient.dat", ios::in | ios::binary);
    info.read(reinterpret_cast<char*>(&record), sizeof(record));

    while (!info.eof())
    {
        // Check if entered username and password matches data file
        if ((strcmp(name, record.username) == 0) && (strcmp(pass, record.password) == 0))
        {
            flag = true;
            break;
        }
        info.read(reinterpret_cast<char*>(&record), sizeof(record));
    }
    // Close data file
    info.close();
    // Return true/false flag to recipient login function
    return flag;
}

// Function to display recipient menu
void recipient_menu()
{
    // Function variable
    int option;
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    while (1)
    {
        // Dipslay subtitle and recipient menu
        cout << endl << "  \tRECIPIENT MENU" << endl;
        cout << "--------------------------------" << endl << endl;
        cout << " Access Donor Information via: " << endl;
        cout << "  1. Full Name" << endl;
        cout << "  2. Blood Group" << endl;
        cout << "  3. Location" << endl;
        cout << "  4. Logout" << endl;

        cout << endl << " Enter your option: "; //User Option Input
        cin >> option;
        cin.ignore(); //Clears input buffer

        cout << endl << endl;

        switch (option)
        {
        case 1: // Search by full name function
        {
            full_name();
            break;
        }
        case 2: // Search by blood group function
        {
            blood_group();
            break;
        }
        case 3: // Search by location function
        {
            location();
            break;
        }
        case 4: // Return to main menu
        {
            system("cls"); // Clears console screen
            cout << "\t\t\t\t\t\t\t\t\t\tLogged out"; // Will display on Main Menu Screen
            main();
        }
        default: // Incorrect input. Allows user to try a different input
        {
            cout << "Invalid selection. Please try again." << endl;
            line();
            break;
        }

        }
    }
} // End of recipient_menu function

// Function to search by donor's full name & display
void full_name()
{
    // Structure, function, and file variables
    Donor_Details record;
    fstream info;
    bool flag = false;
    char firstName[SIZE];
    char lastName[SIZE];

    system("cls"); // Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    // Display subtitle
    cout << endl << "      FULL NAME SEARCH" << endl;
    cout << "--------------------------------" << endl << endl;
    // Open the file for reading
    info.open("Donor.dat", ios::in | ios::binary);
    // Error message for non-existent file
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        // User Input
        cout << "Search by Donor's Full Name" << endl << endl;
        cout << " Enter First Name: ";
        cin.getline(firstName, SIZE);
        cout << " Enter Last Name: ";
        cin.getline(lastName, SIZE);
        cout << endl << "Retrieving matching records..." << endl << endl;
        cout << "----------------------------------" << endl;

        // Searching user's input in data file and displaying results
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
                cout << endl << "----------------------------------" << endl;
                flag = true;
            }
            info.read(reinterpret_cast<char*>(&record), sizeof(record));
        }
        if (flag == true) // Display to confirm all relevent data has been shown
        {
            cout << endl << "That's all the information in the file matching the name provided." << endl;
            line();
        }
        else // Display when searched name is not in file
        {
            cout << endl << firstName << " " << lastName << " cannot be found in our records. Please try again." << endl;
            line();
        }
    }
    //Close data file
    info.close();
} // End of full_name function

// Function to search by donor blood type & display
void blood_group()
{
    // Structure, function, and file variables
    Donor_Details record;
    fstream info;
    bool flag = false;
    char bloodGroup[14];

    system("cls"); // Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    // Display subtitle
    cout << endl << "      BLOOD GROUP SEARCH" << endl;
    cout << "--------------------------------" << endl << endl;
    // Open the file for reading
    info.open("Donor.dat", ios::in | ios::binary);
    // Error message for non-existent file
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        // User Input
        cout << "Search by Blood Group" << endl << endl;
        cout << " Enter Blood Type: ";
        cin.getline(bloodGroup, 14);
        cout << endl << "Retrieving matching records..." << endl;
        cout << endl << "----------------------------------" << endl;

        // Searching user's input in data file and displaying results
        info.read(reinterpret_cast<char*>(&record), sizeof(record));
        while (!info.eof())
        {
            if (strcmp(bloodGroup, record.blood_group) == 0)
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
                cout << endl << "----------------------------------" << endl;
                flag = true;
            }
            info.read(reinterpret_cast<char*>(&record), sizeof(record));
        }

        if (flag == true) // Display to confirm all relevent data has been shown
        {
            cout << endl << "That's all the information in the file matching the Blood Type provided." << endl;
            line();
        }
        else // Display when searched name is not in file
        {
            cout << endl << bloodGroup << " cannot be found in our records. Please try again." << endl;
            line();
        }
    }
    //Close data file
    info.close();
} // End of blood_group function

// Function to search by donor loaction & display
void location()
{
    // Structure, function, and file variables
    Donor_Details record;
    fstream info;
    bool flag = false;
    char location[51];

    system("cls"); //Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    // Display subtitle
    cout << endl << "      LOCATION SEARCH" << endl;
    cout << "--------------------------------" << endl << endl;
    // Open the file for reading
    info.open("Donor.dat", ios::in | ios::binary);
    // Error message for non-existent file
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        //User Input
        cout << "Search by Location" << endl << endl;
        cout << " Enter Clinic Location: ";
        cin.getline(location, 14);
        cout << endl << "Retrieving matching records..." << endl;
        cout << endl << "----------------------------------" << endl;

        // Searching user's input in data file and displaying results
        info.read(reinterpret_cast<char*>(&record), sizeof(record));
        while (!info.eof())
        {
            if (strcmp(location, record.clinic_location) == 0)
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
                cout << endl << "--------------------------------- " << endl;
                flag = true;
            }
            info.read(reinterpret_cast<char*>(&record), sizeof(record));
        }

        if (flag == true) // Display to confirm all relevent data has been shown
        {
            cout << endl << "That's all the information in the file matching the location provided." << endl;
            line();
        }
        else // Display when searched name is not in file
        {
            cout << endl << location << " cannot be found in our records. Please try again." << endl;
            line();
        }
    }
    //Close data file
    info.close();
} // End of location function

// Function for admin login (fixed username & password)
void admin_login()
{
    // Function variables
    string username("Admin");
    string password("Password");
    string user;
    string pass;
    bool flag = false;
    int attempt = 0;

    system("cls"); //Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    // Display subtitle
    cout << endl << " \tADMIN LOGIN" << endl;
    cout << "--------------------------------" << endl << endl;

    // Loop for 3 login attempts
    while (attempt < 3)
    {
        // User input
        cout << " Enter Username: ";
        cin >> user;
        cout << " Enter Password: ";
        cin >> pass;
        // Check if input matches default 
        if ((user == username) && (pass == password))
        {
            system("cls"); //Clears console screen
            cout << "\t\t\t\t\t\t\t\t\tWelcome back " << user << "!"; // Will wellcome and display entered username on next screen
            flag = true;
            admin_menu(); // Call admin menu function
        }
        else if (flag == false) // Display message if incorrect details entered
        {
            cout << endl << "Incorrect Username or Password. Please try again." << endl;
            line();
            attempt++;
        }
        while (attempt > 2) // Close program if incorrect details entered 3 times
        {
            cout << "Limit reached. Program Exited..." << endl << endl;
            exit(0);
        }
    }
    line();
} // End of admin_login function

// Function to display admin menu  
void admin_menu()
{
    // Function variable
    int option;
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    do
    {
        // Display subtitle and admin menu
        cout << endl << "  \tADMIN MENU" << endl;
        cout << "--------------------------------" << endl << endl;
        cout << " 1. View Recipient Information" << endl;
        cout << " 2. Recipient Report" << endl;
        cout << " 3. View Donor Information" << endl;
        cout << " 4. Donors Report" << endl;
        cout << " 5. Update Donor's Blood Report" << endl;
        cout << " 6. Blood Group Report" << endl;
        cout << " 7. Location Report" << endl;
        cout << " 8. Logout" << endl;

        cout << endl << " Enter your option: "; //User Option Input
        cin >> option;
        cin.ignore(); //Clears input buffer
        cout << endl;

        switch (option)
        {

        case 1: // Search recipient information function
        {
            search_recipient();
            break;
        }
        case 2: // View recipient report function 
        {
            recipient_report();
            break;
        }
        case 3: // Search donor information function
        {
            search_donor();
            break;
        }
        case 4: // View donors report function
        {
            donor_report();
            break;
        }
        case 5: // Update donor's blood group function
        {
            update_blood();
            break;
        }
        case 6: // View blood group report function
        {
            blood_report();
            break;
        }
        case 7: // View location report function
        {
            location_report();
            break;
        }
        case 8: // Return to main menu
        {
            system("cls"); // Clears console screen
            cout << "\t\t\t\t\t\t\t\t\t\tLogged out"; // Will display on Main Menu Screen
            main();
        }
        default: // Incorrect input. Allows user to try a different input
        {
            cout << "Invalid selection. Please try again." << endl;
            line();
        }
        }
    } while (option < 8);
} // End of admin_menu function

// Function for admin to search and view Recipient Information
void search_recipient()
{
    // Structure, function and file variables
    fstream info;
    Recipient_Details record;
    bool flag = false;
    char name[SIZE];

    system("cls"); // Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    // Display subtitle
    cout << endl << "     RECIPIENT SEARCH" << endl;
    cout << "--------------------------------" << endl << endl;
    // Open data file for reading
    info.open("Recipient.dat", ios::in | ios::binary);
    // Error message for non-existent file
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
        cout << endl << "----------------------------------" << endl;

        // Searching user's input in data file and displaying results
        info.read(reinterpret_cast<char*>(&record), sizeof(record));
        while (!info.eof())
        {
            if ((strcmp(name, record.name) == 0))
            {
                cout << endl << "  Name:                  " << record.name;
                cout << endl << "  Contact Number:        " << record.contact_number;
                cout << endl << "  Email Address:         " << record.email_address;
                cout << endl << "  Street Address:        " << record.address_line1;
                cout << endl << "  Suburb/City:           " << record.address_line2;
                cout << endl << "  Registration Status:   " << record.registration_status << endl;
                cout << endl << "----------------------------------" << endl;
                flag = true;
            }
            info.read(reinterpret_cast<char*>(&record), sizeof(record));
        }
        if (flag == true) // Display to confirm all relevent data has been shown
        {
            cout << endl << "That's all the information in the file matching the name provided." << endl;
            line();
        }
        else // Display when searched name is not in file
        {
            cout << endl << name << " cannot be found in our records. Please try again." << endl;
            line();
        }
    }
    //Close data file
    info.close();
} // End of search_recipient function

// Function for admin to view complete recipient report 
void recipient_report()
{
    // Structure and file variables
    Recipient_Details record;
    fstream info;

    system("cls"); //Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    // Display subtitle
    cout << endl << "  \tRECIPIENT LIST" << endl;
    cout << "--------------------------------" << endl;

    // Open the file for reading
    info.open("Recipient.dat", ios::in | ios::binary);
    // Error message for non-existent file
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        // Display all recipient records
        info.read(reinterpret_cast<char*>(&record), sizeof(record));
        while (!info.eof())
        {
            cout << endl << "  Name:                  " << record.name;
            cout << endl << "  Contact Number:        " << record.contact_number;
            cout << endl << "  Email Address:         " << record.email_address;
            cout << endl << "  Street Address:        " << record.address_line1;
            cout << endl << "  Suburb/City:           " << record.address_line2;
            cout << endl << "  Registration Status:   " << record.registration_status << endl;
            cout << endl << "----------------------------------" << endl;

            //Read one structure at time & display
            info.read(reinterpret_cast<char*>(&record), sizeof(record));
        }
    }
    // Display to confirm all relevent data has been shown
    cout << endl << "All records on file retrieved..." << endl;
    //Close File
    info.close();
    line();
} // End of recipient_report funtion

// Function for admin to search and view donor information
void search_donor()
{
    // Structure, function and file variables
    Donor_Details record;
    fstream info;
    bool flag = false;
    char firstName[SIZE];
    char lastName[SIZE];

    system("cls"); // Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    // Display subtitle
    cout << endl << "      DONOR SEARCH" << endl;
    cout << "--------------------------------" << endl << endl;
    // Open data file for reading
    info.open("Donor.dat", ios::in | ios::binary);
    // Error message for non-existent file
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        //User Input
        cout << "Search by Donor's Full Name" << endl << endl;
        cout << " Enter First Name: ";
        cin.getline(firstName, SIZE);
        cout << " Enter Last Name: ";
        cin.getline(lastName, SIZE);
        cout << endl << "Retrieving matching records..." << endl;
        cout << endl << "----------------------------------" << endl;

        // Searching user's input in data file and displaying results
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
                cout << endl << "----------------------------------" << endl;
                flag = true;
            }
            info.read(reinterpret_cast<char*>(&record), sizeof(record));
        }

        if (flag == true) // Display to confirm all relevent data has been shown
        {
            cout << endl << "That's all the information in the file matching the name provided." << endl;
            line();
        }
        else // Display when searched name is not in file
        {
            cout << endl << firstName << " " << lastName << " cannot be found in our records. Please try again." << endl;
            line();
        }

    }
    //Close data file
    info.close();
} // End of search_donor function

// Function for admin to update sonor's blood type
void update_blood()
{
    // Structure, function and file variables
    Donor_Details record;
    fstream info;
    long long int recordNumber;

    system("cls"); // Clears console screen
    // Display title/header
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();

    // Display subtitle
    cout << endl << "\tUPDATE BLOOD GROUP" << endl;
    cout << "--------------------------------" << endl << endl;
    // Open data file for writing
    info.open("Donor.dat", ios::in | ios::out | ios::binary);
    // Error message for non-existent file
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        // User input
        cout << "Enter your Record Number: ";
        cin >> recordNumber;
        cin.ignore();
        // Searching user's input in data file and displaying results
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

        // Get new data from user and edit in-memory record
        cout << endl << "Enter the new data:" << endl << endl;
        cout << "  Blood Group: ";
        cin.getline(record.blood_group, SIZE);

        // Move to the right place in file and write the record
        info.seekp(recordNumber * sizeof(record), ios::beg);
        info.write(reinterpret_cast<char*>(&record), sizeof(record));
    }
    // Display confirmation of update
    cout << endl << "The required Blood Group has been updated." << endl;
    // Close data file
    info.close();
    line();
} // End of update_blood function

// Function for admin to view complete donor report 
void donor_report()
{
    // Structure and file variables
    Donor_Details record;
    fstream info;

    system("cls"); //Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    // Display subtitle
    cout << endl << "  \tDONOR LIST" << endl;
    cout << "--------------------------------" << endl;

    // Open the file for reading
    info.open("Donor.dat", ios::in | ios::binary);
    // Error message for non-existent file
    if (!info)
    {
        cout << "Error in opening the file... " << endl;
        line();
    }
    else
    {
        // Display all donor records
        info.read(reinterpret_cast<char*>(&record), sizeof(record));
        while (!info.eof())
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
            cout << endl << "  Clinic Location:       " << record.clinic_location << endl << endl;
            cout << "----------------------------------" << endl;

            //Read one structure at time & display
            info.read(reinterpret_cast<char*>(&record), sizeof(record));
        }
    }
    // Display to confirm all relevent data has been shown
    cout << endl << "All records on file retrieved..." << endl;
    //Close data file
    info.close();
    line();
}

// Function for admin to search and view blood report 
void blood_report()
{
    // Structure, function, and file variables
    Donor_Details record;
    fstream info;
    int option;
    bool flag = false;
    char bloodGroup[14];

    system("cls"); //Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    do
    {
        // Display subtitle and blood group menu
        cout << endl << "\tBLOOD GROUP" << endl;
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
            // Display title/header
            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            // Display subtitle
            cout << endl << "    BLOOD TYPE SEARCH" << endl;
            cout << "--------------------------------" << endl << endl;
            // Open the file for reading
            info.open("Donor.dat", ios::in | ios::binary);
            // Error message for non-existent file
            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                //User Input
                cout << "Search by Blood Group" << endl << endl;
                cout << " Enter Blood Type: ";
                cin.getline(bloodGroup, 14);
                cout << endl << "Retrieving matching records..." << endl;
                cout << endl << "----------------------------------" << endl;

                cout << endl << " Record:" << "\tFull Name:" << "\t\tContact Number:" << "\t\tBlood Group:";
                cout << endl << " *******" << "\t**********" << "\t\t***************" << "\t\t************" << endl;
                // Searching user's input in data file and displaying results
                info.read(reinterpret_cast<char*>(&record), sizeof(record));
                while (!info.eof())
                {
                    if (strcmp(bloodGroup, record.blood_group) == 0)
                    {
                        cout << endl << " " << record.record_number << "\t\t" << record.first_name << " " << record.last_name << "\t\t" << record.contact_number << "\t\t" << record.blood_group;
                        cout << endl << endl;
                        flag = true;
                    }
                    //Read one structure at time & display
                    info.read(reinterpret_cast<char*>(&record), sizeof(record));
                }
                if (flag == true) // Display to confirm all relevent data has been shown
                {
                    cout << endl << "That's all the information in the file matching the Blood Type provided." << endl;
                    line();
                }
                else // Display when searched name is not in file
                {
                    cout << endl << bloodGroup << " cannot be found in our records. Please try again." << endl;
                    line();
                }
            }
            // Close data file
            info.close();
            break;
        }
        case 2:
        {
            system("cls"); //Clears console screen
            // Display title/header
            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            // Display subtitle
            cout << endl << "\tBLOOD GROUP REPORT" << endl;
            cout << "--------------------------------" << endl;

            // Open the file for reading
            info.open("Donor.dat", ios::in | ios::binary);
            // Error message for non-existent file
            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                cout << endl << " Record:" << "\tFull Name:" << "\t\tContact Number:" << "\t\tBlood Group:";
                cout << endl << " *******" << "\t**********" << "\t\t***************" << "\t\t************" << endl;

                // Display all blood group records
                info.read(reinterpret_cast<char*>(&record), sizeof(record));
                while (!info.eof())
                {
                    cout << endl << " " << record.record_number << "\t\t" << record.first_name << " " << record.last_name << "\t\t" << record.contact_number << "\t\t" << record.blood_group;
                    cout << endl << endl;

                    //Read one structure at time & display
                    info.read(reinterpret_cast<char*>(&record), sizeof(record));
                }
            }
            // Display to confirm all relevent data has been shown
            cout << endl << "All records on file retrieved..." << endl;
            // Close data file
            info.close();
            line();
            break;
        }
        case 3:
        {
            system("cls"); // Clears console screen
            // Re-Displaying header as it won't appear breaking out of this menu otherwise
            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            break;
        }
        default: // Incorrect input. Allows user to try a different input
        {
            cout << "Invalid selection. Please try again." << endl;
            line();
        }
        }
    } while (option < 3);
} // End of blood_report function

// Function for admin to search and view location Report 
void location_report()
{
    // Structure, function, and file variables
    Donor_Details record;
    fstream info;
    int option;
    bool flag = false;
    char location[SIZE];

    system("cls"); //Clears console screen
    // Display title/header
    border_line();
    cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
    border_line();
    do
    {
        // Display subtitle and location menu
        cout << endl << "\tLOCATION" << endl;
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
            // Display title/header
            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            // Display subtitle
            cout << endl << "    LOCATION SEARCH" << endl;
            cout << "--------------------------------" << endl << endl;
            // Open the file for reading
            info.open("Donor.dat", ios::in | ios::binary);
            // Error message for non-existent file
            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                //User Input
                cout << "Search by Location" << endl << endl;
                cout << " Enter Clinic Location: ";
                cin.getline(location, 14);
                cout << endl << "Retrieving matching records..." << endl;
                cout << endl << "----------------------------------" << endl;

                cout << endl << " Record:" << "\tFull Name:" << "\t\tContact Number:" << "\t\tLocation:";
                cout << endl << " *******" << "\t**********" << "\t\t***************" << "\t\t*********" << endl;
                // Searching user's input in data file and displaying results
                info.read(reinterpret_cast<char*>(&record), sizeof(record));
                while (!info.eof())
                {
                    if (strcmp(location, record.clinic_location) == 0)
                    {
                        cout << endl << " " << record.record_number << "\t\t" << record.first_name << " " << record.last_name << "\t\t" << record.contact_number << "\t\t" << record.clinic_location;
                        cout << endl << endl;
                        flag = true;
                    }
                    //Read one structure at time & display
                    info.read(reinterpret_cast<char*>(&record), sizeof(record));
                }
                if (flag == true) // Display to confirm all relevent data has been shown
                {
                    cout << endl << "That's all the information in the file matching the location provided." << endl;
                    line();
                }
                else // Display when searched name is not in file
                {
                    cout << endl << location << " cannot be found in our records. Please try again." << endl;
                    line();
                }
            }
            //Close data file
            info.close();
            break;
        }
        case 2:
        {
            system("cls"); //Clears console screen
            // Display title/header
            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            // Display subtitle
            cout << endl << "\tLOCATION REPORT" << endl;
            cout << "--------------------------------" << endl;

            // Open the file for reading
            info.open("Donor.dat", ios::in | ios::binary);
            // Error message for non-existent file
            if (!info)
            {
                cout << "Error in opening the file... " << endl;
                line();
            }
            else
            {
                cout << endl << " Record:" << "\tFull Name:" << "\t\tContact Number:" << "\t\tLocation:";
                cout << endl << " *******" << "\t**********" << "\t\t***************" << "\t\t*********" << endl;

                // Display all location records
                info.read(reinterpret_cast<char*>(&record), sizeof(record));

                while (!info.eof())
                {
                    cout << endl << " " << record.record_number << "\t\t" << record.first_name << " " << record.last_name << "\t\t" << record.contact_number << "\t\t" << record.clinic_location;
                    cout << endl << endl;

                    //Read one structure at time & display
                    info.read(reinterpret_cast<char*>(&record), sizeof(record));
                }
            }
            // Display to confirm all relevent data has been shown
            cout << endl << "All records on file retrieved..." << endl;
            //Close data file
            info.close();
            line();
            break;
        }
        case 3:
        {
            system("cls"); // Clears console screen
            // Re-Displaying header as it won't appear breaking out of this menu otherwise
            border_line();
            cout << endl << ("\x1B[31m\t\t\t\t AOTEAROA BLOOD\033[0m") << endl << endl;
            border_line();
            break;
        }
        default: // Incorrect input. Allows user to try a different input
        {
            cout << "Invalid selection. Please try again." << endl;
            line();
        }
        }
    } while (option < 3);
} // End of location_report function

// Function to display ---------- 
void line()
{
    cout << endl;
    for (int i = 0; i < 97; i++)
    {
        cout << "-";
    }
    cout << endl;
}

// Function to display x----------x 
void border_line()
{
    cout << endl << "+";
    for (int i = 0; i < 95; i++)
    {
        cout << "-";
    }
    cout << "+" << endl;
}
