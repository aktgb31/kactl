/**
 * Author: Amit Kumar
 * Date: 2022-09-30
 * License: CC0
 * Source: Internet
 * Description: Policy based data stucture
 * Time: O(\log N)
 */ 

#include <bits/extc++.h> 
using namespace __gnu_pbds;
typedef tree< int, //key type
null_type, // null_type:set,mapped: map
less_equal<int>, // comparator
rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//1)find_by_order(k) returns element at index k (zero indexed)
//2)order_of_key(element) returns the number of elements strictly smaller than element