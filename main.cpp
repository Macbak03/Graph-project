#include <iostream>
#include "Graph.h"
#include "Action.h"

int main() {

    Graph graphUser("--user-provided");
    //Graph graphGenerated("--generate");
    Action action(&graphUser);
    action.handleAction();

    return 0;
}
