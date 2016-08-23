// console_check_dongle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	short sh_Resultado;			// Inicializa la libreria
	short sh_PuertoDongle = 85;		// En que puerto está
	short sh_numDongles;		// Cuantas llaves usb hay

	sh_Resultado = Init_MatrixAPI();
	if(sh_Resultado < 0)
	{
		printf("Init_MatrixAPI Return-Code: %d", sh_Resultado);
	}

	sh_numDongles = Dongle_Count(sh_PuertoDongle);
	if(sh_numDongles == 0)
	{
		printf("Matrix-dongles not found at LPT/USB!");
		Release_MatrixAPI();
		exit (EXIT_FAILURE);
	}

	Release_MatrixAPI();
	return 0;
}

