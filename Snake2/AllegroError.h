#pragma once
class AllegroError
{
public:
	int errorNo;
	char errorMessage[256];

	AllegroError(int n, char* msg);
	~AllegroError(void);
};

