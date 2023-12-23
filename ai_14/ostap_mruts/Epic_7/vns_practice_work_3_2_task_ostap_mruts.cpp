#include <iostream>

using namespace std;

int main() {
    double height, width, depth;

    cout << "Введіть розміри ящика (в см): ";
    cin >> height >> width >> depth;

    double boxVolume = height * width * depth;

    double boxVolumeInMeters = boxVolume / 1000000.0;

    // Обчислення кількості болтів у ящику (за умови, що один болт займає 2 см^3)
    int boltsCount = static_cast<int>(boxVolume / 2);

    cout << "Кількість болтів у ящику: " << boltsCount << endl;

    return 0;
}