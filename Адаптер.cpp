
//Адаптер позволяет объектам с несовместимыми интерфейсами работать вместе.

//ПРО ОТКРЫТОЕ И ЗАКРЫТОЕ НАСЛЕДОВАНИЕ(пример на cpp.ref)
//Цели, преследуемые при использовании открытого и закрытого наследования различны.
//Если открытое наследование применяется для наследования интерфейса и 
//реализации, то закрытое наследование - только для наследования реализации.

class FahrenheitSensor
{
  public:
    float getFahrenheitTemp() {
      float t = 32.0;
      return t;
    }
};
  
class Sensor
{    
  public:
    virtual ~Sensor() {}
    virtual float getTemperature() = 0;
};
  
class Adapter : public Sensor {    
private:
    FahrenheitSensor* p_fsensor; 
public:
    Adapter( FahrenheitSensor* p ) : p_fsensor(p) {} //появляется конструктор, который принимает в качестве аргумента переменную класса, которую надо преобразовать
    float getTemperature() override {//переопределяем метод получения температуры для нормальной работы датчика
      return (p_fsensor->getFahrenheitTemp()-32.0)*5.0/9.0;//выполняем необходимые преобразования
    }
    ~Adapter() {
      delete p_fsensor;
    }
};

int main()
{
  Sensor* p = new Adapter( new FahrenheitSensor);
}
