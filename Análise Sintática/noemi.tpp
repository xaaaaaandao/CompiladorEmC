inteiro: vet[10]

inteiro: tam

tam := 10

preencheVetor()
  inteiro: i
  inteiro: j
  i := 0
  j := tam
  repita
    vet[i] := j
    i := i + 1
    j := j - 1
  até i < tam
fim
