#include "raylib.h"
int main() {
  const int windowWidth{512};
  const int windowHeight{380};

  InitWindow(windowWidth, windowHeight, "Dapper Dasher");

  const int width{50};
  const int height{80};

  int posY{windowHeight - height};
  int velocity{0};

  SetTargetFPS(240);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);

    if (IsKeyDown(KEY_SPACE)) {
      velocity = -10;
    }

    posY += velocity;

    DrawRectangle(windowWidth / 2, posY, width, height, BLUE);

    EndDrawing();
  }
}
