#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    观察者模式步骤：
        1. 提供一个抽象目标类
        2. 提供一个具体目标类
        3. 提供一个抽象观察者类
        4. 提供一个具体观察者类
    // 员工： 观察者类
    // 老板： 被观察者类
*/
class Boss;
class Staff {
  public:
    Staff(string name, Boss *pBoss) : name(name), pBoss(pBoss) {}
    void update(string action) {
        cout << name << "收到讯息：" << action;
        if (action == "老板从大门走进来了") {
            cout << "----->开启认真工作模式" << endl;
        }
        if (action == "老板走了") {
            cout << "----->开启摸鱼模式" << endl;
        }
    }

  private:
    string name;
    Boss *pBoss;
};

class Boss {
  public:
    void AddObserver(Staff *pstaff) { staff.push_back(pstaff); }
    void Notify(string action) {
        for (auto s : staff) {
            s->update(action);
        }
    }
    void setAction(string action) {
        this->action = action;
        Notify(action);
    }

  private:
    string action;
    vector<Staff *> staff;
};

int main() {
    // 创建被观察者
    Boss *pBoss = new Boss;

    // 创建观察者
    Staff *p1 = new Staff("1号", pBoss);
    Staff *p2 = new Staff("2号", pBoss);

    // 建立关联
    pBoss->AddObserver(p1);
    pBoss->AddObserver(p2);

    // 被观察者改变状态
    pBoss->setAction("老板从大门走进来了");
    pBoss->setAction("老板走了");

    return 0;
}