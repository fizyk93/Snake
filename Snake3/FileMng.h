#pragma once
#include <cstdio>
#include <cstdlib>
#include <cstring>

class FileMng
{
public:
	int *tab;
	int n;
	FILE *fin, *fout;

	FileMng(void);
	~FileMng(void);

	void load();
	void save();
	void update(int data);
	void read();

private:
	static bool compare(int a, int b);
};

