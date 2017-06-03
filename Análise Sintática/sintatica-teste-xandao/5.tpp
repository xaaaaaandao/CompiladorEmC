inteiro principal()
	inteiro: digitado
	inteiro: i
	i := 1
	repita
		flutuante: f
		inteiro: int
		flutuante: resultado
		f := i/2.
		int := i/2
		resultado := f - int
		
		se  resultado > 0 então
			escreva(i)
		fim
		i := i+1
	até i <= digitado
fim

