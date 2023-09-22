#include <iostream>

using namespace std;
/*

    1. 提供一个工厂类
    2. 提供一个抽象产品类
    3. 提供一个具体产品类

    // 简单计算器 + - * /

*/
// 抽象产品类
class Operation {
  public:
    double m_left_val, m_right_val;
    virtual double GetResult() = 0;
};

// 具体产品类
class AddOperation : public Operation {
    double GetResult() override { return m_left_val + m_right_val; }
};
class SubOperation : public Operation {
    double GetResult() override { return m_left_val - m_right_val; }
};
class MulOperation : public Operation {
    double GetResult() override { return m_left_val * m_right_val; }
};
class DivOperation : public Operation {
    double GetResult() override { return m_left_val / m_right_val; }
};

// 工厂类
class OperatorFactory {
  public:
    static Operation *creatOperation(char c) {
        switch (c) {
        case '+':
            return new AddOperation;
            break;
        case '-':
            return new SubOperation;
            break;
        case '*':
            return new MulOperation;
            break;
        case '/':
            return new DivOperation;
            break;
        default:
            return nullptr;
        }
    }
};

// 测试
int main() {
    Operation *add = OperatorFactory::creatOperation('+');
    add->m_left_val = 2;
    add->m_right_val = 5;
    cout << add->GetResult() << endl;
    Operation *sub = OperatorFactory::creatOperation('-');
    sub->m_left_val = 4;
    sub->m_right_val = 6;
    cout << sub->GetResult() << endl;

    delete add;
    delete sub;
    return 0;
}