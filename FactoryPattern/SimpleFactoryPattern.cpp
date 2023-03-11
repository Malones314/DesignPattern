#include<iostream>
using namespace std;
/**
 * @brief 抽象产品类, 作为具体product的父类
 * 
 * Public members:
 *  --- virtual void operation(): 纯虚函数，供子类使用
 *  --- ~Product():析构函数
 * **/
class Product{
public:
  virtual void operation() = 0;
  virtual ~Product(){}
};
/**
 * @brief 具体产品类
 * **/
class ConcreteProduct1 : public Product{
public:
  void operation(){
    cout << "Concrete Product1 operation" << endl;
  }
};
/**
 * @brief 具体产品类
 * **/
class ConcreteProduct2 : public Product{
public:
  void operation(){
    cout << "Concrete Product2 operation" << endl;
  }
};
/**
 * @brief 该类根据传入的参数来创建具体的产品类实例
 * 
 * Public member:
 *  --- static Product* createProduct(int type):通过type来确定要创造哪个ConcreteProduct
 * **/
class SimpleFactory {
public:
  /**
   * @return 返回创造的product实例
   * @param 1：创造ConcreteProduct1 2：创造ConcreteProduct2
   * **/
  static Product* createProduct(int type){
      if( type == 1){
        return new ConcreteProduct1();
      }else if( type == 2){
        return new ConcreteProduct2();
      }
      return nullptr;
  }
  //使用static将成员函数声明为静态函数，它与类的实例化对象无关，可以直接通过类名来调用。
  //工厂类的 createProduct 方法通常都是静态方法，因为客户端通过工厂类的静态方法来创建产
  //品对象，而不需要先实例化工厂类。因此，将 createProduct 方法声明为静态方法，可以避免
  //客户端在使用工厂类时需要创建工厂类对象的麻烦。
};

/**
 * @brief 客户端代码，使用工厂创建产品对象
 * **/
int main(){
  // 创建product1对象
  Product* product1 = SimpleFactory::createProduct(1);
  product1->operation();
  delete product1;

  // 创建product2对象
  Product* product2 = SimpleFactory::createProduct(2);
  product2->operation();
  delete product2;

  return 0;
}