/* Block Breaker Clone - main.c
 * 
 * Created by: S. Harrison
 * Date: 15-09-2018
 */

#include "constants.h"
#include "breaker.h"

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
}

void update() {
	padUpdate();
}

void draw() {
	FntPrint("Block Breaker!");
}
