all: bubble insertion selection text

bubble: bubble.cpp
	g++ $< -o $@

insertion: insertion.cpp
	g++ $< -o $@

selection: selection.cpp
	g++ $< -o $@

text: bubble insertion selection
	./bubble    > bubble.txt
	./insertion > insertion.txt
	./selection > selection.txt

