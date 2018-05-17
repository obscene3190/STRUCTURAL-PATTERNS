#include <iostream>
#include <vector>
using namespace std; 

// Общий интерфейс компонентов
class element
{
  public:
    virtual void info() {}
    virtual ~element() {}
};
 
// Простой компонент
class tfile: public element
{
  public:
    virtual void info() {
      cout<<"Text File "<<endl;
    }
};
 
class image: public element
{
  public:
    virtual void info() {
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
    void info() {
      for(unsigned int i=0; i<c.size(); ++i)
        c[i]->info();
    }
    void addUnit(element* p) { 
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
}
