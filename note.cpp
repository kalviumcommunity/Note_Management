#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Note {
private:
    string title;
    string content;

public:
    Note(const string& t, const string& c) : title(t), content(c) {
        cout << "Creating Note: " << title << endl;
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Content: " << content << endl;
    }

    void updateContent(const string& newContent) {
        this->content = newContent;
        cout << "Content updated for Note: " << title << endl;
    }

    string getTitle() const {
        return title;
    }
};

class Category {
private:
    string categoryName;
    vector<Note*> notes;

public:
    Category(const string& name) : categoryName(name) {
        cout << "Creating Category: " << categoryName << endl;
    }

    void addNoteToCategory(Note* note) {
        notes.push_back(note);
    }

    void listNotes() {
        cout << "Notes in Category '" << categoryName << "':" << endl;
        for (Note* note : notes) {
            note->display();
        }
    }

    string getCategoryName() const {
        return categoryName;
    }

    Note* getNoteByTitle(const string& noteTitle) {
        for (Note* note : notes) {
            if (note->getTitle() == noteTitle) {
                return note;
            }
        }
        return nullptr;
    }
};

class User {
private:
    string userName;
    vector<Category*> categories;

public:
    User(const string& name) : userName(name) {
        cout << "Creating User: " << userName << endl;
    }

    void createCategory(const string& categoryName) {
        categories.push_back(new Category(categoryName));
    }

    Category* getCategoryByName(const string& categoryName) {
        for (Category* category : categories) {
            if (category->getCategoryName() == categoryName) {
                return category;
            }
        }
        return nullptr;
    }
};

int main() {
    User* user = new User("Sarthak");

    user->createCategory("Personal");
    user->createCategory("Work");

    Category* personalCategory = user->getCategoryByName("Personal");
    Category* workCategory = user->getCategoryByName("Work");

    personalCategory->addNoteToCategory(new Note("Personal Note ", "This is a personal note."));
    workCategory->addNoteToCategory(new Note("Work Note ", "This is a work-related note."));

    personalCategory->listNotes();
    workCategory->listNotes();

    Note* noteToUpdate = personalCategory->getNoteByTitle("Personal Note ");
    if (noteToUpdate) {
        noteToUpdate->updateContent("Updated content for Personal Note ");
    } else {
        cout << "Note not found." << endl;
    }

    personalCategory->listNotes();

    return 0;
}
