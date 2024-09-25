#include <iostream>
#include <cstring>

class Chicken
{
    private:
        int age = 24;
        char *name = nullptr;
    public:
        Chicken(){};
        Chicken(int _age) : age(_age) {};
        Chicken(int _age, const char *_name) : age(_age) 
        {
            int len = strlen(_name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = _name[i];
        };

        Chicken(const Chicken &kk):age(kk.age) //赋值构造函数
        {
             int len=strlen(kk.name)+1;
             if (name!=nullptr)
             delete[] name;
             name=new char[len];   //申请一块新的内存
             for (int i=0;i<len;i++)
             {
                name[i]=kk.name[i];
             }
        };
        
        ~Chicken()
        {
            if (name != nullptr)
                delete[] name;
        }
        void setAge(int _age)
        {
            age = _age;
        }
        void setName(const char *_name)
        {
            if(name != nullptr)
                delete[] name;
            int len = strlen(_name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = _name[i];
        }

        const char *getName() const
        {
            return name;
        }

        const int &getAge() const
        {
            return age;
        }

        Chicken &operator=(const Chicken &_c)  //此处第一处采用左值引用是为了实现连续赋值
        {
             if (this == &_c)
             return *this;     //防止自赋值
             age=_c.age;
             int len=strlen(_c.name)+1;
             if (name!=nullptr)
             delete[] name;
             name=new char[len];   //申请一块新的内存
             for (int i=0;i<len;i++)
             {
                name[i]=_c.name[i];
             }
             return *this;
        }

     
};

int main()
{
    auto print = [](const Chicken &c){
        std::cout<<"Hi, everyone! My name is "<<c.getName()
        <<", I am "<<c.getAge()<<" years.old."<<std::endl;

    };
    Chicken c(24, "KunKun");
    print(c);

    Chicken d;
    d=c;
    print(d);

    Chicken a = c;
    print(a);
    
    c.setName("Xukun Cai");
    print(c);
    print(a);
    print(d);

   Chicken b;
   b = d = c;
   print(b);
   print(d);
   return 0;
}