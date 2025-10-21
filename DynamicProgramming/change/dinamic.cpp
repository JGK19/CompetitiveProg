#include <iostream>
#include <vector>

const int INF = 1e9;

int solve(int, std::vector<int>);

int main(void) {
    std::vector<int> moedas = {1, 3, 4};
    int valor = 6;
    
    int resultado = solve(valor, moedas);
    std::cout << resultado;

    return 0;
}

int solve(int x, std::vector<int> moedas) {
    if (x < 0) {return INF;}
    if (x == 0) {return 0;}
    int best = INF;
    for (auto c : moedas) {
        best = std::min(best, solve(x - c, moedas)+1);
    }
    return best;
}