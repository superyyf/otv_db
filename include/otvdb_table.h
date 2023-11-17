#ifndef OTVDB_TABLE_H_
#define OTVDB_TABLE_H_
#include <vector>
#include <tuple>
#include <set>
#include <cassert>
#include <iostream>

namespace otvdb
{

template<typename... Properties>
class Table
{
private:
    /* data */
    std::set<std::tuple<Properties...>> table_;
    std::vector<const char*> labels_;
public:
    Table() = delete;
    Table(std::initializer_list<const char*> _label_list);
    ~Table();

    void insert(std::tuple<Properties...> _entry);
    void show();

};

template<typename... Properties>
Table<Properties...>::Table(std::initializer_list<const char*> _label_list){
    assert((sizeof ...(Properties) != 0));
    assert((sizeof(_label_list) != 0));
    assert((sizeof(_label_list) == sizeof ...(Properties)));
    labels_ = _label_list;
}   

template<typename... Properties>
void Table<Properties...>::insert(std::tuple<Properties...> _entry){
    table_.insert(_entry);
}

template<typename... Properties>
void Table<Properties...>::show(){
    int n = std::tupe_size<std::tuple<Properties...>>;
    for(auto p = table_.begin(); p != table_.end(); ++p){
        for(int i = 0; i < n; ++i){
            std::cout << std::get<i>(*p) << '\t';
        }
        std::cout << std::endl;
    }
}

} // namespace otvdb



#endif // !OTVDB_TABLE_H_