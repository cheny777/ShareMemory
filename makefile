
.PHONY:all
all:client server

client:client.cpp comm.h comm.cpp
	g++ client.cpp comm.h comm.cpp -o client

server:server.cpp comm.h comm.cpp
	g++ server.cpp comm.h comm.cpp -o server

.PHONY:clean
clean:
	rm -rf clent server
