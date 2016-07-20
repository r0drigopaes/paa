#include <bits/stdc++.h>
using namespace std;

#define MAX 200
#define D -1
typedef int matrix[MAX][MAX];

int current_col;
#define MAX_COL_LINE 50

int check(matrix m, int l1, int c1, int l2, int c2)
{
	int ans = D;
	for (int i = l1; i < l2; ++i)
	{
		for (int j = c1; j < c2; ++j)
		{
			if ( (ans == 1 || ans == D ) && m[i][j] == 1 )
			{
				ans = 1;
			}
			else if ( (ans == 0 || ans == D ) && m[i][j] == 0 )
			{
				ans = 0;
			}
			else
			{
				return D;
			}
		}
	}
	return ans;
}

/*
l1 = inclusivo
c1 = inclusivo

l2 = exclusivo
c2 = exclusivo
*/
void dq(matrix m, int l1, int c1, int l2, int c2)
{	
	if (l1 == l2 || c1 == c2)
	{
		return;
	}
	int ans = check(m, l1, c1, l2, c2);
	if (ans != D)
	{
		if ( current_col == MAX_COL_LINE ) 
		{
			current_col = 0;
			printf("\n");
		}
		printf("%d", ans);
		++current_col;
		return;
	}
	else
	{
		if ( current_col == MAX_COL_LINE ) 
		{
			current_col = 0;
			printf("\n");
		}
		printf("D");
		++current_col;

		if (l2 - l1 == 1 && c2-c1 ==1)
		{
			return;
		}

		int mid_col = ceil((c1 + c2) / 2.0);
		int mid_lin = ceil((l1 + l2) / 2.0);

		dq(m, l1, c1, mid_lin, mid_col); // top left
		dq(m, l1, mid_col, mid_lin, c2); // top right
		dq(m, mid_lin, c1, l2, mid_col); // bottom left
		dq(m, mid_lin, mid_col, l2, c2); // bottom right
	}

	

}

void print_m(matrix m, int lin, int col)
{
	printf("\n");
	for (int i = 0; i < lin; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			printf("%d", m[i][j]);
		}
		printf("\n");
	}
}

int main()
{	
	int tc, lin, col;
	string line;
	matrix m;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d%d\n", &lin, &col);
		for (int i = 0; i < lin; ++i)
		{
			getline(cin, line);
			for (int j = 0; j < col; ++j)
			{
				m[i][j] = line[j] - '0';
			}
		}
		// print_m(m, lin, col);
		current_col = 0;		
		dq(m, 0, 0, lin, col);
		printf("\n");
	}
	

	return 0;
}