//Написати перевантажені функції й основну програму, що їх викликає.
//а) для додавання цілих чисел;
//б) для додавання комплексних чисел

#include <iostream>
#include <complex>

std::complex<double> sumcomplex(std::complex<double> a, std::complex<double> b) {
    return a + b;
}

// Функція суми для int
int sum(int a, int b) {
    return a + b;
}

int main() {
    int ia = 8;
    int ib = 19;

    std::complex<double> complex_a(3.3,-1);  // Комплексне число з реальною частиною 3,3 і уявною -1
    std::complex<double> complex_b(-1.7,2); // Комплексне число з реальною частиною -1 і уявною 2

    // Виклик функції для double
    std::complex<double> result_complex = sumcomplex(complex_a, complex_b);

    // Виведення результату для комплексних чисел
    std::cout << "Результат для комплексних: (" << result_complex.real() << "," << result_complex.imag() << ")\n";

    // Виклик функції для int та виведення результату
    std::cout << "Результат для цілих: " << sum(ia, ib) << std::endl;

    return 0;
}
