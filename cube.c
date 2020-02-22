#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
		char* s = argv[1];
		int i, j, n, m;
	    char down[] = {'Y', 'Y', 'Y', 'Y'};
	    char back[] = {'G', 'G', 'G', 'G'};
	    char right[] = {'O', 'O', 'O', 'O'};
	    char temp1, temp2;
	    int row, col;
    
		int len = strlen(s);
	    char grid[7][11] = {
        
	        {' ', ' ', '/', ' ', 'W', ' ', ' ', 'W', ' ', '/', '|'},
	        {' ', '/', ' ', 'W', ' ', ' ', 'W', ' ', '/', 'B', '|'},
	        {'+', '-', '-', '-', '-', '-', '-', '+', 'B', ' ', '|'},
	        {'|', ' ', 'R', ' ', ' ', 'R', ' ', '|', ' ', 'B', '|'},
	        {'|', ' ', ' ', ' ', ' ', ' ', ' ', '|', 'B', ' ', '+'},
	        {'|', ' ', 'R', ' ', ' ', 'R', ' ', '|', ' ', '/', ' '}
	    };
    
	
		if(argc)
			;
		    for(i = 0; i < len; i++)
		    {
		        if(s[i] == '2' || s[i] == '+')
		        {
		            continue;
		        }
		        else if((s[i+1] == '+' && s[i] != 'X') || (s[i+1] != '+' && s[i+1] != '2' && s[i] == 'X'))
		        {
		            if(s[i] == 'F' || s[i] == 'Z')
		            {
		                temp1 = grid[0][7];
		                temp2 = grid[1][6];
		                grid[0][7] = right[1];
		                grid[1][6] = right[3];
		                right[3] = down[2];
		                right[1] = down[3];
		                down[2] = grid[3][5];
		                down[3] = grid[5][5];
		                grid[3][5] = temp1;
		                grid[5][5] = temp2;
                
		                temp1 = grid[2][8];
		                grid[2][8] = grid[1][9];
		                grid[1][9] = grid[3][9];
		                grid[3][9] = grid[4][8];
		                grid[4][8] = temp1;
		            }
		            if(s[i] == 'B' || s[i] == 'Z')
		            {
		                if(s[i] == 'B')
		                {
		                    m = 3;
		                }
		                else
		                {
		                    m = 1;
		                }
		                for(j = 0; j < m; j++)
		                {
		                    temp1 = grid[0][4];
		                    temp2 = grid[1][3];
		                    grid[0][4] = right[2];
		                    grid[1][3] = right[0];
		                    right[0] = down[1];
		                    right[2] = down[0];
		                    down[0] = grid[3][2];
		                    down[1] = grid[5][2];
		                    grid[3][2] = temp1;
		                    grid[5][2] = temp2;
                
		                    temp1 = back[0];
		                    back[0] = back[1];
		                    back[1] = back[3];
		                    back[3] = back[2];
		                    back[2] = temp1;
		                }
		            }
		            if(s[i] == 'U' || s[i] == 'Y')
		            {
		                temp1 = grid[3][2];
		                temp2 = grid[3][5];
		                grid[3][2] = back[1];
		                grid[3][5] = back[0];
		                back[1] = right[1];
		                back[0] = right[0];
		                right[1] = grid[2][8];
		                right[0] = grid[1][9];
		                grid[2][8] = temp1;
		                grid[1][9] = temp2;
                
		                temp1 = grid[0][4];
		                grid[0][4] = grid[0][7];
		                grid[0][7] = grid[1][6];
		                grid[1][6] = grid[1][3];
		                grid[1][3] = temp1;
		            }
		            if(s[i] == 'D' || s[i] == 'Y')
		            {
		                temp1 = grid[5][2];
		                temp2 = grid[5][5];
		                grid[5][2] = back[3];
		                grid[5][5] = back[2];
		                back[3] = right[3];
		                back[2] = right[2];
		                right[3] = grid[4][8];
		                right[2] = grid[3][9];
		                grid[4][8] = temp1;
		                grid[3][9] = temp2;
                
		                temp1 = down[0];
		                down[0] = down[1];
		                down[1] = down[3];
		                down[3] = down[2];
		                down[2] = temp1;
		            }
		            if(s[i] == 'L' || s[i] == 'X')
		            {
		                temp1 = grid[1][3];
		                temp2 = grid[1][6];
		                grid[1][3] = grid[2][8];
		                grid[1][6] = grid[4][8];
		                grid[2][8] = down[2];
		                grid[4][8] = down[0];
		                down[2] = back[2];
		                down[0] = back[0];
		                back[2] = temp1;
		                back[0] = temp2;
                
		                temp1 = grid[3][2];
		                grid[3][2] = grid[3][5];
		                grid[3][5] = grid[5][5];
		                grid[5][5] = grid[5][2];
		                grid[5][2] = temp1;
                
		            }
		            if(s[i] == 'R' || s[i] == 'X')
		            {
		                temp1 = grid[0][4];
		                temp2 = grid[0][7];
		                grid[0][4] = grid[1][9];
		                grid[0][7] = grid[3][9];
		                grid[1][9] = down[3];
		                grid[3][9] = down[1];
		                down[3] = back[3];
		                down[1] = back[1];
		                back[3] = temp1;
		                back[1] = temp2;
                
		                temp1 = right[0];
		                right[0] = right[1];
		                right[1] = right[3];
		                right[3] = right[2];
		                right[2] = temp1;
		            }
		        }
		        else
		        {
		            if(s[i+1] == '2')
		            {
		                n = 2;
		            }
		            else
		            {
		                n = 1;
		            }
		            for(j = 0; j < n; j++)
		            {
		                if(s[i] == 'F' || s[i] == 'Z')
		                {
		                    temp1 = grid[0][7];
		                    temp2 = grid[1][6];
		                    grid[0][7] = grid[3][5];
		                    grid[1][6] = grid[5][5];
		                    grid[3][5] = down[2];
		                    grid[5][5] = down[3];
		                    down[2] = right[3];
		                    down[3] = right[1];
		                    right[3] = temp1;
		                    right[1] = temp2;
                    
		                    temp1 = grid[2][8];
		                    grid[2][8] = grid[4][8];
		                    grid[4][8] = grid[3][9];
		                    grid[3][9] = grid[1][9];
		                    grid[1][9] = temp1;
		                }
		                if(s[i] == 'B' || s[i] == 'Z')
		                {
		                    if(s[i] == 'B')
		                    {
		                        m = 3;
		                    }
		                    else
		                    {
		                        m = 1;
		                    }
		                    for(j = 0; j < m; j++)
		                    {
		                        temp1 = grid[0][4];
		                        temp2 = grid[1][3];
		                        grid[0][4] = grid[3][2];
		                        grid[1][3] = grid[5][2];
		                        grid[3][2] = down[0];
		                        grid[5][2] = down[1];
		                        down[0] = right[2];
		                        down[1] = right[0];
		                        right[2] = temp1;
		                        right[0] = temp2;
                        
		                        temp1 = back[0];
		                        back[0] = back[2];
		                        back[2] = back[3];
		                        back[3] = back[1];
		                        back[1] = temp1;
		                    }
		                }
		                if(s[i] == 'U' || s[i] == 'Y')
		                {
		                    temp1 = grid[3][2];
		                    temp2 = grid[3][5];
		                    grid[3][2] = grid[2][8];
		                    grid[3][5] = grid[1][9];
		                    grid[2][8] = right[1];
		                    grid[1][9] = right[0];
		                    right[1] = back[1];
		                    right[0] = back[0];
		                    back[1] = temp1;
		                    back[0] = temp2;
                    
		                    temp1 = grid[0][4];
		                    grid[0][4] = grid[1][3];
		                    grid[1][3] = grid[1][6];
		                    grid[1][6] = grid[0][7];
		                    grid[0][7] = temp1;
		                }
		                if(s[i] == 'D' || s[i] == 'Y')
		                {
		                    temp1 = grid[5][2];
		                    temp2 = grid[5][5];
		                    grid[5][2] = grid[4][8];
		                    grid[5][5] = grid[3][9];
		                    grid[4][8] = right[3];
		                    grid[3][9] = right[2];
		                    right[3] = back[3];
		                    right[2] = back[2];
		                    back[3] = temp1;
		                    back[2] = temp2;
                    
		                    temp1 = down[0];
		                    down[0] = down[2];
		                    down[2] = down[3];
		                    down[3] = down[1];
		                    down[1] = temp1;
		                }
		                if(s[i] == 'L' || s[i] == 'X')
		                {
		                    temp1 = grid[1][3];
		                    temp2 = grid[1][6];
		                    grid[1][3] = back[2];
		                    grid[1][6] = back[0];
		                    back[2] = down[2];
		                    back[0] = down[0];
		                    down[2] = grid[2][8];
		                    down[0] = grid[4][8];
		                    grid[2][8] = temp1;
		                    grid[4][8] = temp2;
                    
		                    temp1 = grid[3][2];
		                    grid[3][2] = grid[5][2];
		                    grid[5][2] = grid[5][5];
		                    grid[5][5] = grid[3][5];
		                    grid[3][5] = temp1;
		                }
		                if(s[i] == 'R' || s[i] == 'X')
		                {
		                    temp1 = grid[0][4];
		                    temp2 = grid[0][7];
		                    grid[0][4] = back[3];
		                    grid[0][7] = back[1];
		                    back[3] = down[3];
		                    back[1] = down[1];
		                    down[3] = grid[1][9];
		                    down[1] = grid[3][9];
		                    grid[1][9] = temp1;
		                    grid[3][9] = temp2;
                    
		                    temp1 = right[0];
		                    right[0] = right[2];
		                    right[2] = right[3];
		                    right[3] = right[1];
		                    right[1] = temp1;
		                }
		            }
		        }
		    }
    
		    printf("   +------+\n");
		    for(row = 0; row < 7; row++)
		    {
		        for(col = 0; col < 11; col++)
		        {
		            printf("%c", grid[row][col]);
		        }
		        if(row != 6)
		        {
		            printf("\n");
		        }
		    }
		    printf("+------+   \n");
		    printf("Hurrah!\n");
    
		    return 0;
}
