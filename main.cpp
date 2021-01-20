#include <iostream>
#include <vector> // we need this to store a list of our cars by using std::vector
typedef struct Location
{
  float X;
  float Y;
  float Z;
}ALocation;

class Animal
{
  protected:
  ALocation StartLocation{0,0,0};
  public:
  ALocation GetLocation(){return StartLocation;}
  virtual void MorningRoutine(){std::cout << "Fart\n";}

};
class Mammal : public Animal
{
  public:
  void Howl(){ std::cout<< " Howl Howl \n";}
  void MorningRoutine(){std::cout << "Pee \n";}
};
class Wolf : public Mammal
{
  public:
 void Bite(){std::cout << "Yum Yum \n";}
};

class Bird : public Animal
{
  
};
class Owl
{

};
int main() 
{
 Animal* randomAnimal = new Animal();
 std::cout<< " Start Loctaion of Animal" <<randomAnimal->GetLocation().X << "\n";
 randomAnimal->MorningRoutine();
 Mammal* randomMamal = new Mammal();
  std::cout<< " Start Loctaion of Mamal" <<randomMamal->GetLocation().X << "\n";
  randomMamal->MorningRoutine();
  Wolf* Ken = new Wolf();

  Ken->Howl();
  std::cout << Ken->GetLocation().X << "\n";

  // Assigments 
  Animal* MessyAnimal = randomMamal;
  MessyAnimal->MorningRoutine();

  std::vector<Animal*> AllTheAnimals;
  AllTheAnimals.push_back(randomAnimal);
  AllTheAnimals.push_back(randomMamal);
  AllTheAnimals.push_back(Ken);


  // showing example of downward Cast
  for(Animal* RandomAnimal : AllTheAnimals)
  {
    Wolf* randomWolf = dynamic_cast<Wolf*>(RandomAnimal);
    if(randomWolf)
    {
      randomWolf->Bite();
    }
  }
}