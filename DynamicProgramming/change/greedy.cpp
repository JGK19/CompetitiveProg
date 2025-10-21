#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> troco_guloso(int, std::vector<int>);

// {1, 5, 10, 25, 50} 63
// {1, 3, 4} 6

int main(void) {
    std::vector<int> moedas = {1, 3, 4};
    int valor = 6;

    std::vector<int> resultado = troco_guloso(valor, moedas);

    if (resultado.empty()) {
        std::cout << "Não é possível formar o valor com as moedas disponíveis.\n";
    } else {
        std::cout << "Troco usando abordagem gulosa: ";
        for (int m : resultado) std::cout << m << " ";
        std::cout << "\n";
    }

    return 0;
}

std::vector<int> troco_guloso(int valor, std::vector<int> moedas) {
    std::vector<int> troco;
    // Ordena as moedas em ordem decrescente
    std::sort(moedas.begin(), moedas.end(), std::greater<int>());

    while (valor > 0) {
        bool achou = false;
        for (int moeda : moedas) {
            if (moeda <= valor) {
                troco.push_back(moeda);
                valor -= moeda;
                achou = true;
                break;
            }
        }
        if (!achou) {
            // Não é possível formar o valor exato
            troco.clear();
            break;
        }
    }
    return troco;
}