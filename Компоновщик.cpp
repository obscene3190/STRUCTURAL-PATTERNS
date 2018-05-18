#include <iostream>
#include <vector>
#include <cassert>
using namespace std; 

// Общий интерфейс компонентов
class element
{
  public:
    virtual void info() {}
    virtual ~element() {}
    virtual void addUnit(element* p) {
        assert( false);
    }
};
 
// Простой компонент
class tfile: public element
{
  public:
    void info() override {
      cout<<"Text File "<<endl;
    }
    
};
 
class image: public element
{
  public:
    void info() override {
      cout<<"Image "<<endl;
    }
};

 
 
// Контейнер содержит операции добавления/удаления дочерних
// компонентов. Все стандартные операции интерфейса компонентов
// он делегирует каждому из дочерних компонентов.
class folder: public element
{
  private:    
   std::vector<element*> c;
   
  public:
    void info() override {
      for(unsigned int i=0; i<c.size(); ++i)
        c[i]->info();
    }
    void addUnit(element* p) override { 
        c.push_back(p);
    }
    ~folder() {
      for(unsigned int i = 0; i<c.size(); ++i)
        delete c[i];
    }
};

int main() {
    tfile File1;
    folder Folder1;
    image Image1;
    folder Folder2;
    Folder1.addUnit(&File1);
    Folder1.addUnit(&Image1);
    Folder1.info();
    cout<<endl;
    Folder2.addUnit(&Folder1);
    Folder2.addUnit(&File1);
    Folder2.info();
    Image1.addUnit(&File1);
    cout<<endl;
    Folder2.info();
  /*
  Text File 
  Image 

  Text File 
  Image 
  Text File 
  */
}

