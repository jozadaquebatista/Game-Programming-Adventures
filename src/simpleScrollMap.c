#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#define clear system("clear")

#define size_H 6
#define size_W 24

#define break_line puts("")

typedef struct
{
	int x,
	    y;

} CAMERA;

/*
*  TO GO TO THE LEFT INSERT 1
*  TO GO TO THE RIGHT INSERT 2
*  TO EXIT TYPE 3
*
*  to compile: gcc -o map_test map_test.c -std=c11  
*
*  ~Game programming is fun~
 */

char map[ size_H ][ size_W ] = {
			{'9','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
			{'#','b','_','_','#','e','_','#','g','a','_','_','a','a','_','_','#','#','_','_','_','_','_','#'},
			{'_','_','c','_','#','_','_','#','h','a','a','a','_','_','+','+','_','_','_','#','#','#','_','#'},
			{'a','_','_','_','d','_','#','f','_','_','_','_','_','d','+','+','_','_','_','_','#','#','_','#'},
			{'#','b','_','_','_','e','_','_','g','a','a','a','a','d','_','_','#','#','_','_','_','_','_','#'},
			{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','9'}};

void render_map( CAMERA*, int );

int main( int argc, char **argv )
{

	FILE *fd = NULL;

	fd = (FILE*)fopen("/tmp/map.env", "r");

	int isRunning=1,
		offset=0;

	CAMERA *camera = calloc(1, sizeof(CAMERA));

	camera->y = size_H;
	camera->x = size_W;
	

	while(isRunning)
	{

		int key;

		for(int i=0; i<300000000; i++);
		clear;

		if(fd == NULL)
		{
			perror("Error in map load");
		}

		render_map( camera, offset );
		printf("Current Position: %d\n", offset);

		while(1)
		{
			puts("Type 1 for left or 2 for right:");
			scanf("%d", &key);

			if( key == 1 || key == 2 || key == 3 )
				break;
		}

		switch(key)
		{
			case 1:
				if(offset > 0 && offset <= 20)
					offset--;
				break;
			case 2:
				if(offset >= 0 && offset < 20)
					offset++;
				break;
			case 3:
				isRunning = 0;
				clear;
				break;
		}

	}

	break_line;
	free(camera);

	return 0;
}


// IMPLEMENTATION OF FUNCTIONS
void render_map( CAMERA *camera, int offset)
{
	for(int y=0; y<( camera->y ); y++)
	{
		for(int x=offset; x<( camera->x/5 )+(offset); x++)
		{
			if(map[y][x] == '_')
			{
				printf("  ");
			}
			else if(map[y][x] == '#')
			{
				printf("@ ");
			}
			else { printf("%c ", map[y][x]); }
		}
		break_line;
	}
}
