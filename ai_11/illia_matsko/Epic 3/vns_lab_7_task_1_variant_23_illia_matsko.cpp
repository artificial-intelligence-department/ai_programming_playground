#include <iostream>
using namespace std;

struct coordinate{
    double x;
    double y;
};

double length(coordinate coordinate1, coordinate coordinate2)
{
    return sqrt(pow((coordinate2.x - coordinate1.x), 2) + pow((coordinate2.y - coordinate1.y), 2));
}

double square(coordinate coordinateA, coordinate coordinateB, coordinate coordinateC)
{
    double ab = length(coordinateA, coordinateB);
    double ac = length(coordinateA, coordinateC);
    double bc = length(coordinateB, coordinateC);
    double p = (ab+bc+ac)/2;

    return sqrt(p*(p-ab)*(p-ac)*(p-bc));
}

int belong(coordinate coordinateA, coordinate coordinateB, coordinate coordinateC, coordinate coordinateM)
{
    double squareABC = square(coordinateA, coordinateB, coordinateC);
    double squareABM = square(coordinateA, coordinateB, coordinateM);
    double squareACM = square(coordinateA, coordinateC, coordinateM);
    double squareBCM = square(coordinateB, coordinateC, coordinateM);

    if(squareABM + squareACM + squareBCM > squareABC - 0.00001 && squareABM + squareACM + squareBCM < squareABC + 0.00001)
    {
        return 1;
    }
    return 0;
}

int belongsToPolygon(int k, ...)
{
    va_list args;
    coordinate coordinates[k];

    va_start(args, k);

    for(int i=0; i<k; i++)
    {
        coordinates[i] = va_arg(args, coordinate);
    }

    va_end(args);

    double x2, y2;
    double polygonSquare = 0;
    int counter = 1;
    double x1 = coordinates[0].x;
    double y1 = coordinates[0].y;

    for (int i=0; i<k-2; i++) {
        x2 = coordinates[counter].x;
        y2 = coordinates[counter].y;
        polygonSquare += (x1+x2)*(y1-y2);
        x1=x2;
        y1=y2;
        counter++;
    }
    polygonSquare += (coordinates[0].x+x2)*(coordinates[0].y-y2);
    polygonSquare = abs(polygonSquare/2);

    coordinate m = coordinates[k-1];
    double sum = 0.0;
    for(int i=0; i<k-2; i++)
    {
        sum += square(m, coordinates[i], coordinates[i+1]);
    }
    sum += square(m, coordinates[0], coordinates[k-2]);

    if(sum > polygonSquare - 0.00001 && sum < polygonSquare + 0.00001)
    {
        return 1;
    }

    return 0;
}

int main()
{
    vector<coordinate> coordinates = {{1, 2}, {5, 0}, {7, 2}, {6, 5}, {2, 6}, {3, 4}};

    cout << belong(coordinates[0], coordinates[1], coordinates[2], coordinates[5]);
    cout << endl;
    cout << belongsToPolygon(coordinates.size(), coordinates[0], coordinates[1], coordinates[2], coordinates[3], coordinates[4]);
}