#pragma once
#include "P1_Window.h"
#include "P1_Mouse.h"
#include "P1_Gamepad.h"
#include "P1_DeltaClock.h"
#include "P1_Log.h"

struct Game_t;

namespace System
{
	bool IsRunning(const Game_t* game);
	bool Initialize(Game_t* game);

	void HandleInput(Game_t* game);
	void Update(const Game_t* game, const float pDT);
	void Draw(const Game_t* game, double deltaTime);

	void Shutdown(Game_t* game);
}

struct Game_t
{
	Window_t Window = { "Project1", 1600, 900 };
	DeltaClock DeltaClock = { 0 };
	Mouse_t mouse = { 0 };
	Gamepad_t Controller = { 0 };
	bool IsRunning = false;
	bool UsingGamepad = true;
};