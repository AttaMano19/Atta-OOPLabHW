#include <iostream>
#include <string>
using namespace std;

class Physician;
class Accounts;

class HealthProfile {
    private:
        string fullName;
        string profileID;
        string dateOfBirth;
        string* historyNotes;
        int historyCount;

        string* invoiceRecords;
        int invoiceCount;

        void appendHistory(const string& note) {
            string* newNotes = new string[historyCount + 1];
            for (int i = 0; i < historyCount; i++) newNotes[i] = historyNotes[i];
            newNotes[historyCount++] = note;
            delete[] historyNotes;
            historyNotes = newNotes;
        }

        void appendInvoice(const string& invoice) {
            string* newInvoices = new string[invoiceCount + 1];
            for (int i = 0; i < invoiceCount; i++) newInvoices[i] = invoiceRecords[i];
            newInvoices[invoiceCount++] = invoice;
            delete[] invoiceRecords;
            invoiceRecords = newInvoices;
        }

    public:
        HealthProfile(string id, string name, string dob) {
            profileID = id;
            fullName = name;
            dateOfBirth = dob;
            historyNotes = nullptr;
            invoiceRecords = nullptr;
            historyCount = invoiceCount = 0;
        }

        string showBasicInfo() const {
            return "Patient: " + fullName + " | ID: " + profileID + " | DOB: " + dateOfBirth;
        }

        string showMedicalNotes() const {
            string output = "Medical Notes:\n";
            for (int i = 0; i < historyCount; i++) {
                output += "- " + historyNotes[i] + "\n";
            }
            return output;
        }

        string showInvoiceData() const {
            string output = "Invoices:\n";
            for (int i = 0; i < invoiceCount; i++) {
                output += "- " + invoiceRecords[i] + "\n";
            }
            return output;
        }

        friend class Physician;
        friend class Accounts;

        ~HealthProfile() {
            delete[] historyNotes;
            delete[] invoiceRecords;
        }
};

class Physician {
    public:
        void recordNote(HealthProfile& profile, const string& entry) {
            profile.appendHistory("Doctor Note: " + entry);
            cout << "Physician added medical note.\n";
        }

        void viewNotes(const HealthProfile& profile) {
            cout << profile.showMedicalNotes();
        }
};

class Accounts {
    public:
        void recordInvoice(HealthProfile& profile, const string& charge) {
            profile.appendInvoice("Invoice: " + charge);
            cout << "Accounts recorded invoice.\n";
        }

        void viewInvoices(const HealthProfile& profile) {
            cout << profile.showInvoiceData();
        }
};

class Assistant {
    public:
        void viewPublicProfile(const HealthProfile& profile) {
            cout << profile.showBasicInfo() << endl;
        }

        void attemptMedicalAccess(const HealthProfile& profile) {
            cout << "Assistant trying to access medical notes...\n";
            cout << "Access Denied!\n";
        }

        void attemptInvoiceAccess(const HealthProfile& profile) {
            cout << "Assistant trying to access invoice data...\n";
            cout << "Access Denied!\n";
        }
};


int main() {
    HealthProfile profile("HX102", "Maria Blake", "1984-11-03");

    Physician docJones;
    Accounts financeDept;
    Assistant reception;

    cout << "\n>>> Front Desk Check-In <<<\n";
    reception.viewPublicProfile(profile);
    reception.attemptInvoiceAccess(profile);
    reception.attemptMedicalAccess(profile);

    cout << "\n>>> Medical Department <<<\n";
    docJones.recordNote(profile, "Follow-up required for blood test results.");
    docJones.recordNote(profile, "Prescribed vitamin supplements.");
    docJones.viewNotes(profile);

    cout << "\n>>> Billing Department <<<\n";
    financeDept.recordInvoice(profile, "Blood Test: $90");
    financeDept.recordInvoice(profile, "Consultation Fee: $180");
    financeDept.viewInvoices(profile);

    return 0;
}

