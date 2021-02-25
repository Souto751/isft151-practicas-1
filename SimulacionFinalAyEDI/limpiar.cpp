#include "limpiar.h"

void limpiar()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
