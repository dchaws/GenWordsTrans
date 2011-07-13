all: genwords

genwords: genwords.cpp
	g++ -o genwords genwords.cpp

clean:
	rm -rf *.o genwords
