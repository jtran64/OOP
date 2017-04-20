template <class T>

class TestClass
{
public:
	void swap(T &a, T &b)
	{
		T c = a;
		a = b;
		b = c;
	}
};



