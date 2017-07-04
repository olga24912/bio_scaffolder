#ifndef SCAFFOLDER_QUERY_H
#define SCAFFOLDER_QUERY_H

#include <string>

namespace filter {
//Query that process in Filters
    struct Query {
        enum queryType {
            UPLOAD_GRAPH, MIN_EDGE_WEIGHT, MIN_CONTIG_LEN, SET_IGNORE, RESET_IGNORE,
            MERGE_LIB, SET_IGNORE_EDGE
        };
        queryType type;
        std::string argv;

        Query(queryType type, std::string argv) : type(type), argv(argv) {}
    };
}

#endif //SCAFFOLDER_QUERY_H
