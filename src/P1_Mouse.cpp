#include "P1_Mouse.h"

namespace Input
{
	namespace Mouse
	{
		void Update(Cursor* mouse, SDL_Event* evnt)
		{
			mouse->x = evnt->motion.x;
			mouse->y = evnt->motion.y;
		}
	}
}