#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
template <typename T>
bool check(std::vector<T> & vec)
{
   for (int i=0;i<vec.size()-1;i++)
   {
      if (vec[i]>vec[i+1]) return 0;//逐一检验是否满足升序
   }
   return 1;
}

template <typename T>
void heapsort(std::vector<T> & vec)
{
    std::make_heap(vec.begin(),vec.end());//创建堆
    auto last=vec.end();//记录目前还在堆中的元素
    for (int i=0;i<vec.size();i++)
    {
      std::pop_heap(vec.begin(),last);//将最大值置于队尾
      last--;//修正堆的范围
    }
}