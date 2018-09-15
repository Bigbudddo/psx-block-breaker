/* Block Breaker Clone - main.c
 * 
 * Created by: S. Harrison
 * Date: 15-09-2018
 */

#include "constants.h"
#include "breaker.h"

Paddle player;

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

void update() {
	padUpdate();
	
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
