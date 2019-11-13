#ifndef _EVENTS_EVENTSCHEDULER_H_
#define _EVENTS_EVENTSCHEDULER_H_

#include "commands/Command.h"
#include "commands/CommandGroup.h"
#include "main.h"
#include "events/EventListener.h"
#include "subsystems/Subsystem.h"
#include <vector>

class EventScheduler {
  private:
    size_t numSubsystems = 0; // Keeps track of the number of subsystems on the robot
    static EventScheduler* instance;
    EventScheduler();
    std::vector<Subsystem*> subsystems; // Keeps track of subsystems in order to initialize their default commands
    std::vector<EventListener*> eventListeners; // Keeps track of event listeners
    std::vector<Command*> commandQueue; // Queue for commands that have been added
    std::vector<CommandGroup*> commandGroupQueue; // Queue for command groups that have been added
  public:
    const static int millisecondTimeout = 25; // Maximum time to run event listeners
    static EventScheduler* getInstance(); // Return the singleton instance of the event scheduler
    void update(); // Checks event listeners and runs, finishes, and interrupts commands and command groups
    void addEventListener(EventListener* eventListener); // Adds an event listener to keep track of
    void addCommand(Command* commandToRun); // Adds a command to the command queue
    void addCommandGroup(CommandGroup* commandGroupToRun); // Adds a command group to the command group queue
    void removeCommand(Command* commandToRemove); // Removes a command from the command queue and calls its interrupted function
    void removeCommandGroup(CommandGroup* commandGroupToRemove); // Removes a command from the command group queue and calls its interrupted function
    void clearCommandQueue(); // Removes all commands from the command queue and calls their interrupted functions
    void clearCommandGroupQueue(); // Removes all command groups from the command group queue and calls their interrupted functions
    void trackSubsystem(Subsystem* aSubsystem); // Adds a subsystem to the subsystems vector
    bool commandInQueue(Command* aCommand); // Checks if a command is in the command queue
    bool commandGroupInQueue(CommandGroup* aCommandGroup); // Checks if a command is in the command group queue
};

#endif // _EVENTS_EVENTSCHEDULER_H_
