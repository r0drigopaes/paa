/*
http://www.practice.geeksforgeeks.org/problem-page.php?pid=896
Missing element of AP
Divide and Conquer
Rodrigo Paes
*/
#include <bits/stdc++.h>
using namespace std;

int n, r;
int a[10];

/*
b: inclusivo
e: exclusivo
*/
int dq(int b, int e)
{	
	int mid = (b+e) / 2;
	int an = a[0] + (mid) * r; // e-nésimo termo
	/*
	Como o elemento faltante nunca está na extremidade, facilita um pouco a condição
	de parada. Nesse caso ele pode chamar o dq com um único elemento ou mesmo com nenhum.
	Ou seja, 'e' e 'b' podem ser iguais. Por isso coloquei o menor ou igual e não o igual.
	Veja o segundo exemplo da página:  -28 -21 -7 0 
	Ele vai chamar:
		dq(0,4)
		dq(0,2)
		dq(2,2) <- aqui tem que parar. 
	*/
	if (e - b <= 1) // condição de parada  (quando tem um elemento ou nenhum)
	{
		/*
		Quando tem um só elemento, o número faltante está exatamente antes ou depois.		
		Se o enésimo termo for igual ao elemento, então o número está á direita. Caso 
		contrário estará à esquerda.
		*/
		if ( a[mid] == an )
		{
			return a[mid] + r;
		}
		else
		{
			return a[mid] - r;
		}
	}
	else
	{
		/* Se a[mid] for igual ao an, significa que ele está na posição certa e portanto, o elemento
		que falta estará na metade direita. Caso contrário, significa que o array foi deslocado para a
		esquerda, significando que o elemento que falta está à esquerda. */
		if (a[mid] == an )
		{
			return dq(mid + 1, e);
		}
		else
		{
			return dq(b, mid);
		}
	}

}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		r = (a[n-1] - a[0]) / (n); // razão da pa
		
		printf("%d\n", dq(0,n));
	}
	return 0;
}