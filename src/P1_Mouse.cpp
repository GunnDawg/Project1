#include "P1_Mouse.h"

void UpdateCursorPosition(Mouse* mouse, SDL_Event* evnt)
{
	mouse->x = evnt->motion.x;
	mouse->y = evnt->motion.y;
}