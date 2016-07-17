/*
Mutiplicação de matrizes pelo método do Strassen
*/
#include <bits/stdc++.h>
using namespace std;

struct matrix
{
	int **data;
	int l, c;

	matrix(int l, int c) : l(l), c(c)
	{
		data = (int **) calloc(l, sizeof(int *));
		for (int i=0; i < l; ++i)
		{
			data[i] = (int *) calloc (c, sizeof(int));
		}		
	}

	~matrix()
	{
		free(data);
	}
};

struct indexes
{
	int l1, c1, l2, c2;

	indexes(int l1, int c1, int l2, int c2) : l1(l1), c1(c1), l2(l2), c2(c2) {}	
};

struct submatrix
{
	matrix *m;
	indexes i;

	submatrix(matrix *m, indexes i) : m(m), i(i) {}

	indexes get_i11()
	{
		return indexes(i.l1, i.c1, (i.l1 + i.l2) / 2, (i.c1 + i.c2) / 2);
	}

	indexes get_i12()
	{
		return indexes(i.l1, (i.c1 + i.c2)/2, (i.l1 + i.l2) / 2, i.c2);
	}

	indexes get_i21()
	{
		return indexes((i.l1 + i.l2) / 2, i.c1, i.l2, (i.c1 + i.c2) / 2);
	}

	indexes get_i22()
	{
		return indexes((i.l1 + i.l2) / 2, (i.c1 + i.c2) / 2, i.l2, i.c2);
	}

	int rows()
	{
		return (i.l2 - i.l1) + 1;
	}

	int get_single_value()
	{
		if (rows() != 1)
		{
			printf("A submatriz contém mais de um elemento.\n");
			exit(-1);
		}
		return m->data[i.l1][i.c1];
	}

};

void add_matrices(matrix &a, matrix &b, submatrix &c)
{
	for (int lin = 0; lin <= a.l; ++lin)
	{
		for (int col = 0; col <= a.c; ++col)
		{
			c.m->data[c.i.l1 + lin][c.i.c1 + col] = a.data[lin][col] + b.data[lin][col];
		}
	}

}

/* a recebe b */
void assign(submatrix &a, submatrix &b)
{
	for (int lin = a.i.l1; lin <= a.i.l2; ++lin)
	{
		for (int col = a.i.c1; col <= a.i.c2; ++col)
		{
			a.m->data[lin][col] = b.m->data[b.i.l1 + lin][b.i.c1 +  col];
		}
	}
}

matrix mult(submatrix &a, submatrix &b)
{
	matrix m(a.rows(), a.rows());
	
	if (a.rows() == 1)
	{
		m.data[0][0] = a.m->data[a.i.l1][a.i.c1] * b.m->data[b.i.l1][b.i.c1];
		// c.m->data[a.i.l1][a.i.c1] = 
	}
	else
	{
		submatrix a11(a.m, a.get_i11());
		submatrix a12(a.m, a.get_i12());
		submatrix a21(a.m, a.get_i21());
		submatrix a22(a.m, a.get_i22());

		submatrix b11(b.m, b.get_i11());
		submatrix b12(b.m, b.get_i12());
		submatrix b21(b.m, b.get_i21());
		submatrix b22(b.m, b.get_i22());

		// parei aqui: como fazer declarar o c de tal forma que ele fique com a submatriz correta?
		submatrix c(&m, indexes(0, 0, ))

		submatrix c11(c.m, c.get_i11());
		submatrix c12(c.m, c.get_i12());
		submatrix c21(c.m, c.get_i21());
		submatrix c22(c.m, c.get_i22());
		
		add_matrices(mult(a11, b11), mult(a12, b21), c11);
		add_matrices(mult(a11, b12), mult(a12, b22), c12);
		add_matrices(mult(a21, b11), mult(a22, b21), c21);
		add_matrices(mult(a21, b12), mult(a22, b22), c22);
	}
	return m;
}



int main()
{
	return 0;
}