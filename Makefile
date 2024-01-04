all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/AVL_Agaci.cpp -o ./lib/AVL_Agaci.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/Yigin.cpp -o ./lib/Yigin.o	
bagla:
	g++ ./lib/Dugum.o ./lib/Yigin.o ./lib/AVL_Agaci.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program