int main()
{
    long double a, h, s;
    cout << "Введіть початкові дані:" << endl;
    cout << "Підстава (см) > ";
    cin >> a;
    cout << "Висота(см)> ";
    cin >> h;
    cout << a << h << endl;
    s = 0.5 * a * h;
    cout << "Площа трикутника: " << s << " кв.см." << endl;
    return 0;
}
