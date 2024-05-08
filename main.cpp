#include <iostream>
#include "Graph.h"
#include "Action.h"

int main() {

    Graph graphUser(Graph::argumentUser);
    Action action(&graphUser, Graph::argumentUser);
    //Graph graphGenerated(Graph::argumentGenerated);
    //Action action(&graphGenerated, Graph::argumentGenerated);
    action.handleAction();

    return 0;
}
