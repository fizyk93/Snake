#include "FileMng.h"
#include <algorithm>
#include <iostream>


FileMng::FileMng(void)
{
	n = 11;
	tab = new int[n];
}


FileMng::~FileMng(void)
{
}

void FileMng::save()
{
    fopen_s(&fout, "RESULTS.bin", "wb");

    if(!fout)
    {
        printf("nie moge otworzyc pliku");
        return;
    }

    fwrite(tab, sizeof(int), n, fout);

    fclose(fout);
}

void FileMng::load()
{
    fopen_s(&fin, "RESULTS.bin", "rb");
	
    size_t d = 0;

    if(fin)
    {
        d = fread(tab, sizeof(int), n, fin);

        fclose(fin);

    }
    if(!fin || d != n)
        for(int i=0; i<n; i++) tab[i]=0;

}

bool FileMng::compare(int a, int b)
{
	return (a>b);
}
void FileMng::update(int data)
{
    //for(int i = 0; i < n; i++)
    //    if(data == t[i])
    //    {
    //        data = 0;
    //        break;
    //    }

	if(data > tab[n-1])
	{
		tab[n-1] = data;
		std::sort(tab, tab+n, compare);
	}

	//read();
	
    //writeFile(t);
}

void FileMng::read()
{
	std::cout << "Wyniki:\n";
	for(int i = 0; i < n; i++)
	{
		std::cout << tab[i] << std::endl;
	}
}