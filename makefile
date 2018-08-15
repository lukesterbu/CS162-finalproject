CXX = g++
CXXFLAGS = -std=c++11 
#CXXFLAGS += -Wall -Wextra -pedantic -g #Optional debug flags.
OBJECTS = Ammo.o \
	Bandage.o \
	Character.o \
	City.o \
	Cure.o \
	Desert.o \
	finalMain.o \
	Gun.o \
	inputValidation.o \
	Items.o \
	Jungle.o \
	Map.o \
	Ocean.o \
	Player.o \
	Shield.o \
	Space.o \
	Zombie.o \

finalMain: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o finalMain $(OBJECTS)

Ammo.o: Ammo.cpp Ammo.hpp
	$(CXX) $(CXXFLAGS) -c Ammo.cpp

Bandage.o: Bandage.cpp Bandage.hpp
	$(CXX) $(CXXFLAGS) -c Bandage.cpp

Character.o: Character.cpp Character.hpp
	$(CXX) $(CXXFLAGS) -c Character.cpp

City.o: City.cpp City.hpp
	$(CXX) $(CXXFLAGS) -c City.cpp

Cure.o: Cure.cpp Cure.hpp
	$(CXX) $(CXXFLAGS) -c Cure.cpp

Desert.o: Desert.cpp Desert.hpp
	$(CXX) $(CXXFLAGS) -c Desert.cpp

finalMain.o: finalMain.cpp
	$(CXX) $(CXXFLAGS) -c finalMain.cpp

Gun.o: Gun.cpp Gun.hpp
	$(CXX) $(CXXFLAGS) -c Gun.cpp

inputValidation.o: inputValidation.cpp inputValidation.hpp
	$(CXX) $(CXXFLAGS) -c inputValidation.cpp

Items.o: Items.cpp Items.hpp
	$(CXX) $(CXXFLAGS) -c Items.cpp

Jungle.o: Jungle.cpp Jungle.hpp
	$(CXX) $(CXXFLAGS) -c Jungle.cpp

Map.o: Map.cpp Map.hpp
	$(CXX) $(CXXFLAGS) -c Map.cpp

Ocean.o: Ocean.cpp Ocean.hpp
	$(CXX) $(CXXFLAGS) -c Ocean.cpp

Player.o: Player.cpp Player.hpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

Shield.o: Shield.cpp Shield.hpp
	$(CXX) $(CXXFLAGS) -c Shield.cpp

Space.o: Space.cpp Space.hpp
	$(CXX) $(CXXFLAGS) -c Space.cpp

Zombie.o: Zombie.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c Zombie.cpp

clean: 
	clear
	#rm finalMain
	rm *.o
	ls

status:
	clear
	ls
