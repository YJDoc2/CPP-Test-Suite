all : fn_eg class_eg
	rm ./*.o

fn_eg : test_functional_suite.o functional_test_example.o
	g++ -o fn_eg test_functional_suite.o functional_test_example.o

class_eg : test_class_suite.o class_test_example.o
	g++ -o class_eg test_class_suite.o class_test_example.o

class_test_example.o : class_test_example.cpp test_class_suite.hpp
	g++ -c class_test_example.cpp
class_test_example.o : class_test_example.cpp test_class_suite.hpp
	g++ -c class_test_example.cpp

test_class_suite.o : test_class_suite.cpp test_class_suite.hpp 
	g++ -c test_class_suite.cpp

functional_test_example.o : functional_test_example.cpp test_functional_suite.hpp
	g++ -c functional_test_example.cpp

test_functional_suite.o : test_functional_suite.cpp test_functional_suite.hpp 
	g++ -c test_functional_suite.cpp

clean :
	rm ./class_eg ./fn_eg
