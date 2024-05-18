#pragma once
namespace 设计模式
{
	class 工厂模式
	{
	private:
		class 抽象类_接口a
		{
		public:
			virtual void f() = 0;
		};
	public:
		class a1 :public 抽象类_接口a
		{
		public:
			a1() { cout << "加入了新a1\n"; }
			void f() override
			{
				cout << "a1:f()\n";
			}
		};
		class a2 :public 抽象类_接口a
		{
		public:
			a2() { cout << "加入了新a2\n"; }
			void f() override
			{
				cout << "a2:f()\n";
			}
		};
		class factory
		{
		public:
			抽象类_接口a* createa1(string type)
			{
				抽象类_接口a* p;
				if (type == "a1")
				{
					return new a1();
				}
				if (type == "a2")
				{
					return new a2();
				}
			}
		};
		static void main() 
		{
			factory f1;
			抽象类_接口a *o1 = f1.createa1("a1");
			o1->f();
			delete o1;
			o1 = f1.createa1("a2");
			o1->f();
		}
	};
}