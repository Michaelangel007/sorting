all: bubble insertion selection quick text

bubble: bubble.cpp
	g++ $< -o $@

insertion: insertion.cpp
	g++ $< -o $@

selection: selection.cpp
	g++ $< -o $@

quick: quick.cpp
	g++ $< -o $@

text: bubble insertion selection
	./bubble    > bubble.txt
	./insertion > insertion.txt
	./selection > selection.txt
	./quick     > quick.txt

