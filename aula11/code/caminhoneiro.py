def algoritmo_caminhoneiro(p, n, C):
    p = sorted(p)
    S = []
    ultima_parada = 0
    for i in range(1,n):
        if (p[i] - ultima_parada > C):
            ultima_parada = p[i-1] 
            S.append(i-1) 
    return S

postos = [10, 20, 30, 50, 60, 70, 80, 90, 100, 110]
S = algoritmo_caminhoneiro(p = postos, n = 10, C = 40)
print(S)
print([postos[i] for i in S])
