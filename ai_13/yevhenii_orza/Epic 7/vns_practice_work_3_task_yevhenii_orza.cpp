#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    
        double distance;
        std::cout << "Computing running speed." << std::endl;
        std::cout << "Enter the distance (meters) > ";
        std::cin >> distance;

        double totalTime;
        std::cout << "Enter the time (minutes.seconds) > ";
        std::cin >> totalTime;

        // розділення хвилин та секунд
        int minutes = int(totalTime);
        double fractional = totalTime - minutes;
        int seconds = round(fractional * 60);

        // Обрахунок швидкості
        double speed = (distance / 1000) / ((minutes * 60 + seconds) / 3600.0);

        // результат
        std::cout << "Distance: " << distance << " m" << std::endl;
        std::cout << "Time: " << minutes << " min " << seconds << " sec" << std::endl;
        std::cout << "Running speed: " << std::fixed << std::setprecision(2) << speed << " km/hour" << std::endl;


    return 0;
}
