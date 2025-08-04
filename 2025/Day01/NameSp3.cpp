#include <iostream>

namespace BestComImpl {
	void SimpleFunc(void);
}

namespace BestComImpl {
	void PrettyFunc(void);
}

namespace ProgComImpl {
	void SimpleFunc(void);
}


int main() {
	BestComImpl::SimpleFunc();
	return 0;
}

void BestComImpl::SimpleFunc(void) {
	std::cout << "BestCom으로 정의된 함수" << std::endl;
	PrettyFunc(); 
	ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc(void) {
	std::cout << "So Pretty!!" << std::endl;
}

void ProgComImpl::SimpleFunc(void) {
	std::cout << "ProgCom으로 정의된 함수" << std::endl;
}