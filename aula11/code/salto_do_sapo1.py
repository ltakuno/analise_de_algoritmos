# Existem n pedras numa reta numérica, em posições distintas
# v1, v2, ... , vn. Dizemos que o sapo pode saltar de uma pedra
# vi para outra pedra vj desde que a distância entre elas seja
# menor ou igual a delta. 
# Um sapo está inicialmente na pedra v1. Qual é o número de saltos
# que ele precisa dar para chegar na pedra vn?
# ex1: entrada n = 4, v = {1,2,3,4}, delta = 1
#      saída   k = 4, u = {1,2,3,4}
# ex2: entrada n = 6, v = {1,2,3,5,6,7}, delta = 2
#      saída   k = 4, u = {1,3,5,7}
# ex3: entrada n = 3, v = {1,3,4}, delta = 1
#      saída não admite solução, ja que a partir de 1 não é possível
#      que 3 ou 4 sejam o próximo elemento da sequência.
def solve(v, n, delta):
    u = [v[0]]
    ultima_pos = v[0] 
    for i in range(1, n):
        if v[i] - ultima_pos >= delta:
            u.append(v[i])
            ultima_pos = v[i]
    return u

u = solve(v = [1,2,3,5,6,7], n = 6, delta = 2)
print(u)
