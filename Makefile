TwoSumInBST: TwoSumInBST.o
	g++ -g -o TwoSumInBST.exe TwoSumInBST.o -pthread    

TwoSumInBST.o: TwoSumInBST/TwoSumInBST.cpp
	g++ -g  -c -pthread TwoSumInBST/TwoSumInBST.cpp
