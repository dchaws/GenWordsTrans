all: genwords gentrans words2trans

gentrans: gentrans.o printvector.o
	g++ -o gentrans gentrans.o printvector.o

gentrans.o: gentrans.cpp 
	g++ -c gentrans.cpp 

genwords: genwords.o printvector.o
	g++ -o genwords genwords.o printvector.o

genwords.o: genwords.cpp 
	g++ -c genwords.cpp 

printvector.o: printvector.cpp printvector.h
	g++ -c printvector.cpp

words2trans: words2trans.cpp
	g++ -o words2trans words2trans.cpp

clean:
	rm -rf *.o genwords words2trans
