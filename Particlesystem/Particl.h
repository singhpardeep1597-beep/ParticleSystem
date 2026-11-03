#pragma once
#include "raylib.h"
#include <functional>

struct Particl
{
    Vector2 center = Vector2{ 0, 0 };
    Vector2 velocity = Vector2{ 0, 0 };
    float radius = 0;
    float remainingLife = 0;
    float totalLife = 0;
    Color color = BLACK;
    float speed = 0;
    float angle = 0;
    float gravity = 10;
    bool active = false;

    void Activate(Vector2 center, float radius, Color color, float speed, float angle);

    void Draw();

    void Update();
};
