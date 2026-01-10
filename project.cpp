#include <iostream> // using cin and cout
#include <string> // for using string class
#include <vector> // using vector to dynamically add elements 
#include <cstdlib> // for random number generation 
#include <ctime> // get the current calender time 
#include <iomanip> // for using minipulators

using namespace std;

// ANSI color codes
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";
const string RESET = "\033[0m";

//############## Basic structures Used ################################
// Contains all the information about patient expenses
struct Fee
{
    float doctor;
    float medical;
    float room;
    float total;
    string status = "Unpaid";
};

// Contains information about patient
struct Patient
{
    string id;
    string name;
    int age;
    char gender;    
    string contact;     
    string status; // disease or symptom
    Fee charges; 
};

// All information about medicine and their corresponding disease 
// Also how much of a particular medicine is available in stock
struct Pharmacy{
    string diseasename;
    string medicinename;
    int stock;
};

vector<Patient> patients;

//######################## Utility Functions #####################################33
void displayTitle(string title) 
{
    cout << endl;
    cout << CYAN << "====================================" << RESET << endl << endl;
    cout << CYAN << "\t" << title << RESET << endl << endl;
    cout << CYAN << "====================================" << RESET << endl;
    cout << endl << endl;
}

string generateId(int length) 
{
    string id;
    srand(time(0));
    for (int i = 0; i < length; i++) 
    {
        int digit = rand() % 10;
        id += to_string(digit);
    }
    return id; 
}

void repchar(char ch, int n) 
{
    for (int i = 0; i < n; i++)
    {
        cout << ch;
    }
    cout << endl;
}

//#################################### Patient Management #################################
void patientManagement() 
{
    bool running = true;

    while (running) {
    int option;
    displayTitle("Patient Mangement");
    cout << YELLOW << "1) Add New Patient" << RESET << endl;
    cout << YELLOW << "2) View Patient Records" << RESET << endl;
    cout << YELLOW << "3) Search Patient by ID" << RESET << endl;
    cout << YELLOW << "4) Update Patient Info" << RESET << endl;
    cout << YELLOW << "5) Delete Patient Record" << RESET << endl;
    cout << YELLOW << "6) Main Menu" << RESET << endl;

    cout << endl;
    cout << CYAN << "Enter choice: " << RESET;
    cin >> option;
    
        switch (option) 
        {
            case 1: {
                displayTitle("ADD PATIENT");
                Patient patient;
                cout << "Enter Patient Name: ";
                getline(cin >> ws, patient.name);
                cout << "Enter Age: ";
                cin >> patient.age;
                cout << "Enter Gender (M/F): ";
                cin >> patient.gender;
                cout << "Enter Contact Number: ";
                getline(cin >> ws, patient.contact);
                cout << "Enter Disease/Symptoms: ";
                getline(cin >> ws, patient.status);

                patient.id = generateId(5);
                patients.push_back(patient);

                cout << GREEN << endl << "Patient added successfully!" << RESET << endl; 
                cout << GREEN << "Generated Patient ID: " << patient.id << RESET; 
                break;
            }

           case 2: {
               displayTitle("PATIENT RECORDS");
               cout << CYAN << "ID" << setw(25) << "Name" << setw(30) << "Age"
                    << setw(15) << "Gender" << setw(15) << "Contact"
                    << setw(25) << "Disease" << RESET << endl;
               cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
               for (Patient p: patients) {
                    cout << p.id << setw(25) << p.name  << setw(30)
                         << p.age << setw(15) << p.gender
                         << setw(15) << p.contact << setw(25)
                         << p.status << endl;
               }
               break;
           }

           case 3: {
               displayTitle("SEARCH PATIENT");
               string id;
               cout << "Enter Patient Id: ";
               getline(cin >> ws, id);
               bool found = false;
               for (Patient p: patients) {
                   if (p.id == id) {
                       found = true;
                       cout << GREEN;
                       cout << setw(30) << left << "Id:" << right << p.id << endl;
                       cout << setw(30) << left << "Name:" << right << p.name << endl;
                       cout << setw(30) << left << "Age:" << right << p.age << endl;
                       cout << setw(30) << left << "Contact:" << right << p.contact << endl;
                       cout << setw(30) << left << "Disease / Symptom:" << right << p.status << endl;
                       cout << RESET;
                       break;
                   }
               }

               if (found == false) {
                   cout << RED << "No Patient Found with this ID." << RESET;
               }
               break;
           }

           case 4: {
               displayTitle("UPDATE PATIENT INFO");
               string id;
               cout << "Enter Patient Id: ";
               getline(cin >> ws, id);
               bool found = false;
               for (Patient& p: patients) {
                   if (p.id == id) {
                       found = true;
                       cout << GREEN << "Patient Found!" << RESET << endl;
                       displayTitle("Current Information");
                       cout << setw(25) << left << "1. Id:" << right << p.id << endl;
                       cout << setw(25) << left << "2. Name:" << right << p.name << endl;
                       cout << setw(25) << left << "3. Age:" << right << p.age << endl;
                       cout << setw(25) << left << "4. Contact:" << right << p.contact << endl;
                       cout << setw(25) << left << "5. Disease / Symptom:" << right << p.status << endl << endl;

                       cout << YELLOW;
                       cout << "Which field do you want to update?" << endl;
                       cout << "1. Name" << endl;
                       cout << "2. Age" << endl;
                       cout << "3. Gender" << endl;
                       cout << "4. Contact" << endl;
                       cout << "5. Disease / Symptom" << endl;
                       cout << "6. Cancel Update" << RESET << endl << endl;

                       int choice;
                       cout << "Enter Choice: ";
                       cin >> choice;

                       switch(choice) {
                           case 1: {
                                string name;
                                cout << "Enter New Name: ";
                                getline(cin >> ws, name);
                                p.name = name;
                                break;
                           }
                           case 2: {
                                int age;
                                cout << "Enter New Name: ";
                                cin >> age;
                                p.age = age;
                                break;
                           }
                           case 3: {
                                char gender;
                                cout << "Enter New Gender: ";
                                cin >> gender;
                                p.gender = gender;
                                break;
                           }
                           case 4: {
                                string contact;
                                cout << "Enter New Contact: ";
                                getline(cin >> ws, contact);
                                p.contact = contact;
                                break;
                           }
                           case 5: {
                                string status;
                                cout << "Enter New Disease / Symptom: ";
                                getline(cin >> ws, status);
                                p.status = status;
                                break;
                           }
                           case 6: {
                                cout << RED << "Update Cancelled!" << RESET << endl;
                           }
                       }

                       if (choice != 6) {
                            cout << GREEN << "Updating record... " << endl;
                            cout << "Patient info updated successfully!" << RESET;
                       }
                       break;
                   }
               }

               if (found == false) {
                   cout << RED << "No Patient Found with this ID." << RESET;
               }               
               break;
           }

           case 5: {
                displayTitle("DELETE PATIENT RECORD");
                string id;
                cout << "Enter Patient ID: ";
                getline(cin >> ws, id);

                bool found = false;
                for (int i = 0; i < patients.size(); i++) {
                    Patient p = patients[i];
                    if (p.id == id) {
                       displayTitle("Current Information");
                       found = true;
                       cout << setw(25 + 14 + 3) << p.id << endl;
                       cout << setw(25 + 12 + 3) << p.name << endl;
                       cout << setw(25 + 13 + 3) << p.age << endl;
                       cout << setw(25 + 9 + 3) << p.contact << endl;
                       cout << setw(25 + 3) << p.status << endl << endl;

                       cout << YELLOW << "Do you want to delete this record(y/n): " << RESET;
                       char ans;
                       cin >> ans;

                       if (ans == 'y') {
                           patients.erase(patients.begin() + i);
                           cout << RED << "Deleting record..." << endl;
                           cout << "Record Deleted!!" << RESET;
                       } 
                    }
                }

               if (found == false) {
                   cout << RED << "No Patient Found with this ID." << RESET;
               }
           }

           case 6: {
                running = false;
                break;
           }

           default: {
                cout << RED << "Invalid Optoin." << RESET;
           }
        }
    }
}

//############################################# Billing System #####################################################
void billingSystem() {
    displayTitle("Billing System");
    cout << YELLOW << "1. Generate Patient Bill" << RESET << endl;
    cout << YELLOW << "2. View All Bills" << RESET << endl;
    cout << YELLOW << "3. Update Payment Status" << RESET << endl;
    cout << YELLOW << "4. Main Menu" << RESET << endl << endl; 
    int choice;
    cout << CYAN << "Enter choice: " << RESET;
    cin >> choice;

    switch (choice) {
        case 1: {
            displayTitle("Generate Bill"); 
            cout << "Enter patient id: ";
            string id;
            getline(cin >> ws, id);
            for (Patient& p: patients) {
                if (p.id == id) {
                    cout << "Enter Doctor Fee: ";
                    cin >> p.charges.doctor;
                    cout << "Enter Medical Fee: ";
                    cin >> p.charges.medical;
                    cout << "Enter Room Fee: ";
                    cin >> p.charges.room; 
                    p.charges.total = p.charges.doctor + p.charges.medical + p.charges.room;

                    repchar('-', 30);    
                    cout << CYAN << "Bill Summary" << RESET << endl;
                    repchar('-', 30);

                    cout << setw(25) << left << "Doctor Fee: " << right << p.charges.doctor << endl;
                    cout << setw(25) << left << "Medical Fee: " << right << p.charges.medical << endl;
                    cout << setw(25) << left << "Room Fee: " << right << p.charges.doctor << endl;
                    repchar('-', 30);
                    cout << GREEN << setw(25) << left << "Total Amount: " << right << p.charges.total << " PKR" << RESET << endl;
                    cout << setw(25) << left << "Payment Status: " << right << p.charges.status << endl << endl;
                    cout << GREEN << "Bill Generated Successfully!" << RESET << endl;
                }
            } 
        }

        case 2: {
            displayTitle("All Bills");             
            cout << CYAN << "No." << setw(15)  << "Patient ID" << setw(15)
                 << "Name" << setw(15) << "Total(PKR)" << setw(15)
                 << "Status" << RESET << endl;
            repchar('-', 70);
            for (int i = 0; i < patients.size(); i++) {
                Patient p = patients[i];
                cout << i << setw(15) << p.id << setw(15)
                     << p.name << setw(15)
                     << p.charges.total << setw(15)
                     << p.charges.status << endl;
            }
            break;
        }

        case 3: {
            string id;
            cout << "Enter Patient ID to update bill: ";
            getline(cin >> ws, id);

            for (Patient& p: patients) {
                if (p.id == id) {
                    string status;
                    cout << "Enter new Bill Status: ";
                    getline(cin >> ws, status); 
                    p.charges.status = status;
                    cout << GREEN << "Payment status updated!" << RESET << endl;
                }
            }  
            break;
        }
    }    
}

//############################################# Pharmacy System #########################################################
void pharmacyManagement() {
    Pharmacy Med[12]={
        {"FEVER","IBUPROFEN",340},{"VOMITING","DOMPERIDONE",240},
        {"THROATINFECTION","AZOTHROMYCIN",230},{"OSTEOPOROSIS","ALBENDRONATE",340},
        {"DIABETES","METFORMIN",130},{"HEARTPATIENT","CLOPIDOGRIL",170},
        {"ANTI-ALLERGIC","CETRIZINE",97},{"ANTI-DEPRESSANT","ALPRAZOLAM",230},
        {"HEADACHE","PANADOL",500},{"MIGRAINE","NAPROXENE",190},
        {"ACIDITY","OMEPRAZOLE",350},{"STEROID","DEXAMETHRASONE",240}
    };

    int choice;
    string patientDisease;
    string selectedMedicine;
    int issuequantity;
    bool found;

    displayTitle("Hospital Pharmacy");

    do {
        cout << YELLOW << "1. ISSUE MEDICINE(BY DISEASE)" << RESET << endl;
        cout << YELLOW << "2. UPDATE MEDICINE " << RESET << endl;
        cout << YELLOW << "3. VIEW STOCK " << RESET << endl;
        cout << YELLOW << "4. MAIN MENU" << RESET << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
        case 1: {
            cout << "Enter Patient Disease : ";
            cin >> patientDisease;
            found = false;

            cout << CYAN << "Suggested Medicine :" << RESET << endl;

            for(int i = 0; i < 12; i++){
                if(Med[i].diseasename == patientDisease){
                    cout << " - " << Med[i].medicinename << endl;
                    found = true;
                }
            }

            if (!found){
                cout << RED << "No medicine available for this disease!" << RESET << endl;
                break;
            }

            cout << "Select medicine from above list: ";
            cin >> selectedMedicine;

            for (int i = 0; i < 12; i++){
                if (Med[i].medicinename == selectedMedicine &&
                    Med[i].diseasename == patientDisease){

                    cout << "Previous Quantity: " << Med[i].stock << endl;
                    cout << "Enter quantity to issue: ";
                    cin >> issuequantity;

                    if (issuequantity <= Med[i].stock){
                        Med[i].stock -= issuequantity;
                        cout << GREEN << "Issued Quantity: " << issuequantity << RESET << endl;
                        cout << "Remaining Quantity: " << Med[i].stock << endl;
                    }
                    else{
                        cout << RED << "Not enough stock!" << RESET << endl;
                    }
                    break;
                }
            }
            break;
        }

        case 2:{
            string medicinename;
            found = false;

            cout << "Enter medicine name (CAPS): ";
            cin >> medicinename;

            for (int i = 0; i < 12; i++){
                if (Med[i].medicinename == medicinename){
                    found = true;
                    cout << "Current stock: " << Med[i].stock << endl;
                    cout << "Enter new stock: ";
                    cin >> Med[i].stock;
                    cout << GREEN << "Quantity updated successfully!" << RESET << endl;
                    break;
                }
            }

            if (!found){
                cout << RED << "Sorry, Medicine not found!" << RESET << endl;
            }
            break;
        }

        case 3:{
            displayTitle("VIEW STOCK");
            for (int i = 0; i < 12; i++){
                cout << GREEN << Med[i].diseasename << RESET << " | "
                     << CYAN << Med[i].medicinename << RESET << " | "
                     << YELLOW << Med[i].stock << RESET << endl;
            }
            repchar('-', 40);
            break;
        }

        case 4:{
            cout << GREEN << "Thank you for Visiting our Pharmacy " << RESET << endl;
            break;
        }

        default:{
            cout << RED << "INVALID CHOICE!" << RESET << endl;
            cout << "Please select 1-4 " << endl;
            break;
        }
    }

    }while(choice != 4);
}

//############################################################ Main Menu #########################################################
void mainMenu() {
    bool running = true;

    while(running) {
        displayTitle("Main Menu");
        cout << GREEN << "1. Patient Managment" << RESET << endl;
        cout << GREEN << "2. Pharamacy System" << RESET << endl;
        cout << GREEN << "3. Billing System" << RESET << endl;
        cout << RED << "4. Exit" << RESET << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                patientManagement();
                break;
            case 2:
                pharmacyManagement();
                break;
            case 3:
                billingSystem();
                break;
            case 4:
                cout << GREEN << "Thank you for using Hospital Management System" << RESET << endl;
                running = false;
                break;
            default:
                cout << RED << "Invalid Choice" << RESET;
        }
    }
}

int main() {
    mainMenu();
    return 0;
}

