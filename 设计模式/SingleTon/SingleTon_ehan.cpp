#include <iostream>
using namespace std;
/*
    要点：
    1. 私有化构造函数：这样外界就无法自由地创建类对象，进而阻止了多个实例的产生
    2. 类定义中含有该类的唯一静态私有对象：静态变量存放在全局存储区，且是唯一的，供所有对象使用
    3. 用公有的静态函数来获取该实例：提供了访问接口

    懒汉式：在使用类对象（单例实例）时才会去创建它，不然就懒得去搞
    饿汉式：单例实例在类装载时构建，有可能全局都没使用过，但它占用了
        空间，就像等着发救济粮的饿汉提前排好队等吃的一样
*/

class Singleton {
    public:
        // 用公有的静态函数来获取该实例
        static Singleton* get_instance(){
            return m_sin_ins;
        } 
    private:
        Singleton(){}
        static Singleton*  m_sin_ins;
};
Singleton* Singleton::m_sin_ins = new Singleton;

int main()
{
    Singleton* p1 = Singleton::get_instance();
    Singleton* p2 = Singleton::get_instance();

    cout <<  "p1的地址是: " << hex << p1 << endl;
    cout <<  "p2的地址是: " << hex << p2 << endl;

    return 0;
}