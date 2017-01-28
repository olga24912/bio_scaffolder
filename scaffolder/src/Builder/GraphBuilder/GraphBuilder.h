#ifndef SCAFFOLDER_GRAPHBUILDER_H
#define SCAFFOLDER_GRAPHBUILDER_H


#include "ContigGraph/ContigGraph.h"
#include "Builder/SamFileWriter/SamFileWriteEdge.h"

// main class for generate conection between contigs.
class GraphBuilder {
protected:
    std::string path; // path/to/the/dir where this class will generate files.

    ContigGraph* graph; //generated graph
    SamFileWriteEdge samFileWriter; //for write info about edge's reads

    string libName; //name of the lib

    virtual string getLibColor() = 0; //return color for current lib
    static string colorToString(int color[3]); // translate color like array {255, 0, 255} to  string "#ff00ff"
    virtual void setSamFileWriter(); // init samFileWriter
public:
    //fun that need to call for add conection between contigs;
    virtual void evaluate() = 0;

    //set graph, and change lib in it to new.
    // need to be coll after setLibName
    virtual void setGraph(ContigGraph* graph);

    //set libName
    //create new dir: path/libName
    void setLibName(std::string libName, std::string path);
};


#endif //SCAFFOLDER_GRAPHBUILDER_H
