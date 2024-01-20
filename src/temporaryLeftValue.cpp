#include <iostream>

template <typename numberType>
numberType add(numberType __x, numberType __y);

template <typename numberType>
numberType add(numberType __x, numberType __y)
{
	return __x + __y;
}

int main(int argc,  char const *argv[])
{
	/*
	 * use {} to create a temporary right value
	 * the scope only in this function
         */
	std::printf("114514 + 1919810 = %zd\n", add(std::size_t{114514}, std::size_t{1919810}));
	return EXIT_SUCCESS;
}
