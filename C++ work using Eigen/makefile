Transformation: Transformation.cpp
	clang++ Transformation.cpp -o Transformation -I/usr/local/Cellar/eigen/3.2.5/include/eigen3/ 

draw.o:draw.cpp
	g++ -c draw.cpp -I/usr/local/Cellar/sfml/2.3_1/include 

draw:draw.o
	g++ draw.o -o draw -L/usr/local/Cellar/sfml/2.3_1/lib -lsfml-graphics -lsfml-window -lsfml-system

JT: JT.cpp
	clang++ JT.cpp -o JT -I/usr/local/Cellar/eigen/3.2.5/include/eigen3/
