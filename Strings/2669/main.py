#! /usr/bin/python3
# encoding: utf-8

linha = input()
pesos = [0] * len(linha)

# Transforma todos os caracteres em pesos e realiza a soma total
total = 0
for i in range(len(linha)):
    pesos[i] = (ord(linha[i]) - 96)

# Pega os pesos de todas as substrings
subPesos = set()
for i in range(1, len(pesos) + 1):
    # 'i' é o limite superior da fatia. O inferior é sempre zero
    for j in range(len(pesos) - i + 1):
        # 'j' é o índice pelo qual a fatia será deslocada ao longo da sequência
        subPeso = sum(pesos[j:(i + j)])
        subPesos.add(subPeso)

print(len(subPesos))
