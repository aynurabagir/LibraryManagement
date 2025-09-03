#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int publicationYear;
    string isbn;

public:
    void setDetails(string t, string a, int y, string i) {
        title = t;
        author = a;
        publicationYear = y;
        isbn = i;
    }

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Year: " << publicationYear << endl;
        cout << "ISBN: " << isbn << endl;
    }

    string getTitle() const { return title; }
};

int main() {
    vector<Book> library;
    int choice;

    while (true) {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by Title\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string t, a, i;
            int y;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, t);
            cout << "Enter author: ";
            getline(cin, a);
            cout << "Enter year: ";
            cin >> y;
            cout << "Enter ISBN: ";
            cin >> i;

            Book newBook;
            newBook.setDetails(t, a, y, i);
            library.push_back(newBook);

            cout << "Book added successfully!\n";

        } else if (choice == 2) {
            if (library.empty()) {
                cout << "No books in the library.\n";
            } else {
                for (int j = 0; j < library.size(); j++) {
                    cout << "\nBook " << j + 1 << ":\n";
                    library[j].display();
                }
            }

        } else if (choice == 3) {
            string searchTitle;
            cout << "Enter title to search: ";
            cin.ignore();
            getline(cin, searchTitle);

            bool found = false;
            for (auto &b : library) {
                if (searchTitle == b.getTitle()) {
                    b.display();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found!\n";
            }

        } else if (choice == 4) {
            cout << "Exiting program...\n";
            break;

        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
