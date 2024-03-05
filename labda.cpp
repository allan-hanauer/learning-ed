#include <iostream>
#include <functional> // Para std::function

using namespace std;
int main() {
    // Definindo a lambda para realizar operações
    typedef function<double(double, double, char)> Operation;
    Operation operacao = [](double a, double b, char op) -> double {
        switch(op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                if (b != 0) {
                    return a / b;
                } else {
                    cout << "Erro: Divisão por zero!" << endl;
                    return 0;
                }
            default:
                cout << "Operação inválida!" << endl;
                return 0;
        }
    };

    // Testando a lambda com diferentes operações
    cout << "3 + 4 = " << operacao(3, 4, '+') << endl;
    cout << "7 - 2 = " << operacao(7, 2, '-') << endl;
    cout << "5 * 6 = " << operacao(5, 6, '*') << endl;
    cout << "8 / 2 = " << operacao(8, 2, '/') << endl;
    cout << "9 / 0 = " << operacao(9, 0, '/') << endl; // Tentativa de divisão por zero

    return 0;
}
