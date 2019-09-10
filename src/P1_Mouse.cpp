#include "P1_Mouse.h"

namespace Input
{
	namespace Mouse
	{
		void Update(Mouse_t* mouse, SDL_Event* evnt)
		{
			mouse->x = evnt->motion.x;
			mouse->y = evnt->motion.y;
		}
	}
}