#pragma once
#include<iostream>
#include<vector>

using namespace std;
#include"模板模式.h"
#include"策略模式.h"
#include"观察者模式.h"
#include"装饰器类.h"
#include"桥接模式.h"
#include"工厂模式.h"
namespace c
{
class a {
public:
	class b
	{
	private:
		size_t id;
		static size_t total;
	public:

		b() { id = ++total; }
	};
};
}
