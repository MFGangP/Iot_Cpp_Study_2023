#include <iostream>

<<<<<<< HEAD
namespace Hybrid {
	void HybFunc(void) {
		std::cout << "So simple function!" << std::endl;
		std::cout << "In namespace Hybrid!" << std::endl;
	}
}

int main(void) {
	using Hybrid::HybFunc;
	HybFunc();
	return 0;
=======
namespace Hybrid{
    void HybFunc(void){
        std::cout<<"So simple function!"<<std::endl;
        std::cout<<"In namespace Hybrid!"<<std::endl;
    }
}

int main(void){
    using Hybrid::HybFunc;
    HybFunc();
    return 0; 
>>>>>>> b4129da34f2f7da400cdd8674786538e479d9d06
}