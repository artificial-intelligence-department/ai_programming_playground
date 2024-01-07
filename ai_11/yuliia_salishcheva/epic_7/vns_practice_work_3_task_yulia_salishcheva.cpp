//������ 22. ���������� ������� ������� ���������� �
//�������� ������ � ���� � ������� ���������� �� ���.
//����� ���������� ��� ������ �� ��� ��������� ��������, ��
//�������������(���, �� ��������� ������������, ������
//���������� �������).
//���������� ������� �������.
//������ �������� ��� :
//ֳ�� ������(���.) > 2.75
//ֳ�� ����������(���.) > 0.5
//ʳ������ ���������(���.) > 7
//������� ������� : 15.45 ���.

#include <iostream>
using namespace std;

int main()
{
    //���������� ������
    double priceNotebook, priceEnvelope, countSets, purchasePrice = 0.0;

    //����������� ��� �����������, ��� ��� ��� ���(��� ���� ������)
    cout << "Enter price notebook: ";
    cin >> priceNotebook;

    //�������� ����� � ��������� ����������� � ��� �� ����������� �������� �����
    if (priceNotebook <= 2.75)
    {
        cerr << "You should enter price notebook > 2.75";
        return -1;
    }

    //����������� ��� �����������, ��� ��� ��� ���(��� ����������)
    cout << "Enter price envelope: ";
    cin >> priceEnvelope;

    //�������� ����� � ��������� ����������� � ��� �� ����������� �������� �����
    if (priceEnvelope < 0.5)
    {
        cerr << "You should enter price envelope > 0.5";
        return -1;
    }

    //����������� ��� �����������, ��� ��� ��� ���(������� ���������)
    cout << "Enter count sets: ";
    cin >> countSets;

    //�������� ����� � ��������� ����������� � ��� �� ����������� �������� �����
    if (countSets < 7)
    {
        cerr << "You should enter count sets > 7";
        return -1;
    }

    purchasePrice = priceNotebook * countSets;//���������� ���� ������ � ��������� �� �������� �������
    purchasePrice += priceEnvelope * countSets;//���������� ���� ���������� � ��������� �� �������� �������

    //��������� ����������
    cout << "Purchase price: " << purchasePrice << "grn" << endl;

}