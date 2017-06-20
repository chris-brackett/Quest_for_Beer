#Note: makefile adapted from makeDemo in the TA example code section

PROGS := finalProject
OBJS := main Player Space BrewingRoom Window Outside BarleyField HopsField FenceTop SupplyRoom SupplyRoomDrawer TastingRoom Tunnel

all: $(PROGS) clean

finalProject: main.o Player.o Space.o BrewingRoom.o Window.o Outside.o BarleyField.o HopsField.o FenceTop.o SupplyRoom.o SupplyRoomDrawer.o SupplyRoomCabinet.o TastingRoom.o Tunnel.o Backpack.o
	g++ -std=c++0x -g main.o Player.o Space.o BrewingRoom.o Window.o Outside.o BarleyField.o HopsField.o FenceTop.o SupplyRoom.o SupplyRoomDrawer.o SupplyRoomCabinet.o TastingRoom.o Tunnel.o Backpack.o -o finalProject

main.o: main.cpp
	g++ -c main.cpp

Backpack.o: Backpack.cpp
	g++ -c Backpack.cpp

Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp

Space.o: Space.cpp Space.hpp
	g++ -c Space.cpp

BrewingRoom.o: BrewingRoom.cpp BrewingRoom.hpp
	g++ -c BrewingRoom.cpp

Window.o: Window.cpp Window.hpp
	g++ -c Window.cpp

Outside.o: Outside.cpp Outside.hpp
	g++ -c Outside.cpp

BarleyField.o: BarleyField.cpp BarleyField.hpp
	g++ -c BarleyField.cpp

HopsField.o: HopsField.cpp HopsField.hpp
	g++ -c HopsField.cpp

FenceTop.o: FenceTop.cpp FenceTop.hpp
	g++ -c FenceTop.cpp

SupplyRoom.o: SupplyRoom.cpp SupplyRoom.hpp
	g++ -c SupplyRoom.cpp

SupplyRoomDrawer.o: SupplyRoomDrawer.cpp SupplyRoomDrawer.hpp
	g++ -c SupplyRoomDrawer.cpp

SupplyRoomCabinet.o: SupplyRoomCabinet.cpp SupplyRoomCabinet.hpp
	g++ -c SupplyRoomCabinet.cpp

TastingRoom.o: TastingRoom.cpp TastingRoom.hpp
	g++ -c TastingRoom.cpp

Tunnel.o: Tunnel.cpp Tunnel.hpp
	g++ -c Tunnel.cpp

clean:
	rm -f $(OBJS) *.o *~