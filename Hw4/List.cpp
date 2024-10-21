#include "List.h"
#include <iostream>
List<int> create_Mylist(List<int>& initial_list)
{
   initial_list.push_back(11);      //调用的功能包括begin(),end(),insert()等函数
   initial_list.push_front(-1);
   return initial_list;
}
//自定义函数，向头尾部各插入一个数，并返回一个临时值

void print_List(List<int>& pl)
{
   List<int>::iterator iter=pl.begin();
   while (iter!=pl.end())
   {
      std::cout<<*iter<<' ';
      iter++;
   }
   std::cout<<std::endl;
}//打印链表


int main()
{
    List<int> List1;                   //双向链表的缺省构造函数，且该过程调用私有成员的init()
    List<int> List2={1,2,3,4,5};      //使用初始化链表的构造函数
    print_List(List2);
    List<int> List3(List2);            //测试拷贝构造函数
     print_List(List3);
    List1=List3;                     //测试赋值函数(copy and swap)
   print_List(List1);
    List<int> List4(create_Mylist(List2)); //测试移动构造函数，函数返回值为右值
    List<int>::const_iterator iter1; //只读迭代器的缺省构造函数
    int size4=List4.size();           //测试size()函数
    std::cout<<size4<<std::endl;
    bool emp4=List4.empty();          //测试empty()函数
    std::cout<<emp4<<std::endl;
    List4.clear();                   //测试clear()函数
    std::cout<<List4.empty()<<std::endl;

    List<int> List5={1,3,5};
    std::cout<<List5.front()<<std::endl;
    std::cout<<List5.back()<<std::endl;  //测试非常量对象的front(),back()函数
    //同时也调用了非常量对象的begin()和end()

    const List<int> List6={2,4,6};
    std::cout<<List6.front()<<std::endl;
    std::cout<<List6.back()<<std::endl;  //测试常量对象的front(),back()函数
 //同时也调用了常量对象的begin()和end()

    List5.push_front(1+2+3);
    List5.push_back(20-10+8);  //测试含右值的push_front()和push_back()
    std::cout<<List5.front()<<std::endl;
    std::cout<<List5.back()<<std::endl;

    List5.pop_front();
    List5.pop_back();
    std::cout<<List5.front()<<std::endl;
    std::cout<<List5.back()<<std::endl; //测试pop_front(),pop_back()

    List<int> List7={7,8,9};
    List7.insert(--List7.end(),1+9); //调用前置自减
    List7.insert(List7.begin(),3+3); //测试insert()的右值版本 
     print_List(List7);
    

    List7.erase(++List7.begin(),List7.end()); //测试erase()的范围擦除以及前置自增
     print_List(List7);

    List<int> List8={10,20,30};
    List<int>::iterator iter8(List8.begin());
    iter8++;
    std::cout<<*iter8<<std::endl;
    iter8--;
    std::cout<<*iter8<<std::endl;  //测试带参数的iterator构造函数和后置自增自减
    
    List<int>::iterator iter9(List8.begin());
    List<int>::iterator iter10(List8.end());
    iter9++;
    iter10--;
    if (iter9==iter10) std::cout<<1<<std::endl;

    if (iter9!=iter10) std::cout<<0<<std::endl;//测试两个判断符

    const List<int> List10={1,2,3,5,8};
    std::cout<<(List10.begin()!=List10.end())<<std::endl;
    std::cout<<(List10.begin()==List10.end())<<std::endl;
    std::cout<<*List10.begin()<<std::endl;//测试静态的判断符

    List<int>::const_iterator iter11(List10.begin());
    List<int>::const_iterator iter12(List10.end());
    iter12--;
    iter11++;
    iter12--;
    std::cout<<*iter11<<' '<<*iter12<<std::endl;
    --iter11;
    ++iter12;
    std::cout<<*iter11<<' '<<*iter12<<std::endl;//测试常量形式下的自增自减函数(包括前置后置)
    return 0;
}
