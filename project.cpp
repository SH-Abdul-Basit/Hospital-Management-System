#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

struct Patient
{
    string id;
    string name;
    int age;
    char gender;    
    string contact;     
    string status; // disease or symptom
};


// Clear the screen and display the title
void displayTitle(string title) 
{
    system("clear");
    cout << "====================================" << endl << endl;
    cout << "         " << title << endl << endl;
    cout << "====================================" << endl;
    cout << endl << endl;
}

// Generate a random password
// TODO: Add random alphabet as well 
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

void patientManagement() 
{
    vector<Patient> patients;
    Patient testPatient = {"00000", "Abdul Basit", 20, 'M', "0316-9665169", "Allergies"};
    bool running = true;

    patients.push_back(testPatient);
    // Patient vector for dynamically adding patients
    while (running) {
    int option;
    displayTitle("Patient Mangement");
    cout << "1) Add new patient" << endl;
    cout << "2) View Patient Records" << endl;
    cout << "3) Search Patient by ID" << endl;
    cout << "4) Update Patient Info" << endl;
    cin >> option;

    // Note: cin >> ws is for clearing the buffer (removing /n)
    
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

                cout << endl;
                cout << "Patient added successfully!" << endl; 
                cout << "Generated Patient ID: " << patient.id; 
                break;
            }
           case 2: {
               displayTitle("PATIENT RECORDS");
               cout << "ID" << setw(25) << "Name" << setw(30) << "Age" << setw(15) << "Gender" << setw(15) << "Contact" << setw(25) << "Disease" << endl;
               cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
               for (Patient p: patients) {
                    cout << p.id << setw(25) << p.name  << setw(30) << p.age << setw(15) << p.gender << setw(15) << p.contact << setw(25) << p.status << endl;
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
                       cout << "Id:" << setw(25 + 14) << p.id << endl;
                       cout << "Name:" << setw(25 + 12) << p.name << endl;
                       cout << "Age:" << setw(25 + 13) << p.age << endl;
                       cout << "Contact:" << setw(25 + 9) << p.contact << endl;
                       cout << "Disease / Symptom:" << setw(25) << p.status << endl;
                       break;
                   }
               }

               if (found == false) {
                   cout << "No Patient Found with this ID.";
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
                       cout << "Patient Found!" << endl;
                       displayTitle("Current Information");
                       cout << "1. Id:" << setw(25 + 14 + 3) << p.id << endl;
                       cout << "2. Name:" << setw(25 + 12 + 3) << p.name << endl;
                       cout << "3. Age:" << setw(25 + 13 + 3) << p.age << endl;
                       cout << "4. Contact:" << setw(25 + 9 + 3) << p.contact << endl;
                       cout << "5. Disease / Symptom:" << setw(25 + 3) << p.status << endl << endl;

                       cout << "Which field do you want to update?" << endl;
                       cout << "1. Name" << endl;
                       cout << "2. Age" << endl;
                       cout << "3. Gender" << endl;
                       cout << "4. Contact" << endl;
                       cout << "5. Disease / Symptom" << endl;
                       cout << "6. Cancel Update" << endl << endl;

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
                                cout << "Update Cancelled!" << endl;
                           }
                       }

                       if (choice != 6) {
                            cout << "Updating record... " << endl;
                            cout << "Patient info updated successfully!";
                       }

                       break;
                   }
               }

               if (found == false) {
                   cout << "No Patient Found with this ID.";
               }               
               break;
           }
        }

        cout << endl;
        cout << "Do you want to continue(y/n): ";
        char input;
        cin >> input;

        if (input == 'n') {
            running = false;
        }
    }

    
}

void mainMenu() {
    patientManagement();
}
int main() {
    mainMenu();
    return 0;
}
