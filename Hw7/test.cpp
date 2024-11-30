#include "Heapsort.h"

int main()
{
    int total;
    total=1000000;
    std::random_device rd;  
    std::mt19937 gen(rd()); //随机数生成器
    std::uniform_int_distribution<> distrib(1, 1000000); 

    std::vector<int> dorder,ddorder;
    std::vector<int> inc,iinc;
    std::vector<int> dec,ddec;
    std::vector<int> dup,ddup;
    for (int i=0;i<total;i++)
    {
         int temp=distrib(gen);
         dorder.push_back(temp);
         ddorder.push_back(temp);
    }//生成随机序列，范围是1-1000000

     for (int i=0;i<total;i++)
    {
         inc.push_back(i);
         iinc.push_back(i);
    }//生成升序序列

     for (int i=0;i<total;i++)
    {
         dec.push_back(1000000-i);
         ddec.push_back(1000000-i);
    }//生成降序序列

     for (int i=0;i<1000;i++)
    {
        for (int j=0;j<1000;j++)
        {
         dup.push_back(i+j);
         ddup.push_back(i+j);
        }
    }//生成有重复的序列

    auto start1 = std::chrono::high_resolution_clock::now();
    heapsort<int>(dorder);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    std::cout<<duration1.count()<<"ms ";
    start1=std::chrono::high_resolution_clock::now();
    std::sort_heap(ddorder.begin(),ddorder.end());
    end1 = std::chrono::high_resolution_clock::now();
    duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    std::cout<<duration1.count()<<"ms"<<std::endl;//分别排序并计时输出


    auto start2 = std::chrono::high_resolution_clock::now();
    heapsort<int>(inc);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
     std::cout<<duration2.count()<<"ms ";
    start2=std::chrono::high_resolution_clock::now();
    std::sort_heap(iinc.begin(),iinc.end());
    end2 = std::chrono::high_resolution_clock::now();
    duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
    std::cout<<duration2.count()<<"ms"<<std::endl;//分别排序并计时输出

   auto start3 = std::chrono::high_resolution_clock::now();
    heapsort<int>(dec);
    auto end3 = std::chrono::high_resolution_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - start3);
     std::cout<<duration3.count()<<"ms ";
    start3=std::chrono::high_resolution_clock::now();
    std::sort_heap(ddec.begin(),ddec.end());
    end3 = std::chrono::high_resolution_clock::now();
    duration3 = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - start3);
    std::cout<<duration3.count()<<"ms"<<std::endl;//分别排序并计时输出

       auto start4 = std::chrono::high_resolution_clock::now();
    heapsort<int>(dup);
    auto end4 = std::chrono::high_resolution_clock::now();
    auto duration4 = std::chrono::duration_cast<std::chrono::milliseconds>(end4 - start4);
     std::cout<<duration4.count()<<"ms ";
    start4=std::chrono::high_resolution_clock::now();
    std::sort_heap(ddorder.begin(),ddorder.end());
    end4 = std::chrono::high_resolution_clock::now();
    duration4 = std::chrono::duration_cast<std::chrono::milliseconds>(end4 - start4);
    std::cout<<duration4.count()<<"ms"<<std::endl;//分别排序并计时输出

    if (check<int>(dorder)) std::cout<<"correct!"<<std::endl;
    if (check<int>(inc)) std::cout<<"correct!"<<std::endl;
    if (check<int>(dec)) std::cout<<"correct!"<<std::endl;
    if (check<int>(dup)) std::cout<<"correct!"<<std::endl;//逐个检验结果，若结果正确则返回correct
    return 0;
}