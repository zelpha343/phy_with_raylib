#include <raylib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

Vector2 nextPosition(Vector2 currentPos, Vector2 velocity, float dt);

Vector2 nextVelocity(Vector2 currentVel, Vector2 Acceleration, float dt);

Vector2 nextAcceleration(Vector2 currentAcc, Vector2 position, float mass, float k, float dt);

int main()
{
    const int winHeight = 720;
    const int winWidth = 1280;

    InitWindow(winWidth, winHeight, "Pendulum");

    SetTargetFPS(1);
    float dt = 0.1;
    float mass = 2000;
    float k = 1;

    Vector2 p;
    p.x = winWidth / 2;
    p.y = winHeight / 2;

    Vector2 v;
    v.x = 0;
    v.y = 0;

    Vector2 a;
    a.x = 0;
    a.y = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        v = nextVelocity(v, a, dt);
        p = nextPosition(p, v, dt);
        a = nextAcceleration(a, p, mass, k, dt);

        DrawCircle(p.x, p.y, 5, RED);
        char *position[20];
        sprintf(position, "X: %.3f, Y: %.3f", p.x, p.y);
        DrawText(position, 0, 0, 50, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

Vector2 nextPosition(Vector2 currentPos, Vector2 velocity, float dt)
{
    Vector2 nextPos;
    nextPos.x = currentPos.x + dt * velocity.x;
    nextPos.y = currentPos.y + dt * velocity.y;

    return nextPos;
}

Vector2 nextVelocity(Vector2 currentVel, Vector2 Acceleration, float dt)
{
    Vector2 nextVel;
    nextVel.x = currentVel.x + dt * Acceleration.x;
    nextVel.y = currentVel.y + dt * Acceleration.y;

    return nextVel;
}

Vector2 nextAcceleration(Vector2 currentAcc, Vector2 position, float mass, float k, float dt)
{
    Vector2 nextAcc;
    nextAcc.x = -(k / mass) * position.x;
    nextAcc.x = -(k / mass) * position.y;
}
