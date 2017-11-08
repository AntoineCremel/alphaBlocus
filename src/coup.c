#include "coup.h"

void emptyCoin(t_Coin * self)
{
	// 0 Variables
	t_Coup * buffer = self->ancre;

	// 1 On désinitialise à chaque fois le premier maillon
	while(buffer)
	{
		self->ancre = buffer->suivant;

		free(buffer);

		buffer = self->ancre;
	}
}
