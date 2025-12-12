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

vector<Patient> patients;
Patient testPatient = {"00000", "Abdul Basit", 20, 'M', "0316-9665169", "Allergies"};

// Clear the screen and display the title
void displayTitle(string title) 
{
    system("clear");
    cout << "====================================" << endl << endl;
    cout << "       " << title << endl << endl;
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

    patients.push_back(testPatient);
    // Patient vector for dynamically adding patients
    int option;
    displayTitle("Patient Mangement");
    cout << "1) Add new patient" << endl;
    cout << "2) View Patient Records" << endl;
    cout << "3) Search Patient by ID" << endl;
    cin >> option;

    // Note: cin >> ws is for clearing the buffer (removing /n)
    switch (option) 
    {
        case 1: {
            displayTitle("Add Patient");
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
           displayTitle("Patient Records");
           cout << "ID" << setw(25) << "Name" << setw(30) << "Age" << setw(15) << "Gender" << setw(15) << "Contact" << setw(25) << "Disease" << endl;
           cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
           for (Patient p: patients) {
                cout << p.id << setw(25) << p.name  << setw(30) << p.age << setw(15) << p.gender << setw(15) << p.contact << setw(25) << p.status << endl;
           }
           break;
       }

       case 3: {
           displayTitle("Search Patient");
           string id;
           cout << "Enter Patient Id: ";
           getline(cin >> ws, id);
           for (Patient p: patients) {
               if (p.id == id) {
                   cout << "Id:" << setw(25 + 14) << p.id << endl;
                   cout << "Name:" << setw(25 + 12) << p.name << endl;
                   cout << "Age:" << setw(25 + 13) << p.age << endl;
                   cout << "Contact:" << setw(25 + 9) << p.contact << endl;
                   cout << "Disease / Symptom:" << setw(25) << p.status << endl;
                   break;
               }
           }
       }
    }

    char input;
    cin >> input;
}

void mainMenu() {

}
int main() {
    while (true) {
        patientManagement();
    }
    return 0;
}
