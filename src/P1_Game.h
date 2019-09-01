#pragma once
#include "P1_Window.h"
#include "P1_DeltaClock.h"
#include "P1_Log.h"

struct Game;

bool IsRunning(const Game* game);
bool InitializeGame(Game* game);

void HandleInput(Game* game);
void Update(const Game* game);
void Draw(const Game* game);

void ShutdownGame(Game* game);

struct Game
{
	GameWindow Window = { "Project1", 1600, 900 };
	DeltaClock DeltaClock;
	bool IsRunning = false;
};