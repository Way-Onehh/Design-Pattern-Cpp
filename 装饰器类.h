#pragma once
namespace 设计模式 
{
	class 装饰器模式
	{
	private:
		class 抽象类_接口a 
		{
		public:
			virtual void f() = 0;
			virtual void f1() = 0;
			virtual void f2() = 0;
		};
		
	public:
		class b :public 抽象类_接口a 
		{
		public:
			void f() override { cout << "b::f()\n"; }
			void f1()override { cout << "b::f1()\n"; }
			void f2()override { cout << "b::f2()\n"; }
		};
		class 装饰器类 :public 抽象类_接口a
		{
			抽象类_接口a* _p;
		public:
			装饰器类(抽象类_接口a* p):_p(p) {}
			 void f() override { _p->f(); }
			 void f1()override { _p->f1(); }
			 void f2()override { _p->f2(); }
			 void f4() { cout << "装饰器类::f4()\n"; }
		};
		static void main()
		{
			b o1;
			装饰器类 o2(&o1);
			o2.f();
			o2.f1();
			o2.f2();
			o2.f4();
		}
	};
}