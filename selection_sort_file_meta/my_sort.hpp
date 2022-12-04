// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful

// selection sort with a function object
template<class T, class Compare>
void my_selection_sort( T begin, T end, Compare comp) {
  for (T i = begin; i != end; ++i) {
    T min = i;
    for (T j = i; j != end; ++j) {
      if (comp(*j, *min)) {
        min = j;
      }
    }
    //swap
    auto tmp = *i;
    *i = *min;
    *min = tmp;
  }
}