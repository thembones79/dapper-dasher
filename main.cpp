#include "raylib.h"
int main() {
  const int windowWidth{512};
  const int windowHeight{380};

  InitWindow(windowWidth, windowHeight, "Dapper Dasher");

  const int gravity{6000};

  Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");




  Texture2D scarfy = LoadTexture("textures/scarfy.png");
  Rectangle scarfyRec;
  scarfyRec.width = scarfy.width / 6;
  scarfyRec.height = scarfy.height;
  scarfyRec.x = 0;
  scarfyRec.y = 0;
  Vector2 scarfyPos;
  scarfyPos.x = windowWidth / 2 - scarfyRec.width / 2;
  scarfyPos.y = windowHeight - scarfyRec.height;

  int frame{};
  const float updateTime{1.0 / 12.0};
  float runningTime{};

  const int jumpVel{-1600};

  int velocity{};
  bool isInAir{false};

  SetTargetFPS(240);

  while (!WindowShouldClose()) {

    const float dT{GetFrameTime()};

    BeginDrawing();
    ClearBackground(WHITE);

    isInAir = scarfyPos.y < windowHeight - scarfyRec.height;

    if (!isInAir) {
      velocity = 0;
    } else {
      velocity += gravity * dT;
    }

    if (IsKeyDown(KEY_SPACE) && !isInAir) {
      velocity = jumpVel;
    }

    scarfyPos.y += velocity * dT;

    runningTime += dT;
    if (runningTime >= updateTime) {
      runningTime = 0.0;
      scarfyRec.x = frame * scarfyRec.width;
      frame++;
      if (frame > 5) {
        frame = 0;
      }
    }

    DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

    EndDrawing();
  }
  UnloadTexture(scarfy);
  UnloadTexture(nebula);
  CloseWindow();
}
