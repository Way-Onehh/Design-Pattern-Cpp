#pragma once
namespace 设计模式 
{
	class 桥接模式
	{
	private:
		class 抽象类_接口api
		{
		public:
			virtual void api1() = 0;
			virtual void api2() = 0;
			virtual void api3() = 0;
		};
		class 抽象类_接口a
		{
		protected:
			抽象类_接口api* api;
		public:
			抽象类_接口a(抽象类_接口api* p) :api(p) {}
			virtual void f() = 0;
			virtual void f1() = 0;
			virtual void f2() = 0;
		};
	public:
		class a :public 抽象类_接口a
		{
		public:
			a(抽象类_接口api* p) : 抽象类_接口a(p) {}
			void f() override { cout << "在f()里面\n"; api->api1(); }
			void f1()override { cout << "在f1()1里面\n"; api->api2(); }
			void f2()override { cout << "在f2()2里面\n";  api->api3(); }
		};
		class api :public 抽象类_接口api
		{
		public:
			void api1() { cout << "用了api1\n"; }
			void api2() { cout << "用了api2\n"; }
			void api3() { cout << "用了api3\n"; }
		};
		static void main() 
		{
			api o1;
			a o2(&o1);
			o2.f();
			o2.f1();
			o2.f2();
		}
	};

}