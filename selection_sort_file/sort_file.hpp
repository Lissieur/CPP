// Do not change
#include <iostream>
#include <fstream>


#include <list>
#include <vector>
#include <deque>

#include "my_sort.hpp"

// Change here
// All occurences of XXX need to be replaced with
// something more meaningful


template<class V, class C>
void read_file_to_cont(std::ifstream& f, C& c) {
    V v;
    while (f >> v) {
        c.push_back(v);
    }
}

template<class V, class C>
void read_and_sort(std::ifstream& fi, std::ofstream& fo) {
    C c = {};
    read_file_to_cont<V, C>(fi, c);
    my_selection_sort(c.begin(), c.end());
    for (auto &v : c) {
        fo << v << std::endl;
    }
}

template<class V>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo) {
  // read second line to decide container
  char container_type;
  fi >> container_type;
  fo << container_type << std::endl;
  switch (container_type) {
    case 'l':
      read_and_sort<V, std::list<V>>(fi, fo);
      break;
    case 'v':
      read_and_sort<V, std::vector<V>>(fi, fo);
      break;
    case 'd':
      read_and_sort<V, std::deque<V>>(fi, fo);
      break;
    default:
      throw std::runtime_error("Unknown container");
  }
}


void read_and_sort_decide_valuetype(std::ifstream& fi, std::ofstream& fo) {
  // read first line to decide value type
  char value_type;
  fi >> value_type;
  fo << value_type << std::endl;
  switch(value_type) {
    case 'i':
      read_and_sort_decide_container<int>(fi, fo);
      break;
    case 'u':
      read_and_sort_decide_container<unsigned>(fi, fo);
      break;
    case 'f':
      read_and_sort_decide_container<float>(fi, fo);
      break;
    case 'd':
      read_and_sort_decide_container<double>(fi, fo);
      break;
    case 'c':
      read_and_sort_decide_container<char>(fi, fo);
      break;
    case 's':
      read_and_sort_decide_container<std::string>(fi, fo);
      break;
    default:
      throw std::runtime_error("Unknown value type");
  }
}

// switch(line[0]) {
//     case 'i':
//       template<int>
//       read_and_sort_decide_container(fi, fo);
//       break;
//     case 'u':
//       template<unsigned int>
//       read_and_sort_decide_container(fi, fo);
//       break;
//     case 'f':
//       template<float>
//       read_and_sort_decide_container(fi, fo);
//       break;
//     case 'd':
//       template<double>
//       read_and_sort_decide_container(fi, fo);
//       break;
//     case 'c':
//       template<char>
//       read_and_sort_decide_container(fi, fo);
//       break;
//     case 's':
//       template<std::string>
//       read_and_sort_decide_container(fi, fo);
//       break;
//     default:
//       throw std::runtime_error("Unknown value type");
//   }

// std::getline(fi, line);
//   switch(line[0]) {
//     case 'i':
//       read_and_sort_decide_container<int>(fi, fo);
//       break;
//     case 'd':
//       read_and_sort_decide_container<double>(fi, fo);
//       break;
//     case 's':
//       read_and_sort_decide_container<std::string>(fi, fo);
//       break;
//     default:
//       throw std::runtime_error("Unknown value type");
//   }