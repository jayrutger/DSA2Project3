#include "AdjacencyMatrix.hpp"

int main()
{

	AdjacencyMatrix obj;

	obj.MakeArrayFromFile();

//	obj.PrintMatrix();
		
	obj.Permutate(12);	

//	obj.GetDistance();
	

	return 0;
}
