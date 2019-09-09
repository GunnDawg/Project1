#pragma once
#include "P1_Window.h"
#include "P1_Mouse.h"
#include "P1_Gamepad.h"
#include "P1_DeltaClock.h"
#include "P1_Log.h"

struct Game;

bool IsRunning(const Game* game);
bool InitializeGame(Game* game);

void HandleInput(Game* game);
void Update(const Game* game, const float pDT);
void Draw(const Game* game, double deltaTime);

void ShutdownGame(Game* game);

struct Game
{
	GameWindow Window = { "Project1", 1600, 900 };
	DeltaClock DeltaClock = { 0 };
	Mouse mouse = { 0 };
	GamePad Controller = { 0 };
	bool IsRunning = false;
	bool UsingGamepad = true;
};