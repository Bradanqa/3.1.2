#include <iostream>

class SmartArray {
public:
   SmartArray(int size) {
      this->size = size;
      arr = new int[size];
      index = 0;
      std::cout << "constructor" << std::endl;
   }

   SmartArray(const SmartArray &ogj) {
      this->size = ogj.size;
      this->arr = new int[ogj.size];
      this->index = ogj.index;
      for (int i = 0; i < ogj.size; ++i) {
         arr[i] = ogj.arr[i];
      }
      std::cout << "constructor" << std::endl;
   }

   ~SmartArray() {
      delete[] arr;
      std::cout << "destructor" << std::endl;
   }

   void addElement(int value) {
      if (index < size) {
         arr[index] = value;
         index++;
      }
      else {
         throw std::runtime_error("Index out of bounds");
      }
   }

   int getElement(int index) {
      if (index < 0 || index > this->index - 1) {
         throw std::runtime_error("Index out of bounds");
      }
      else {
         return arr[index];
      }
   }

   SmartArray& operator=(const SmartArray& other) {
      if (this != &other) {
         delete[] arr;
         size = other.size;
         arr = new int[size];
         index = other.index;
         for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
         }
      }
      return *this;
   }

private:
   int* arr;
   int size;
   int index;
};

int main() {

   try {
      SmartArray arr(5);
      arr.addElement(1);
      arr.addElement(2);
      arr.addElement(3);
      std::cout << arr.getElement(0) << std::endl;
      std::cout << arr.getElement(1) << std::endl;
      std::cout << arr.getElement(2) << std::endl;

      SmartArray newArr(5);
      newArr.addElement(5);
      newArr.addElement(4);
      newArr.addElement(8);
      std::cout << newArr.getElement(0) << std::endl;
      std::cout << newArr.getElement(1) << std::endl;
      std::cout << newArr.getElement(2) << std::endl;

      arr = newArr;

      std::cout << arr.getElement(0) << std::endl;
      std::cout << arr.getElement(1) << std::endl;
      std::cout << arr.getElement(2) << std::endl;


   }
   catch (const std::exception& ex) {
      std::cout << ex.what() << std::endl;
   }

}