#ifndef c_Func_Pointer_HPP_
#define c_Func_Pointer_HPP_

#include <iostream>
#include "cFuncPointer.hpp"

using namespace std;

funcPointer::funcPointer()
{
	size = 5;
	//pFuncPointerArray[size] = {};
	/*for(int i =0; i<size; i++)
	{
		pFuncPointerArray[i] = NULL;
	}*/

	pFuncPointerArray = new pFunctionPointer[size];
};


funcPointer::funcPointer(int len = 5)
{
	size = len;

	pFuncPointerArray = new pFunctionPointer[size];

	//cout << endl << "Size: "<<size;
};

bool funcPointer:: assignFunc(pFunctionPointer function, int number)
{
	if(function == NULL)
	{
		cout << endl << "assignFunc():: Null cannot be passed as a function";
		return false;
	}
	if(number > size-1 )
	{
		cout <<  endl << "assignFunc():: Assignment number is grater than array length";
		return false;
	}

	pFuncPointerArray[number] = function;

	return true;

};

bool funcPointer::runFunc(int number)
{
	if(number > size-1 )
	{
		cout <<  endl << "runFunc():: Assignment number is grater than array length";
		return false;
	}	

	(*(*pFuncPointerArray[number]))();

	return true;
};

funcPointer::~funcPointer()
{
	for(int i =0; i<size; i++)
	{
		pFuncPointerArray[i] = NULL;
	}

	delete pFuncPointerArray;
	pFuncPointerArray = NULL;
	size=0;
};

#endif //#ifdef c_Func_Pointer_HPP_