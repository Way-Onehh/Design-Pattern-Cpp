/* 用类型的接口来实列化 */
//定制化的工厂

//抽象工厂  分离点      怎么去生产 
//具体工厂  多态
//接口      见工厂模式
//产品      见工厂模式

/*abstract*/
/* I AbstractFactoryInterface */
/* I interface1 */
/* I interface2 */
/*Concrete*/
/* c FactoryInterface12 生产12接口*/
/* c FactoryInterface1  生产1接口*/
/* c FactoryInterface2  生产2接口*/
/* c classA1/2 产品A1/2*/
/* c classB1/2 产品B1/2*/


#include<stdio.h>

class interface1
{
public:
    virtual void print()=0;
   
    virtual ~interface1()
    {
        printf("this is interface1's instance %p\n",this);
    }
};

class ClassA1 :public interface1
{
public:
    virtual void print()
    {
        printf("this is ClassA1's instance %p\n",this);
    }

    virtual ~ClassA1()
    {
        printf("this is ClassA1's ~ClassA %p\n",this);
    }
};

class classB1 :public interface1
{
public:
    virtual void print()
    {
        printf("this is ClassB1's instance %p\n",this);
    }
    
    virtual ~classB1()
    {
        printf("this is ClassB1's ~ClassA %p\n",this);
    }
};

class interface2
{
public:
    virtual void print()=0;
   
    virtual ~interface2()
    {
        printf("this is interface2's instance %p\n",this);
    }
};

class ClassA2 :public interface2
{
public:
    virtual void print()
    {
        printf("this is ClassA2's instance %p\n",this);
    }

    virtual ~ClassA2()
    {
        printf("this is ClassA2's ~ClassA %p\n",this);
    }
};

class classB2 :public interface2
{
public:
    virtual void print()
    {
        printf("this is ClassB2's instance %p\n",this);
    }
    
    virtual ~classB2()
    {
        printf("this is ClassB2's ~ClassA %p\n",this);
    }
};

class AbstractFactroyInterface
{
public:
     virtual interface1 * GetInstance1(int Typeid)=0;
     virtual interface2 * GetInstance2(int Typeid)=0;
     static void DestroyInstance1(interface1 * ptr)
     {
        delete ptr;
     }
     static void DestroyInstance2(interface2 * ptr)
     {
        delete ptr;
     }
};

class FactoryInterface12 : public AbstractFactroyInterface
{
public:
    virtual interface1 * GetInstance1(int Typeid)
    {
        interface1 * ptr=nullptr;
        switch(Typeid)
        {
            case 0:
                ptr = new ClassA1;
                break;
            case 1:
                ptr = new classB1;
                break;
            defualt:
                ptr = nullptr;        
                break;
        }
        return ptr;
        }
        
    virtual interface2 * GetInstance2(int Typeid)
    {
        interface2 * ptr=nullptr;
        switch(Typeid)
        {
            case 0:
                ptr = new ClassA2;
                break;
            case 1:
                ptr = new classB2;
            break;
            defualt:
                ptr = nullptr;        
                break;
         }
        return ptr;
    }

};

class FactoryInterface1 : public AbstractFactroyInterface
{
public:


    virtual interface1 * GetInstance1(int Typeid)
    {
        interface1 * ptr=nullptr;
        switch(Typeid)
        {
            case 0:
                ptr = new ClassA1;
                break;
            case 1:
                ptr = new classB1;
                break;
            defualt:
                ptr = nullptr;        
                break;
        }
        return ptr;
        }
        
    virtual interface2 * GetInstance2(int Typeid)
    {
        interface2 * ptr=nullptr;
        return ptr;
    }

};
class FactoryInterface2 : public AbstractFactroyInterface
{
public:


    virtual interface1 * GetInstance1(int Typeid)
    {
        interface1 * ptr=nullptr;
        return ptr;
        }
        
    virtual interface2 * GetInstance2(int Typeid)
    {
        interface2 * ptr=nullptr;
        switch(Typeid)
        {
            case 0:
                ptr = new ClassA2;
                break;
            case 1:
                ptr = new classB2;
            break;
            defualt:
                ptr = nullptr;        
                break;
         }
        return ptr;
    }

};

int main()
{
    AbstractFactroyInterface *Fptr12= new FactoryInterface12(); 
    AbstractFactroyInterface *Fptr1= new FactoryInterface1(); 
    AbstractFactroyInterface *Fptr2= new FactoryInterface2(); 

    auto Iptr1= Fptr12->GetInstance1(0);
    auto Iptr2= Fptr12->GetInstance2(0);
    auto Iptr3= Fptr12->GetInstance1(0);
    auto Iptr4= Fptr12->GetInstance2(0);

    AbstractFactroyInterface::DestroyInstance1(Iptr1);
    AbstractFactroyInterface::DestroyInstance2(Iptr2);
    AbstractFactroyInterface::DestroyInstance1(Iptr3);
    AbstractFactroyInterface::DestroyInstance2(Iptr4);
       
    return 0;
}
