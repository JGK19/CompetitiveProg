from functools import lru_cache

INF = float('inf')

def main():
    moedas = [1, 3, 4]
    valor = 6

    resultado = solve(valor, tuple(moedas))  
    print(resultado)

@lru_cache(maxsize=None)  # memoization ilimitada
def solve(x, moedas):
    if x < 0:
        return INF
    if x == 0:
        return 0
    best = INF
    for c in moedas:
        best = min(best, solve(x - c, moedas) + 1)
    return best

if __name__ == "__main__":
    main()
