/*
Dividir e Conquistar
Busca binária

http://www.spoj.com/problems/BOOKS1/

Rodrigo Paes
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define DEBUG 0
#define D if (DEBUG)

/*
A lógica aqui é a seguinte: suponha que não existe limite de páginas que cada
copiador pode pegar. Nesse caso, o primeiro copiador ficaria com todos os livros
e os outros ficariam ociosos. Não é isso que queremos, precisamos que todos os copiadores
fiquem com pelo menos um livro.

Sendo assim, diminuimos esse limite. Nesse caso, iremos diminuindo esse limite até encontrar
o menor limite possível. A cada nova tentativa de diminuir o limite de paginas, temos que verificar
se é possível alocar os copiadores. Se for, tentamos um limite menor, senão, um limite maior.

Porém, a forma como escolheremos um limite será através de uma busca binária.

*/
int solve(const vi &pages, int scribes)
{
	int n = pages.size();
	int lo = 0;
	int hi = 0;
	int max_pages;
	int current_pages, current_scriber, required;

	// O menor valor será o livro com maior número de páginas. E o maior valor será a soma de todos os livros
	for (int i=0; i< n; ++i) // O(n)
	{
		if (pages[i] > pages[lo])
		{
			lo = i;
		}
		hi += pages[i];
	}
	lo = pages[lo];

	while (lo < hi)  // busca binária: O(lg(n))
	{
		max_pages = lo + (hi - lo)/2;
		current_pages = 0;
		required=1;	
		D printf("Tentando: %d\n", max_pages);

		// verificação se a solução é válida: O(n)
		for (int i=0; i < n; ++i)
		{
			D printf("    i=%d, required=%d\n", i, required);
			
			if (current_pages + pages[i] <= max_pages)
			{
				// O copiador atual é capaz de copiar aquele livro.
				current_pages += pages[i];				
			}
			else
			{		
				/* 
				passa para o próximo copiador.
				Esse array significa qual o livro que o copiador parou.
				Ou seja, a posição k do array, signica que o copiador k
				ficou com os livros assigment[k-1] até (assigment[k] -1)
				*/				
				current_pages = pages[i];
				required++;
			}	
			
			
		}
		
		if ( required <= scribes)
		{
			/* 
			Nem todos os copiadores foram utilizados, logo, pode ser que exista
			uma distribuição melhor. Vamos tentar com menos páginas de limite para 
			cada um
			*/
			hi = max_pages;
		}
		else
		{
			/* estourou o número de copiadores necessários, é preciso subir o limite para
			encontrar uma distribuição adequada
			*/
			lo = max_pages+1;
		}
	}//end while

	/* nesse ponto já sabemos que a solução é "lo", que é a menor 
		quantidade de páginas possível para alocar para os copiadores
	*/	

	return lo;
}

bool print(int hi , int remaining_scribers ,vi &pages , int max_pages)
{	
    int count = 0;
    int lo = -1;
    for(int i = hi; i >= 0; i--)
    {    	
    	/*
    		Nesse caso, são checadas duas condições:
    		1- se ainda existe espaço para o copiador atual
    		2- Suponha que existam 2 livros, logo, o valor de i será 1, pois ele representa o índice.
    			O remaining_scribers guarda quantos copiadores ainda restam, contando com o copiador da
    			chamada atual. Ou seja, se ainda existirem 2 livros e existirem 3 copiadores (contando com o atual),
    			a i será 1, remaining_scribers será 3.  Mas precisamos fazer com que o copiador atual não
    			pegue mais nenhum livro. Pois se ele pegar, não sobrará livros para os primeiros copiadores.
    			Sendo assim, comparamos i com remaining_scribers-2. 
    		*/
        if(count + pages[i] > max_pages || i == remaining_scribers-2)
        {
            // como está de trás pra frente, o i será o valor máximo da próxima chamada
            // o número de copiadores tbm deve diminuir.
            // a chamada é feita de forma recursiva para imprimir na ordem inversa
            print(i , remaining_scribers-1  , pages , max_pages);
            lo = i;
            break;
        }
        count += pages[i];
    }

    if(lo >= 0)
        printf(" /");
    for(int i = lo + 1; i <= hi ; i++)
    {
    	if (i==0) printf("%d", pages[i]);
    	else printf(" %d", pages[i]);
    }
        
}

int main()
{
	int tc, books, scribes, page, b, e;
	vi pages;
	deque<int> assignment;

	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d%d", &books, &scribes);
		pages.clear();
		assignment.clear();
		
		for (int i=0; i< books; ++i)
		{
			scanf("%d", &page);
			pages.push_back(page);
		}
		
		int max_pages = solve(pages, scribes);
		D printf("max:%d\n", max_pages);

		print(pages.size()-1, scribes, pages, max_pages);
		printf("\n");
	}
	return 0;

}
