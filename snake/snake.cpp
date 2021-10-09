#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <curses.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

bool kbhit() {
  termios term;
  tcgetattr(0, &term);

  termios term2 = term;
  term2.c_lflag &= ~ICANON;
  tcsetattr(0, TCSANOW, &term2);

  int byteswaiting;
  ioctl(0, FIONREAD, &byteswaiting);

  tcsetattr(0, TCSANOW, &term);

  return byteswaiting > 0;
}
#define WIDTH 20
#define HEIGHT 20
#define MAXLEN 50
#define PAUSE_MSG "Paused, Please press space to continue"

void moveSnake();
// Dir
enum Dir { UP, DOWN, LEFT, RIGHT };
// point
typedef struct {
  int x;
  int y;
} Point;
// Game
struct Game {
  int score;
  bool start;
  bool gameover;
} Game;
// MAP
struct Map {
  int width;
  int height;
} Map;
// SNAKE
struct Snake {
  int size;
  Dir dir;
  Point *coor;
} Snake;
// Fruit
struct Fruit {
  Point coor;
  bool flag;
} fruit;
// LOGIC
// Init
void Init() {
  srand((unsigned)time(NULL));
  initscr();
  cbreak();
  noecho();
  Map.width = WIDTH;
  Map.height = HEIGHT;
  Snake.size = 3;
  Point *coor = (Point *)std::malloc(sizeof(Point) * MAXLEN);
  for (int i = 0; i < Snake.size; i++) {
    coor[i].x = Map.width - i;
    coor[i].y = Map.height / 2;
  }
  Snake.coor = coor;
  Snake.dir = RIGHT;
  Game.score = 0;
  Game.start = true;
  Game.gameover = false;
  fruit.coor.x = rand() % (Map.width - 1) * 2 + 1;
  fruit.coor.y = rand() % (Map.height - 1) + 1;
  fruit.flag = false;
}
// when snake head hit fruit, eat and re-create a new fruit
void Eat() {
  if (Snake.coor[0].x == fruit.coor.x && Snake.coor[0].y == fruit.coor.y) {
    fruit.flag = true;
    fruit.coor.x = rand() % Map.width * 2;
    fruit.coor.y = rand() % Map.height;
    fruit.flag = false;
    Snake.size == 50 ? NULL : Snake.size++;
  }
  if (!fruit.flag) {
    mvprintw(fruit.coor.y, fruit.coor.x, "x");
  }
  refresh();
}
// DRAW
void Draw() {
  clear();
  // draw map
  for (int row = 0; row < Map.height; row++) {
    if (row == 0 || row == Map.height - 1) {
      mvprintw(row, 0, "########################################");
    } else {
      mvprintw(row, 0, "#");
      mvprintw(row, Map.width * 2 - 1, "#");
    }
  }
  // draw snake
  for (int i = 0; i < Snake.size; i++) {
    move(Snake.coor[i].y, Snake.coor[i].x);
    printw("o");
  }
  Eat();
}
void snakeMove() {
  for (int i = Snake.size - 1; i > 0; i--) {
    Snake.coor[i].x = Snake.coor[i - 1].x;
    Snake.coor[i].y = Snake.coor[i - 1].y;
  }
  switch (Snake.dir) {
  case UP:
    Snake.coor[0].y--;
    break;
  case DOWN:
    Snake.coor[0].y++;
    break;
  case LEFT:
    Snake.coor[0].x--;
    break;
  case RIGHT:
    Snake.coor[0].x++;
    break;
  }
}
void kbLogic() {
  if (kbhit()) {
    char c = getch();
    switch (c) {
    case 'w':
      if (Snake.dir != DOWN)
        Snake.dir = UP;
      break;
    case 's':
      if (Snake.dir != UP)
        Snake.dir = DOWN;
      break;
    case 'a':
      if (Snake.dir != RIGHT)
        Snake.dir = LEFT;
      break;
    case 'd':
      if (Snake.dir != LEFT)
        Snake.dir = RIGHT;
      break;
    case ' ':
      Game.start = !Game.start;
      break;
    case 'q':
      Game.gameover = true;
      break;
    default:
      break;
    }
  }
}
int main(int argc, char *argv[]) {
  Init();
  while (!Game.gameover) {
    if (Game.start) {
      kbLogic();
      snakeMove();
      Draw();
      usleep(500000);
    } else {
      char const *msg = PAUSE_MSG;
      int x = Map.width - std::strlen(msg) / 2;
      mvprintw(Map.height / 2, x / 2, msg);
      refresh();
      while (' ' != std::getchar()) {
      }
      Game.start = !Game.start;
    }
  }
  endwin();
  free(Snake.coor);

  return 0;
}
