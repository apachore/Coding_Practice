

class funcPointer
{
public:
	bool assignFunc(void (*function)(), int number);
	bool runFunc(int number);
	funcPointer();
	funcPointer(int size);
	~funcPointer();

private:
	int size;
	void (*pFuncPointerArray[5])();
};