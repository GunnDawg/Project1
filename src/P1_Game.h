#pragma once
#include "P1_Window.h"
#include "P1_Mouse.h"
#include "P1_Gamepad.h"
#include "P1_DeltaClock.h"
#include "P1_Log.h"

struct Game;

namespace System
{
	bool IsRunning(const Game* game);
	bool Initialize(Game* game);

	void HandleInput(Game* game);
	void Update(const Game* game, const float pDT);
	void Draw(const Game* game, double deltaTime);

	void Shutdown(Game* game);
}

struct Game
{
	GameWindow Window = { "Project1", 1600, 900 };
	DeltaClock DeltaClock = { 0 };
	Cursor Mouse = { 0 };
	Controller Controller = { 0 };
	bool IsRunning = false;
	bool UsingGamepad = true;
};