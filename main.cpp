#include "raylib.h"
int main() {
  const int windowWidth{512};
  const int windowHeight{380};

  InitWindow(windowWidth, windowHeight, "Dapper Dasher");

  const int gravity{1};
  const int jumpVel{-22};
  const int width{50};
  const int height{80};

  int posY{windowHeight - height};
  int velocity{};
  bool isInAir{false};

  SetTargetFPS(240);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);

    isInAir = posY < windowHeight - height;

    posY += velocity;

    if (!isInAir) {
      velocity = 0;
    } else {
      velocity += gravity;
    }

    if (IsKeyDown(KEY_SPACE) && !isInAir) {
      velocity = jumpVel;
    }

    DrawRectangle(windowWidth / 2, posY, width, height, BLUE);

    EndDrawing();
  }
}
