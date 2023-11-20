#ifndef OTVDB_TABLE_H_
#define OTVDB_TABLE_H_
#include <vector>
#include <tuple>
#include <set>
#include <cassert>
#include <iostream>
#include <utility>

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
    std::cout << sizeof(_label_list) << "," << sizeof ...(Properties) << std::endl;
    assert((sizeof ...(Properties) != 0));
    assert((_label_list.size() != 0));
    assert((_label_list.size() == sizeof ...(Properties)));
    labels_ = _label_list;
}

template<typename... Properties>
Table<Properties...>::~Table(){} 

template<typename... Properties>
void Table<Properties...>::insert(std::tuple<Properties...> _entry){
    table_.insert(_entry);
}

template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type
print(const std::tuple<Tp...>& t)
{ }

template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I < sizeof...(Tp), void>::type
print(const std::tuple<Tp...>& t)
{
    std::cout << std::get<I>(t) << std::endl;
    print<I + 1, Tp...>(t);
}

template<typename... Properties>
void Table<Properties...>::show(){
    for(auto p = table_.begin(); p != table_.end(); ++p){
        print(*p);
    }
}


} // namespace otvdb



#endif // !OTVDB_TABLE_H_