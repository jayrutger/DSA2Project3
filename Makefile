CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -ftest-coverage -fprofile-arcs

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS:.hpp=.o)

main: $(OBJECTS) main.o AdjacencyMatrix.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf main.dSYM
	$(RM) *.o *.gc* test/*.o test/*.gc* *.dSYM test/test core main

testBuild: $(OBJECTS) test/test.o
	$(CXX) $(CXXFLAGS) -o test/test $^

test: testBuild
	$(RM) *.gcda *.gcov test/*.gcda test/*.gcov
	test/test --success

coverage: SHELL:=/bin/bash
coverage:
	total_score=0; \
	total_lines=0; \
	cpp_files=`ls *.cpp | grep -v main.cpp`; \
	echo "\n$${cpp_files}"; \
	gcov $${cpp_files}; \
	for file in `gcov $${cpp_files} | sed  -n -e "/File '[a-z.]/{N;N;p;}" | grep -v "File" | grep -v "creating" | sed 's/[^0-9]*//' | sed 's/\.[0-9]*% of /,/'`; \
	do \
		IFS=', ' read -r -a array <<< "$${file}"; \
		total_lines=$$((total_lines+$${array[1]})); \
		total_score=$$((total_score+($${array[0]}*$${array[1]}))); \
		echo "$${array[0]}% of $${array[1]} lines"; \
	done; \
	echo "\n$${total_lines} total lines"; \
	echo "Overall coverage: $$((total_score/total_lines))%"
