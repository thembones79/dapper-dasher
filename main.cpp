#include "raylib.h"
int main() {
  const int windowWidth{512};
  const int windowHeight{380};

  InitWindow(windowWidth, windowHeight, "Dapper Dasher");

  bool collision_with_axe{false};


  SetTargetFPS(240);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);


    EndDrawing();
  }
}
