#include "AdjacencyMatrix.hpp"

int main()
{

	AdjacencyMatrix obj;

	obj.MakeArrayFromFile();

//	obj.PrintMatrix();
		
	obj.Permutate(12);	



	return 0;
}
