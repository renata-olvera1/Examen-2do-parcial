bin/prueba : src/prueba.cpp
	g++ src/prueba.cpp -Iinclude -o bin/prueba -lftxui-screen -lftxui-dom -lftxui-component -std=c++2a

ejecutar: bin/prueba
	./bin/prueba

