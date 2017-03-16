
typedef void(*pFunctionPointer)();

class funcPointer
{
public:
	bool assignFunc(pFunctionPointer, int number);
	bool runFunc(int number);
	funcPointer();
	funcPointer(int size);
	~funcPointer();

private:
	int size;
	pFunctionPointer *pFuncPointerArray;
};