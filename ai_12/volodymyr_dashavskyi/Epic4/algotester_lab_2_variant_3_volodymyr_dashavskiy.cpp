#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> cells(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> cells[i];
    }

    int left_drone_position = 1;
    int right_drone_position = N;

    while (true)
    {
        if (left_drone_position == right_drone_position)
        {
            cout << left_drone_position << " " << right_drone_position << endl;
            cout << "Collision" << endl;
            break;
        }
        else if (left_drone_position > right_drone_position)
        {
            cout << left_drone_position << " " << right_drone_position << endl;
            cout << "Miss" << endl;
            break;
        }
        else if (left_drone_position == right_drone_position - 1)
        {
            cout << left_drone_position << " " << right_drone_position << endl;
            cout << "Stopped" << endl;
            break;
        }

        left_drone_position += cells[left_drone_position - 1];

        right_drone_position -= cells[right_drone_position - 1];
    }

    return 0;
}