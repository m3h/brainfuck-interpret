#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int isBrainy(int c)
{
	return c == '<' || c == '>' || c == '-' || c == '+' || c == '[' || c == ']' || c == ',' || c == '.';
}

int main()
{
	vector<char> prog;
	vector<int> loops;

	int data[30000];

	int c;
	while((c = getchar()) != EOF)
		if(isBrainy(c))
			prog.push_back(c);
/*
	for(int i = 0; i < prog.size(); ++i)
		putchar(prog[i]);
	putchar('\n');
*/

	int endloop = 0;
	int h = 0;
	for(int i = 0; i < prog.size(); ++i) {

		while(endloop) {
			if(prog[i] == ']')
				--endloop;
			else if (prog[i] == '[')
				++endloop;
			++i;
		}

//			printf("P:%c ", prog[i] );
		switch(prog[i]) {

			case '+':
				++data[h];
				break;

			case '-':
				--data[h];
				break;
			
			case '>':
				++h;
				break;

			case '<':
				--h;
				break;

			case ',':
				data[h] = getchar();
				break;

			case '.':
				putchar( data[h] );
				break;

			case '[':
				if(data[h] == 0) {
					printf("ENDLOOP %d \n", i);
					++endloop;
				}
				else {
					printf("Enter Loop %d \n", i);
					loops.push_back(i);
				}
				break;

			case ']': 
				i = loops[loops.size()-1]-1;
				printf("GOTO: %d\n", i);
				break;
		}
	}
	printf("\n");
}
