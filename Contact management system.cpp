#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
public:
    string name;
    string phone;
    string email;

    Contact(string n, string p, string e) : name(n), phone(p), email(e) {}
};

class ContactManager {
private:
    vector<Contact> contacts;

public:
    void addContact() {
        string name, phone, email;
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Phone: ";
        getline(cin, phone);
        cout << "Enter Email: ";
        getline(cin, email);

        Contact newContact(name, phone, email);
        contacts.push_back(newContact);
        cout << "Contact added successfully!\n";
    }

    void displayContacts() {
        if (contacts.empty()) {
            cout << "No contacts available.\n";
            return;
        }
        for (size_t i = 0; i < contacts.size(); i++) {
            cout << "Contact " << i + 1 << ":\n";
            cout << "Name: " << contacts[i].name << "\n";
            cout << "Phone: " << contacts[i].phone << "\n";
            cout << "Email: " << contacts[i].email << "\n";
            cout << "--------------------------\n";
        }
    }

    void searchContact() {
        string name;
        cout << "Enter Name to search: ";
        getline(cin, name);

        for (const auto& contact : contacts) {
            if (contact.name == name) {
                cout << "Contact found:\n";
                cout << "Name: " << contact.name << "\n";
                cout << "Phone: " << contact.phone << "\n";
                cout << "Email: " << contact.email << "\n";
                return;
            }
        }
        cout << "Contact not found.\n";
    }

    void deleteContact() {
        string name;
        cout << "Enter Name to delete: ";
        getline(cin, name);

        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->name == name) {
                contacts.erase(it);
                cout << "Contact deleted successfully!\n";
                return;
            }
        }
        cout << "Contact not found.\n";
    }
};

int main() {
    ContactManager cm;
    int choice;

    while (true) {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. Display All Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cm.addContact();
                break;
            case 2:
                cm.displayContacts();
                break;
            case 3:
                cm.searchContact();
                break;
            case 4:
                cm.deleteContact();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
