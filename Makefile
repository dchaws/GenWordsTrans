all: genwords words2trans

genwords: genwords.cpp
	g++ -o genwords genwords.cpp

words2trans: words2trans.cpp
	g++ -o words2trans words2trans.cpp

clean:
	rm -rf *.o genwords words2trans
