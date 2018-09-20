/* Block Breaker Clone - main.c
 * 
 * Created by: S. Harrison
 * Date: 15-09-2018
 */

#include "constants.h"
#include "breaker.h"

Paddle player;
Block blocks[5][6];

int main() {
	initialize();

	while(1) {
		update();
		draw();
		display();
	}
	
	return 0;
}

void initialize() {
	// setup initalizers
	initializeScreen();
	initializePad();
	initializeDebugFont();
	
	// define the background colour
	setBackgroundColor(createColor(50, 50, 50));

	// define the player object
	player = createPaddle(60);
}

/*
Block * createBlockRow(Color color, int rowY) {
	int c;
	int width = (SCREEN_WIDTH - 20) / 6;
	static Block r[6];
	
	for (c = 0; c < 6; c = c + 1) {
		r[c] = createBlock(color, c * width, y, width);
	}
	
	return r;
}*/

void update() {
	padUpdate();
	
	if (padCheck(Pad1Start)) {
		int x, y;
		Color color = createColor(125, 125, 125);
		
		for (y = 0; y < 5; y++) {
			for (x = 0; x < 6; x++) {
				blocks[y][x] = createBlock(color, x * 50, y * 15, 50);
			}
		}
	}
	
	if (padCheck(Pad1Left)) {
		player = movePaddle(player, -2);
	}
	
	if (padCheck(Pad1Right)) {
		player = movePaddle(player, 2);
	}
}

void draw() {
	drawPaddle(player);
	FntPrint("Block Breaker!");
}
