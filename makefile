rcstring: rcstring.o
	g++ -g -Wall -pedantic $^ -o $@

rcstring.o: test_matrix.cpp matrix.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm rcmatrix.o rcmatrix
