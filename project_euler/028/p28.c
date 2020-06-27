#include <stdio.h>


/*
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

Direction:

	1
4		2
	3
*/

int main()
{
	int board[1001][1001]={{ 0 }};
	int i, j, tot=1001*1001;
	int x=501, y=499;
	int line_size=2, column_size=2;
	int direction=4;
	int current_traveled=0;
	board[500][500]=1; board[501][500]=2;
	int h, k, result=0;


	for(i=2; i<tot; i++){
		board[x][y]=i+1;

		switch(direction){
			case 1: 
				y++;
				if(current_traveled==column_size) {
					current_traveled=0;
					direction=2;
					column_size++;	
				}
				break;
			case 2:
				x++;
				if(current_traveled==line_size) {
					current_traveled=0;
					direction=3;
					line_size++;
				}
				break;
			case 3:
				y--;
				if(current_traveled==column_size) {
					current_traveled=0;
					direction=4;
					column_size++;
				}
				break;
			case 4:
				x--;
				if(current_traveled==line_size) {
					current_traveled=0;
					direction=1;
					line_size++;	
				}
				break;
			default: 
				printf("Caso errado\n");
				break;
		}

		current_traveled++;

	}
	
	for(h=0;h<1001;h++)
		result+=board[h][h];
	for(k=1000, h=0;h<1001;k--,h++)	
		result+=board[k][h];

	result--;

	printf("Result: %d\n", result);

	return 0;
}