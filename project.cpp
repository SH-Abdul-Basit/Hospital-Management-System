#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Patient
{
    string id;
    string name;
    int age;
    char gender;    
    string phoneNumber;     
    string status; // disease or symptom
};

// Clear the screen and display the title
void displayTitle(string title) 
{
    system("clear");
    cout << "------------------------------------" << endl;
    cout << "       " << title << endl;
    cout << "------------------------------------" << endl;

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
    // Patient vector for dynamically adding patients
    vector<Patient> patients;

    int option = 1;
    displayTitle("Patient Mangement");
    cout << "1) Add new patient" << endl;
    cin >> option;

    // Note: cin >> ws is for clearing the buffer (removing /n)
    switch (option) 
    {
        case 1:
            displayTitle("Add Patient");
            Patient patient;
            cout << "Enter Patient Name: ";
            getline(cin >> ws, patient.name);
            cout << "Enter Age: ";
            cin >> patient.age;
            cout << "Enter Gender (M/F): ";
            cin >> patient.gender;
            cout << "Enter Disease/Symptoms: ";
            getline(cin >> ws, patient.status);

            patient.id = generateId(5);

            patients.push_back(patient);

            cout << endl;
            cout << "Patient added successfully!" << endl; 
            cout << "Generated Patient ID: " << patient.id; 
            break;
    }
}

void mainMenu() {

}

int main() {
    patientManagement();
    return 0;
}
