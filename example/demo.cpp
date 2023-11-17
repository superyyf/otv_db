#include "otvdb_table.h"
#include <string>

int main(){
    otvdb::Table<int, std::string, double> tab({"age", "name", "high"});
    tab.insert(std::make_tuple(25, "yyf", 175.5));
    tab.show();

}