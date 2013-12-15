#include "AllegroError.h"
#include <cstring>


AllegroError::AllegroError(int n, char* msg) : errorNo(n)
{
	strcpy_s(errorMessage, msg);
}


AllegroError::~AllegroError(void)
{
}
