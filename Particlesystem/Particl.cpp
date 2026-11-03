#include "Particl.h"
#include <cmath>

void Particl::Activate(Vector2 spawnCenter, float spawnRadius, Color spawnColor, float spawnSpeed, float spawnAngle)
{
    center = spawnCenter;
    radius = spawnRadius;
    color = spawnColor;
    speed = spawnSpeed;
    angle = spawnAngle;
    velocity = { std::cos(angle * DEG2RAD) * speed, std::sin(angle * DEG2RAD) * speed };
    totalLife = 1.75f;
    remainingLife = totalLife;
    gravity = 10.0f;
    active = true;
}

void Particl::Update()
{
    if (!active) return;

    const float deltaTime = GetFrameTime();
    const float frameScale = deltaTime * 60.0f;

    velocity.y += gravity * deltaTime * 0.6f;
    center.x += velocity.x * frameScale;
    center.y += velocity.y * frameScale;
    remainingLife -= deltaTime;

    if (remainingLife <= 0.0f ||
        center.x < -radius || center.x > GetScreenWidth() + radius ||
        center.y < -radius || center.y > GetScreenHeight() + radius)
    {
        active = false;
    }
}

void Particl::Draw()
{
    if (active)
    {
        DrawCircleV(center, radius, Fade(color, remainingLife / totalLife));
    }
}
