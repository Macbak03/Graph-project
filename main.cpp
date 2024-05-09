#include <iostream>
#include "Graph.h"
#include "Action.h"
#include "InvalidDataException.h"

using namespace std;

int main() {
    Graph* graphUser;
    try{
        graphUser = new Graph(Graph::argumentUser);
    } catch (InvalidDataException& exception){
        cerr<<exception.what();
        return 1;
    }

    Action action(graphUser, Graph::argumentUser);
    //Graph graphGenerated(Graph::argumentGenerated);
    //Action action(&graphGenerated, Graph::argumentGenerated);
    action.handleAction();

    return 0;
}
