## clock
A clock simulation that counts time in hh:mm:ss format with each digit having its own state machine. Counts up from 0 and prints the time continuosly to the console.
### macros
Properties of the clock can be changed in the Globalmacros.h file.\
SPEEDMULTIPLIER affects how fast the clock is ticking. When set to 1 it ticks once every second. When set to 2 it ticks twice every second, etc.\
FPS affects how often the time will be printed to the console. If set to 3 it will print 3 times each second.\
TIMEOUTSEC sets the time in second it takes from the program start for the program to automatically terminate.

### clock module
The clock module is responsible for managing the digit modules and send the current time to the main module. It repeatedly ticks at a timing based on the SPEEDMULTIPLIER value and sends a message to the digit modules when they should increase. If the SPEEDMULTIPLIER is very high, then there might be missed timeouts. The missed timeouts are not compensated for, but if there are missed timeouts, then the ticker will go slower in the pase of the more significant digit and in the future the more significant digit will be increased instead.
### Digit modules
Each digit module is responsible for 1 digit and is controlled by the clock module. The clock module can send a request to get the value of the current digit. To control the digit, the clock module can send messages to the digit when it should be increased and what base the digit should count with (such as the 10th digit of seconds should be in base 6, since there are 60 seconds in a minute). When the increase results in a overflow, then the digit will send a carry message to the clock module.
### Main module
The main module continuesly requests the current time from the clock module and prints it to the console at a pase based on the FPS value. It also has a timer that tells the program when it should terminate based on the TIMEOUTSEC variable.