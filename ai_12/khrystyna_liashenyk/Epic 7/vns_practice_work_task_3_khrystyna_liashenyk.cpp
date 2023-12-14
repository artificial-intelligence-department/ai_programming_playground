#include <iostream>
#include <iomanip> // Для використання функції setprecision()
using namespace std;

int main() {
    const double m_to_km = 3.6; // Коефіцієнт для конвертації метрів за секунду в кілометри за годину

    int distance_meters;
    double time_minutes, time_seconds;

    cout << "Enter the distance (meters) > ";
    cin >> distance_meters;

    cout << "Enter the time (minutes seconds) > ";
    cin >> time_minutes >> time_seconds;

    double total_time_seconds = time_minutes * 60 + time_seconds;  // Переведення часу в секунди

    cout << "Distance: " << distance_meters << " m" << endl;
    cout << "Time: " << time_minutes << " min " << time_seconds << " sec = " << total_time_seconds << " sec" << endl;

    double speed_m = static_cast<double>(distance_meters) / total_time_seconds; // Обчислення швидкості в метрах за секунду
    double speed_km = speed_m * m_to_km; // Конвертація швидкості з метрів за секунду в кілометри за годину

    cout << fixed << setprecision(2); // Встановлення точності для виводу дробових чисел
    cout << "Running speed: " << speed_km << " km/h" << endl;

    return 0;
}
