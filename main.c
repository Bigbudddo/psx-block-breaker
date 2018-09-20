/* Block Breaker Clone - main.c
 * 
 * Created by: S. Harrison
 * Date: 15-09-2018
 */

#include "constants.h"
#include "breaker.h"

int x, y;
Paddle player;
Block blocks[5][6];
Color colours[5];

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

	// setup block colours
	colours[0] = createColor(51, 153, 255);
	colours[1] = createColor(255, 51, 255);
	colours[2] = createColor(255, 0, 127);
	colours[3] = createColor(128, 255, 0);
	colours[4] = createColor(255, 51, 51);

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
		
		// create the blocks
		for (y = 0; y < 5; y++) {
			for (x = 0; x < 6; x++) {
				blocks[y][x] = createBlock(colours[y], (x * 50) + 10, (y * 15) + 10, 50, 10);
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

	// draw the blocks
	for (y = 0; y < 5; y++) {
		for (x = 0; x < 6; x++) {
			drawBlock(blocks[y][x]);
		}
	}

	//FntPrint("Block Breaker!");
}
