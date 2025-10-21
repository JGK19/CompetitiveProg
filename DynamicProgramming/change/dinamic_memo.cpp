#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1e9;

int solve(int x, const std::vector<int>& moedas, std::vector<int>& memo) {
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (memo[x] != -1) return memo[x]; // já calculado

    int best = INF;
    for (auto c : moedas) {
        best = std::min(best, solve(x - c, moedas, memo) + 1);
    }
    
    memo[x] = best;
    return best;
}

int main() {
    std::vector<int> moedas = {1, 3, 4};
    int valor = 6;

    std::vector<int> memo(valor + 1, -1); // -1 = ainda não calculado

    int resultado = solve(valor, moedas, memo);
    std::cout << resultado << std::endl;

    return 0;
}