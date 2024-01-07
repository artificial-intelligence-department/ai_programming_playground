#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

using namespace std;

struct List
{
public:
    struct Node
    {
        char *str;
        Node *next = NULL;
        Node *prev = NULL;

        Node(char *arg)
        {
            auto size = strlen(arg) + 1;
            this->str = new char(size);
            strcpy(this->str, arg);
        }

        ~Node()
        {
            if (this->str != NULL)
            {
             //   delete[] this->str;
            }
        }
    };

private:
    Node *first = NULL;
    Node *last = NULL;

    void print(Node *elem)
    {
        if (elem != NULL)
        {
            cout << "\"" << elem->str << "\"";
            if (elem->next != NULL)
            {
                cout << ", ";
            }
            print(elem->next);
        }
    }

    void remove(Node *elem)
    {
        if (elem == this->first && elem == this->last)
        {
            this->first = NULL;
            this->last = NULL;
        }
        else if (elem == this->first)
        {
            this->first = elem->next;
            this->first->prev = NULL;
        }
        else if (elem == this->last)
        {
            this->last = elem->prev;
            this->last->next = NULL;
        }
        else
        {
            Node *prevNode = elem->prev;
            Node *nextNode = elem->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
        delete elem;
    }

public:
    void clear()
    {
        Node *elem = this->first;
        while (elem)
        {
            Node *nextElem = elem->next;
            delete elem;
            elem = nextElem;
        }
        this->first = NULL;
    }

    List()
    {
    }

    ~List()
    {
        this->clear();
    }

    void push_back(char *arg)
    {
        Node *node = new Node(arg);
        if (this->first == NULL)
        {
            this->first = node;
            this->last = node;
        }
        else
        {
            this->last->next = node;
            Node *p = this->last;
            this->last = node;
            node->prev = p;
        }
    }

    void print()
    {
        if (this->first == NULL)
        {
            cout << "List is empty!\n";
        }
        else
        {
            Node *elem = this->first;
            print(elem);
            cout << "\n";
        }
    }

    void remove(char *arg)
    {
        Node *elem = this->last;
        while (elem != NULL)
        {
            Node *prevElem = elem->prev;
            if (strcmp(elem->str, arg) == 0)
            {
                this->remove(elem);
                break;
            }
            elem = prevElem;
        }
    }

    void saveIntoFile(char *fileName)
    {
        // відкриваємо файл
        ofstream outf{fileName, ios::trunc | ios::out};
        if (!outf)
        {
            return;
        }

        Node *elem = this->first;
        while (elem != NULL)
        {
            Node *nextElem = elem->next;
            // записуємо node у файл
            outf << elem->str << "\n";
            elem = nextElem;
        }
        outf.close();
    }

    void readContentFromFile(char *fileName)
    {
        ifstream fin;
        fin.open(fileName);
        if (!fin.is_open())
        {
            return;
        }
        while (true)
        {
            string strLine;
            getline(fin, strLine);
            if (fin.eof())
            {
                break;
            }
            else
            {
                this->push_back((char *)strLine.c_str());
            }
        }
        fin.close();
    }
};

int main()
{
    List list;

    list.push_back("Some text");
    list.push_back("Next element");
    list.print();

    list.clear();
    list.print();

    list.push_back("Some text");
    list.push_back("Middle");
    list.push_back("Some text");
    list.print();

    list.remove("Some text");
    list.print();

    list.saveIntoFile("data.txt");

    list.clear();
    list.print();

    list.readContentFromFile("data.txt");
    list.print();

    return 0;
}