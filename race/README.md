## Race
A program that simulates a race between a tortoise and a hare.

### Racer
The tortoise and hare are represented by each having a Racer capsule.\
They have different stats provided by a RacerProfile which takes values from race/config/RacerProfileMacros.h\
The Racer will wait for a start signal and after they hear the signal they will start running after their reaction time has expired. Then they will run forward defined by their speed until they either reach the goal or run out of stamina. If they run out of stamina they will rest to regain their stamina and then start running again.
### Main capsule
The main capsule is the capsule responsible for communicating with the racers and print the race to the console. It will send the start signal to the racers and while the race is in progress it will repeatedly request the position of the racers, so it can print the racers in their current positions. When a racer reaches the goal the racer will send a message to the main capsule and main will announce the winner. The length of the race and the frequency main will print to the console can be changed in race/config/GlobalMacros.h with the GOAL and FPS definitions.
### Race Printer
The main capsule uses a class called RacePrinter to print the race to the console. It is a regular C++ class with no Code RealTime code. It uses Ascii from files in the racerAscii folder to represent the racers. To use the RacePrinter main needs to first add the racers to the racePrinter using the addRacer() function. Then it needs to call initPrint() for racePrinter to initialize the variables used for printing (all variables except the xPositions)\
Then when it finally comes to printing call the print() function with the x-positions of the racers as input.\
Some variables can be changed for the RacePrinter in race/config/RacePrinterMacros.h\
TRACKHEIGHT is the height used for the track ignoring air above the track (air is just used to print the racers above the track)\
PRINTWIDTH is the length of the lines used for printing\
STARTWIDTH is the width used for the starting area. Having it above 0 allows seeing the racers before they cross the start line.\
GOALWIDTH is similarly to the STARTWIDTH the width of the goal