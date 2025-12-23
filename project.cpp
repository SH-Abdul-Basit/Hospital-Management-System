#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

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

struct Doctor
{
    string name;
    string doctors_id;
    string Speciality;
    string doctors_experience;
    string contact;
    string meeting;
};



vector<Patient> patients;
Patient testPatient = {"00000", "Abdul Basit", 20, 'M', "0316-9665169", "Allergies"};

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



void repchar(char ch, int n) 
{
    for (int i = 0; i < n; i++)
    {
        cout << ch;
    }
    cout << endl;
}

void patientManagement() 
{
    bool running = true;

    // Patient vector for dynamically adding patients
    while (running) {
    int option;
    displayTitle("Patient Mangement");
    cout << "1) Add New Patient" << endl;
    cout << "2) View Patient Records" << endl;
    cout << "3) Search Patient by ID" << endl;
    cout << "4) Update Patient Info" << endl;
    cout << "5) Delete Patient Record" << endl;
    cout << endl;
    cout << "Enter choice: ";
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
                       cout << "1. Id:" << setw(25 + 14 + 3) << p.id << endl;
                       cout << "2. Name:" << setw(25 + 12 + 3) << p.name << endl;
                       cout << "3. Age:" << setw(25 + 13 + 3) << p.age << endl;
                       cout << "4. Contact:" << setw(25 + 9 + 3) << p.contact << endl;
                       cout << "5. Disease / Symptom:" << setw(25 + 3) << p.status << endl << endl;

                       cout << "Do you want to delete this record(y/n): ";
                       char ans;
                       cin >> ans;

                       if (ans == 'y') {
                           patients.erase(patients.begin() + i);
                           cout << "Deleting record..." << endl;
                           cout << "Record Deleted!!";
                       } 
                    }
                }

               if (found == false) {
                   cout << "No Patient Found with this ID.";
               }
           }

           dkefault: {
                cout << "Invalid Optoin.";
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

void searchings(vector<Doctor> doctors, string id)
{
    bool found = false;

    for (Doctor d : doctors)
    {
        if (id == d.doctors_id)
        {
            cout << "The doctor is available" << endl;
            found = true;
            repchar('_', 130);
            cout << "Name " << setw(20)
                 << "Doctor ID " << setw(20)
                 << "Doctor Speciality" << setw(20)
                 << "Past Experience " << setw(20)
                 << "Contact number" << setw(20)
                 << "Meeting hours" << endl;

            cout << d.name << setw(20)
                 << d.doctors_id << setw(20)
                 << d.Speciality << setw(20)
                 << d.doctors_experience << setw(20)
                 << d.contact << setw(20)
                 << d.meeting << endl;
            repchar('_', 130);
        }
    }

    if (found == false)
    {
        cout << " doctor is not present in this hospital" << endl;
    }

    cout << endl << endl << endl;
}

void table(vector<Doctor> doctors)
{
    repchar('_', 70);
    cout << "Name " << setw(20)
         << "Doctor ID " << setw(20)
         << "Doctor Speciality" << setw(20)
         << "Past Experience" << setw(20)
         << "contact number" << setw(20)
         << "Meeting hours" << endl;

    for (Doctor d : doctors)
    {
        cout << d.name << setw(20)
             << d.doctors_id << setw(20)
             << d.Speciality << setw(20)
             << d.doctors_experience << setw(20)
             << d.contact << setw(20)
             << d.meeting << endl;
    }

    cout << endl << endl;
}

void doctorManagement()
{

    vector<Doctor> doctors;

    displayTitle("Doctor Management");

        string id; 

    int choice;

    while (true)
    {
        cout << "1) Add Doctor" << endl;
        cout << "2) View All Doctors" << endl;
        cout << "3) Search Doctor" << endl;
        cout << "4) Update Doctor Details" << endl;
        cout << "5) Delete Doctor" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            {
            Doctor d;
            cout << "Enter Name of Doctor : ";
            getline(cin >> ws, d.name);

            cout << endl;
            cout << "Your doctor id is : ";
            d.doctors_id = generateId(5);
            cout << d.doctors_id << endl;

            cout << "Enter Speciality of Doctor : ";
            getline(cin >> ws, d.Speciality);

            cout << endl;
            cout << "Enter Doctors Past Experience : ";
            getline(cin >> ws, d.doctors_experience);

            cout << endl;
            cout << "Enter Doctors contact number : ";
            cin >> d.contact;

            cout << endl;
            cout << "Enter the Meeting hours of Doctors : ";
            getline(cin >> ws, d.meeting);

            cout << endl;
            doctors.push_back(d);
            break;
        }

        case 2: {
            cout << "The list of all doctor is as Follows... " << endl;
            table(doctors);
            break;
        }

        case 3:
        {
            cout << "Enter the Id of Doctor : ";
            cin >> id;
            cout << endl;
            searchings(doctors, id);
            break;
        }

        case 4:
        {
            bool running = true;
            cout << "Enter the Id of The doctor whose detail you want to udoctorsdate : ";
            getline(cin >> ws, id);

            for (int i = 0; i < doctors.size(); i++)
            {
                if (doctors[i].doctors_id == id)
                {
                    Doctor d = doctors[i];
                    cout << "Doctor found!" << endl;
                    cout << "Current Information" << endl;
                    cout << "1. Id:" << setw(25) << d.doctors_id << endl;
                    cout << "2. Name:" << setw(25) << d.name << endl;
                    cout << "3. Past Experience" << setw(25) << d.doctors_experience << endl;
                    cout << "4. Contact:" << setw(25) << d.contact << endl;
                    cout << "5. Speciality" << setw(25) << d.Speciality << endl << endl;

                    while (running)
                    {
                        cout << "Which field do you want to update?" << endl;
                        cout << "1. Name" << endl;
                        cout << "2. Speciality" << endl;
                        cout << "3. Past Experience" << endl;
                        cout << "4. Contact" << endl;
                        cout << "5. Meeting hours" << endl;
                        cout << "6. Cancel Update" << endl << endl;

                        int choice;
                        cout << "Enter Choice" << endl;
                        cin >> choice;

                        switch (choice)
                        {
                        case 1:
                            cout << "Enter the new name" << endl;
                            getline(cin >> ws, doctors[i].name);
                            cout << "This Field has been updated" << endl;
                            break;

                        case 2:
                            cout << "Enter Speciality of Doctor" << endl;
                            getline(cin >> ws, doctors[i].Speciality);
                            cout << "This Field Has been updated" << endl;
                            break;

                        case 3:
                            cout << "Enter The doctors Experience" << endl;
                            getline(cin >> ws, doctors[i].doctors_experience);
                            cout << "This field has been updated" << endl;
                            break;

                        case 4:
                            cout << "Enter Contact no :" << endl;
                            cin >> doctors[i].contact;
                            cout << "This field has been updated" << endl;
                            break;

                        case 5:
                            cout << " Enter Meeting Hours" << endl;
                            getline(cin >> ws, doctors[i].meeting);
                            cout << "This field has been updated" << endl;
                            break;

                        case 6:
                            cout << "Update has been cancel" << endl;
                            running = false;
                            break;

                        default:
                            cout << "invalid input" << endl;
                        }
                    }
                }
            }
            break;
        }

        case 5:
        {
            cout << "Enter the Id of the Doctor whom You want to delete : ";
            getline(cin >> ws, id);

            for (int i = 0; i < doctors.size(); i++)
            {
                if (doctors[i].doctors_id == id)
                {
                    doctors.erase(doctors.begin() + i);
                    cout << "doctor details has been deleted" << endl;
                }
            }
            break;
        }

        default:
            cout << "invalid input" << endl;
        }
    }
}


void billingSystem() {
    displayTitle("Billing System");
    cout << "1. Generate Patient Bill" << endl;
    cout << "2. View All Bills" << endl;
    cout << "3. Update Payment Status" << endl;
    cout << "4. Back to Main Menu" << endl << endl; 
    int choice;
    cout << "Enter choice: ";
    cin >> choice;
  

    // left and right modifiers are used to to align very line with each other  
    switch (choice) {
        case 1: {
            displayTitle("Generate Bill"); 
            cout << "Enter patient id: ";
            string id;
            getline(cin >> ws, id);
            for (Patient& p: patients) {
                if (p.id == id) {
                    cout << endl;
                    cout << "Enter Doctor Fee: ";
                    cin >> p.charges.doctor;
                    cout << "Enter Medical Fee: ";
                    cin >> p.charges.medical;
                    cout << "Enter Room Fee: ";
                    cin >> p.charges.room; 
                    p.charges.total = p.charges.doctor + p.charges.medical + p.charges.room;
                    repchar('-', 30);    
                    cout << "Bill Summary" << endl;
                    repchar('-', 30);
                    cout << setw(25) << left << "Doctor Fee: " << right << p.charges.doctor << endl;
                    cout << setw(25) << left << "Medical Fee: " << right << p.charges.medical << endl;
                    cout << setw(25) << left << "Room Fee: " << right << p.charges.doctor << endl;
                    repchar('-', 30);
                    cout << setw(25) << left << "Total Amount: " << right << p.charges.total << " PKR" << endl;
                    cout << setw(25) << left << "Payment Status: " << right << p.charges.status << endl << endl;
                    cout << "Bill Generated Successfully!" << endl;
                    
                }
            } 
        }

        case 2: {
            displayTitle("All Bills");             
            cout << "No." << setw(15)  << "Patient ID" << setw(15) << "Name" << setw(15) << "Total(PKR)" << setw(15) << "Status" << endl;
            repchar('-', 70);
            for (int i = 0; i < patients.size(); i++) {
                Patient p = patients[i];
                cout << i << setw(15) << p.id << setw(15) << p.name << setw(15) << p.charges.total << setw(15) << p.charges.status << endl;
            }
        }

        case 3: {
             
        }
    }    
}

void pharmacyManagement() {

}


void mainMenu() {
    patients.push_back(testPatient);
    // patientManagement();
    doctorManagement();
    // billingSystem();
}
int main() {
    mainMenu();
    return 0;
}
