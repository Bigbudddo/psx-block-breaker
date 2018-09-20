/* breaker.h
 * Created by: S. Harrison
 * Date: 15-09-2018
 */

#pragma once

typedef struct {
	int size, x, y, is_moving, speed_x, speed_y;
	Box box;
} Ball;

typedef struct {
	int size, x, y;
	Box box;
} Block;

typedef struct {
	int x, y, length;
	Line line;
} Paddle;

typedef struct {
	int score_left;
} Scoreboard;

/* Block Functions */
Block createBlock(Color color, int x, int y, int width, int height) {
	Block block;
	
	block.size = 10;
	block.x = x;
	block.y = y;
	block.box = createBox(color, x, y, x + width, y + height);
	
	return block;
}

void drawBlock(Block block) {
	drawBox(block.box)
}

/* Paddle Functions */
Paddle createPaddle(int length) {
	Paddle paddle;
	
	paddle.x = SCREEN_WIDTH / 2 - length / 2;
	paddle.y = SCREEN_HEIGHT - 30;
	paddle.length = length;
	paddle.line = createLine(createColor(255, 255, 255), paddle.x, paddle.y, paddle.x + paddle.length, paddle.y);
	
	return paddle;
}

Paddle movePaddle(Paddle paddle, int delta_x) {
	if (delta_x < 0 && paddle.x + delta_x <= 22) {
		paddle.x = 20;
		return paddle;
	}
	
	if (delta_x > 0 && paddle.x + paddle.length + delta_x > SCREEN_WIDTH - 22) {
		paddle.x = SCREEN_WIDTH - 20 - paddle.length;
		return paddle;
	}
	
	paddle.x += delta_x;
	paddle.line = moveLine(paddle.line, paddle.x, paddle.y, paddle.x + paddle.length, paddle.y);
	return paddle;
}

void drawPaddle(Paddle paddle) {
	drawLine(paddle.line);
}