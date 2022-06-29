udp_client: main.o udp_client.o
	g++ main.o udp_client.o -o udp_client -lSDL2

main.o: src/main.cpp
	g++ -c src/main.cpp

udp_client.o: src/udp_client.cpp src/udp_client.h
	g++ -c src/udp_client.cpp

clean: 
	rm *.o udp_client