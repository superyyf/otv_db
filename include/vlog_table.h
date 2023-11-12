#ifndef VLOG_TABLE_H_
#define VLOG_TABLE_H_
#include <vector>
#include <tuple>

template<typename T>
class Property {
private:
    std::string label_;
    T value_;
public:

    


};

template<class... Properties>
class Table
{
private:
    /* data */
    std::vector<std::tuple<Properties>> table_;
    std::vector<std::string> labels_;
public:
    Table() = delete;
    template<class... Properties> Table();
    ~Table();

    void insert(std::tuple<Properties> _entry);

};

#endif // !VLOG_TABLE_H_