/* breaker.h
 * Created by: S. Harrison
 * Date: 15-09-2018
 */

#pragma once
#include "constants.h"

typedef struct {
	bool is_moving;
	int size, x, y, speed_x, speed_y;
	Box box;
} Ball;

typedef struct {
	bool active;
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

/* Ball Functions */
Ball accelerateBall(Ball ball) {
	if (ball.speed_x < 0) {
		ball.speed_x -= rand() % 2;
	}
	else {
		ball.speed_x += rand() % 2;
	}

	if (ball.speed_y < 0) {
		ball.speed_y -= rand() % 2;
	}
	else {
		ball.speed_y += rand() % 2;
	}

	return ball;
}

Ball createBall(Color Color, int x, int y, int size) {
	Ball ball;
	ball.size = size;
	ball.x = x;
	ball.y = y;
	ball.speed_x = 0;
	ball.speed_y = 0;
	ball.is_moving = false;

	return ball;
}

Ball kickBall(Ball ball) {
	if (ball.is_moving == true) {
		return ball;
	}
	else {
		ball.speed_x = 1 + rand() % 2 - rand() % 4;
		ball.speed_y = 1 + rand() % 2 - rand() % 2;
		ball.is_moving = true;
		return ball;
	}
}

Ball moveBall(Ball ball, Paddle paddle) {
	if (ball.is_moving == false) {
		return ball;
	}

	ball.x += ball.speed_x;
	ball.y += ball.speed_y;
	ball.box = moveBox(ball.box, ball.x, ball.y);

	// TODO: write collision and checks?

	return ball;
}

void drawBall(Ball ball) {
	drawBox(ball.box);
}

/* Block Functions */
Block createBlock(Color color, int x, int y, int width, int height) {
	Block block;
	
	block.active = true;
	block.size = 10;
	block.x = x;
	block.y = y;
	block.box = createBox(color, x, y, x + width, y + height);
	
	return block;
}

void drawBlock(Block block) {
	if (block.active == true) {
		drawBox(block.box);
	}
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