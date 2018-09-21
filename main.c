/* Block Breaker Clone - main.c
 * 
 * Created by: S. Harrison
 * Date: 15-09-2018
 */

#include "constants.h"
#include "breaker.h"

int x, y;
Ball ball;
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
	ball = createBall(createColor(255, 255, 255), (SCREEN_WIDTH / 2) - 2, (SCREEN_HEIGHT / 2) - 2, 2);
}

void update() {
	padUpdate();
	
	if (padCheck(Pad1Start)) {
		
		// create the blocks
		for (y = 0; y < 5; y++) {
			for (x = 0; x < 6; x++) {
				blocks[y][x] = createBlock(colours[y], (x * 50) + 10, (y * 15) + 10, 50, 10);
			}
		}

		// do we generate the ball object?
	}
	
	// move the paddle/player to the left
	if (padCheck(Pad1Left)) {
		player = movePaddle(player, -2);
	}
	
	// move the paddle/player to the right
	if (padCheck(Pad1Right)) {
		player = movePaddle(player, 2);
	}

	// update/move the ball object
	ball = moveBall(ball, player);
}

void draw() {
	// draw the blocks
	for (y = 0; y < 5; y++) {
		for (x = 0; x < 6; x++) {
			drawBlock(blocks[y][x]);
		}
	}

	// draw the player & ball on the screen
	drawPaddle(player);
	drawBall(ball);

	//FntPrint("Block Breaker!");
}
