#include <iostream>
#include <vector>
#include <string>

using namespace std;
void upgradesort(vector<int>& array, int length)
{

    for (int startindex = 0; startindex < length; startindex++)
    {
        int minindex = startindex;
        for (int currentindex = startindex; currentindex < length; currentindex++)
        {
            if (array[currentindex] < array[minindex])
            {
                minindex = currentindex;
            }
        }
        swap(array[startindex], array[minindex]);
    }
}
class binarytree
{
private:
    vector<int> tree;
public:
    void insert(int input)
    {
        bool presence = false;
        for (int i = 0; i < tree.size(); i++)
        {
            if (tree[i] == input)
            {
                presence = true;
            }
        }
        if (!presence)
        {
            tree.insert(tree.begin(), input);
            upgradesort(tree, tree.size());
        }
    }
    string contains(int input)
    {
        bool presence = false;
        for (int i = 0; i < tree.size(); i++)
        {
            if (tree[i] == input)
            {
                presence = true;
            }
        }
        if (presence)
        {
            return "Yes";
        }
        else
        {
            return "No";
        }
    }
    int size()
    {
        return tree.size();
    }
    void print()
    {
        for (int i = 0; i < tree.size(); i++)
        {
            cout << tree[i] << " ";
        }
    }

};

int main()
{
    binarytree tree;
    string identificator;
    int Q;
    cin >> Q;
    cin.ignore(30000, '\n');
    for (int m = 0; m < Q; m++)
    {

        cin >> identificator;
        if (identificator == "insert")
        {
            int input;
            cin >> input;
            cin.ignore(30000, '\n');
            tree.insert(input);

        }
        if (identificator == "contains")
        {
            int input;
            cin >> input;
            cin.ignore(30000, '\n');
            cout << tree.contains(input);
            cout << endl;
        }
        if (identificator == "size")
        {
            cout << tree.size();
            cout << endl;

        }

        if (identificator == "print")
        {

            tree.print();
            cout << endl;

        }

    }



}
