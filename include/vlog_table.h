#ifndef VLOG_TABLE_H_
#define VLOG_TABLE_H_
#include <vector>
#include <tuple>
#include <map>

namespace otvdb
{

template<typename... Properties>
class Table
{
private:
    /* data */
    template<typename T> std::map<T, std::tuple<Properties...>> table_;
    std::vector<const char*> labels_;
public:
    Table() = delete;
    template<typename... Properties> Table(std::vector<const char*> _label_list, const char *_key_label){
        
    }
    ~Table();

    void insert(std::tuple<Properties...> _entry);

};

template<typename... Properties>
Table::Table(std::vector<const char*> _label_list, const char *_key_label){
    if (sizeof ...(Properties) != sizeof(_label_list)){
        /* code */
    }
    
}   

} // namespace otvdb



#endif // !VLOG_TABLE_H_