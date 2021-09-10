#include <iostream>
#include <unistd.h>
#include <string>
#include <ApplicationServices/ApplicationServices.h>

void setMousePosition(int i) {
    CGEventRef event = CGEventCreate(NULL);
    CGPoint location = CGEventGetLocation(event);

    location.x += i;
    location.y -= i;

    CGDisplayMoveCursorToPoint(CGMainDisplayID(), location);

    std::string output = std::to_string((int)(location.x)) + std::string(", ") + std::to_string((int)(location.y));
    std::cout << "mouse location:" << output << std::endl;
    CFRelease(event);
}

void timerStarter() {
    for(int i = 0; i<= 10; i++) {
        std::cout << i << std::endl;
        usleep(1000000); // sleep for 1 second  
        setMousePosition(i);
    }
}

int main()
{
    int starting_time, ending_time = 0;

    std::cout << "this is wwy for mac os!" << std::endl;
    // std::cout << "Enter starting time:" << std::endl;
    // std::cin >> starting_time; // convert into time
    // // test
    // std::cout << "user output: " << starting_time << std::endl;
   
    // std::cout << "Enter ending time:" << std::endl;
    // std::cin >> ending_time; // convert into time
    // //test
    // std::cout << "user output: " << ending_time << std::endl;
    
    timerStarter();
}