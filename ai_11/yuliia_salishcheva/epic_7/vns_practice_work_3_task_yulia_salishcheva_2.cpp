#include <iostream>
using namespace std;

int main() {
    //���������� ������ � ��������
    int shaybs_per_hour, count1DayShift = 0, count2DayShift = 0, count30Day = 0;
    const int hourCount1DayS = 8;
    const int preventionHour = 1;
    const int weekend = 4;
    const int daysOfmonth = 30;

    //����������� ��� �����������, ��� ��� ��� ���(������� ���� �� ������)
    cout << "Enter count shaybs (in 1 hour): ";
    cin >> shaybs_per_hour;

    count1DayShift = shaybs_per_hour * (hourCount1DayS - preventionHour); // ������� ������� �� 1 ���� � ����
    count2DayShift = (shaybs_per_hour * (hourCount1DayS - preventionHour)) * 2;// ������� ������� �� 2 ���� � ����
    count30Day = (daysOfmonth - weekend) * count2DayShift;// ������� ������� �� 2 ���� �� ����� (� ���������)

    //��������� ����������
    cout << "The number of parts for 1 shift per day: " << count1DayShift << endl;
    cout << "The number of parts for 2 shifts per day: " << count2DayShift << endl;
    cout << "The number of parts for 2 shifts per month (including days off): " << count30Day << endl;
    return 0;
}
