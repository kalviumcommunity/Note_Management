#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Note
{
private:
    string title;
    string content;
    static int noteCount;

public:
    Note(const string &t, const string &c) : title(t), content(c)
    {
        cout << "Creating Note: " << title << endl;
        noteCount++;
    }

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Content: " << content << endl;
    }

    void updateContent(const string &newContent)
    {
        this->content = newContent;
        cout << "Content updated for Note: " << title << endl;
    }

    string getTitle() const
    {
        return title;
    }

    static int getNoteCount()
    {
        return noteCount;
    }
};

int Note::noteCount = 0;

class Category
{
private:
    string categoryName;
    vector<Note *> notes;

public:
    Category(const string &name) : categoryName(name)
    {
        cout << "Creating Category: " << categoryName << endl;
    }

    void addNoteToCategory(Note *note)
    {
        notes.push_back(note);
    }

    void listNotes()
    {
        cout << "Notes in Category '" << categoryName << "':" << endl;
        for (Note *note : notes)
        {
            note->display();
        }
    }

    string getCategoryName() const
    {
        return categoryName;
    }

    Note *getNoteByTitle(const string &noteTitle)
    {
        for (Note *note : notes)
        {
            if (note->getTitle() == noteTitle)
            {
                return note;
            }
        }
        return nullptr;
    }
};

class User
{
private:
    string userName;
    vector<Category *> categories;

public:
    User(const string &name) : userName(name)
    {
        cout << "Creating User: " << userName << endl;
    }

    void createCategory(const string &categoryName)
    {
        categories.push_back(new Category(categoryName));
    }

    Category *getCategoryByName(const string &categoryName)
    {
        for (Category *category : categories)
        {
            if (category->getCategoryName() == categoryName)
            {
                return category;
            }
        }
        return nullptr;
    }
};

int main()
{
    string username;
    cout << "Enter your username: ";
    getline(cin, username);
    User *user = new User(username);

    string choice;
    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Add a category" << endl;
        cout << "2. Add a note" << endl;
        cout << "3. Update a note" << endl;
        cout << "4. Display a category" << endl;
        cout << "5. Display a note" << endl;
        cout << "6. Get total note count" << endl;
        cout << "7. Exit" << endl;
        getline(cin, choice);

        if (choice == "1")
        {
            string categoryName;
            cout << "Enter category name: ";
            getline(cin, categoryName);
            user->createCategory(categoryName);
        }
        else if (choice == "2")
        {
            string categoryToInsert;
            cout << "Enter the name of the category where you want to add the note: ";
            getline(cin, categoryToInsert);
            Category *category = user->getCategoryByName(categoryToInsert);
            if (category)
            {
                string noteTitle, noteContent;
                cout << "Enter note title: ";
                getline(cin, noteTitle);
                cout << "Enter note content: ";
                getline(cin, noteContent);
                category->addNoteToCategory(new Note(noteTitle, noteContent));
            }
            else
            {
                cout << "Category not found." << endl;
            }
        }
        else if (choice == "3")
        {
            string categoryToUpdate;
            cout << "Enter the name of the category you want to update: ";
            getline(cin, categoryToUpdate);
            Category *selectedCategory = user->getCategoryByName(categoryToUpdate);
            if (selectedCategory)
            {
                selectedCategory->listNotes();
                string noteTitleToUpdate, newContent;
                cout << "Enter the title of the note you want to update in " << selectedCategory->getCategoryName() << ": ";
                getline(cin, noteTitleToUpdate);
                Note *noteToUpdate = selectedCategory->getNoteByTitle(noteTitleToUpdate);
                if (noteToUpdate)
                {
                    cout << "Enter new content for the note: ";
                    getline(cin, newContent);
                    noteToUpdate->updateContent(newContent);
                }
                else
                {
                    cout << "Note not found." << endl;
                }
            }
            else
            {
                cout << "Category not found." << endl;
            }
        }
        else if (choice == "4")
        {
            string categoryToDisplay;
            cout << "Enter the name of the category you want to display: ";
            getline(cin, categoryToDisplay);
            Category *selectedCategory = user->getCategoryByName(categoryToDisplay);
            if (selectedCategory)
            {
                selectedCategory->listNotes();
            }
            else
            {
                cout << "Category not found." << endl;
            }
        }
        else if (choice == "5")
        {
            string categoryToDisplay;
            cout << "Enter the name of the category of the note you want to display: ";
            getline(cin, categoryToDisplay);
            Category *selectedCategory = user->getCategoryByName(categoryToDisplay);
            if (selectedCategory)
            {
                string noteTitleToDisplay;
                cout << "Enter the title of the note you want to display: ";
                getline(cin, noteTitleToDisplay);
                Note *selectedNote = selectedCategory->getNoteByTitle(noteTitleToDisplay);
                if (selectedNote)
                {
                    selectedNote->display();
                }
                else
                {
                    cout << "Note not found." << endl;
                }
            }
            else
            {
                cout << "Category not found." << endl;
            }
        }
        else if (choice == "6")
        {
            cout << "Total number of notes: " << Note::getNoteCount() << endl;
        }
        else if (choice == "7")
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (true);

    return 0;
}
