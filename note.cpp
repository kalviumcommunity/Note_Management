#include <iostream>
#include <string>
using namespace std;

class Note
{
private:
    string title;
    string content;

public:
    Note(const string t, const string c) : title(t), content(c)
    {
        cout << "Creating Note: " << title << endl;
    }

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Content: " << content << endl;
    }
};

int main()
{

    const int NotesSize = 4;
    Note notes[NotesSize] = {
        Note("Note 1", "This is the content of Note 1."),
        Note("Note 2", "This is the content of Note 2."),
        Note("Note 3", "Note 3 content."),
        Note("Note 4", "Note 4 content.")};
        

    for (int i = 0; i < NotesSize; ++i)
    {
        notes[i].display();
    }

    return 0;
}
