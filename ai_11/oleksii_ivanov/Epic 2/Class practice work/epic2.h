#ifndef epic2_h
#define epic2_h

enum Weather {
    SUNNY, CLOUDY, RAINY, SNOWY, WINDY,
};

void shouldBringJacket(const Weather& weather);
void suggestedActivity(const Weather& weather);
void suggestedShoes(Weather weather);

#endif //epic2_h
