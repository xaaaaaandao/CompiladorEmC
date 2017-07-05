{variável redefinida - erro}
{flutuante: a}
{inteiro: a}

{variável redefinida - erro}
{inteiro: b}
{inteiro: b}

{variável redefinida - erro}
{flutuante: c}
{inteiro: c[30]}


{quando é flutante - erro}
{flutuante : a}
{inteiro : j[30]}
{quando é inteiro - erro}
{inteiro : j[60e-10]}
{quando é inteiro - certo}
{inteiro : k[30]}

{quando é inteiro - certo}
{inteiro : k[30][50]}
{quando é inteiro, flutuante - errado}
{flutuante : a}
{inteiro : k[a][50]}
{quando é flutuante, inteiro - errado}
{flutuante : a}
{flutuante : k[50][a]}
{quando é flutuante, flutuante - errado}
{flutuante : a, b}
{flutuante : k[a][b]}

{atribuicao - inteiro := flutuante - errado}
{flutuante : c}
{inteiro : a}
{a := c}
{a := 0.5}
{atribuicao - flutuante := inteiro - errado}
{c := a}
{c := 0}
{flutuante : c[30][30]}
{inteiro : a,b}
{a := c[3][3]}
{a := c[3]}
{a := c[0.5][0.4]}
{a := c[0.5][3]}
{a := c[7][30E-10]}
{c[3][3] := 0.76+0.5}

flutuante : a[30]
a[3] := 5.6

flutuante jabulani(flutuante : j)
	retorna(0.5)
fim

inteiro principal()
	inteiro: b
	b := 10
	jabulani(b)
	retorna(b)
fim